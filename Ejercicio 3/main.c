#include <stdio.h>
#include <stdlib.h>
#define COLOR system("COLOR B");
#include <conio.h>
#include <string.h>
#define ESC 27

/// Hacer una función que retorne un 1 (uno) o 0 (cero) si existe un determinado elemento en una lista dada.
/// (considerar caso ordenada y caso desordenada)
typedef struct
{

    char  nombre[30];
    int age;
    char sex;

} persona;

typedef struct _listaPersonas
{
    persona pers;
    struct _listaPersonas * siguiente;

} listaPersonas;


///PROTOTIPADO
void mostrar_archivo(FILE * archi);
void cargar_archivo(FILE *archi);
listaPersonas *crear_nodo(persona pers);
listaPersonas * cargar_lista_al_Ppio(listaPersonas * lista,FILE *archi);
void mostrar_lista(listaPersonas* lista);
listaPersonas * agregar_al_principio(listaPersonas* lista,listaPersonas* nuevoNodo);
listaPersonas * inic();
listaPersonas* agregar_al_final(listaPersonas * lista, FILE* archi);
listaPersonas * agregarFinal(listaPersonas* lista,listaPersonas * nuevoNodo);
listaPersonas * buscarUltimo(listaPersonas * lista) ;
int devuelve_flag(listaPersonas *lista,char nombre[30]);

int main()
{
    COLOR;
    listaPersonas * lista=NULL;

    FILE *archi=fopen("ARCH","a+b");
    if(archi)
    {
        ///  cargar_archivo(archi);
        mostrar_archivo(archi);
system("pause");

 ///       lista=cargar_lista_al_Ppio(lista,archi);
        lista= agregar_al_final(lista,archi);
        mostrar_lista(lista);
        printf(" DEVUELVE %d",devuelve_flag(lista,"NOMBRE ALEATORIO"));

    }

    fclose(archi);
    return 0;
}

void cargar_archivo(FILE *archi)
{
    archi=fopen("ARCH","a+b");
    char o=0;
    persona p;
    while(o!=27)
    {

        printf("INGRESE NOMBRE \n");
        fflush(stdin);
        gets(p.nombre);
        printf("INGRESE SEXO \n");
        scanf("%c",&p.sex);
        printf("INGRESE EDAD \n");
        scanf("%d",&p.age);
        fflush(stdin);
        o=getch();

        fwrite(&p,sizeof(persona),1,archi);
    }
    fclose(archi);

}
void mostrar_archivo(FILE * archi)
{
    persona p;
    archi=fopen("ARCH","r+b");
    while(fread(&p,sizeof(persona),1,archi)>0)
    {
        printf("NOMBRE : %s \n",p.nombre);
        printf("EDAD : %d \n",p.age);
        printf("SEXO : %c \n",p.sex);

    }
    fclose(archi);
}

listaPersonas *crear_nodo(persona per1)
{
    listaPersonas * nuevoNodo= (listaPersonas*)malloc(sizeof(listaPersonas));
    nuevoNodo ->pers=per1;
    nuevoNodo ->siguiente = NULL;


    return nuevoNodo;
}

listaPersonas * inic()
{
    return NULL ;
}


listaPersonas * cargar_lista_al_Ppio(listaPersonas * lista,FILE *archi)
{
    archi=fopen("ARCH","r+b");
    persona pers1;
    listaPersonas *nuevoNodo=inic() ;

    if(archi)
    {

        while(fread(&pers1,sizeof(persona),1,archi)>0)
        {

            nuevoNodo=crear_nodo(pers1);

            lista= agregar_al_principio(lista,nuevoNodo);


        }
    }
    else
    {
        printf("ERROR \n");
    }

    fclose(archi);

    return lista;
}

void mostrar_lista(listaPersonas *lista)
{

    listaPersonas *seg=lista;

    while(seg->siguiente )
    {
        printf("nombre :%s \n",seg ->pers.nombre);
        printf("edad: %d \n",seg ->pers.age);
        printf("SEXO  : %c", seg->pers.sex);
        seg= seg->siguiente;
    }
    printf("nombre :%s \n",seg ->pers.nombre);
    printf("edad: %d \n",seg ->pers.age);
    printf("SEXO  : %c", seg->pers.sex);
}

listaPersonas * agregar_al_principio(listaPersonas* lista,listaPersonas* nuevoNodo)
{

    nuevoNodo->siguiente=  lista;
    return  nuevoNodo;
}


listaPersonas* agregar_al_final(listaPersonas * lista, FILE* archi){
 archi=fopen("ARCH","r+b");
    persona pers1;
    listaPersonas *nuevoNodo=inic() ;

    if(archi)
    {

        while(fread(&pers1,sizeof(persona),1,archi)>0)
        {
        nuevoNodo=crear_nodo(pers1);
   if(lista == NULL) {
      lista = nuevoNodo;
   } else {
         listaPersonas* seg = lista;

          while(seg->siguiente != NULL)
            {
             seg = seg->siguiente;
            }

        seg->siguiente = nuevoNodo;
   }

        }


    }
    fclose(archi);

return lista;
}

listaPersonas * buscarUltimo(listaPersonas * lista) {
   listaPersonas* seg = lista;
   if(seg != NULL)
      while(seg->siguiente != NULL) {
         seg = seg->siguiente;
      }
    return seg;
 }

listaPersonas * agregarFinal(listaPersonas * lista, listaPersonas * nuevoNodo) {


   if(lista == NULL) {
      lista = nuevoNodo;
   } else {
      listaPersonas * ultimo = buscarUltimo(lista);
      ultimo->siguiente = nuevoNodo;
   }
   return lista;
}




/**
listaPersonas * agregarFinal(listaPersonas * lista, listaPersonas * nuevoNodo) {


   if(lista == NULL) {
      lista = nuevoNodo;
   } else {
         listaPersonas* seg = lista;

          while(seg->siguiente != NULL)
            {
             seg = seg->siguiente;
            }

        seg->siguiente = nuevoNodo;
   }

   return lista;
}
*/

int devuelve_flag(listaPersonas *lista,char nombre[30]){

int flag=0;

listaPersonas *seg=lista;

while(seg){

    if(strcmpi(seg->pers.nombre ,nombre)==0){
        flag=1;
    }

seg=seg->siguiente;
}



return flag;
}
