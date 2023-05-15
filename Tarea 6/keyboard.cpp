/*La complejidad de este algoritmo es O(n), pues se recorre la cadena una sola vez y las operaciones
insert, conociendo el iterador y llevar el iterador al principio o al final de la lista son todas 
constantes, entonces la mayor complejidad es de O(n).*/
#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

void beiju(string s){
    int i;
    list<char> lista;
    list<char>::iterator it = lista.end();
    for (i=0;i<s.size();i++){
        if (s[i]=='['){
            it=lista.begin();
        }
        else if(s[i]==']'){
            it=lista.end();
        }
        else if (s[i]!='[' && s[i]!=']'){
            lista.insert(it,s[i]);
        }


    }
    for (it=lista.begin();it!=lista.end();it++){
        cout<<*it;
    } 
    cout<<endl;
}

int main(){
    string s;
    while (cin>>s){
        beiju(s);
    }
    return 0;
}