/*María Camila Caicedo Florez
código de estudiante: 8977474
Fecha: 30 de mayo de 2023*/
#ifndef proyecto_h
#define proyecto_h
#include <iostream>
#include <list>
#include <deque>
#include <string>
#include <vector>
using namespace std;

class BigInteger{
    private:
    bool signo;
    deque<int> lista;
    public:
    /*OPERACIONES DEL TAD*/
    /*Constructoras*/
    BigInteger(const deque<int> &, bool );
    BigInteger(const string &);
    BigInteger();
    BigInteger (const BigInteger &);


    /*Modificadoras*/
    void add (BigInteger &);
    void product (BigInteger &);
    void substract (BigInteger &);
    void quotient (BigInteger &);
    void remainder (BigInteger &);
    void pow (int n);
    string toString ();
    void setSign(bool sign);

    /*Analizadoras*/
    int getIth(int);
    int getSize ();
    bool getSign ();
    vector<BigInteger> tablaMult();

    /*Sobrecarga de operadores*/
    BigInteger operator+ (BigInteger &);
    BigInteger operator- (BigInteger &);
    BigInteger operator* (BigInteger &);
    BigInteger operator/ (BigInteger &);
    BigInteger operator% (BigInteger &);
    bool operator== (BigInteger &);
    bool operator< (BigInteger &);
    bool operator<= (BigInteger &);

    /*Estáticas*/
    static BigInteger sumarListaValores (list<BigInteger> &);
    static BigInteger multiplicarListaValores (list<BigInteger> &);



};

#endif