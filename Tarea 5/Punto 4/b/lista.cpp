#include "lista.h"

/*Complejidad*/
/*La complejidad de la sobrecarga del operador + es de O(n^2*m) donde
n es la longitud de la lista que se pasa por referencia, y p la lista que se retorna.
Esto ocurre debido a que al momento de recorrer la segunda lista para añadir
los datos a la tercera se llama a la función infolista, que tiene una complejidad lineal,
esto a su vez está anidado en un ciclo, lo que hace que se obtenga una complejidad O(n^2),
sin embargo, como también se debe recorrer toda la lista 3 para poder anexarle al
final ese elemento, la longitud de la lista 3, es decir p, se multiplica por la
complejidad anterior y lo que se obtiene es la complejidad mencionada al principio.*/

Lista::Lista(){
  act = NULL;
}

void Lista::anxLista(Elemento elem){
  Nodo* tmp;
  Nodo* nuevo = new Nodo;
  nuevo->dato = elem;
  nuevo->sig = NULL;

  if(act == NULL)
    act = nuevo;
  else{
    tmp = act;
    while(tmp->sig != NULL)
      tmp = tmp->sig;
      tmp->sig = nuevo;
  }
}

Lista Lista::operator+(Lista &l){
  Lista l3;
  Nodo* tmp=act;
  while (tmp!=NULL){
    l3.anxLista(tmp->dato);
    tmp=tmp->sig;
  }
  int longitud=l.longLista();
  for (int i=1;i<=longitud;i++){
    l3.anxLista(l.infoLista(i));
  }
  return l3;
    
}

void Lista::insLista(Elemento elem, int pos){
  Nodo *nuevo, *tmp;
  nuevo = new Nodo;
  nuevo->dato = elem;
  nuevo->sig = NULL;

  if(pos >= 1 && pos <= longLista()){
    if(pos == 1){
      nuevo->sig = act;
      act = nuevo;
    }
    else{
      tmp = act;
      for(int i = 0; i < pos - 2; i++)
	tmp = tmp->sig;
      nuevo->sig = tmp->sig;
      tmp->sig = nuevo;
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
