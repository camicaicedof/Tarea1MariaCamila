#include "lista.h"
#include <iostream>
/*Complejidad*/
/*La función insertarEnListaOrdena() tiene una complejidad, en su peor caso,
de O(n^2) y en su mejor caso O(1). El peor caso ocurre cuando v es mayor
que todos los elementos en la lista, por lo que se llama la función infoLista 
n veces, que a su vez tiene una complejidad de O(n), por esta razón, al anidarse
se obtiene una complejidad de O(n^2). En el mejor caso, el elemento a insertar es
menor que todos los demás elementos por lo que el ciclo while solo itera una vez, 
al igual que infolista, como estamos buscando el primer elemento entonces no itera
en el for sino que solo retorna el dato de la cabeza, y al insertarlo en la lista
ocurre lo mismo, por lo que su complejidad sería constante.*/


void insertarEnListaOrdenada(Lista &l, int v){
  int i=1, longitud=l.longLista();
  bool flag=true;
  while (i<=longitud and flag==true){
    if (v<=l.infoLista(i)){
      l.insLista(v,i);
      flag=false;
    }
    else if (i==longitud){
      l.anxLista(v);
    }
    i++;
  }
}

int main(){
  int i;
  Lista l;
  l.anxLista(1);
  l.anxLista(2);
  insertarEnListaOrdenada(l,5);
  insertarEnListaOrdenada(l,4);
  for (i=1;i<=l.longLista();i++){
    cout<<l.infoLista(i)<<" ";
  }
  cout<<endl;
  return 0;
}