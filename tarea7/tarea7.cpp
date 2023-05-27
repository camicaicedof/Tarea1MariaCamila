
/*María Camila Caicedo Florez
Código: 8977474*/


#include <iostream>
#include <algorithm>
#include <stack>
#include <list>
#include <queue>
#include <deque>
#include <vector>
#include<map>
using namespace std;

/*la complejidad de esta operación es O(n) donde n es la cantidad de elementos
de la cola*/
void eliminarPosicionesPila(stack<int> &pil,list<int> &l){
    deque<int> dq;
    while (!pil.empty()){
        dq.push_back(pil.top());
        pil.pop();
    }
    list<int>::iterator it=l.begin();
    for (it=l.begin();it!=l.end();it++){
        dq[*it]=0;
    }
    for (int i=dq.size();i>=0;i--){
        if (dq[i]!=0){
            pil.push(dq[i]);
        }
    }
}
/*la complejidad de esta operación es de O(nlogn) donde n es la cantidad 
de elementos que hay en el vector. Ya que el make_heap tiene una complejidad
de O(logn) y está dentro de un ciclo que recorre todas las posiciones del vector*/
void ordenarConMonticulo(vector<int> &vec){
    list<int> prov;
    int l=vec.size();

    for (int i=0;l;i++){
        make_heap(vec.begin(),vec.end());
        prov.push_back(vec.front());
        pop_heap(vec.begin(), vec.end());  
        vec.pop_back();  
    }
    for (list<int> :: iterator it=prov.begin();it!=prov.end();it++){
        vec.push_back(*it);
    }
}

/*Esta operación tiene una complejidad de O(n) donde n es la cantidad de elementos
de la cola, para verificar que todo esté en orden hay que recorrerla toda.*/
bool verificarOrdenadoCola(queue<int> cola){
    bool ans=true;
    int tmp=cola.front();
    cola.pop();
    if (tmp<=cola.front()){
        tmp=cola.front();
        cola.pop();
        while (!cola.empty() && ans){
            if (tmp>cola.front()){
                ans = false;
            }
            tmp=cola.front();
            cola.pop();
        }
    }
    else if (tmp >=cola.front()){
        tmp=cola.front();
        cola.pop();
        while (!cola.empty() && ans){
            if (tmp<cola.front()){
                ans = false;
            }
            tmp=cola.front();
            cola.pop();
        }
    }
    return ans;
}
/*La complejidad de este algoritmo es de O(nlogn) donde n es la cantidad de 
elementos en la lista, y añadirlos a la cola de prioridad y organizarlos es logn
por lo que se genera esa complejidad*/
int obtenerMenorCosto (list<int> &l){
    priority_queue <int,vector<int> ,greater<int>> q;
    for(list<int>::iterator it=l.begin();it!=l.end();it++){
        q.push(*it);
    }
    int ans,tmpSum,tmp;
    
    for (int i=0;i<l.size();i++){
        
        if (i==0){
            tmp=q.top();
            q.pop();
            tmpSum=tmp+q.top();
            q.pop();
        }
        else{
            tmpSum+=q.top();
            q.pop();}

    }
    return tmpSum;
} 
/*La complejidad de este algoritmo es O(nlogn) ya que se recorre toda la cadena
y añadir cada elemento del mapa tiene una complejidad O(logn)*/
map <char,list<int>> obtenerPosicionesOcurrencias (string cad){
    map <char,list<int>> mapa;
    for (int i=0;i<cad.size();i++)
        mapa[cad[i]].push_back(i);
    return mapa;
}
int main(){
    return 0;
}
