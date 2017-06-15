#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define reservar_memoria (Nodo *)malloc(sizeof(Nodo))
#define reservar_memoria_arbol (NodoArboles *)malloc(sizeof(NodoArboles))

struct NodoArboles {
    int dato;
    NodoArboles *derecho;
    NodoArboles *izquierdo;
};

NodoArboles *Arbol = NULL;

struct Nodo{
    int dato;
    Nodo *siguiente;
};

Nodo *primero = NULL;
Nodo *ultimo = NULL;

void menu_principal();
void menu_colas();
void menu_pilas();
void menu_listas();
void menu_arboles();
void generar_numeros(Nodo *&,Nodo *&);
void insertar_elementos(Nodo *&,Nodo *&,int);
void imprimir(Nodo *);
void burbuja(Nodo *);
void imprimir_arbol(NodoArboles *, int);
void insertar_arbol(NodoArboles *&,int);
void insertar_pila(Nodo *&,int);
void inOrden(NodoArboles *);
void insercion(Nodo *);

int cont=0;

int main(){
    menu_principal();
    return 0;
}
void menu_principal(){
    int opc;
    do{
        printf("\n*****\tMenu Principal\t*****\n");
        printf("\n1.Funciones Colas");
        printf("\n2.Funciones Pilas");
        printf("\n3.Funciones Listas");
        printf("\n4.Funciones Arboles");
        printf("\n0.Salir\n");
        printf("\nIngrese una opcion: ");
        scanf("%d",&opc);
        switch(opc){
            case 0:
                exit(0);
            break;
            case 1:
                menu_colas();
            break;
            case 2:
                menu_pilas();
            break;
            case 3:
                menu_listas();
            break;
            case 4:
                menu_arboles();
            break;
            default:
                printf("\nOpcion invalida\n");
            break;
        }
        system("pause");
        system("cls");
        menu_principal();
    }while(opc!=0);
}
void menu_colas(){
    clock_t comienzo,final;
    int opc;
    do{
        printf("\n*****\tMenu Colas\t*****\n");
        printf("\n1. Insertar datos de archivo");
        printf("\n2. Metodo de ordenamiento burbuja");
        printf("\n3. Metodo de ordenamiento insercion");
        printf("\n4. Imprimir cola");
        printf("\n0. Menu principal\n");
        printf("\nIngrese una opcion: ");
        scanf("%d",&opc);
        switch(opc){
            case 0:
                menu_principal();
            break;
            case 1:
                comienzo = clock();
                generar_numeros(primero,ultimo);
                final = clock();
                printf("\nTiempo total: %.2f segundos\n",1000.00*(final-comienzo)/CLOCKS_PER_SEC);
            break;
            case 2:
                comienzo = clock();
                burbuja(primero);
                final = clock();
                printf("\nTiempo total: %.2f segundos\n",1000.00*(final-comienzo)/CLOCKS_PER_SEC);
            break;
            case 3:
                comienzo = clock();
                insercion(primero);
                final = clock();
                printf("\nTiempo total: %.2f segundos\n",1000.00*(final-comienzo)/CLOCKS_PER_SEC);
            break;
            case 4:
                imprimir(primero);
            break;
            default:
                printf("\nOpcion invalida\n");
            break;
        }
        system("pause");
        system("cls");
    }while(opc!=0);
}
void menu_pilas(){
    clock_t comienzo,final;
    int opc;
    int num, nDatos, cant, i = 0;
    do{
        printf("\n*****\tMenu Pilas\t*****\n");
        printf("\n1. Insertar datos de archivo");
        printf("\n2. Metodo de ordenamiento burbuja");
        printf("\n3. Metodo de ordenamiento insercion");
        printf("\n4. Imprimir pila");
        printf("\n0. Menu principal\n");
        printf("\nIngrese una opcion: ");
        scanf("%d",&opc);
        switch(opc){
            case 0:
                menu_principal();
            break;
            case 1:
                comienzo = clock();
                FILE *archivo;
                archivo = fopen("archivo_numeros.txt", "w");
                printf("Ingrese cantidad de numeros que desea generar\n");
                printf("\n1.Un millon\n2.Dos millones\n3.Cinco millones\n4.Diez millones\n5.Veinte millones\n");
                printf("Datos: ");
                scanf("%d", &cant);
                if(cant == 1){
                    nDatos=1000000;
                }else if(cant == 2){
                    nDatos=2000000;
                }else if (cant == 3){
                    nDatos=5000000;
                }else if(cant == 4){
                    nDatos=10000000;
                }else if(cant == 5){
                    nDatos=20000000;
                }
                srand(time(NULL));
                while(i < nDatos){
                    num = (rand () % (1999998 + 1));
                    fprintf(archivo, "%d\n", num);
                    insertar_pila(primero, num);
                    i += 1;
                }
                final = clock();
                printf("\nTiempo total: %.2f segundos\n",1000.00*(final-comienzo)/CLOCKS_PER_SEC);

            break;
            case 2:
                comienzo = clock();
                burbuja(primero);
                final = clock();
                printf("\nTiempo total: %.2f segundos\n",1000.00*(final-comienzo)/CLOCKS_PER_SEC);
            break;
            case 3:
                comienzo = clock();
                insercion(primero);
                final = clock();
                printf("\nTiempo total: %.2f segundos\n",1000.00*(final-comienzo)/CLOCKS_PER_SEC);
            break;
            case 4:
                imprimir(primero);
            break;
            default:
                printf("\nOpcion invalida\n");
            break;
        }
        system("pause");
        system("cls");
    }while(opc!=0);
}
void menu_listas(){
    clock_t comienzo,final;
    int opc;
    do{
        printf("\n*****\tMenu Lista\t*****\n");
        printf("\n1. Insertar datos de archivo");
        printf("\n2. Metodo de ordenamiento burbuja");
        printf("\n3. Imprimir lista");
        printf("\n0. Menu principal\n");
        printf("\nIngrese una opcion: ");
        scanf("%d",&opc);
        switch(opc){
            case 0:
                menu_principal();
            break;
            case 1:
                comienzo = clock();
                generar_numeros(primero,ultimo);
                final = clock();
                printf("\nTiempo total: %.2f segundos\n",1000.00*(final-comienzo)/CLOCKS_PER_SEC);
            break;
            case 2:
                comienzo = clock();
                burbuja(primero);
                final = clock();
                printf("\nTiempo total: %.2f segundos\n",1000.00*(final-comienzo)/CLOCKS_PER_SEC);
            break;
            case 3:
                comienzo = clock();
                insercion(primero);
                final = clock();
                printf("\nTiempo total: %.2f segundos\n",1000.00*(final-comienzo)/CLOCKS_PER_SEC);
            break;
            case 4:
                imprimir(primero);
            break;
            default:
                printf("\nOpcion invalida\n");
            break;
        }
        system("pause");
        system("cls");
    }while(opc!=0);
}
void menu_arboles(){
    clock_t comienzo,final;
    int opc, cont=0, nDatos, cant, n;
    do{
        printf("\n*****\tMenu Arboles\t*****\n");
        printf("\n1. Insertar datos de archivo");
        printf("\n2. Ordenar");
        printf("\n3. Imprimir arbol");
        printf("\n0. Menu principal\n");
        printf("\nIngrese una opcion: ");
        scanf("%d",&opc);
        switch(opc){
            case 0:
                menu_principal();
            break;
            case 1:
                FILE *archivo;
                archivo = fopen("archivo_numeros.txt", "w");
                printf("Ingrese cantidad de numeros que desea generar\n");
                printf("\n1.Un millon\n2.Dos millones\n3.Cinco millones\n4.Diez millones\n5.Veinte millones\n");
                printf("Datos: ");
                scanf("%d", &cant);
                if(cant == 1){
                    nDatos=1000000;
                }else if(cant == 2){
                    nDatos=2000000;
                }else if (cant == 3){
                    nDatos=5000000;
                }else if(cant == 4){
                    nDatos=10000000;
                }else if(cant == 5){
                    nDatos=20000000;
                }
                for(int i=0;i<nDatos;i++){
                    n=(rand () % (1999998 + 1));
                    fprintf(archivo, "%d\n", n);
                    insertar_arbol(Arbol,n);
                }
            break;
            case 2:
                inOrden(Arbol);
            break;
            case 3:
                printf("\nImprimiento arbol\n\n");
                imprimir_arbol(Arbol, cont);
            break;
            default:
                printf("\nOpcion invalida\n");
            break;
        }
        system("pause");
        system("cls");
    }while(opc!=0);
}
void generar_numeros(Nodo *&primero,Nodo *&ultimo){
    FILE *archivo;
	archivo = fopen("archivo_numeros.txt", "w");
	int num, nDatos, cant, i = 0;
	printf("Ingrese cantidad de numeros que desea generar\n");
	printf("\n1.Un millon\n2.Dos millones\n3.Cinco millones\n4.Diez millones\n5.Veinte millones\n");
	printf("Datos: ");
	scanf("%d", &cant);
	if(cant == 1){
        nDatos=1000000;
	}else if(cant == 2){
	    nDatos=2000000;
	}else if (cant == 3){
        nDatos=5000000;
	}else if(cant == 4){
        nDatos=10000000;
	}else if(cant == 5){
        nDatos=20000000;
	}
	srand(time(NULL));
	while(i < nDatos){
		num = (rand () % (1999998 + 1));
		fprintf(archivo, "%d\n", num);
		insertar_elementos(primero, ultimo, num);
		i += 1;
	}
}
void insertar_elementos(Nodo *&primero,Nodo *&ultimo, int n){
    Nodo *nuevo = reservar_memoria;
	nuevo -> dato = n;
	nuevo -> siguiente = NULL;
	if(primero == NULL){
		primero = nuevo;
	}else{
		ultimo -> siguiente = nuevo;
	}
	ultimo = nuevo;
}
void imprimir(Nodo * primero){
    if(primero != NULL){
		Nodo *actual = reservar_memoria;
		actual = primero;
		while(actual != NULL){
			printf("%d \n", actual -> dato);
			actual = actual -> siguiente;
		}
	}else{
		printf("\nVacio\n");
	}
}
void burbuja(Nodo * primero){
    if(primero != NULL){
		Nodo *p = reservar_memoria;
		Nodo *j = reservar_memoria;
		int aux;
		p = primero;
		while(p != NULL){
			j = p -> siguiente;
			while(j != NULL){
				if(p -> dato > j -> dato){
					aux = p -> dato;
					p -> dato = j -> dato;
					j -> dato = aux;
				}
				j = j -> siguiente;
			}
			p = p -> siguiente;
		}
	}else{
		printf("\nVacio\n");
	}
}
void imprimir_arbol(NodoArboles *Arbol, int cont){
int i;
	if(Arbol == NULL){
		return;
	}else{
		imprimir_arbol(Arbol -> derecho, cont += 1);
		for(i = 0; i < cont; i++){
			printf("   ");
		}
		printf("%d\n", Arbol -> dato);
		imprimir_arbol(Arbol -> izquierdo, cont += 1);
	}
}
void insertar_arbol(NodoArboles *&Arbol, int n){
    if(Arbol==NULL){
        NodoArboles *nuevo_nodo = reservar_memoria_arbol;
        Arbol=nuevo_nodo;
        nuevo_nodo->dato=n;
        nuevo_nodo->izquierdo=NULL;
        nuevo_nodo->derecho=NULL;
    }else{
        int valorRaiz=Arbol->dato;
        if(n<valorRaiz){
            insertar_arbol(Arbol->izquierdo,n);
        }else{
            insertar_arbol(Arbol->derecho,n);
        }
    }
}
void insertar_pila(Nodo *&primero, int num){
    Nodo* aux=reservar_memoria;
    aux->dato=num;
    aux->siguiente=primero;
    primero=aux;
}

