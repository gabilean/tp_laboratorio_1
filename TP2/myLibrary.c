#include <stdio_ext.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "myLibrary.h"

/**
    utn_getNombre :
    @param
    @param
    @return
*/

int myLibrary_sumaTotal(int notas[], int tamanio)
{
    int acumulador=0;
    int i;

    for(i=0;i<tamanio;i++)
    {
        acumulador = acumulador + notas[i];
    }

    return acumulador;
}

/**
    utn_getNombre :
    @param
    @param
    @return
*/

int myLibrary_Promedio(int notas[], int tamanio)
{
    int suma=0;
    int promedio=0;

    suma = myLibrary_sumaTotal(notas, tamanio);
    promedio = suma/promedio;

    return promedio;
}

/**
    utn_getNombre :
    @param
    @param
    @return
*/

void myLibrary_cargarListado(int notas[], int tamanio)
{
    int i;
    int numeroIngresado;

    for(i=0;i<tamanio;i++)
    {
        printf("\n Ingrese nota: ");
        scanf("%d", &numeroIngresado);
        notas[i] = numeroIngresado;
    }
}

/**
    utn_getNombre :
    @param
    @param
    @return
*/

int myLibrary_numMaximo(int num[], int tamanio)
{
    int max=0;
    int i;

    for(i=0;i<tamanio;i++)
    {
        if(i==0 || num[i] > max)
        {
            max = num[i];
        }
    }

    return max;
}

/**
    utn_getNombre :
    @param
    @param
    @return
*/

int myLibrary_numMinimo(int num[], int tamanio)
{
    int min;
    int i;

    for(i=0;i<tamanio;i++)
    {
        if(i==0 || num[i] < min)
        {
            min = num[i];
        }
    }

    return min;
}

/**
    utn_getNombre :
    @param
    @param
    @return
*/

int myLibrary_CantidadPares(int num[], int tamanio)
{
    int contadorPares=0;
    int par;
    int i;

    for(i=0; i<tamanio; i++)
    {
        par = num[i]%2;

        if(par == 0)
        {
            contadorPares++;
        }
    }

    return contadorPares;
}

/**
    utn_getNombre :
    @param
    @param
    @return
*/

int myLibrary_CantidadEntreNotas(int num[], int tamanio, int limInferior, int limSuperior)
{
    int contador=0;
    int i;

    for(i=0;i<tamanio;i++)
    {
        if(num[i]>=limInferior && num[i]<=limSuperior)
        {
            contador++;
        }
    }

    return contador;
}

/**
    utn_getNombre :
    @param
    @param
    @return
*/

int myLibrary_getInt(char mensaje[])
{
    int auxiliar;

    printf("%s", mensaje);
    scanf("%d", &auxiliar);

    return auxiliar;
}

/**
    utn_getNombre :
    @param
    @param
    @return
*/

float myLibrary_getFloat(char mensaje[])
{
    float auxiliar;

    printf("%s", mensaje);
    scanf("%f", &auxiliar);

    return auxiliar;
}

/**
    utn_getNombre :
    @param
    @param
    @return
*/

char myLibrary_getChar(char mensaje[])
{
    char auxiliar;

    printf("%s", mensaje);
    fflush(stdin);
    scanf("%c", &auxiliar);

    return auxiliar;
}

/**
    utn_getNombre :
    @param
    @param
    @return
*/

int myLibrary_esNumerico(char str[])
{
    int i;
    int retorno = -1;

    while(str[i] != '\0')
    {
        if(str[i] < '0' || str[i] > '9')
        {
            retorno = 0;
        }
        i++;
    }

    return retorno;
}

/**
    utn_getNombre :
    @param
    @param
    @return
*/

int myLibrary_esSoloLetras(char str[])
{
    int i;
    int retorno = 1;

    while(str[i] != '\0')
    {
        if(str[i] != ' ' && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' ||  str[i] > 'Z'))
        {
            retorno = 0;
        }
        i++;
    }

    return retorno;
}

/**
    utn_getNombre :
    @param
    @param
    @return
*/

int myLibrary_esAlfaNumerico(char str[])
{
    int i;
    int retorno = 1;

    while(str[i] != '\0')
    {
        if(str[i] != ' ' && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' ||  str[i] > 'Z') && (str[i] < '0' && str[i] > '9'))
        {
            retorno = 0;
        }
        i++;
    }

    return retorno;
}

/**
    utn_getNombre :
    @param
    @param
    @return
*/

int myLibrary_getString(char* pBuffer, int limite)
{
    int retorno = -1;
    int len;
    char bufferStr[4096];

    if(pBuffer != NULL && limite > 0)
    {
        fgets(bufferStr, limite, stdin);
        __fpurge(stdin);
        len = strlen(bufferStr);
        if(len != limite-1 || bufferStr[limite-2] == '\n')
        {
            bufferStr[len-1] = '\0';
        }

        strncpy(pBuffer, bufferStr, limite);
        retorno = 0;
    }

    return retorno;
}

/**
    utn_getNombre :
    @param
    @param
    @return
*/

int myLibrary_getStringLetras(char str[], char input[])
{
    char aux[4000];
    int retorno = 0;
    myLibrary_getString(str, aux);

    if(myLibrary_esSoloLetras(aux))
    {
        strcpy(input, aux);
        retorno = 1;
    }

    return retorno;
}

/**
    utn_getNombre :
    @param
    @param
    @return
*/

int myLibrary_getStringNumeros(char* str, int limite, char* msg, char* msgErr, int reintentos)
{
    int retorno=-1;
    char bufferNumero[4096];

    if(str != NULL && msg != NULL && msgErr != NULL && limite > 0 && reintentos >= 0)
    {
        do
        {
            __fpurge(stdin);
            reintentos--;
            printf("%s", msg);
            if(myLibrary_getString(bufferNumero,limite)==0 && myLibrary_esNumerico(bufferNumero))
            {

                strncpy(str, bufferNumero, limite);
                retorno = 0;
                break;
            }
            else
            {
                printf("%s", msgErr);
            }
        }while(reintentos >= 0);
    }
    return retorno;
}

/**
    utn_getNombre :
    @param
    @param
    @return
*/

int myLibrary_isValidLetras(char* pBuffer, int limite)
{
    int retorno = 0;
    int i;

    if(pBuffer != NULL && limite > 0)
    {
        retorno = 1;
        for(i=0; i < limite && pBuffer[i] != '\0'; i++)
        {
            if(tolower(pBuffer[i]) < 'a' || tolower(pBuffer[i]) > 'z')
            {
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}

/**
    utn_getNombre :
    @param
    @param
    @return
*/

int myLibrary_getNombre(char* pNombre,int limite, char* msg, char* msgErr, int reintentos)
{
    int retorno=-1;
    char bufferNombre[4096];

    if(pNombre != NULL && msg != NULL && msgErr != NULL && limite > 0 && reintentos >= 0)
    {
        do
        {
            __fpurge(stdin);
            reintentos--;
            printf("%s", msg);
            if(myLibrary_getString(bufferNombre,limite)==0 && myLibrary_isValidLetras(bufferNombre, limite))
            {
                strncpy(pNombre, bufferNombre, limite);
                retorno = 0;
                break;
            }
            else
            {
                printf("%s", msgErr);
            }
        }while(reintentos >= 0);
    }
    return retorno;
}

/*void myLibrary_mostrarEmpleados(struct eEmpleado datos, int limite)
{
    int i;

    for(i=0; i<limite; i++)
    {
        printf("Dato: %s - %s - %s\n", datos->nombre, datos->apellido, datos->edad);
    }
}*/
