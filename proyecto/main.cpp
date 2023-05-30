#include <iostream>
#include <string>
#include <iostream>
#include <list>
#include <deque>
#include <string>
using namespace std;

class BigInteger{
    private:
    bool signo;
    deque<int> lista;
    public:
    /*OPERACIONES DEL TAD*/
    /*Constructoras*/
    BigInteger(deque<int> listaa, bool sign0);
    BigInteger(string &s);
    BigInteger();
    BigInteger (BigInteger &lista2);

    /*Modificadoras*/
    void add (BigInteger &lista2);
    void product (BigInteger &lista2);
    void substract (BigInteger &lista2);
    void quotient (BigInteger &lista2);
    void remainder (BigInteger &lista2);
    void pow (BigInteger &lista2, int val);
    string toString ();
    void setSign(bool sign);

    /*Analizadoras*/
    int getIth(int i);
    int getSize ();
    bool getSign ();

    /*Sobrecarga de operadores*/
    BigInteger operator+ (BigInteger &lista2);
    BigInteger operator- (BigInteger &lista2);
    BigInteger operator* (BigInteger &lista2);
    BigInteger operator/ (BigInteger &lista2);
    BigInteger operator% (BigInteger &lista2);
    bool operator== (BigInteger &lista2);
    bool operator< (BigInteger &lista2);
    bool operator<= (BigInteger &lista2);



};

int BigInteger::getIth (int i){
    return lista[i];
}
int BigInteger::getSize (){
    return lista.size();
}
bool BigInteger::getSign (){
    return signo;
}
void BigInteger::setSign (bool sign){
    signo=sign;
}
BigInteger :: BigInteger (deque<int> listaa, bool sign0){
    signo=sign0;
    lista=listaa;
}
BigInteger :: BigInteger(){
    signo=true;
}

BigInteger :: BigInteger(BigInteger &lista2){
    signo=lista2.getSign();
    lista= deque<int>(lista2.lista);
}



BigInteger::BigInteger(string &s){
    int n, i=0;
    if (s[0]=='-'){
        signo=false;
        for (i=s.size()-1;i>0;i--){
            n=s[i]-'0';
            lista.push_back(n);
        }
    }
    else {
        signo=true;
        for (i=s.size()-1;i>=0;i--){
            n=s[i]-'0';
            lista.push_back(n);
        }
    }
}

bool BigInteger::operator<(BigInteger &lista2){
    bool ans=false, flag=true;
    if (signo!=lista2.getSign()){
        if (signo && !lista2.getSign())
            ans=false;
        else if (!signo && lista2.getSign())
            ans=true;
    }
    else if (!signo && !lista2.getSign()){
        if (lista.size()!= lista2.getSize())
            ans=lista.size()>lista2.getSize();
        else{
            int i=lista.size();
            while (i>=0 && flag){
                if (lista[i]!=lista2.getIth(i)){
                    ans=lista[i]>lista2.getIth(i);
                    flag=false;
                }
                i--;
            }
        }
    }
    else if (signo && lista2.getSign()){
        if (lista.size()!=lista2.getSize())
            ans=(lista.size())<(lista2.getSize());
        else{
            int i=lista.size()-1;
            while (i>=0 && flag){
                if (lista[i]!=lista2.getIth(i)){
                    ans=lista[i]<lista2.getIth(i);
                    flag=false;
                }
                i--;
            }

        }
    }
    return ans;
}


bool BigInteger::operator<=(BigInteger &lista2){
    bool ans=true, flag=true;
    if (signo!=lista2.getSign()){
        if (signo && !lista2.getSign())
            ans=false;
        else if (!signo && lista2.getSign())
            ans=true;
    }
    else if (!signo && !lista2.getSign()){
        if (lista.size()!= lista2.getSize())
            ans=lista.size()>=lista2.getSize();
        else{
            int i=lista.size()-1;
            while (i>=0 && flag){
                if (lista[i]!=lista2.getIth(i)){
                    ans=lista[i]>=lista2.getIth(i);
                    flag=false;
                }
                i--;
            }
        }
    }
    else if (signo && lista2.getSign()){
        if (lista.size()!=lista2.getSize())
            ans=lista.size()<=lista2.getSize();
        else{
            int i=lista.size()-1;
            while (i>=0 && flag){
                if (lista[i]!=lista2.getIth(i)){
                    ans=lista[i]<=lista2.getIth(i);
                    flag=false;
                }
                i--;
            }

        }
    }
    return ans;
}

bool BigInteger::operator==(BigInteger &lista2){
    bool ans=false, flag=true;
    if (signo==lista2.getSign()){
        if (lista.size()==lista2.getSize()){
            int i=lista.size()-1;
            while (i>=0 && flag){
                if (lista[i]!=lista2.getIth(i)){
                    flag=false;
                }
                i--;
            }
            if (flag)
                ans=true;
        }
    }
    return ans;
}




/*----------------------------------------------------------------------------------*/


string biggerOrSmaller (string num1,string dec1, string num2, string dec2){
    string ans;
    BigInteger x(num1), y(num2);
    if (y<x){
        ans="Bigger";
    }
    else if (x<y){
        ans="Smaller";
    }
    else {
        BigInteger d1(dec1),d2(dec2);
        if (d1.getSize()==d2.getSize()){
            if (d2<d1){
                ans="Bigger";
            }
            else if (d1<d2){
                ans="Smaller";
            }
            else{
                ans= "Same";
            }
        }
        else {
            bool flag1=true,flag2=true;
            for (int i=0;i<d1.getSize();i++ && flag1){
                if (d1.getIth(i)!=0){
                    flag1=false;
                }
            }
            for (int i=0;i<d2.getSize();i++ && flag2){
                if (d2.getIth(i)!=0){
                    flag2=false;
                }
            }
            if (flag1 && flag2){
                ans="Same";
            }
            else if (!flag1 && flag2){
                ans="Bigger";
            }
            else if (flag1 && !flag2){
                ans="Smaller";
            }
            else{
                if (d2<d1){
                    ans="Smaller";
                }
                else if (d1<d2){
                    ans="Bigger";
                }
                else if (d1==d2){
                    ans="Same";
                }
            }
        }
    }
    return ans;
}

string lecturaDatos (string cad1){
    string cad2, num1,dec1,num2,dec2,ans;
    cin>>cad2;
    int i=0;
    while (cad1[i]!='.'){
        num1.push_back(cad1[i]);
        i++;
    }
    i++;
    while (i<cad1.size()){
        dec1.push_back(cad1[i]);
        i++;
    }
    i=0;
    while (cad2[i]!='.'){
        num2.push_back(cad2[i]);
        i++;
    }
    i++;
    while (i<cad2.size()){
        dec2.push_back(cad2[i]);
        i++;
    }
    ans=biggerOrSmaller(num1,dec1,num2,dec2);
    return ans;
}

int main(){
    string cad1, ans;
    int contador=1;
    while(cin>>cad1){
        ans=lecturaDatos(cad1);
        cout<<"Case "<<contador<<": "<<ans<<endl;
        contador++;
    }
    return 0;
}