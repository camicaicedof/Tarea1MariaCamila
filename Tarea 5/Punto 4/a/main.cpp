#include "lista.h"
#include <iostream>

/*Complejidad*/
/*la complejidad de este algoritmo es de (n^2*m), donde n es la cantidad de
elementos de la lista2 y m la cantidad de elementos de lista1, ya que el ciclo
recorre toda la lista 2 y además tiene que recorrer de nuevo la lista para hallar
el dato que se necesita, y además se recorre la lista1 para añadir el elemento en la
posición final.*/

void concatenarLista(Lista &l1,Lista &l2){
  int i, longitud=l2.longLista();
  for (i=1;i<=longitud;i++){
    l1.anxLista(l2.infoLista(i));
  }
}
int main(){
    Lista l1;
    Lista l2;
    int i;
    l1.anxLista(5);
    l1.anxLista(10);
    l1.anxLista(12);
    l1.anxLista(15);

    l2.anxLista(1);
    l2.anxLista(4);

    concatenarLista(l1,l2);
    for (i=1;i<=l1.longLista();i++){
      cout<<l1.infoLista(i)<<" ";
    }
    cout<<endl;
    return 0;
}