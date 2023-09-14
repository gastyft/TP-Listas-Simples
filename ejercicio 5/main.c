#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#define ESC 27



typedef struct
{

    int edad;
    char nombre[30];

} Persona;

typedef struct _listaPersonas
{

    Persona personaa;
    struct _listaPersonas *siguiente;

} listaPersonas;

///Invertir los elementos de una lista redireccionando solamente los punteros. (No se deben crear nuevos nodos)


///PROTOTIPADO

listaPersonas *cargar_persona(listaPersonas *lista);
void mostrar_lista(listaPersonas*lista);
listaPersonas *agregar_al_final(listaPersonas *lista,listaPersonas*nuevoNodo);
listaPersonas *crear_nodo();
listaPersonas *inic();
listaPersonas *invertir(listaPersonas *lista);


int main()
{
    system("COLOR B");

    listaPersonas *lista=inic();




    lista= cargar_persona(lista);
    mostrar_lista(lista);
    system("pause");
    lista= invertir(lista);
    mostrar_lista(lista);

    return 0;
}


listaPersonas *cargar_persona(listaPersonas *lista)
{
    Persona pers;
    char o=0;
    listaPersonas *nuevoNodo=inic();
    while(o!=27)
    {

        printf("INGRESE NOMBRE \n");
        fflush(stdin);
        gets(pers.nombre);
        printf("INGRESE EDAD \n");
        scanf("%d",&pers.edad);
        printf("INGRESE ESC PARA SALIR \n");
        nuevoNodo=crear_nodo(pers);
        lista= agregar_al_final(lista,nuevoNodo);
        fflush(stdin);
        o=getch();
    }
    return lista;
}

listaPersonas *inic()
{
    return NULL;
}

listaPersonas *crear_nodo(Persona pers)
{

    listaPersonas * nuevoNodo= (listaPersonas*)malloc(sizeof(listaPersonas));


    nuevoNodo->personaa=pers;
    nuevoNodo->siguiente=NULL;

    return nuevoNodo;
}


listaPersonas *agregar_al_final(listaPersonas *lista,listaPersonas*nuevoNodo)
{

    if(lista == NULL)
    {
        lista = nuevoNodo;
    }
    else
    {
        listaPersonas* seg = lista;

        while(seg->siguiente != NULL)
        {
            seg = seg->siguiente;
        }

        seg->siguiente = nuevoNodo;
    }

    return lista;
}


void mostrar_lista(listaPersonas*lista)
{

    listaPersonas *seg=lista;
    while(seg->siguiente)
    {
        printf("NOMBRE %s \n",seg->personaa.nombre);
        printf("EDAD %d \n",seg->personaa.edad);
        seg=seg->siguiente;
    }
    printf("NOMBRE %s \n",seg->personaa.nombre);
    printf("EDAD %d \n",seg->personaa.edad);

}



listaPersonas *invertir(listaPersonas *lista)
{

    listaPersonas *aux=inic();
    listaPersonas *aux2=lista;
    listaPersonas *seg=lista;
    if( lista  == NULL)
    {
        aux=lista;
    }
    else
    {

        while(seg->siguiente!= NULL)
        {


            while(aux2 ->siguiente!=NULL)
            {

                aux2=aux2->siguiente;
            }
            if(aux2->siguiente == NULL)
                {
                    if(aux!=NULL){
                         aux->siguiente=aux ;
                    aux = aux2;
                    }
                    else{
                            aux=aux2;
                    }
                }
            seg= seg->siguiente;
            aux2 =seg;

        }


    }
    return aux;
}



