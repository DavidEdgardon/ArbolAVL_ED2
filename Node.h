//
// Created by ASUS on 3/5/2019.
//

#ifndef ARBOLAVL2_0_NODE_H
#define ARBOLAVL2_0_NODE_H

#include <fstream>
#include <iostream>
using namespace std;

struct Nodo {
    int dato;
    Nodo * der;
    Nodo *izq;
    int altura ;
};


Nodo*crearNodo(int);
Nodo * insertarArbol(Nodo*, int);
void preOrden( Nodo *);
void posOrden(Nodo *);
void inOrden(Nodo *);
int altura( Nodo*);
Nodo* Roatacionder(Nodo *);
Nodo *Rotacionizq(Nodo *);
int FactorEquilibrio( Nodo *N);

int getHeight(Nodo *& );
Nodo* minValueNode(Nodo*);
Nodo* maxValueNode(Nodo*);
Nodo* deleteNode(Nodo*, int, int);



#endif //ARBOLAVL2_0_NODE_H
