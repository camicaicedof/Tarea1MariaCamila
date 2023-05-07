#ifndef proyecto_h
#define proyecto_h

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class BigInteger{
    private:
    vector<int> vec;
    public:
    /*OPERACIONES DEL TAD*/
    /*Constructoras*/
    void StringToBigInt(string &s);
    BigInteger copyBigInt (BigInteger &vec2);

    /*Modificadoras*/
    void add (BigInteger &vec2);
    void product (BigInteger &vec2);
    void substract (BigInteger &vec2);
    void quotient (BigInteger &vec2);
    void remainder (BigInteger &vec2);
    void pow (BigInteger &vec2, int val);
    string toString ();

    /*Analizadoras*/
    int getIth(int i);
    int getSize ();

    /*Sobrecarga de operadores*/
    BigInteger operator+ (BigInteger &vec2);
    BigInteger operator- (BigInteger &vec2);
    BigInteger operator* (BigInteger &vec2);
    BigInteger operator/ (BigInteger &vec2);
    BigInteger operator% (BigInteger &vec2);
    bool operator== (BigInteger &vec2);
    bool operator< (BigInteger &vec2);
    bool operator<= (BigInteger &vec2);



};

#endif