#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
/*
        BIBLIOTECA CON LISTAS ENLAZADAS
*/
//ESTRUCTURAS
typedef struct Libro
{  // UN LIBRO, TIENE UN TITULO, UN AUTOR, Y UN ISBN, ESTO SE GUARDARÁ DE LA SIGUIENTE MANERA: 
    char titulo[50];
    char autor[20];
    char isbn[13];
} Libro;
typedef struct Nodo
{ //AQUÍ SE CRAN LOS CAJONES DE LA LIBRERÍA, EN UN CAJÓN HAY UN LIBRO Y UN ENLACE A EL SIGUIENTE CAJON.
    Libro libro;
    struct Nodo* siguiente;
} Nodo;
typedef struct Lista
{ // AQUÍ GUARDAMOS DONDE INICIA LA LIBRERÍA, PARA SIEMPRE ACCEDER A CUALQIER VALOR DE LA LISTA
    Nodo* cabeza;
    int longitud;
} Lista;
//ESTRUCTURAS fin

//OPERACIONES CON LA LISTA DE LIBROS
Nodo* CrearNodo(Libro* libro){ // SE CREA UN NUEVO CAJÓN DONDE SE GUARDA LA INFORMACIÓN DE UN LIBRO Y LA UBICACIÓN DEL SIGUEINTE CAJÓN
    Nodo* nodo = (Nodo *)malloc(sizeof(Nodo));//CREAR ESPACIO EN MEMORIA PARA EL CAJÓN
    strncpy(nodo->libro.titulo, libro->titulo, 50);//COPIAMOS LA INFORMACIÓN DEL LIBRO A ESTE CAJÓN 
    strncpy(nodo->libro.autor, libro->autor, 20);
    strncpy(nodo->libro.isbn, libro->isbn, 13);
    nodo->siguiente = NULL;//EL SIGUEINTE CAJÓN SERÁ NULL POR SI NO SABEMOS CUAL ES
    return nodo; //ENVIAMOS LA INFORMACIÓN DEL CAJÓN
}
void DestruirNodo(Nodo* nodo){ //PARA ELIMINAR CAJONES QUE YA NO SE USAN
    free(nodo);
}
void InsertarPrincipio(Lista* lista, Libro* libro){//SE COLOCA UN LIBRO ARRIBA TE TODOS LOS CAJONES
    Nodo* nodo = CrearNodo(libro); //SE CREA EL CAJÓN SIN APUNTAR A NADA
    nodo->siguiente = lista->cabeza;//AHORA APUNTAMOS A EL CAJÓN QUE ANTES ERA EL INICIAL
    lista->cabeza = nodo;//Y LA CABEZA AHORA SERÁ EL NUEVO CAJÓN
    lista->longitud++;
}
void InsertarFinal(Lista* lista, Libro* libro){//SE COLOCA UN LIBRO HASTA ABAJO DE TODOS LOS CAJONES
    Nodo* nodo = CrearNodo(libro);//CREAMOS EL CAJÓN CON LA INFO DEL LIBRO
    if (lista->cabeza == NULL) //SI NO HAY CAJONES CREADOS, ENTONCES EL PRIMERO SERÁ EL CAJÓN QUE CREAMOS ARRIBA
    {
        lista->cabeza = nodo;
    } else{
        Nodo* puntero = lista->cabeza; //CON EL NODO PRINCIPAL SE RECORRE LA LIBRERÍA, ENTONCES LO GUARDAMOS EN UNA VARIABLE TIPO NODO* 
        //ESTE PUNTERO IRÁ AVANZANDO DESDE LA CABEZA HASTA EL FINAL PARA ENCONTRAR EL ÚLTIMO CAJÓN
        while (puntero->siguiente){ //MIENTRAS HAYA CAJONES AVANZAMOS
            puntero = puntero->siguiente;
        } //SI SE TERMINA EL WHILE ES PORQUE LLEGAMOS AL FINAL EL SIGUIENTE ES NULL Y AHÍ GUARDAREMOS EL CAJÓN CREADO AL INICIO CON LA INFO DEL LIBRO
        puntero->siguiente = nodo;
    }
    lista->longitud++;
}
void InsertarDespues(int n, Lista* lista, Libro* libro){
    Nodo* nodo = CrearNodo(libro); //CREAMOS UN CAJÓN CON LA INFO DEL LIBRO SIN APUNTAR A NADA
    if (lista->cabeza == NULL)// SI LA LIBRERÍA ESTÁ VACÍA, SOLAMENTE SE AGREGA EL NODO AL INICIO
    {
        lista->cabeza = nodo;
    }
    else
    {
        //BUSCAMOS DONDE ESTÁ EL CAJÓN n ->
        Nodo* puntero = lista->cabeza;
        int posicion = 0; //GUARDAMOS EL INICIO DE LA LIBRERÍA Y CONTAMOS QUE ES LA POSICIÓN 0, DE AQUÍ INICIAMOS HASTA LLEGAR A n
        while (posicion < n && puntero->siguiente ) // CONTANDO CUANTOS CAJONES AVANZAMOS HASTA LLEGAR A n O HASTA LLEGAR AL FINAL
        {
            puntero = puntero->siguiente;//VAMOS AVANZANDO DE CAJÓN SALTANDO ENTRE EL LUGAR AL QUE APUNTAN
            posicion++; //CONTAMOS CUANTOS CAJONES HEMOS AVANZADO
        }
        nodo->siguiente = puntero->siguiente; //AQUÍ HACEMOS QUE EL CAJÓN QUE IRA EN MEDIO APUNTE A EL CAJÓN QUE ESTÁ ALA DERECHA, CAJÓN QUE ANTES APUNTABA EL DE LA IZQUIERDA
        puntero->siguiente = nodo; //AHORA EN CAJÓN A LA IZQUIERA APUNTA A EL NUEVO Y EL NUEVO APUNTA A EEL CAJÓN QUE ESTABA A LA DERECHA
    }
    lista->longitud++;
}
Libro* Obtener(int n, Lista* lista){ //AQUÍ SE IMPRIME EL LIBRO QUE ESTÉ EN EL CAJÓN n QUE SE DESEE VER SU INFORMACIÓN
    if (lista->cabeza == NULL)//PROBAMOS QUE HAYA CAJONES CON LIBROS EN LA ESTANTERÍA
    {
        printf("No hay libros!!\n");
        Sleep(1500);
        return NULL;
    }else
    {
        Nodo* puntero = lista->cabeza;
        int posicion = 0;//GUARDAMOS EL INICIO DE LA LIBRERÍA Y CONTAMOS QUE ES LA POSICIÓN 0, DE AQUÍ INICIAMOS HASTA LLEGAR A n
        while (posicion < n && puntero->siguiente ) // CONTANDO CUANTOS CAJONES AVANZAMOS HASTA LLEGAR A n O HASTA LLEGAR AL FINAL
        {
            puntero = puntero->siguiente;//VAMOS AVANZANDO DE CAJÓN SALTANDO ENTRE EL LUGAR AL QUE APUNTAN
            posicion++; //CONTAMOS CUANTOS CAJONES HEMOS AVANZADO
        }
        if (posicion != n)//SI HAY MENOS LIBROS QUE n, SIGNIFICA QUE NO EXISTE EL LIBRO n Y SE REGRESA NULL
        {
            printf("\nHay menos libros!\n");
            Sleep(1500);
            return &puntero->libro;
        }
        else // SI POSICION ES IGUAL A n, SIGNIFICA QUE EXISTE EL LIBRO n Y LO IMPRIMIMOS.
        {
            return &puntero->libro;
        }
    }
}
int Contar(Lista* lista){
    return lista->longitud;
}
void EliminarPrincipio(Lista* lista){
    if(lista->cabeza){//SI LA LISTA ESTÁ VACÍA NO SE PUEDE ELIMINAR NADA
        Nodo* eliminado = lista->cabeza; //GUARDAMOS EL LUGAR DE MEMORIA DE EL PRIMER CAJÓN, PARA DESPUÉS ELIMINARLO
        lista->cabeza = lista->cabeza->siguiente;//AHORA HACEMOS QYE EL SEGUNDO CAJÓN SERA EL PRIMERO.
        DestruirNodo(eliminado); //BORRAMOS EL PRIMER CAJÓN MANDANDO SU UBICACIÓN
        lista->longitud--;
        printf("\nSe ha eliminado el primer nodo!\n");
        system("PAUSE");
    }else
    {
        printf("\nLista vacia!\n");
        Sleep(1500);
    }
}
void EliminarUltimo(Lista* lista){
    if(lista->cabeza){//SI ESTÁ VACÍA NO PODEMO ELIMINAR NADA
        if(lista->cabeza->siguiente ){
            Nodo* puntero = lista->cabeza; //CON EL NODO PRINCIPAL SE RECORRE LA LIBRERÍA, ENTONCES LO GUARDAMOS EN UNA VARIABLE TIPO NODO* 
            //ESTE PUNTERO IRÁ AVANZANDO DESDE LA CABEZA HASTA EL FINAL PARA ENCONTRAR EL ÚLTIMO CAJÓN
            while (puntero->siguiente->siguiente){ //AL LLEGAR AL PENULTIMO NOS DETENEMOS
                //LLEGAMOS AL PENULTIMO CAJÓN CUANDO EL SIGUEINTE DEL SIGEINTE DE ESE CAJÓN ES NULL
                puntero = puntero->siguiente; // SALTAMOS ENTRE PUNTEROS
            } //SI SE TERMINA EL WHILE ES PORQUE LLEGAMOS AL PENULTIMO CAJÓN ENTONCES...
            Nodo* eliminado = puntero->siguiente; //GUARDAMOS EL CAJÓN A ELIMINAR, EL ÚLTIMO
            puntero->siguiente = NULL; //HACEMOS QUE EL PENULTIMO CAJÓN SEA EL ÚLTIMO Y APUNTE A LA NADA
            DestruirNodo(eliminado); // BORRAMOS EL ÚLTIMO CAJÓN DE LA MEMORIA;
            lista->longitud--;
            printf("\nUltimo nodo eliminado!\n");
            system("PAUSE");
        }else//SI LA LIBRERÍA SOLO TIENE UN ELEMENTO, NO EXISTE UN PENULTIMO ENTONCES...
        {
            Nodo* eliminado = lista->cabeza; //GUARDAMOS EL PRIMER CAJÓN
            lista->cabeza = NULL; //AQUÍ ELIMINAMOS EL INICIO ANTERIOR, YA NO PODEMOS LLEGAR A EL, AHORA LA LISTA ESTÁ VACÍA.
            DestruirNodo(eliminado); // BORRAMOS LA INFORMACIÓN DEL CAJÓN
            lista->longitud--;
            printf("\nUltimo nodo eliminado!\n");
            system("PAUSE");
        }
    }else
    {
        printf("\nLista vacia!");
        Sleep(1500);
    }
    
}
void EliminarElemento(int n, Lista* lista){
    if (lista->cabeza)// COMPRBAMOS QUE LA LISTA NO ESTE VACÍA, SI EL PRIMER CAJON ES UN NULL SE CANCELA EL PROCESO
    {
        if (n == 0) //SI n ES 0 SOLAMENTE ELIMINAMOS EL PRINCIPIO Y LLAMAMOS A LA FUNCION
        {
            EliminarPrincipio(lista);
        }
        else if (n < lista->longitud)//AQUÍ CONFIRMAMOS QUE n NO SEA MAYOR A LA CANTIDAD DE LIBROS QUE EXISTEN
        {
            Nodo* puntero = lista->cabeza;
            int posicion = 0;
            while (posicion < (n - 1))
            {
                puntero = puntero->siguiente;
                posicion++;
            }//AVANZAMOS HASTA LLEGAR A EL CAJÓN A LA IZQUIERDA DEL CAJÓN A ELIMINAR
            Nodo* eliminado = puntero->siguiente; //GUARDAMOS EL CAJÓN A ELIMINAR
            puntero->siguiente = eliminado->siguiente; // HACEMOS QUE EL CAJÓN A LA IZQUIERDA APUNTE A EL CAJÓN A AL ADERECHA DEL QUE SE ELIMINARÁ
            DestruirNodo(eliminado);
            lista->longitud--;
            printf("\nNodo eliminado!");
            system("PAUSE");
        }else
        {
            printf("\nHay menos libros!");
            system("PAUSE");
        }
    }else
    {
        printf("\nLista vacia!!\n");
        system("PAUSE");
    }
    
}
void ImprimirLista(Lista* lista){
    if(lista->cabeza == NULL)
    {
        printf("\nLa lista esta vacia!\n");
        system("PAUSE");
    }
    else
    {
        Nodo* puntero = lista->cabeza;
        int posicion=0;
        printf("\nTitulo      Autor     ISBN\n");
        while (posicion < lista->longitud)
        {
            printf("%s | %s | %s\n", puntero->libro.titulo, puntero->libro.autor, puntero->libro.isbn);
            puntero = puntero->siguiente;
            posicion++;
        }
        printf("\n");
        system("PAUSE");
    }
}
//OPERACIONES CON LA LISTA DE LIBROS fin
void RegistrarLibro(Libro* libro){
    char titulo[50], autor[20], isbn[13];
    printf("\nIngrese el titulo del libro: ");
    fflush(stdin);
    gets(titulo);
    strncpy(libro->titulo, titulo, 50);
    printf("\nIngrese el autor del libro: ");
    gets(autor);
    strncpy(libro->autor, autor, 20);
    printf("\nIngrese el ISBN del libro: ");
    gets(isbn);
    strncpy(libro->isbn, isbn, 13);
}

