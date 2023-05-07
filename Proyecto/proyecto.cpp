#include "proyecto.h"

int BigInteger::getIth (int i){
        return vec[i];
}
int BigInteger::getSize (){
        return vec.size();
}

void BigInteger::StringToBigInt(string &s){
    int i, n;
    for (i=s.size()-1;i>=0;i--){
        n=s[i]-'0';
        vec.push_back(n);
    }
}

void BigInteger::add(BigInteger &vec2){
    int acarreo=0, prov, l1,l2, lvec1=vec.size(),lvec2=vec2.getSize(),contador;
    l1=(lvec1<=lvec2)?lvec1:lvec2;
    l2=(lvec1>lvec2)?lvec1:lvec2;
    for (int i=0;i<l1;i++){
        prov=vec[i]+vec2.getIth(i)+acarreo;
        if (prov>9){
            acarreo=1
            
        }

    }
}


string BigInteger::toString(){
    int i;
    char n;
    string retorno;
    for (i=vec.size()-1;i>=0;i--){
        n=vec[i]+'0';
        retorno.push_back(n);
    }
    return retorno;
}
