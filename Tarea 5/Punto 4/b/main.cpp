#include "lista.h"
#include <iostream>

int main(){
    Lista l1;
    Lista l2;
    Lista l3;
    int i;
    l1.anxLista(5);
    l1.anxLista(10);
    l1.anxLista(12);
    l1.anxLista(15);

    l2.anxLista(1);
    l2.anxLista(4);

    l3=l1+l2;
    
    for (i=1;i<=l3.longLista();i++){
      cout<<l3.infoLista(i)<<" ";
    }
    cout<<endl;
    return 0;
}