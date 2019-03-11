#include "Node.h"
#include "Archivo.h"

#include <iostream>
#define nullptr 0
using namespace std;


int main(){
    Nodo *raiz = NULL;
    int opcion=0,opc=0,dato;
    int nodos=0,nodosEli=0,elegir=0;
    char nombre[50];

    cout<<"Ingrese nombre del Archivo: ";
    cin>>nombre;

            do {
                cout<<endl<< " * * * A R B O L  A V L * * * "<<endl;
                cout << "1. Ingresar Nodo "<<endl;
                cout << "2. Borrar Nodo"<<endl;
                cout << "3. Mostrar Archivo"<<endl;
                cout << "4. Mostrar inOrden"<<endl;
                cout << "5. Mostrar PreOrden"<<endl;
                cout << "6. Mostrar PostOrden"<<endl;
                cout << "-1. Salir"<<endl;

                cout<<"Ingrese una opcion:";
                cin >> opcion;

                if (opcion == 1) {
                    cout << "Ingrese dato: ";
                    cin >> dato;
                    raiz = insertarArbol(raiz, dato);
                    Ingresar(dato, raiz, nombre);
                    Actualizar(raiz, nombre);
                    nodos++;
                }
                if (opcion == 2) {
                    cout << "Dato a Eliminar: ";
                    cin >> dato;
                    if(raiz->dato==dato) {
                        cout << "1.Sucesor"<<endl;
                        cout<< "2.Predecesor"<<endl;
                        cin >> elegir;
                    }
                    deleteNode(raiz, dato,elegir);
                    ActualizarEli(raiz, nombre,dato);
                    //Eliminarenelarchivo(dato, nombre,raiz);
                    nodosEli++;
                }
                if (opcion == 3) {
                    ImprimirArchivoAct(nombre,nodos,nodosEli);
                }
                if (opcion == 4) {
                    cout << "\nInOrden :\n";
                    inOrden(raiz);
                }
                if (opcion == 5) {
                    cout << "\nPreOrden :\n";
                    preOrden(raiz);

                }
                if (opcion == 6) {
                    cout << "\nPosOrden :\n";
                    posOrden(raiz);
                }

            } while (opcion != -1);

            opcion=3;
            opc=opcion;
    system("cls");
}