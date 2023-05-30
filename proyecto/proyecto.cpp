#include "proyecto.h"
/*
Función getIth
Entrada: Un entero positivo.
Salida: Un número entero positivo.
Descripción: Esta función retorna el número que se encuentra en la
posición i de la lista del BigInteger actual.
*/
int BigInteger::getIth (int i){
    return lista[i];
}
/*
Función getSize
Entrada: No aplica
Salida: Un número entero positivo.
Descripción: Esta función retorna la cantidad de dígitos que tiene el BigInteger
al que se le aplica la función.

*/
int BigInteger::getSize (){
    return lista.size();
}
/*
Función getSign
Entrada: No aplica
Salida: Un booleano.
Descripción: Esta función retorna el signo que tiene el BigInteger al que se
le aplica la función, true si el signo es positivo y false si el signo es 
negativo.

*/
bool BigInteger::getSign(){
    return signo;
}


/*
Función setSign
Entrada: Un Booleano
Salida: No aplica
Descripción: Esta función puede cambiar el signo del BigInteger al que se le
aplique esta función.

*/
void BigInteger::setSign (bool sign){
    signo=sign;
}
/*
Función constructora1 BigInteger
Entrada: Un deque y un Booleano
Salida: Un BigInteger
Descripción: Esta función crea un BigInteger con el deque y el signo
que se le pasa por parámetro.

*/
BigInteger::BigInteger(const deque<int> &listaa, bool sign0){
    signo=sign0;
    lista=listaa;
}
/*
Función constructora2 BigInteger
Entrada: No aplica.
Salida: Un BigInteger.
Descripción: Esta función retorna un BigInteger vacío con un signo por defecto
*/
BigInteger :: BigInteger(){
    signo=true;
}
/*
Función constructora3 BigInteger
Entrada: un BigInteger
Salida: Un BigInteger
Descripción: Esta función copia el BigInteger que se le pasa por parámetro y lo retorna.
*/
BigInteger :: BigInteger(const BigInteger &lista2){
    signo=lista2.signo;
    lista= deque<int>(lista2.lista);
}
/*
Función constructora4 BigInteger
Entrada: Un string
Salida: Un BigInteger
Descripción: Esta función retorna un BigInteger que toma el signo y el valor a 
partir del string que se pasa por parámetro.
*/
BigInteger::BigInteger(const string &s){
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
/*
Función add
Entrada: Un BigInteger
Salida: No aplica
Descripción: Esta función suma los elementos que hay en el BigInteger actual
con el que se pasa por referencia y almacena el resultado en el mismo BigInteger.
*/
void BigInteger::add(BigInteger &lista2){
    int acarreo=0, prov,longl1=lista.size(),longl2=lista2.getSize(), l1, l2, i;
    if ((signo && lista2.getSign()) || (!signo && !lista2.getSign())){
        if (longl1<longl2){
            l1=lista.size();
            l2=lista2.getSize();
        }
        else{
            l1=lista2.getSize();
            l2=lista.size();
        }
        i=0;
        if (longl1<longl2){
            while (i<l2){
                if (i<l1){
                    prov=lista[i]+lista2.getIth(i)+acarreo;
                    if (prov>9){
                        acarreo=1;
                        lista[i]=prov-10;
                    }
                    else{
                        acarreo=0;
                        lista[i]=prov;
                    }
                }
                else{
                    prov=lista2.getIth(i)+acarreo;
                    if (prov>9){
                        acarreo=1;
                        lista.push_back(prov-10);
                    }
                    else{
                        acarreo=0;
                        lista.push_back(prov);
                    }
                }
                i++;
            }
        }
        else{
            while (i<l2){
                if (i<l1){
                    prov=lista[i]+lista2.getIth(i)+acarreo;
                    if (prov>9){
                        acarreo=1;
                        lista[i]=prov-10;
                    }
                    else{
                        acarreo=0;
                        lista[i]=prov;
                    }
                }
                else{
                    prov=lista[i]+acarreo;
                    if (prov>9){
                        acarreo=1;
                        lista[i]=prov-10;
                    }
                    else{
                        acarreo=0;
                        lista[i]=prov;
                    }
                }
                i++;
            }
        }
        if (acarreo==1){
            lista.push_back(1);
        }
    }
    else if (signo && !lista2.getSign()){
        lista2.setSign(true);
        this->substract(lista2);
        lista2.setSign(false);
    }
    else if (!signo && lista2.getSign()){
        signo=true;
        bool signtemp;
        if (lista2<*this){
            signtemp=false;
        }
        else{
            signtemp=true;
        }
        this->substract(lista2);
        signo=signtemp;
    }
}
/*
Función substract
Entrada: Un BigInteger
Salida: No aplica
Descripción: Esta función resta los elementos que hay en el BigInteger actual
con el que se pasa por referencia y los almacena en el mismo BigInteger.
*/
void BigInteger::substract(BigInteger &lista2){
    int acarreo=0, prov,longl1=lista.size(),longl2=lista2.getSize(), i;
    BigInteger x;
    if (signo && lista2.getSign()){
        if (*this<lista2){
            x =lista2-(*this);
            //cout<<x.toString();
            *this= BigInteger (x);
            signo=false;/*
            for (i=0;i<longl2;i++){
                if (i<longl1){
                    if (lista2.getIth(i)<lista[i]){
                        if (lista2.getIth(i)>=0 && i!=longl2-1){
                            prov=10+lista2.getIth(i)-acarreo-lista[i];
                            lista[i]=prov;  
                            acarreo=1;
                        }
                        else if (lista2.getIth(i)<0 && i!=longl2-1){
                            prov=9-lista2.getIth(i)-acarreo;
                            acarreo=1;
                        }
                        
                    }
                    else {
                        lista[i]=lista2.getIth(i)-lista[i]-acarreo;
                        acarreo=0;
                    }
                }
                else{
                    lista.push_back(lista2.getIth(i)-acarreo);
                    acarreo=0;
                }
            }*/

        }
        else if (!(*this<lista2)){
            for (i=0;i<longl1;i++){
                if (i<longl2){
                    if (lista[i]<lista2.getIth(i)){
                        if (lista[i]>=0 && i!=longl1-1){
                            prov=lista[i]+10-lista2.getIth(i);
                            lista[i]=prov;
                            lista[i+1]-=1;
                        }
                        else if (lista[i]<0 && i!=longl1-1){
                            prov=9-lista2.getIth(i);
                            lista[i]=prov;
                            lista[i+1]-=1;
                        }
                    }
                    else {
                        lista[i]=lista[i]-lista2.getIth(i);
                    }
                }
            }
        }
        else if (*this==lista2){
            lista.clear();
            lista.push_back(0);
        }
    }
    
    else if (!signo && !lista2.getSign()){
        signo=true;
        bool signotemp;
        lista2.setSign(true);
        if (*this<lista2){
            signotemp=true;
        }
        else{
            signotemp=false;
        }
        this->substract(lista2);
        signo=signotemp;
        lista2.setSign(false);
    }
    else if (signo && !lista2.getSign()){
        signo=true;
        lista2.setSign(true);
        this->add(lista2);
        lista2.setSign(false);
    }
    else if (!signo && lista2.getSign()){
        lista2.setSign(false);
        this->add(lista2);
        lista2.setSign(true);
    }
    bool flag;
    for (int i=lista.size()-1;i>=0;i-- && flag){
        if (lista.back()==0){
            lista.pop_back();
        }
        else{
            flag=false;
        }
    }
    if (lista.empty()){
        lista.push_back(0);
    }
}
/*
Función product
Entrada: Un BigInteger
Salida: No aplica
Descripción: Esta función multiplica los elementos que hay en el BigInteger actual
con el que pasa por referencia y los almacena en el mismo BigInteger.
*/
void BigInteger:: product (BigInteger &lista2){ 
    bool signotemp=signo, signotemp2=lista2.getSign();
    signo=true;
    lista2.setSign(true);
    bool flag;
    deque<int> dq, tmp;
    BigInteger y;
    BigInteger x("0");
    int num, contador=0;
    for (int i=0;i<lista2.getSize();i++){
        contador=0;
        tmp.clear();
        for (int j=0;j<lista.size();j++){
            num=lista[j]*lista2.getIth(i);
            if (num>9){
                num+=contador;
                tmp.push_back(num%10);
                contador=num/10;
                
            }
            else if (num<=9){
                tmp.push_back(num+contador);
                contador=0;
            }
        }
        if (contador!=0){
            tmp.push_back(contador);
        }
        for (int l=0;l<i;l++){
            tmp.push_front(0);
        }
        y=BigInteger(tmp,true);
        x.add(y);
    }
    if (signotemp==signotemp2){
        signo=true;
    }
    else{
        signo=false;
    }
    lista2.setSign(signotemp2);
    lista.clear();
    for (int i=0;i<x.getSize();i++){
        lista.push_back(x.getIth(i));
    }
}
/*
Función quotient
Entrada: Un BigInteger
Salida: No aplica
Descripción: Esta función divide los elementos que hay en el BigInteger actual
con el que pasan por referencia y los almacena en el mismo BigInteger. Tomando
el BigInteger actual como dividendo y el otro como divisor.
*/
void BigInteger::quotient(BigInteger &lista2){
    bool signtemp1=signo, signtemp2=lista2.getSign();
    deque<int> ans;
    lista2.setSign(true);
    if (*this<lista2){
        lista.clear();
        lista.push_back(0);
    }
    else if (*this==lista2){
        lista.clear();
        lista.push_back(1);
        if (signtemp1==signtemp2)
            signo=true;
        else
            signo=false;
    }
    else {
        BigInteger x, copia(*this);
        vector<BigInteger> vec;
        vec=lista2.tablaMult();
        int contador=lista.size()-1;
        string s;
        char c;
        for (int i=0;i<lista2.getSize();i++){
                c=lista[contador]+48;
                s.push_back(c);
                contador--;
            }
        x= BigInteger(s);
        if (x<lista2){
            c=lista[contador]+48;
            s.push_back(c);
            contador--;
            x = BigInteger(s);
            }
        while (contador>=-1){
            int j=0;
            while(vec[j]<=x){
                j++;
            }
            j--;
            ans.push_front(j);
            (*this)=x-(vec[j]);
            if (contador>=0){
                lista.push_front(copia.getIth(contador));     
            }
            contador--;
            x=BigInteger (*this);
            }

            lista.clear();
            if (signtemp1==signtemp2)
                *this = BigInteger(ans,true);
            else
                *this = BigInteger(ans,false);
        }

    lista2.setSign(signtemp2);
}
/*
Operación estática sumarListaValores
Entrada: Una lista de BigInteger
Salida: un BigInteger
Descripción: Esta función suma todos los elementos que 
se encuentran en la lista y almacena esta suma en un BigInteger.
*/
BigInteger BigInteger::sumarListaValores (list<BigInteger> &listaBI){
    BigInteger ans;
    for (list<BigInteger> :: iterator it=listaBI.begin();it!=listaBI.end();it++){
        ans.add(*it);
    }
    return ans;
}
/*
Operación estática multiplicarListaValores
Entrada: Una lista de BigInteger
Salida: Un BigInteger
Descripción: Esta función multiplica los elementos que hay en el lista y los guarda
en otro BigInteger;
*/
BigInteger BigInteger :: multiplicarListaValores (list<BigInteger> &listaBI){
    BigInteger ans=BigInteger(*listaBI.begin());
    for (list<BigInteger> :: iterator it=listaBI.begin()++;it!=listaBI.end();it++){
        ans.product(*it);
    }
    return ans;
}
/*
Función remainder
Entrada: Un BigInteger
Salida: No aplica
Descripción: Esta función divide los elementos que hay en el BigInteger actual
entre los que se pasan por referencia y almacena el residuo de esa operación en el
BigInteger actual.
*/
void BigInteger::remainder(BigInteger &lista2){
    bool signtemp=lista2.getSign();
    lista2.setSign(true);
    if (*this==lista2){
        lista.clear();
        lista.push_back(0);

    }
    else if (lista2<*this){
        BigInteger x, copia(*this);
        vector<BigInteger> vec;
        vec=lista2.tablaMult();
        int contador=lista.size()-1;
        string s;
        char c;
        for (int i=0;i<lista2.getSize();i++){
            c=lista[contador]+48;
            s.push_back(c);
            contador--;
        }
        x= BigInteger(s);
        if (x<lista2){
            c=lista[contador]+48;
            s.push_back(c);
            contador--;
            x = BigInteger(s);
        }
        while (contador>=-1){
            int j=0;
            while(vec[j]<=x){
                j++;
            }
            j--;
            (*this)=x-(vec[j]);
            if (contador>=0){
                lista.push_front(copia.getIth(contador));
            }
            contador--;
            x=BigInteger (*this);
        }
    }
    lista2.setSign(signtemp);
}
/*
Función pow
Entrada: Un entero
Salida: No aplica
Descripción: Esta función eleva el BigInteger actual a la potencia del
entero del parámetro. Es decir, el BigInteger se multiplica por si mismo tantas
veces como el parámetro.
*/
void BigInteger :: pow(int n){
    bool signotemp=signo;
    signo=true;
    BigInteger x(*this);
    if (n!=0){
        for (int i=1;i<n;i++){
            (*this).product(x);
        }
        if (n%2==1){
            if (!signotemp)
                signo=signotemp;
        }
    }
    else if (n==0){
        lista.clear();
        lista.push_back(1);
    }/*
    else if (n%2==0){
        (*this).product(x);
        x = BigInteger (*this);
        for (int i=1;i<n/2;i++){
            (*this).product(x);
        }
    }
    else {
        BigInteger y(*this);
        (*this).product(x);
        x = BigInteger(*this);
        (*this).product(y);
        for (int i=1;i<n/2;i++){
            (*this).product(x);
        }
        if (!signotemp)
            signo=signotemp;
    }*/
}
/*
Sobrecarga operador +
Entrada: Un BigInteger
Salida: Un BigInteger
Descripción: Tiene la misma función que el add, pero en vez de guardar la suma
en el BigInteger actual, la guarda en otro BigInteger, que es el que retorna.
*/
BigInteger BigInteger::operator+(BigInteger &lista2){
    BigInteger x(*this);
    x.add(lista2);
    return x;
}
/*
Sobrecarga operador *
Entrada: Un BigInteger
Salida: Un BigInteger
Descripción: Tiene la misma función que el product, pero en vez de guardar la multiplicación
en el BigInteger actual, la guarda en otro BigInteger, que es el que retorna.
*/
BigInteger BigInteger::operator*(BigInteger &lista2){
    BigInteger x(*this);
    x.product(lista2);
    return x;
}
/*
Sobrecarga operador /
Entrada: Un BigInteger
Salida: Un BigInteger
Descripción: Tiene la misma función que el quotient, pero en vez de guardar la división
en el BigInteger actual, la guarda en otro BigInteger, que es el que retorna.
*/
BigInteger BigInteger::operator/(BigInteger &lista2){
    BigInteger x(*this);
    x.quotient(lista2);
    return x;
}
/*
Sobrecarga operador %
Entrada: Un BigInteger
Salida: Un BigInteger
Descripción: Tiene la misma función que el remainder, pero en vez de guardar el residuo
en el BigInteger actual, lo guarda en otro BigInteger, que es el que retorna.
*/
BigInteger BigInteger::operator%(BigInteger &lista2){
    BigInteger x(*this);
    x.remainder(lista2);
    return x;
}
/*
Sobrecarga operador -
Entrada: Un BigInteger
Salida: Un BigInteger
Descripción: Tiene la misma función que el substract, pero en vez de guardar la resta
en el BigInteger actual, la guarda en otro BigInteger, que es el que retorna.
*/
BigInteger BigInteger::operator-(BigInteger &lista2){
    BigInteger x(*this);
    x.substract(lista2);
    return x;
}
/*
Función toString
Entrada: No aplica
Salida: Un string
Descripción: Transforma el BigInteger actual en un string, con el signo dependiendo
del booleano del BigInteger y el número dependiendo del deque del BigInteger
*/
string BigInteger::toString(){
    int i=0;
    char n;
    string s;
    if (!signo){
        s.push_back('-');
    }
    for (deque<int>::reverse_iterator it=lista.rbegin();it!=lista.rend();it++){
        n=*it+'0';
        s.push_back(n);
    }
    return s;
}

/*
Sobrecarga operador <
Entrada: Un BigInteger
Salida: Un booleano
Descripción: Compara el BigInteger actual con el que se pasa por referencia, 
retorna true, si el actual es menor que el otro BigInteger y false si no lo es.
*/
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
            int i=lista.size()-1;
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
            ans=lista.size()<lista2.getSize();
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
/*
Sobrecarga operador <=
Entrada: Un BigInteger
Salida: Un booleano
Descripción: Compara el BigInteger actual con el que se pasa por referencia, 
retorna true, si el actual es menor o igual que el otro BigInteger y false si es mayor.
*/
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
            ans=lista.size()<lista2.getSize();
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
/*
Sobrecarga operador ==
Entrada: Un BigInteger
Salida: Un booleano
Descripción: Compara el BigInteger actual con el que se pasa por referencia, 
retorna true, si el actual es exactamente igual que el otro BigInteger y false si no lo es.
*/
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
/*
operación tablaMult
Entrada: No aplica
Salida: Un vector de BigInteger
Descripción: Crea una tabla de multiplicar del BigInteger actual por los
números del 1 al 9. Se usa para la operación quotient.
*/
vector<BigInteger> BigInteger::tablaMult(){
    string s;
    vector<BigInteger> vec;
    for(int i=0;i<=10;i++){
        s=i+48;
        BigInteger bigMult(s);
        BigInteger copia(*this);
        copia.product(bigMult);
        vec.push_back(copia);
    }
    return vec;
}