#include "cola_de_prioridad.h"
/*Complejidad*/
/*En este caso solo se modifica la complejidad de enqueue, al llamar la función insListaOrdenada.
Pues al contrario de anxLista, esta función ordena los datos de menor a mayor. En el peor caso,
esta operación tendría complejidad de O(n), que ocurre cuando se debe insertar el elemento en
una posición que no es ni la primera, ni la última. En el mejor caso, sería O(1), que ocurre
cuando se inserta el elemento es menor o mayor que todos. Como la cola ya estaba ordenada, la
complejidad de el resto de operaciones como front, deque y vacía cola, se realizan en un tiempo
constante, es decir que su complejidad es de O(1).*/

Cola::Cola(){
}

Elemento Cola::front(){
   Elemento ans = l.infoLista(1);
   return ans;
}

void Cola::enqueue(Elemento e){
   l.insListaOrdenada(e);
}

void Cola::deque(){
   l.elimLista(1);
}

bool Cola::vaciaCola(){
  bool ans;
  if(l.vaciaLista())
     ans = true;
  else
     ans = false;
  return ans;
}
