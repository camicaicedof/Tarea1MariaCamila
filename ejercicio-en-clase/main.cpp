/*María Camila Caicedo y Federico Terán*/

#include <iostream>
#include "cola_de_prioridad.h"
using namespace std;

int main(){
    Cola cola;
    cola.enqueue(3);
    cola.enqueue(2);
    cola.enqueue(4);
    cola.enqueue(5);
    cola.enqueue(1);
    while (!cola.vaciaCola()){
        cout<<cola.front()<<" ";
        cola.deque();
    }
    return 0;
}