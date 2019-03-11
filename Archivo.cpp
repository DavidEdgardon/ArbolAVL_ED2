//
// Created by ASUS on 3/5/2019.
//
#include "Archivo.h"

#include  "Node.h"
#include <fstream>
#include  <iostream>

using namespace std;


void  Ingresar(int dato, Nodo *arbol, char *n) {
    fstream archivoAVL(n, ios::out | ios::app | ios::binary);

    if (!archivoAVL) {
        cerr << "No se puedo abrir el archivo";
        return;
    }

    archivo nuevo;
    nuevo.izq = -1;
    nuevo.valor = dato; // funcion segun el dato tirrar el hijo izq o dercho
    nuevo.der = -1;

    archivoAVL.write(reinterpret_cast <const char *>(&nuevo), sizeof(archivo));
    archivoAVL.close();
}


void Actualizar(Nodo *root, char *n) {
    fstream archivoModef(n, ios::in | ios::out | ios::binary);
    ifstream archivoIn(n, ios::in | ios::binary);

    if (!archivoModef) {
        cerr << " No se puedo abrir el archivo ";
        return;
    }


    archivo actual;
    archivoIn.read(reinterpret_cast <char *>(&actual), sizeof(archivo));
    int pos = GetPosicion(actual.valor, n);
    archivoIn.seekg(1 * sizeof(archivo), ios::beg);

    archivo nuevo;
    archivoModef.seekp(pos * sizeof(archivo), ios::beg);

    while (!archivoIn.eof()) {
        nuevo.izq = GetPosicion(izquierda(actual.valor, root), n);
        nuevo.valor = actual.valor;
        nuevo.der = GetPosicion(derecha(actual.valor, root), n);;

        archivoIn.read(reinterpret_cast<char *>(&actual), sizeof(archivo));
        archivoModef.write(reinterpret_cast <const char *>(&nuevo), sizeof(archivo));
    }
    archivoModef.close();
}

void ActualizarEli(Nodo *root, char *n, int dato) {
    ifstream archivoIn(n, ios::in | ios::binary);
    ofstream archivoModef(n, ios::out | ios::app | ios::binary);

    if (!archivoModef) {
        cerr << "No se puedo abrir el archivo ";
        return;
    }

    archivo actual;
    archivoIn.read(reinterpret_cast <char *>(&actual), sizeof(archivo));
    int pos = GetPosicion(actual.valor, n);
    archivoIn.seekg(1 * sizeof(archivo), ios::beg);

    archivo nuevo;
    archivoModef.seekp(pos * sizeof(archivo), ios::beg);

    while (!archivoIn.eof()) {

        nuevo.izq = GetPosicion(izquierda(actual.valor, root), n);
        nuevo.valor = actual.valor;
        nuevo.der = GetPosicion(derecha(actual.valor, root), n);;

        if (actual.izq==GetPosicion(dato, n)) {
            nuevo.izq = -1;
            nuevo.valor = actual.valor;
            nuevo.der = actual.der;
        } else if (actual.der == GetPosicion(dato, n)) {
            nuevo.izq = actual.izq;
            nuevo.der = -1;
            nuevo.valor = actual.valor;
        } else if (actual.valor==dato) {
            nuevo.izq = -1;
            nuevo.der = -1;
            nuevo.valor = -1;
        }

        archivoIn.read(reinterpret_cast<char *>(&actual), sizeof(archivo));
        archivoModef.write(reinterpret_cast <const char *>(&nuevo), sizeof(archivo));
    }
    archivoModef.close();
}

int derecha(int dato, Nodo *arbol) {
    if (arbol == NULL)
        return -1;

    if (dato == arbol->dato) {
        return (arbol->der == nullptr) ? -1 : arbol->der->dato;
    } else if (dato > arbol->dato) {
        return derecha(dato, arbol->der);
    } else {
        return derecha(dato, arbol->izq);
    }
}

int izquierda(int dato, Nodo *arbol) {
    if (arbol == NULL)
        return -1;

    if (dato == arbol->dato) {
        return (arbol->izq == nullptr) ? -1 : arbol->izq->dato;
     } else if (dato < arbol->dato) {
        return izquierda(dato, arbol->izq);
    } else {
        return izquierda(dato, arbol->der);
    }
}

int GetPosicion(int codigo, char *n) {
    ifstream archivoPos(n, ios::in | ios::binary);

    if (!archivoPos) {
        cerr << " No se puedo abrir el archivo";
        return -1;
    }
    archivo nuevo;
    archivoPos.seekg(0, ios::beg);
    archivoPos.read(reinterpret_cast <char *>(&nuevo), sizeof(archivo)); //la cantidad que voy a leer
    int posicion = 0;

    while (!archivoPos.eof()) {
        if (nuevo.valor == codigo){
            archivoPos.close();
            return posicion;
        }
        posicion++;
        archivoPos.read(reinterpret_cast <char *>(&nuevo), sizeof(archivo)); //la cantidad que voy a leer
    }

    archivoPos.close();
    return -1;
}


void ImprimirArchivoAct(char *n, int nodos, int nodosEli) {
    ifstream archivoIn(n, ios::in | ios::binary);
    if (!archivoIn) {
        cerr << " No se puedo abrir el archivo";
        return;
    }
    if(nodosEli==0) {
        archivoIn.seekg(0, ios::beg);
    }else if(nodosEli==1) {
        archivoIn.seekg(sizeof(archivo) * nodos, ios::beg);
    }else if(nodosEli==2) {
        nodosEli = nodosEli + 1;
        archivoIn.seekg(sizeof(archivo) * nodos * nodosEli, ios::beg);
    }else if(nodosEli==3) {
        nodosEli = nodosEli + 4;
        archivoIn.seekg(sizeof(archivo) * nodos * nodosEli, ios::beg);
    }

    cout << "* * * A r c h i v o  B i n a r i o * * *"<<endl;
    archivo actual;

    archivoIn.read(reinterpret_cast <char *>(&actual), sizeof(archivo));
    while (!archivoIn.eof())  {
        if(actual.valor != -1) {
            cout  << " |Izquierda: " << actual.izq << "|Valor: " << actual.valor << "|Derecha: " << actual.der << "| " << endl;
        }
            archivoIn.read(reinterpret_cast<char *>(&actual), sizeof(archivo));
    }

    archivoIn.close();
}
