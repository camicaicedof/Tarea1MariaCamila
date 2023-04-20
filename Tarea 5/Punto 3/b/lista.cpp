#include "lista.h"

/*La complejidad de la función insListaOrdenada es de O(1) en el mejor caso
y O(n) en el peor caso. El mejor caso es cuando no hay ningún elemento en la 
lista por lo que solo se debe establecer act como el elemento. En el peor caso
se debe recorrer toda la lista ya que el elemento que se desea ingresar es mayor
que todos los elementos que estaban antes ahí*/


Lista::Lista(){
  act = NULL;
}

void Lista::insListaOrdenada(Elemento elem){
  Nodo *nuevo, *tmp, *ant;
  nuevo=new Nodo;
  nuevo->dato=elem;
  nuevo->sig=NULL;
  if (act == NULL){
    act=nuevo;
  }
  else {
    if (elem< act->dato){
      nuevo->sig=act;
      act=nuevo;
    }
    else{
      tmp=act;
      while(tmp!= NULL and tmp->dato< elem){
        ant=tmp;
        tmp=tmp->sig;
      }
      ant->sig=nuevo;
      nuevo->sig=tmp;
    }
  }

}


void Lista::elimLista(int pos){
  Nodo *tmp, *elim;
  if(pos >= 1 && pos <= longLista()){
    if(pos == 1)
      act = act->sig;
    else{
      tmp = act;
      for(int i = 0; i < pos-2; i++)
	tmp = tmp->sig;
      elim = tmp->sig;
      tmp->sig = tmp->sig->sig;
      delete elim;
    }
  }
}

Elemento Lista::infoLista(int pos){
  Nodo* tmp = act;

  for(int i = 1; i < pos; i++)
    tmp = tmp->sig;

  return tmp->dato;
}

int Lista::longLista(){
  Nodo* tmp = act;
  int cont = 0;

  while(tmp != NULL){
    tmp = tmp->sig;
    cont++;
  }

  return cont;
}

bool Lista::vaciaLista(){
  return act == NULL;
}
