//
// Created by ASUS on 3/5/2019.
//

#include "Node.h"
#include "Archivo.h"
#include<stdio.h>
#include<stdlib.h>
#include <algorithm>
#include <iostream>
#define nullptr 0

using namespace std;


Nodo *crearNodo(int n) {
    Nodo* newnodo = new Nodo();

    newnodo->dato = n;
    newnodo->der = nullptr;
    newnodo->izq = nullptr;
    newnodo->altura = 0;

    return newnodo;
}

Nodo * insertarArbol( Nodo *arbol, int n) {
    if (arbol == NULL)
        return(crearNodo(n));

    if (n < arbol->dato)
        arbol->izq = insertarArbol(arbol->izq, n);
    else if (n > arbol->dato)
        arbol->der = insertarArbol(arbol->der, n);
    else
        return arbol;
    arbol->altura = max(getHeight(arbol->izq), getHeight(arbol->der));

    int balance = FactorEquilibrio(arbol);
    //  desbalanceo en parte izquierda // rotacion derecha
    if (balance < -1 && n < arbol->izq->dato) {
        cout << "Rotacion Simple Derecha" << endl;
        return Roatacionder(arbol);
    }
    // Desbalanceo en la parte derecha Rotacion izquierda
    if (balance > 1 && n > arbol->der->dato) {
        cout << "Rotacion Simple Izquierda" << endl;
        return Rotacionizq(arbol);
    }
    //  Rotacion Izquierdda Derecha
    if (balance < -1 && n > arbol->izq->dato) {
        cout<<"Rotacion Doble Izquierda-Derecha"<<endl;
        arbol->izq = Rotacionizq(arbol->izq);
        return Roatacionder(arbol);
    }

    // Rotacion Derecha Izquierda R
    if (balance > 1 && n < arbol->der->dato)
    {cout<<"Rotacion Doble Derecha-Izquierda"<<endl;
        arbol->der = Roatacionder(arbol->der);
        return Rotacionizq(arbol);
    }
    return arbol;
}

int getHeight(Nodo *& tmp){
    if (tmp == 0)
        return 0;
    else
        return 1 + max(getHeight(tmp->izq), getHeight(tmp->der));
}

Nodo* Roatacionder( Nodo *raiz) {
    Nodo *tmp = raiz->izq;
    Nodo *arbol = tmp->der;

    tmp->der = raiz;
    raiz->izq = arbol;

    raiz->altura = getHeight(raiz);
    tmp->altura = getHeight(tmp);

    return tmp;
}

Nodo * Rotacionizq(  Nodo * raiz) {
    Nodo *tmp = raiz->der;
    Nodo *arbol = tmp->izq;

    tmp->izq = raiz;
    raiz->der = arbol;

    raiz->altura = getHeight(raiz);
    tmp->altura = getHeight(tmp);

    return tmp;
}


int FactorEquilibrio( Nodo *N) {
    if (N == NULL)
        return 0;
    return getHeight(N->der) - getHeight(N->izq);
}


Nodo * minValueNode( Nodo* node) {
    Nodo* current = node;
    while (current->izq != NULL)
        current = current->izq;

    return current;
}

Nodo * maxValueNode( Nodo* node) {
    Nodo* current = node;
    while (current->der != NULL)
        current = current->der;

    return current;
}


Nodo* deleteNode(Nodo* raiz, int valor, int elegir) {
    if (raiz == NULL)
        return raiz;
    if (valor < raiz->dato)
        raiz->izq = deleteNode(raiz->izq, valor,elegir);
    else if (valor > raiz->dato)
        raiz->der = deleteNode(raiz->der, valor,elegir);
    else {
        if ((raiz->izq == NULL) || (raiz->der == NULL)) {
            Nodo *temp = raiz->izq ? raiz->izq : raiz->der;
            if (temp == NULL) {
                temp = raiz;
                raiz = NULL;
            } else
                *raiz = *temp;
            free(temp);
        } else if(elegir==1) {
            Nodo* temp = minValueNode(raiz->der);
            raiz->dato = temp->dato;
            raiz->der = deleteNode(raiz->der, temp->dato,elegir);
        } else if(elegir==2) {
            Nodo* temp = maxValueNode(raiz->izq);
            raiz->dato = temp->dato;
            raiz->izq = deleteNode(raiz->izq, temp->dato,elegir);
        }
    }

    if (raiz == NULL)
        return raiz;

    raiz->altura = max(getHeight(raiz->izq), getHeight(raiz->der));
    int balance = FactorEquilibrio(raiz);

    if (balance < -1 && valor < raiz->izq->dato) {
        return Roatacionder(raiz);
    }
    if (balance > 1 && valor > raiz->der->dato) {
        return Rotacionizq(raiz);
    }
    if (balance < -1 && valor > raiz->izq->dato) {
        raiz->izq = Rotacionizq(raiz->izq);
        return Roatacionder(raiz);
    }
    if (balance > 1 && valor < raiz->der->dato) {
        raiz->der = Roatacionder(raiz->der);
        return Rotacionizq(raiz);
    }
    return raiz;
}



void preOrden( Nodo *root)
{
    if(root == NULL)
        return;
    cout << root->dato << endl;
    if(root->izq != NULL)
        preOrden(root->izq);
    if(root->der != NULL)
        preOrden(root->der);

}

void inOrden(Nodo* root)
{
    if(root == NULL)
        return;
    if(root->izq != NULL)
        inOrden(root->izq);
    cout << root->dato << endl;
    if(root->der != NULL)
        inOrden(root->der);

}

void posOrden( Nodo* root)
{
    if(root == NULL)
        return;
    if(root->izq != NULL)
        posOrden(root->izq);
    if(root->der != NULL)
        posOrden(root->der);
    cout << root->dato << endl;

}