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


#include "Common.h"

/**
@ingroup Common
**/
Common::Common() {

}

/**
@ingroup Common
**/
Common::~Common() {

}

/**
@ingroup Common
Get the next string with a given delimiter from an open stringstream object
@param str stringstream to iterate on
@param delimiters a char which specifies the delimiter to tokenize the string stream, typicall space or tab
@return The tokenized string, the stringstream is also advanced
**/
string Common::nextToken(stringstream &str, const char *delimiters) {
    string ret("");
    unsigned char c;
    int i;
    while( (c = str.get()) && !str.eof())
    {
        for(i = 0; delimiters[i];i++)
        {
            if(c == delimiters[i])
                break;
        }
        if(c == delimiters[i])
            break;
        ret.append(1,c);
    }
    if(!str.eof())
        str.unget();
    return ret;
}

/**
@ingroup Common
Skip space on an open stringstream until a non-space or non-tab or non return is found
@param str stringstream to advance on
**/
void Common::skipSpaces(stringstream &str) {
    char c;
    while (((c = str.get()) == ' ') || c == '\t' || c == '\r' || c == '\n');
    str.unget();
}

/**
@ingroup Common
Read a specific char from a stringstream
@param str stringstream to advance on
@param c char to find
**/
void Common::readChar(stringstream &str, int c) {
    int cc;
    if ((cc = str.get()) != c)
        cerr << "expected " << (char) c << "but found " << (char) cc << "\n";
}

/**
@ingroup Common
Read a given char ignoring spaces or tabs
@param str stringstream to advance on
@param c char to find
**/
void Common::skipSpacesReadChar(stringstream &str, int c) {
    skipSpaces(str);
    readChar(str, c);
    skipSpaces(str);
}

/**
@ingroup Common
Get the next char
@param str stringstream to iterate on
**/
int Common::nextChar(stringstream &str) {
    int c = str.get();
    str.unget();
    return c;
}

/**
@ingroup Common
Trim the string from spaces or tabulation or carriage returns
**/
string Common::trim(string &s) {
    char drop[] = " \t\r";

    s.erase(s.find_last_not_of(drop)+1);
    s.erase(0,s.find_first_not_of(drop));

    return s;
}

/**
@ingroup Common
Return true if two strings are equal ignoring case
@param s1 string 1 to compare
@param s2 string 2 to compare
@return 1 if the strings are equal, 0 otherwise
**/
int Common::equalCaseInsensitive(string s1, string s2)
{
    if(s1.size() != s2.size())
        return 0;

    int n = s1.size();

    for(int i = 0; i < n; i++) {
        if(tolower(s1.at(i)) != tolower(s2.at(i)))
            return 0;
    }

    return 1;
}

/**
  @ingroup Common
  Tokenize a stirng and returns a vector of strings tokenized with a given delimiter
  @param str string to tokenize
  @param tokens return vector of strings
  @param delimiters string containing char delimiters
**/
void Common::tokenizeString(const string& str, vector<string>& tokens, const string& delimiters) {
    tokens.clear();
    // Skip delimiters at beginning.
    string::size_type lastPos = str.find_first_not_of(delimiters, 0);
    // Find first "non-delimiter".
    string::size_type pos = str.find_first_of(delimiters, lastPos);

    while (string::npos != pos || string::npos != lastPos) {
        // Found a token, add it to the vector.
        tokens.push_back(str.substr(lastPos, pos - lastPos));
        // Skip delimiters.  Note the "not_of"
        lastPos = str.find_first_not_of(delimiters, pos);
        // Find next "non-delimiter"
        pos = str.find_first_of(delimiters, lastPos);
    }
}
/**
 *@ingroup Common
 * @brief Common::isnumeric Check if a string is numeric or contains non numeric characters
 * @param p
 * @return
 */
bool Common::isnumeric(const char *p)
{
     if (*p)
     {
          char c;
          while ((c=*p++))
          {
              if (!isdigit(c) || !ispunct(c))
                  return false;
          }
          return true;
      }
      return false;
}

/**
@ingroup Common
@return Return a uniform random number in [0,1]
**/
double Common::unifRand()
{  return mtrand1.rand();
}

/**
@ingroup Common
@return Return a uniform random number in interval [a,b]
@param a minimum limit
@param b maximum limit
@return a number with random uniform distrbution in [a,b]
**/
double Common::unifRand(double a, double b)
{  //return (b-a)*unifRand() + a;
    return (b-a)*mtrand1.rand() +a ;
}

/**
@ingroup Common
@return Return a uniform random number in open interval [0,end)
@param end maximum limit excluded
**/
double Common::unifRandExc(double end)
{  return mtrand1.randExc(end);
}

/**
@ingroup Common
@return Return a uniform random integer number in [a,b]
@param a  lower limit
@param b higher limit
**/
int Common::unifRand(int a, int b)
{  //return (b-a)*unifRand() + a;
    return (b-a)*mtrand1.randInt() + a;
}

/**
@ingroup Common
@return Return a uniform random long integer number in [0,n]
@param n higher limit
**/
long Common::unifRand(long n)
{

    if (n < 0) n = -n;
    if (n==0) return 0;

    long num = mtrand1.randInt( n );
    return num;
}

/**
@ingroup Common
@return Return 1 or -1 with 50% probability
**/
int Common::unifPosOrNeg()
{  int res=0;
    (unifRand(1)== 0) ? res=1 : res= -1;
    return res;
}


/**
 * @brief Common::iReadChar
 * @param str
 * @param c
 * @return
 */
int Common::iReadChar(stringstream &str, int c)
{  int cc;
    if ((cc = str.get()) != c)
    {  cerr << "expected \"" << (char) c << "\" but found \"" << (char) cc << "\" ";
        return 1;
    }
    return 0;
}

/**
 * @brief Common::iSkipSpacesReadChar
 * @param str
 * @param c
 * @return
 */
int Common::iSkipSpacesReadChar(stringstream &str, int c)
{
    Common::skipSpaces(str);
    int ret=iReadChar(str, c);
    skipSpaces(str);
    return ret;
}

/**
 * @brief Common::iNextChar
 * @param str
 * @return
 */
int Common::iNextChar(stringstream &str)
{  int c = str.get();
    str.unget();
    return c;
}
