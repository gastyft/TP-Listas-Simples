#include <stdio.h>
#include <stdlib.h>
#define COLORCITO system("COLOR a");

///Hacer un programa que lea de un archivo datos y los inserte en una lista en forma ordenada.

typedef struct
{
    int num;
} nume;

typedef struct
{

    nume num;
    struct nodo * siguiente;
} nodo;

void cargar_archivo(FILE *archi);
void mostrar_archivo(FILE *archi);
nodo *inic_lista();
nodo *agregar_al_principio(nodo *lista, nodo* nuevoNodo);
nodo *cargar_lista(nodo *lista, FILE *archi);
void mostrar_lista(nodo*lista);

int main()
{
    system("COLOR B");
    FILE *archi =fopen("ARCH","a+b");
    if(archi)
    {
/// cargar_archivo(archi);
        mostrar_archivo(archi);
        nodo *lista = inic_lista();
        lista=cargar_lista(lista,archi);
        system("pause");
        COLORCITO;///VERDE
        mostrar_lista(lista);
    }
    else
    {
        printf("ERROR EN ARCHIVO \n");
    }


    fclose(archi);
    return 0;
}


void cargar_archivo(FILE *archi)
{
    int i=0;
    archi =fopen("ARCH","a+b");
    while(i<5)
    {
        int num= i+1;
        fwrite(&num,sizeof(int),1,archi);
        i++;
    }

    fclose(archi);
}
void mostrar_archivo(FILE *archi)
{
    int num;
    archi =fopen("ARCH","r+b");
    while(fread(&num,sizeof(int),1,archi)>0)
    {

        printf("%d",num);
    }


}

nodo *cargar_lista(nodo *lista, FILE *archi)
{

    int num ;
    nume num2;


    archi=fopen("ARCH","r+b");
    if(archi)
    {
        while(fread(&num,sizeof(int),1,archi)>0)
        {

            num2.num=num;
            nodo * nuevo = (nodo*) malloc(sizeof(nodo));
            nuevo->num=num2;
            nuevo ->siguiente=NULL;

            lista=agregar_al_principio(lista,nuevo);
        }


    }

    return lista;
}

nodo * agregar_al_principio(nodo* lista,nodo* nuevoNodo)
{

    nuevoNodo->siguiente=  lista;
    return  nuevoNodo;
}

nodo *inic_lista()
{

    return  NULL;

}

void mostrar_lista(nodo*lista)
{
    nodo *seg =lista;

    while(seg->siguiente!= NULL)
    {
        printf("\n LISTA %d", seg->num.num);
        seg=(nodo *)seg->siguiente;
    }
printf("\n LISTA %d", seg->num.num);
}

