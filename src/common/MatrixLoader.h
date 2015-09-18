/****************************************************************************
**
** Copyright (C) 2012 Carlo Nicolini (nicolini.carlo@gmail.com)
** All rights reserved.
**
** Warning: This program is protected by copyright law and international
** treaties. Unauthorized reproduction and distribution of this program,
** or any portion of it, may result in severe civil and criminal penalties,
** and will be persecuted to the maximum extent possible under the law.
**
****************************************************************************/

#ifndef _MATRIX_LOADER_H
#define _MATRIX_LOADER_H
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <fstream>
#include <iostream>
#include <stdexcept>

#include "Common.h"
/**
 * @ingroup Common
 * @brief The MatrixLoader class Help the user to load a matrix from file, it's exception safe, throws if error or inconsistencies are found during parsing process
 */
template <typename Derived>
class MatrixLoader
{
    typedef typename Derived::Scalar SparseScalar;
    typedef typename Derived::Scalar Scalar;

public:
    /**
     * @brief MatrixLoader
     * @param filename
     * @param loadingSparseMatrix
     */
    MatrixLoader(const char *filename, bool loadingSparseMatrix=false)
    {
        std::ifstream is(filename);

        if (is.is_open())
        {
            if (loadingSparseMatrix)
                loadSparseMatrixSVMLight(is,S);
            else
                loadDenseMatrix(is,M);
        }
    }
    /**
     * @brief MatrixLoader
     * @param filename
     */
    MatrixLoader(const std::string &filename, bool loadingSparseMatrix=false)
    {
        std::ifstream is(filename.c_str());

        if (is.is_open())
        {
            if (loadingSparseMatrix)
                loadSparseMatrixSVMLight(is,S);
            else
                loadDenseMatrix(is,M);
        }
    }

    /**
     * @brief MatrixLoader
     * @param is
     */
    MatrixLoader(std::ifstream &is, bool loadingSparseMatrix=false)
    {
        if (is.is_open())
        {
            if (loadingSparseMatrix)
                loadSparseMatrixSVMLight(is,S);
            else
                loadDenseMatrix(is,M);
        }
    }

    /**
     * @brief getMatrix
     * @return
     */
    const Derived &getMatrix()
    {
        return M;
    }

    /**
     * @brief getSparseMatrix Get the sparse matrix as const reference
     * @return The reference to sparse matrix
     */
    const Eigen::SparseMatrix< SparseScalar > &getSparseMatrix()
    {
        return S;
    }

private:
    Derived  M;
    typename Eigen::SparseMatrix< SparseScalar > S;

    /**
     * @brief loadDenseMatrix
     * @param is
     * @param A
     */
    void loadDenseMatrix(ifstream &is, Eigen::MatrixBase<Derived> &A)
    {
        if (!is.is_open())
        {
            throw std::runtime_error("Input stream is not open, busy or the selected file doesn't exist");
            return;
        }

        std::vector < Scalar > dataarray;
        // First count the rows of the matrix
        unsigned int nrows=0,ncols=0;
        while ( !is.eof() )
        {
            vector<string> tokens;
            string line;
            std::getline(is,line);
            if (line.empty())
                break;

            // Search for comments with # or % if comments are found, then skip the line
            //cout << trimline(line) << endl;
            size_t found = Common::trim(line).find_first_of("%#");
            if ( found!=string::npos && found==0 )  // if some of comment char are found and are not in the first lines
            {
                continue;
            }

            // Search for non-numeric values
            Common::tokenizeString(line,tokens,"\t ,");
            if (ncols!=0 && tokens.size()!=ncols)
            {
                std::string errormessage("Error too many columns at row ");
                throw std::runtime_error( (errormessage.append(stringify<int>(nrows+1))).c_str() );
            }

            if (nrows==0)
                ncols=tokens.size();

            unsigned int charcolumn=tokens.size(); // start counting from the total number of tokes
            for (vector< std::string>::iterator iter = tokens.begin(); iter!=tokens.end(); ++iter)
            {
                Scalar value = std::numeric_limits< Scalar >::min();
                if ( str2num<Scalar>(*iter,value) )
                {
                    dataarray.push_back(value);
                    charcolumn+=iter->size();
                }
                else
                {
                    std::string errormessage("Error parsing file on row ");
                    errormessage+=stringify<int>(nrows+1);
                    errormessage+=", column " + stringify<unsigned int>(charcolumn) + string(": A non-numeric value was found: \'") + (*iter) + "\'";
                    throw std::runtime_error(errormessage);
                }
            }
            nrows++;
        }
        // Finally map the std::vector to the matrix with correct number of rows and column, remember that the matrix is in RowMajor format
        A = Eigen::Map<Derived> (&dataarray.at(0),nrows,ncols);
    }

    /**
     * @brief loadSparseMatrixSVMLight Load a sparse matrix from SVM light matrix file, ignores labels
     * @param is Input file stream
     * @param S Sparse matrix to fill
     * @param ignoreLabels True if you have to ignore labels
     */
    void loadSparseMatrixSVMLight(ifstream &is,  Eigen::SparseMatrix< SparseScalar > &S, bool ignoreLabels=true)
    {
        std::vector < Eigen::Triplet<typename Derived::Scalar> > dataarray;
        // First count the rows of the matrix
        unsigned int nrows=0,maxcols=0;
        if (!is.is_open())
        {
            throw std::runtime_error("Input stream is not open, busy or the selected file doesn't exist");
            return;
        }
        string line;
        while (getline(is, line))
        {
            if (line.size() == 0)
                continue;
            int junk;
            stringstream sstream(line);
            if ( ignoreLabels )
                sstream >> junk; //Ignore the label of first column
            Common::skipSpaces(sstream);

            size_t found = Common::trim(line).find_first_of("%#");
            if ( found!=string::npos && found==0 )  // if some of comment char are found and are not in the first lines
            {
                continue;
            }

            string remainingline;
            getline(sstream,remainingline);

            vector <string> tokens;
            Common::tokenizeString(remainingline,tokens," :");
            // Odd columns contain value, even columns contain column index
            for (unsigned int i=0; i<tokens.size(); i+=2)
            {
                unsigned int m = nrows;
                int n=std::numeric_limits<int>::min();
                Scalar value=std::numeric_limits<Scalar>::min();
                str2num<Scalar>(tokens.at(i+1),value);
                str2num<int>(tokens.at(i),n);
                maxcols=std::max<int>(maxcols,n);
                dataarray.push_back(Eigen::Triplet<Scalar>(m,n,value));
            }
            ++nrows;
        }
        if (nrows!=0)
        {
            S.resize(nrows,maxcols+1);
            S.setFromTriplets(dataarray.begin(),dataarray.end());
        }
        else
        {
            throw  std::runtime_error("File is empty, cannot load anything");
        }
    }
};

#endif
