#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Funciones.h"

/**
* \brief Solicita un número al usuario y realiza la acción pedido
* \param void
* \return void
*/

void menuCalculadora(void)
{
    float operadorA = 0;
    float operadorB = 0;
    float rsuma;
    float rresta;
    float rmulti;
    float rdivision;
    float rfactorialA;
    float rfactorialB;
    int flagNum1 = -1;
    int flagNum2 = -1;
    int respuesta = 0;

    do
    {
        printf("Calculadora\n\n");
        printf("1. Ingresar 1er operando (A = %.2f)\n", operadorA);
        printf("2. Ingresar 2do operando (B = %.2f)\n", operadorB);
        printf("3. Calcular todas las operaciones\n");
        printf("4. Informar resultados\n");
        printf("5. Salir\n\n");

        printf("Ingrese opcion: ");
        scanf("%d", &respuesta);

        switch(respuesta)
        {
            case 1:
                flagNum1 = cargarNumero(&operadorA, "Ingrese un numero: ");
                break;
            case 2:
                flagNum2 = cargarNumero(&operadorB, "Ingrese un numero: ");
                break;
            case 3:
                if(flagNum1 == 0 && flagNum2 == 0)
                {
                    rsuma = suma(operadorA, operadorB);
                    rresta = resta(operadorA, operadorB);
                    rmulti = multiplicacion(operadorA, operadorB);
                    rdivision = division(operadorA, operadorB);
                    rfactorialA = factorial(operadorA);
                    rfactorialB = factorial(operadorB);
                    printf("\n\nCalculo completo!\n\n");
                }
                else
                {
                    printf("Ingrese ambos operadores para continuar con el calculo!\n\n");
                }
                break;
            case 4:
                if(flagNum1 == 0 && flagNum2 == 0)
                {
                    informarTodo(rsuma, rresta, rmulti, rdivision, rfactorialA, rfactorialB);
                }
                else
                {
                    printf("Ingrese ambos operadores para continuar con el informe!\n\n");
                }
                break;
            case 5:
                printf("Presione cualquier tecla para salir\n");
                respuesta = 5;
                break;
            default:
                printf("Ingrese un valor correcto\n");
                break;
        }

    }while(respuesta != 5);
}

/**
* \brief Solicita un número al usuario
* \param input Se carga el numero ingresado
* \param message Es el mensaje a ser mostrado
* \return Si se cargo el numero devuelve 0 si no -1
*
*/
int cargarNumero(float* input,char message[])
{
    float auxiliar;
    int retorno = -1;

    if(input != NULL)
    {
        printf("%s", message);
        scanf("%f", &auxiliar);
        *input = auxiliar;
        retorno = 0;
    }
    else
    {
        retorno = -1;
    }

    return retorno;
}

/**
* \brief Muestra por pantalla el resultado de todas las operaciones aritméticas ingresadas
* \param suma Resultado de la suma
* \param resta Resultado de la resta
* \param multiplicación Resultado de la multiplicación
* \param división Resultado de la división
* \param factorial Resultado del factorial del primer numero ingresado
* \param factorial2 Resultado del factorial del segundo numero ingresado
* \return void
*/

void informarTodo(float suma, float resta, float multiplicacion, float division, float factorial, float factorial2)
{
    printf("El resultado de A+B es: %.2f\n", suma);
    printf("El resultado de A-B es: %.2f\n", resta);
    if(division != -1)
    {
        printf("El resultado de A/B es: %.2f\n", division);
    }
    else
    {
        printf("No se puede dividir por 0\n");
    }
    printf("El resutlado de A*B es: %.2f\n", multiplicacion);
    printf("El factorial de A es: %.2f y de B: %.2f\n", factorial, factorial2);
}

/**
* \brief Realiza la suma de los numeros recibidos
* \param num1 Primer numero ingresado por el usuario
* \param num2 Segundo numero ingresado por el usuario
* \return Devuelve la suma entre num1 y num2
*/

float suma(float num1, float num2)
{
    float resultado;

    resultado = num1+num2;

    return resultado;
}

/**
* \brief Realiza la resta de los numeros recibidos
* \param num1 Primer numero ingresado por el usuario
* \param num2 Segundo numero ingresado por el usuario
* \return Devuelve la resta entre num1 y num2
*/

float resta(float num1, float num2)
{
    float resultado;

    resultado = num1-num2;

    return resultado;
}

/**
* \brief Realiza la multiplicación de los numeros recibidos
* \param num1 Primer numero ingresado por el usuario
* \param num2 Segundo numero ingresado por el usuario
* \return Devuelve la multiplicación entre num1 y num2
*/

float multiplicacion(float num1, float num2)
{
    float resultado;

    resultado = num1*num2;

    return resultado;
}

/**
* \brief Realiza la división de los numeros recibidos
* \param num1 Primer numero ingresado por el usuario
* \param num2 Segundo numero ingresado por el usuario
* \return Devuelve la división entre num1 y num2
*/

float division(float num1, float num2)
{
    float resultado;

    resultado = num1/num2;

    return resultado;
}

/**
* \brief Realiza el factorial del número recibido
* \param num Numero ingresado por el usuario
* \return Devuelve el factorial de num
*/

float factorial(float num)
{
    float resultado;

    if(num == 1)
    {
        return 1;
    }
    resultado = num * factorial(num-1);

    return resultado;
}
