/* Copyright (c) 2009-2013, Michele Dallachiesa, Carlo Nicolini
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of the <organization> nor the
 *       names of its contributors may be used to endorse or promote products
 *       derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY <copyright holder> ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL <copyright holder> BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */


#include "Cnf.h"

/**
 * @brief Cnf::Cnf
 */
Cnf::Cnf() : nvars(0)
{

}

/**
 * @brief Cnf::Cnf
 * @param orig
 */
Cnf::Cnf(const Cnf& orig) : nvars(orig.nvars)
{
}

/**
 * @brief Cnf::~Cnf
 */
Cnf::~Cnf()
{
    /*
     *for (Clauses::iterator iter = clauses.begin(); iter != clauses.end(); ++iter)
    {  iter->clear();
    }
    clauses.clear();
    */
}

/**
 * @brief Cnf::loadFromFile
 * @param is
 */
void Cnf::loadFromFile(istream& is)
{
    long p;
    char c;
    int sign;
    Clause clause;
    clauses.clear();
    DEBUG_PRINT(" Loading CNF formula ...");
    while (!is.eof())
    {
        // skip comment & problem description lines
        while ((c = is.get()) == 'c' || c == 'p')
            while ((c = is.get()) != '\n'){};
        is.unget();
        clause.clear();
        do
        {
            while (isspace(c = is.get())); // ignore spaces
            if (is.eof())
            {  break;
            }
            else
            {  if (c == '-')
                {  sign = -1;
                }
                else
                {  sign = 1;
                    is.unget();
                }
                p = 0;
                while (isdigit(c = is.get()))
                {
                    p = 10 * p + c - '0';
                }
                p = sign * p;
                if (p != 0)
                    clause.push_back(p);
            }
        }
        while (p != 0);
        if(!clause.empty() )
            clauses.push_back(clause);
    }
    DEBUG_PRINT( "CNF Formula loaded %d clauses. "<<  clauses.size());
#ifdef DEBUG
    //this->print(cerr);
#endif
}

/**
 * @brief Cnf::loadFromFile2 It's a slower but always correct version of the parser because is based on string tokenization
 * @param filename
 */
void Cnf::loadFromFile2(ifstream &file)
{
    this->clauses.clear();
    std::string line;
    Clause clause;
    while ( getline(file,line) )
    {
        // Tokenize the string accordin to spaces
        std::string trimmedLine = Common::trim(line);
        if (trimmedLine.empty())
            continue;
        if (trimmedLine.at(0)=='c' || trimmedLine.at(0)=='p')
            continue;

        std::stringstream buffer(trimmedLine);
        long var;
        while (buffer >> var)
        {
            if (var==0)
            {
                clauses.push_back(clause);
                clause.clear();
            }
            else
            {
                clause.push_back(var);
            }
        }

        /*
         * XXX THIS COMMENTED VERSION IS MUCH SLOWER
        std::vector<std::string> tokens;
        Common::tokenizeString(trimmedLine,tokens," ");
        // Search for the last '0', if it is present at this same line, then the clause has to be added to the clauses list
        // otherwise we must get a new line and check until a final '0' is found
        if (tokens.back()!="0")
        {
            // Populate the current clause and then only when a 0 is found, add it to the clauses
            for (std::vector<std::string>::iterator iter = tokens.begin(); iter!=tokens.end();++iter)
            {
                std::stringstream buffer(*iter);
                long var;
                buffer >> var;
                clause.push_back( var );
            }
        }
        else
        {
            for (std::vector<std::string>::iterator iter = tokens.begin(); iter!=tokens.end();++iter)
            {
                std::stringstream buffer(*iter);
                long var;
                buffer >> var;
                if (var!=0)
                    clause.push_back( var );
            }
            clauses.push_back(clause);
            clause.clear();
        }
        */
    }
    DEBUG_PRINT( "CNF Formula loaded %d clauses. "<<  clauses.size());
#ifdef DEBUG
//    this->print(cerr);
#endif
}

