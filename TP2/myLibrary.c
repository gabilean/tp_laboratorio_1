#include <stdio_ext.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "myLibrary.h"

static int getFloat(float* num);

/** \brief Verifica si es entero
 * \param char str*
 * \return int return (-1) es error [Largo invalido o puntero nulo] - (0) OK
 */

int myLibrary_esInt(char* str)
{
    int i;
    int retorno = 0;

    while(str[i] != '\0')
    {
        if(str[i] < '0' || str[i] > '9')
        {
            retorno = -1;
        }
        i++;
    }

    return retorno;
}

/** \brief Verifica si es flotante
 * \param char str*
 * \return int return (-1) es error [Largo invalido o puntero nulo] - (0) OK
 */

int myLibrary_esFloat(char* str)
{
    int i=0;
    int contPuntos = 0;
    int retorno = -1;

    while(str[i] != '\0')
    {
        if(str[i] == ',' || str[i] == '.')
        {
            str[i] = '.';
            contPuntos++;

            if(contPuntos == '2')
            {
                break;
            }
        }

        else if((str[i] < '0') || (str[i] > '9'))
        {
            break;
        }

        i++;

        if(str[i] == '\0')
        {
            retorno = 0;
        }
    }

    return retorno;
}

/** \brief Verifica si es solo letras
 * \param char str*
 * \return int return (-1) es error [Largo invalido o puntero nulo] - (0) OK
 */

int myLibrary_esSoloLetras(char* str)
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

/** \brief Verifica si es alfanumerico
 * \param char str*
 * \return int return (-1) es error [Largo invalido o puntero nulo] - (0) OK
 */

int myLibrary_esAlfaNumerico(char* str)
{
    int i;
    int retorno = -1;

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

/** \brief Verifica si es string
 * \param char pBuffer*
 * \param int limite tamaño
 * \return int return (-1) es error [Largo invalido o puntero nulo] - (0) OK
 */

int myLibrary_getString(char* pBuffer, int limite)
{
    int retorno = -1;
    int len;
    char bufferStr[4096];

    if(pBuffer != NULL && limite > 0)
    {
        __fpurge(stdin);
        fgets(bufferStr, limite, stdin);
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

/** \brief Verifica si es string y float
 * \param float num*
 * \return int return (-1) es error [Largo invalido o puntero nulo] - (0) OK
 */

static int getFloat(float* num)
{
    char bufferStr[100];
    int retorno = -1;

    if(myLibrary_getString(bufferStr, 100) == 0 && myLibrary_esFloat(bufferStr) == 0)
    {
        *num = atof(bufferStr);
        retorno = 0;
    }

    return retorno;
}

/** \brief Pide un numero flotante, lo valida y lo guarda en la variable pasada por referencia
 * \param float num*
 * \param int limite
 * \param char msg*
 * \param char msgErr*
 * \param int reintentos
 * \return int return (-1) es error [Largo invalido o puntero nulo] - (0) OK
 */

int myLibrary_getFloat(float* num, int limite, char* msg, char* msgErr, int reintentos)
{
    int retorno=-1;
    float bufferNumero;

    if(num != NULL && msg != NULL && msgErr != NULL && limite > 0 && reintentos >= 0)
    {
        do
        {
            __fpurge(stdin);
            reintentos--;
            printf("%s", msg);
            if(getFloat(&bufferNumero) == 0)
            {
                *num = bufferNumero;
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

/** \brief Pide un numero entero, lo valida y lo guarda en la variable pasada por referencia
 * \param int num*
 * \param int limite
 * \param char msg*
 * \param char msgErr*
 * \param int reintentos
 * \return int return (-1) es error [Largo invalido o puntero nulo] - (0) OK
 */
int myLibrary_getInt(int* num, int limite, char* msg, char* msgErr, int reintentos)
{
    int retorno=-1;
    char bufferNumero[limite];

    if(num != NULL && msg != NULL && msgErr != NULL && limite > 0 && reintentos >= 0)
    {
        do
        {
            __fpurge(stdin);
            reintentos--;
            printf("%s", msg);
            if(myLibrary_getString(bufferNumero, limite) ==0 && myLibrary_esInt(bufferNumero))
            {

                *num = atoi(bufferNumero);
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

/** \brief Valida si la cadena pasada por referncia es solo letras
 * \param char pBuffer*
 * \param int limite
 * \return int return (-1) es error [Largo invalido o puntero nulo] - (0) OK
 */

int myLibrary_isValidLetras(char* pBuffer, int limite)
{
    int retorno = 0;
    int i;

    if(pBuffer != NULL && limite > 0)
    {
        //retorno = 1;
        for(i=0; i < limite && pBuffer[i] != '\0'; i++)
        {
            if(tolower(pBuffer[i]) < 'a' || tolower(pBuffer[i]) > 'z')
            {
                retorno = -1;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Pide un nombre, lo valida y lo guarda en la variable pasada por referencia
 * \param char pNombre*
 * \param int limite
 * \param char msg*
 * \param char msgErr*
 * \param int reintentos
 * \return int return (-1) es error [Largo invalido o puntero nulo] - (0) OK
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
            if(myLibrary_getString(bufferNombre,limite) == 0 && myLibrary_isValidLetras(bufferNombre, limite) == 0)
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