void inOrden(NodoArboles *Arbol){
    if(Arbol==NULL){
        return;
    }else{
        inOrden(Arbol->izquierdo);
        printf("%d - ",Arbol->dato);
        inOrden(Arbol->derecho);
    }
}
void insercion(Nodo *primero){
    if(primero !=NULL){
        Nodo *i = reservar_memoria;
        Nodo *j = reservar_memoria;
        int aux;
        i = primero;
        while(i != NULL){
            j = i->siguiente;
            while(j != NULL){
                if(j->dato < i->dato){
                    aux = i->dato;
                    i->dato = j->dato;
                    j->dato = aux;
                }
                j = j->siguiente;
            }
            i = i->siguiente;
        }
    }
}
/*void quicksort(Nodo *primero, Nodo *ultimo){
    Nodo *i = reservar_memoria;
    Nodo *j = reservar_memoria;
    Nodo *x = reservar_memoria;
    int aux, cont=0;
    i = primero;
    j = ultimo;
    //x = (i->siguiente + j->siguiente)/2;
    do{
        while(primero->dato < x && j <= ultimo->dato){
            primero->siguiente;
        }
        while(x < ultimo->dato && j <= primero->dato){
            ultimo->siguiente;
        }
        if(i <= j){
           aux = i->dato;
           i->dato = j->dato;
           j ->dato = aux;
           i = i->siguiente;
           j = j->siguiente;
        }
    }
    while(i <= j);
        if(primero < j){
            quicksort(primero, j);
        }else if(i < ultimo){
            quicksort(i,ultimo);
        }
}*/