/**
 * @brief Cnf::buildVariableInteractionGraph
 * @param graph
 * @return
 */
bool Cnf::buildVariableInteractionGraph(Graph *graph)
{
    //LOG(1, 1, " ! Building variable interaction graph ...");
    for (Clauses::iterator iter1 = clauses.begin(); iter1 != clauses.end(); ++iter1)
    {
        for (Clause::iterator iter2 = iter1->begin(); iter2 != iter1->end(); ++iter2)
        {  graph->insertNode(abs(*iter2));
        }
        for (Clause::iterator iter2 = iter1->begin(); iter2 != iter1->end(); ++iter2)
        {  for (Clause::iterator iter3 = iter1->begin(); iter3 != iter1->end(); ++iter3)
            {  if (abs(*iter2) != abs(*iter3))
                    graph->insertEdge(abs(*iter2), abs(*iter3));
            }
        }
    }
    //    LOG(1, 1, "   * (|V|,|E|) = (%d,%d)", graph->nodes.size(), graph->getEdgesCount());
    return true;
}

/**
 * @brief Cnf::buildResolutionGraph
 * @param graph
 * @return
 */
bool Cnf::buildResolutionGraph(Graph *graph)
{
    int nextClauseId = 1;
    //    LOG(1, 1, " ! Building resolution graph ...");
    //  LOG(1, 1, "   * Building literals table ...");
    ClausesLiterals clausesLiterals; // literal -> clauses set where it occurs.
    // carico la struttura clausesLiterals:
    for (Clauses::iterator iter1 = clauses.begin(); iter1 != clauses.end(); ++iter1)   // per ogni clausola
    {  for (Clause::iterator iter2 = iter1->begin(); iter2 != iter1->end(); ++iter2)   // per ogni literal
        {  //   LOG(1, 1, "in literal %d inserisco clause %d", *iter2, nextClauseId);
            clausesLiterals[*iter2].insert(nextClauseId);
        }
        nextClauseId++;
    }
    // ora genero il resolution graph:
    for (ClausesLiterals::iterator iter = clausesLiterals.begin(); iter != clausesLiterals.end(); ++iter)
    {  if (iter->first < 0) // work only on positive literals.
            continue;
        // per ciascun literal positivo ....
        Literals negClauseLiterals = clausesLiterals[-iter->first]; // take corresponding negative literal
        // ora ho in iter il clauses set per il literal positivo ed in negClauseLiterals il clauses set per il literal negativo (della stessa variabile).
        //  LOG(1,1,"considero literals %d e %d", iter->first, -iter->first);
        for (Literals::iterator iter1 = iter->second.begin(); iter1 != iter->second.end(); ++iter1)
        {  for (Literals::iterator iter2 = negClauseLiterals.begin(); iter2 != negClauseLiterals.end(); ++iter2)
            {  // here we work on variable A:
                // in iter1 we have clauses ids of literal A, in iter2 we have clauses ids of literal -A.
                //  LOG(1,1,"ho clauses %d %d", *iter1, *iter2);
                graph->insertNode(*iter1);
                graph->insertNode(*iter2);
                graph->insertEdge(*iter1, *iter2);
            }
        }
    }
    //    clausesLiterals.clear();
    // LOG(1, 1, "   * (|V|,|E|) = (%d,%d)", graph->nodes.size(), graph->getEdgesCount());
    return graph;
}

void Cnf::print(ostream &os)
{
    for (Clauses::iterator iterAllClauses = clauses.begin(); iterAllClauses != clauses.end(); ++iterAllClauses)
    {
        for (Clause::iterator iterLiterals = iterAllClauses->begin(); iterLiterals != iterAllClauses->end(); ++iterLiterals)
        {
            os << (*iterLiterals) << " ";
        }
        os << endl;
    }
}