void main()
{
    Libro* libro = (Libro*)malloc(sizeof(Libro));
    Lista lista;
    lista.cabeza = NULL;
    lista.longitud = 0;
    int op = 0, n=0;
    do
    {
        system("CLS");
        printf("----------------------------------------------------------------------\n");
        printf("------------------LISTA DE LIBROS DE UNA BIBLIOTECA-------------------\n");
        printf("----------------------------------------------------------------------\n");
        printf("1. Poner al Inicio.\n2. Poner al Final.\n3. Poner en Medio.\n4. Eliminar del Inicio.\n5. Eliminar del Final.\n6. Eliminar de en Medio.\n7. Imprimir lista de Libros.\n8. Imprimir un Libro.\n9. Cantidad de Libros.\n0. SALIR \n\n");
        printf("Seleccione una de las opciones anteriores:  ");
        scanf("%d", &op);
        switch (op)
        {
            case 1:
                RegistrarLibro(libro);
                InsertarPrincipio(&lista, libro);
                break;
            case 2:
                RegistrarLibro(libro);
                InsertarFinal(&lista, libro);
                break;
            case 3:
                RegistrarLibro(libro);
                printf("\nEl libro se colocara despues del libro numero...: ");
                scanf("%d", &n);
                n--;
                InsertarDespues(n, &lista, libro);
                break;
            case 4:
                EliminarPrincipio(&lista);
                break;
            case 5:
                EliminarUltimo(&lista);
                break;
            case 6:
                printf("\nIngrese la posicion del nodo a eliminar:  ");
                scanf("%d", &n);
                n--;
                EliminarElemento(n, &lista);
                break;
            case 7:
                ImprimirLista(&lista);
                break;
            case 8:
                printf("Ingrese la posicion del libro a imprimir: ");
                scanf("%d", &n);
                n--;
                libro = Obtener(n, &lista);
                printf("\nTitulo: %s\nAutor: %s\nISBN: %s\n", libro->titulo, libro->autor, libro->isbn);
                system("PAUSE");
                break;
            case 9:
                n = Contar(&lista);
                printf("\nCantidad de libros en la lista:  %d\n", n);
                system("PAUSE");
                break;
            case 0:
                break;
            default:
                printf("\nSeleccione otra opcion.\n");
                system("PAUSE");
                break;
        }
    } while (op);
    printf("\nSaliendo...\n\n");
    system("PAUSE");   
}
