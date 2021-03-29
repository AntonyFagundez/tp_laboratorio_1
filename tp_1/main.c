#include <stdio.h>
#include <stdlib.h>
#define ING_PRIM_OPER '1'
#define ING_SEG_OPER '2'
#define CALCULAR '3'
#define OBTENER '4'
#define SALIR '5'
#define URED "\e[4;91m"

#define WHTHB "\e[0;107m"
#define BHRED "\e[1;91m"
#define RED   "\033[1;91m"
#define GREEN "\033[0;92m"
#define YELLOW   "\033[1;93m"
#define BLUE   "\033[0;94m"
#define MAGENTA   "\033[0;95m"
#define CYAN   "\033[0;96m"
#define WHITE   "\x1B[37m"
#define RESET "\033[0m"
#define BHWHT "\e[1;97m"

#include "fagundez_math.h"
#include <Windows.h>

char menu(int*, int*, int, int);
char getChar(char*);
int getInt(char* texto);

int main()
{
    int primNum;
    int segNum;
    int flagPrimNum;
    int flagSegNum;
    int validDiv;

    int resultSum;
    int resultRes;
    float resultMult;
    float resultDiv;
    long long int resultFactPrim;
    long long int resultFactSeg;

    char resp;

    flagPrimNum=0;
    flagSegNum=0;
    validDiv=0;

    resp='s';


    do{
        switch(menu(&primNum, &segNum, flagPrimNum, flagSegNum))
        {
            case ING_PRIM_OPER:
                primNum = getInt("Ingrese primer operando: ");
                flagPrimNum=1;
                break;
            case ING_SEG_OPER:
                segNum = getInt("Ingrese segundo operando: ");
                flagSegNum = 1;
                break;
            case CALCULAR:
                if(flagPrimNum && flagSegNum)
                {
                    resultSum = sum(primNum, segNum);
                    resultRes = res(primNum, segNum);
                    resultMult = mult(primNum, segNum);
                    if(segNum != 0)
                    {
                        resultDiv = division(primNum, segNum);
                        validDiv=1;
                    }
                    else
                    {

                        printf(RED "Segundo operando invalido para realizar division.. " YELLOW "No debe ser 0\n" RESET);
                        validDiv=0;
                    }
                    if(primNum < 0)
                    {
                        printf(RED "Valor invalido para sacar factorial del primer operando. " YELLOW "No debe ser negativo\n" RESET);
                    }
                    else
                    {
                        resultFactPrim = factorial(primNum);
                    }
                    if(segNum < 0)
                    {
                        printf(RED "Valor invalido para sacar factorial del segundo operando. "YELLOW "No debe ser negativo\n" RESET);
                    }
                    else
                    {
                        resultFactSeg = factorial(segNum);
                    }
                    if(validDiv)
                    {//Se deja el mensaje visible para el usuario durante un segundo y medio
                        printf(GREEN "Todas las operaciones se realizaron satisfactoriamente");
                    }

                    Sleep(1500);
                }
                else
                {
                    printf( YELLOW "No puede realizar todas las operaciones si no ingresa ambos operandos\n" RESET);
                    Sleep(1500);
                }
                break;
            case OBTENER:
                if(flagPrimNum && flagSegNum)
                {
                    printf("El resultado de A"MAGENTA"+"RESET"B es %d\n", resultSum);
                    printf("El resultado de A"MAGENTA"-"RESET"B es %d\n", resultRes);
                    if(validDiv)
                    {
                        printf("El resultado de A"MAGENTA"/"RESET"B es %.2f\n", resultDiv);
                    }
                    else
                    {
                        printf(BHRED "ERROR. " RESET "Segundo operando invalido para realizar division. " YELLOW"No debe ser 0\n" RESET);
                    }

                    printf("El resultado de A"MAGENTA"*"RESET"B es %.2f\n", resultMult);
                    printf("El factorial de A es: %I64d y El factorial de B es: %I64d\n", resultFactPrim, resultFactSeg);
                }
                else
                {
                    printf(BHRED "Ingrese ambos operandos para calcular\n" RESET);
                }
                system("pause");
                break;
            case SALIR:
                resp = getChar("Desea continuar?(s/n)\n");
            break;

        }
    }while(resp == 's');

    return EXIT_SUCCESS;
}

char menu(int * x, int * y, int flagX, int flagY)
{
    char option;
    system("cls");


    printf(BHWHT "Calculadora\n" RESET);
    printf("Opciones:\n");

    if(flagX)
    {
        printf(BHWHT"1."RESET" Ingresar 1er operando (A=" GREEN "%d" RESET ")\n" , *x);
    }
    else
    {
        printf(BHWHT"1."RESET" Ingresar 1er operando (A=" YELLOW "X" RESET ")\n" );
    }

    if(flagY)
    {
        printf(BHWHT"2."RESET" Ingresar 2do operando (B=" GREEN "%d" RESET ")\n" , *y);
    }
    else
    {
        printf(BHWHT"2."RESET" Ingresar 2do operando (B=" YELLOW "Y" RESET ")\n");
    }


    printf(BHWHT"3."RESET" Calcular todas las "MAGENTA"operaciones\n" RESET);
    printf("  a) Calcular la suma (A" MAGENTA "+" RESET "B)\n");
    printf("  b) Calcular la resta (A" MAGENTA "-" RESET "B)\n");
    printf("  c) Calcular la division (A" MAGENTA "/" RESET "B)\n");
    printf("  d) Calcular la multiplicacion (A" MAGENTA "*" RESET "B)\n");
    printf("  e) Calcular el factorial (A"MAGENTA"!"RESET")\n");
    printf(BHWHT"4."RESET" Informar resultados\n");
    printf(BHWHT"5."RESET" Salir\n");
    printf("Ingrese opcion:");
    fflush(stdin);
    scanf("%c",&option);

    return option;
}

char getChar(char* texto)
{
    char result;

    printf(texto);
    fflush(stdin);
    scanf("%c", &result);

    return result;
}

int getInt(char* texto)
{
    int success = 0;
    int result;

    printf(texto);
    fflush(stdin);
    success = scanf("%d", &result);
    while(!success)
    {
        printf(RED "ERROR." RESET "Debe ingresar digitos\n");
        printf(texto);
        fflush(stdin);
        success = scanf("%d", &result);
    }

    return result;
}
