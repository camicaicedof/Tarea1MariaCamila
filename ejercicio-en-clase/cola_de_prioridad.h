#ifndef  COLA_DE_PRIORIDAD
#define COLA_DE_PRIORIDAD


#include "lista.h"

typedef int Elemento;

class Cola{
   Lista l;

   public:
      Cola(); // crearCola
      Elemento front();
      void deque();
      void enqueue(Elemento);
      bool vaciaCola();
};


#endif