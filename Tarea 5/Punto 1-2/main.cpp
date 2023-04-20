#include "lista.h"
#include <iostream>

/*Complejidad*/
/*La función contarOcurrencias tiene una complejidad O(n^2) ya que, el ciclo
recorre la lista n veces, siendo n la cantidad de elementos que hay en la lista
y adentro del ciclo, hay una comparación del entero con un elemento de la lista.
Como la función infoLista() también tiene una complejidad de O(n), al estar anidada
en el ciclo se repetiría n veces, lo que nos lleva a tener la complejidad inicial

De la misma manera, la función obtenerMenores tiene una complejidad de O(n^2) ya que,
contiene un ciclo que itera hasta la longitud de la lista y adentro de este tiene
la función infoLista() que también tiene una complejidad de O(n), por lo que, al estar
anidada, tendría la complejidad mencionada anteriormente*/


int contarOcurrencias (Lista &l, int v){
    int contador=0,i, longitud=l.longLista();
    for (i=1;i<=longitud;i++){
        if(v==l.infoLista(i)){
            contador++;
        }
    }
    return contador;
}

Lista obtenerMenores (Lista &l, int v){
  Lista retorno;
  int longitud=l.longLista(),i;
  for(i=1;i<=longitud;i++){
    int elem =l.infoLista(i);
    if (v>elem){
      retorno.anxLista(elem);
    }
  }
  return retorno;
}
int main(){
    Lista l;
    Lista x;
    int i;
    l.anxLista(5);
    l.anxLista(10);
    l.anxLista(12);
    l.anxLista(15);

    cout << contarOcurrencias(l,5) << endl;
    x=obtenerMenores(l,20);
    for (i=1;i<=x.longLista();i++){
      cout<<l.infoLista(i)<<" ";
    }
    cout<<endl;
    return 0;
}