/*La complejidad de este algoritmo es de O(n*log2n), cuando n es la cantidad de pacientes si la 
cantidad de pacientes es menor o igual a 1000, si la cantidad de pacientes es mayor, entonces
n es la cantidad de casos, y como buscar un elemento en un mapa es O(log2n) entonces, al recorrer
la lista y buscar un elemento por cada vez que se recorre queda en una complejidad total de O(nlog2n)*/

#include <iostream>
#include <list>
#include <map>
#include <algorithm>
using namespace std;


void queue(int pacientes, int casos){
    char c;
    int i, n,j;
    map<int,int> mapa;
    list <int> cola,cola0;

    if (pacientes<=1000){
        for (i=0;i<pacientes;i++){
            cola.push_back(i+1);
            cola0.push_back(0);
        }
    }
    else {
        for (i=0;i<1000;i++){
            cola.push_back(i+1);
            cola0.push_back(0);
        } 
    }
    
    for (i=0;i<1000;i++){
        mapa[i+1]=0;
    }

    list<int>::iterator it=cola.begin(), it2=cola0.begin();
    for (j=0;j<casos;j++){
        cin>>c;
        if (c=='N'){
            if ((*it2)!=mapa[*it]){
                while ((*it2)!=mapa[*it]){
                    //cout<<"entra";
                    //ncout<<*it<<*it++<<"2 "<<mapa[*it]<<"m ";
                    cola.pop_front();
                    cola0.pop_front();
                    it=cola.begin();
                    it2=cola0.begin();
                }
            }

            cout<<*it<<endl;
            cola.push_back(*it);
            cola0.push_back(*it2);
            //cout<<*it<<*it2;
            cola.erase(it);
            cola0.erase(it2);
            it=cola.begin();
            it2=cola0.begin();
        }
        else if (c=='E'){
            cin>>n;
                mapa.insert(pair<int,int>(n,0));
                mapa[n]+=1;
                cola0.push_front(mapa[n]);
                cola.push_front(n);
                it=cola.begin();
                it2=cola0.begin();
        }
    }

    
}
int main(){
    int pacientes, casos, contador=1;
    string prioridad;
    cin>>pacientes;
    cin>>casos;
    while (pacientes!=0 && casos!=0){
        cout<<"Case "<<contador<<":"<<endl;
        contador++;
        queue(pacientes,casos);
        cin>>pacientes;
        cin>>casos;
    }
    
    
    return 0;
}