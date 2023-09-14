#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define color system("COLOR B");
#define ESC 27


///Hacer una función que intercale en orden los elementos de dos listas ordenadas generando una nueva lista.
///Se deben redireccionar los punteros, no se deben crear nuevos nodos.


///NO ME SALIO PREGUNTAR FUNCION INTERCALAR
typedef struct
{
    char nombre[30];
    int edad;
} Persona;
typedef struct _listaPersonas
{
    Persona pers;
    struct _listaPersonas *siguente;

} listaPersonas;


///PROTOTIPADO
listaPersonas* inic();
listaPersonas *agregar_al_Ppcio(listaPersonas *lista, listaPersonas *nuevoNodo);
listaPersonas *crear_nodo(Persona pers);
listaPersonas *cargar_datos(listaPersonas *lista, Persona pers);
void mostrar_lista(listaPersonas *lista);
listaPersonas *intercalar(listaPersonas *lista, listaPersonas* lista2);

int main()
{
    color;
    listaPersonas *lista1=inic();
    listaPersonas *lista2 =inic();
     listaPersonas *listaN =inic();
    Persona pers;
    printf("CARGA DE LISTA 1 \n");
    lista1= cargar_datos(lista1,pers);
    printf("CARGA DE LISTA 2 \n");
    lista2=cargar_datos(lista2,pers);

    mostrar_lista(lista1);
    system("pause");
    mostrar_lista(lista2);
    listaN=intercalar(lista1,lista2);
    printf("MUESTRA LISTA LUEGO DE INTERCALAR \n");
    mostrar_lista(listaN);


    return 0;
}

listaPersonas * inic()
{
    return NULL;
}



listaPersonas *buscar_ultimo(listaPersonas *lista)
{
    listaPersonas *seg=lista;

    while(seg)
    {
        seg=seg->siguente;

    }


    return seg;
}

listaPersonas *agregar_al_Ppcio(listaPersonas *lista, listaPersonas *nuevoNodo)
{
    if(lista == NULL)
    {
        lista = nuevoNodo;
    }
    else
    {
        nuevoNodo->siguente=lista;
        lista = nuevoNodo;
    }
    return lista;
}



listaPersonas *crear_nodo(Persona pers1)
{
    listaPersonas *nuevo= (listaPersonas*)malloc(sizeof(listaPersonas));
    nuevo->pers= pers1;
    nuevo->siguente= NULL;
    printf("ENTRE CREAR \n");
    return nuevo;
}


listaPersonas *cargar_datos(listaPersonas *lista, Persona pers1)
{

    char o=0;

    while(o!=27)
    {

        printf("INGRESE NoMBRE \n");
        fflush(stdin);
        gets(pers1.nombre);
        printf("Ingrese edad \n");
        scanf("%d",&pers1.edad);
        fflush(stdin);
        o=getch();

        lista=agregar_al_Ppcio(lista,crear_nodo(pers1));
    }

    return lista;
}


void mostrar_lista(listaPersonas *lista)
{
    listaPersonas *seg=lista;
    int i=0;
    while(seg->siguente!=NULL)
    {


        printf("Primer pos %d NOMBRE %s \n",i,seg->pers.nombre);
        printf("EDAD %d \n",seg->pers.edad);
        seg=seg->siguente;

        i++;
    }
    printf("Primer pos %d NOMBRE %s \n ",i,seg->pers.nombre);
    printf("EDAD %d \n",seg->pers.edad);
}

///NO ME SALIO PREGUNTAR
listaPersonas *intercalar(listaPersonas *lista, listaPersonas* lista2)
{


    listaPersonas *listanueva =inic();
    while( lista && lista2)
    {
          listanueva->siguente =lista;
          lista =lista->siguente;

printf("ENTRE INTERCALAR WHILE \n");
          listanueva->siguente =lista2;
          lista2=lista2->siguente;


    }

    return listanueva;

}
