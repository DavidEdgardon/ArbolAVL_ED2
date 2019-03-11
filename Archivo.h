//
// Created by ASUS on 3/5/2019.
//

#ifndef ARBOLAVL2_0_ARCHIVO_H
#define ARBOLAVL2_0_ARCHIVO_H

#include "Node.h"

struct archivo {
    int izq;
    int valor;
    int der;
};

void Actualizar(Nodo *, char *);
void ActualizarEli(Nodo *, char *,int);
void Ingresar(int, Nodo *, char *);
void ImprimirArchivoAct(char *, int, int);
int  GetPosicion(int, char *);

int izquierda(int, Nodo *);
int derecha(int, Nodo *);


#endif //ARBOLAVL2_0_ARCHIVO_H
