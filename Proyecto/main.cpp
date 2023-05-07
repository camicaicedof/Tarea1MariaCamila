#include "proyecto.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;
void imprimirBigInt(BigInteger &x){
    string m;
    m=x.toString();
    for (int i=0;i<m.size();i++)
        cout<<m[i]<<" ";
}

int main(){
    string s="99",m="1";
    BigInteger x, y;
    x.StringToBigInt(s);
    y.StringToBigInt(m);
    x.add(y);
    imprimirBigInt(x);

    return 0;
}