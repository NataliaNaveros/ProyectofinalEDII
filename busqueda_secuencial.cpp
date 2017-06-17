#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define reservar_memoria (Nodo *)malloc(sizeof(Nodo))

struct Nodo{
    int dato;
    Nodo *siguiente;
};
Nodo *primero;
Nodo *ultimo;

void generar_numeros(Nodo *&, Nodo *&);
void insertar_elementos(Nodo *&, Nodo *&, int);
void buscar_elementos(Nodo *&);
void imprimir_elementos(Nodo *);
void ordenar_elementos(Nodo *);
void vaciar_elementos(Nodo *&);

int main(){
    int opc;
    do{
        printf("Opciones del programa\n");
        printf("\n0. Salir");
        printf("\n1. Insertar elementos");
        printf("\n2. Imprimir elementos");
        printf("\n3. Buscar elementos");
        printf("\n4. Ordenar elementos");
        printf("\n5. Vaciar elementos\n");
        printf("\nIngrese una opcion: ");
        scanf("%d",&opc);
        printf("\n\n");
        switch(opc){
        case 0:
            printf("\nFinalizado\n\n");
            exit(0);
            break;
        case 1:
            generar_numeros(primero,ultimo);
            break;
        case 2:
            imprimir_elementos(primero);
            break;
        case 3:
            buscar_elementos(primero);
            break;
        case 4:
            ordenar_elementos(primero);
            break;
        case 5:
            vaciar_elementos(primero);
            break;
        default:
            printf("\nOpcion no valida\n\n");
            break;
        }
        printf("\n\n");
        system("pause");
        system("cls");
    }while(opc != 0);
}
void generar_numeros(Nodo *&primero, Nodo *&ultimo){
    int num, nDatos, i = 0;
	printf("Ingrese cantidad de numeros a generar: ");
	scanf("%d", &nDatos);
	srand(time(NULL));
	while(i < nDatos){
		num = (rand () % (1999998 + 1));
		insertar_elementos(primero, ultimo, num);
		i += 1;
	}
}
void insertar_elementos(Nodo *&primero, Nodo *&ultimo, int n){
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
void buscar_elementos(Nodo *&primero){
    Nodo *aux=reservar_memoria;
    aux=primero;
    int buscar=0, encontrado=0,cont=0;
    printf("\nIngrese dato a buscar: ");
    scanf("%d",&buscar);
    if(primero!=NULL){
        while(aux!=NULL){
            if(aux->dato==buscar){
                printf("\nEl dato ( %d ) fue encontrado en la posicion %d\n", buscar, cont);
                encontrado=1;
            }
            aux=aux->siguiente;
            cont=cont+1;

        }
        if(encontrado==0){
            printf("\nEl dato no ha sido encontrado\n");
        }
    }else{
        printf("\nLa lista se encuentra vacia\n");
    }
}
void imprimir_elementos(Nodo *primero){
    	if(primero != NULL){
		Nodo *actual = reservar_memoria;
		actual = primero;
		while(actual != NULL){
			printf("%d \n", actual -> dato);
			actual = actual -> siguiente;
		}
	}else{
		printf("\nLa lista se encuentra vacia\n");
	}
}
void ordenar_elementos(Nodo *primero){
    if(primero != NULL){
		Nodo *i = reservar_memoria;
		Nodo *j = reservar_memoria;
		int aux;
		i = primero;
		while(i != NULL){
			j = i -> siguiente;
			while(j != NULL){
				if(i -> dato > j -> dato){
					aux = i -> dato;
					i -> dato = j -> dato;
					j -> dato = aux;
				}
				j = j -> siguiente;
			}
			i = i -> siguiente;
		}
	}else{
		printf("\nLa lista se encuentra vacia\n");
	}
}
void vaciar_elementos(Nodo *&primero){
 Nodo *aux;
    while(primero!=NULL){
        aux=primero;
        primero=aux->siguiente;
        free(aux);
    }
    printf("\nLa lista se vacio con exito\n");
}
