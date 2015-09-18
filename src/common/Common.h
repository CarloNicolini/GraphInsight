/****************************************************************************
**
** Copyright (C) 2010 Michele Dallachiesa (michele.dallachiesa@gmail.com)
** All rights reserved.
**
** Warning: This program is protected by copyright law and international
** treaties. Unauthorized reproduction and distribution of this program,
** or any portion of it, may result in severe civil and criminal penalties,
** and will be persecuted to the maximum extent possible under the law.
**
****************************************************************************/


#ifndef _COMMON_H
#define	_COMMON_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <map>
#include <set>
#include <vector>
#include <string>
#include "MersenneTwister.h"

using namespace std;

static MTRand mtrand1;

#ifdef DEBUG
#define DEBUG_PRINT(x) do{ cerr << "DEBUG: " << x << "\n"; cerr.flush(); }while(0)
#else
#define DEBUG_PRINT(x) do{}while(0)
#endif

#ifndef SQR
#define SQR(c)  ((c) * (c))
#endif


#ifndef M_PI
#define M_PI 3.141592653589793238462643
#endif

#ifdef _WIN32
#define isnan(x) _isnan(x)
#define isinf(x) (!_finite(x))
#define fpu_error(x) (isinf(x) || isnan(x))
#ifndef NOMINMAX
#define NOMINMAX
#endif
#endif

/**
*  \defgroup Common The Common group which encapsulates some common usage functions
*  \brief Common groups all the functions and methods which are of very common use, they are at most static methods.
*  \class Common
* \ingroup Common
* \brief Common is a set of functions and method for various usage
**/
class Common {
public:
    Common();
    ~Common();

    static void skipSpaces(stringstream &str);
    static void readChar(stringstream &str, int c);
    static void skipSpacesReadChar(stringstream &str, int c);
    static int nextChar(stringstream &str);
    static void tokenizeString(const string& str, vector<string>& tokens, const string& delimiters);
    static string nextToken(stringstream &str, const char *delimiters);
    static string trim(string &s);
    static int equalCaseInsensitive(string s1, string s2);
    static bool  isnumeric(const char *p);

    // Random number generation utils
    static double unifRand();
    static double unifRand(double a, double b);
    static int    unifRand(int a, int b);
    static double unifRandExc(double);
    static long   unifRand(long n);
    static int unifPosOrNeg();

    // Old versions of IO functions
    static int iReadChar(stringstream &str, int c);
    static int iSkipSpacesReadChar(stringstream &str, int c);
    static int iNextChar(stringstream &str);

};

template <class T> string stringify(const T &t)
{
    std::ostringstream o;
    o<< t;
    return o.str();
}

template< class T>
bool str2num( const std::string& s, T &val )
{
    std::istringstream i(s);
    if (!(i >> val))
        return false;
    return true;
}

template <class T> string vector2string( const std::vector< T >& s, const std::string &separator )
{
  std::string ret;
  for (unsigned int i=0; i<s.size(); i++)
      ret.append(stringify<T>(s.at(i)) + " " + separator);
  // erase the last separator or space
  ret.erase(ret.end()-1);
  return ret;
}

template <typename T> bool valueInRange(const T& value, const T& low, const T& high)
{
    return !(value < low) && !(high < value);
}
#endif	/* _COMMON_H */

