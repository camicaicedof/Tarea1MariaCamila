#include "lista.h"
#include <iostream>

int main(){
  Lista l;
  int i;
  l.insListaOrdenada(4);
  l.insListaOrdenada(2);
  l.insListaOrdenada(-1);
  l.insListaOrdenada(1);
  l.insListaOrdenada(12);
  l.insListaOrdenada(5);
  l.insListaOrdenada(30);
  l.insListaOrdenada(6);
  for (i=1;i<=l.longLista();i++){
    cout<<l.infoLista(i)<<" ";
  }
  return 0;
}