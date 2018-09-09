#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"

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
                operadorA = cargarNumero();
                break;
            case 2:
                operadorB = cargarNumero();
                break;
            case 3:
                rsuma = suma(operadorA, operadorB);
                rresta = resta(operadorA, operadorB);
                rmulti = multiplicacion(operadorA, operadorB);
                rdivision = division(operadorA, operadorB);
                rfactorialA = factorial(operadorA);
                rfactorialB = factorial(operadorB);
                printf("\n\nCalculo completo!\n\n");
                break;
            case 4:
                informarTodo(rsuma, rresta, rmulti, rdivision, rfactorialA, rfactorialB);
                break;
            case 5:
                printf("Finalizado\n");
                respuesta = 5;
                break;
            default:
                printf("Ingrese un valor correcto\n");
                break;
        }

    }while(respuesta != 5);
}

float cargarNumero(void)
{
    float numero;

    printf("Ingrese un numero:");
    scanf("%f", &numero);

    return numero;
}

float suma(float num1, float num2)
{
    float resultado;

    resultado = num1+num2;

    return resultado;
}

float resta(float num1, float num2)
{
    float resultado;

    resultado = num1-num2;

    return resultado;
}

float multiplicacion(float num1, float num2)
{
    float resultado;

    resultado = num1*num2;

    return resultado;
}

float division(float num1, float num2)
{
    float resultado;

    resultado = num1/num2;

    return resultado;
}

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


void informarTodo(float suma, float resta, float multiplicacion, float division, float factorial, float factorial2)
{
    printf("El resultado de A+B es: %.2f\n", suma);
    printf("El resultado de A-B es: %.2f\n", resta);
    printf("El resultado de A/B es: %.2f\n", division);
    printf("El resutlado de A*B es: %.2f\n", multiplicacion);
    printf("El factorial de A es: %.2f y de B: %.2f\n", factorial, factorial2);
}
