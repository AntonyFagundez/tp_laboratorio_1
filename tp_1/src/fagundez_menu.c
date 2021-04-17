/*
 * fagundez_menu.c
 *
 *  Created on: 17 abr. 2021
 *      Author: Antony
 */

#include <stdio.h>
#include <stdlib.h>
#include <synchapi.h>

#include "fagundez_colors.h"
#include "fagundez_menu.h"
#include "fagundez_math.h"
#include "fagundez_utils.h"

#define MAX_INT_FACT 19

#if defined(_WIN32) || defined(_WIN64) || defined(__WINDOWS__)
#define CLEAR_COMMAND "cls"
#else
#define CLEAR_COMMAND "clear"
#endif


int menu(int *x, int *y, int flagX, int flagY)
{
	int option;
	system(CLEAR_COMMAND);
	printf(BHWHT "Calculadora\n" RESET);
	printf("Opciones:\n");

	if (flagX)
	{
		printf(
		BHWHT"1."RESET" Ingresar 1er operando (A=" BHGRN "%d" RESET ")\n", *x);
	}
	else
	{
		printf(
		BHWHT"1."RESET" Ingresar 1er operando (A=" BHYEL "X" RESET ")\n");
	}

	if (flagY)
	{
		printf(
		BHWHT"2."RESET" Ingresar 2do operando (B=" BHGRN "%d" RESET ")\n", *y);
	}
	else
	{
		printf(HWHT"2."RESET" Ingresar 2do operando (B=" BHYEL "Y" RESET ")\n");
	}

	printf(BHWHT"3."RESET" Calcular todas las " BHMAG "operaciones\n" RESET);
	printf("  a) Calcular la suma (A" BHMAG "+" RESET "B)\n");
	printf("  b) Calcular la resta (A" BHMAG "-" RESET "B)\n");
	printf("  c) Calcular la division (A" BHMAG "/" RESET "B)\n");
	printf("  d) Calcular la multiplicacion (A" BHMAG "*" RESET "B)\n");
	printf("  e) Calcular el factorial (A"BHMAG"!"RESET")\n");
	printf(BHWHT"4."RESET" Informar resultados\n");
	printf(BHWHT"5."RESET" Salir\n");
	option = getInt("Ingrese opcion:");

	return option;
}

void calcular(int *primNum, int *segNum, int *resultSum, int *resultRes,
		float *resultMult, float *resultDiv, unsigned long long *resultFactPrim,
		unsigned long long *resultFactSeg, int *flagPrimNum, int *flagSegNum,
		int *validDiv, int *flagFactPrim, int *flagFactSeg)
{
	if (*flagPrimNum && *flagSegNum)
	{
		*resultSum = sum(*primNum, *segNum);
		*resultRes = res(*primNum, *segNum);
		*resultMult = mult(*primNum, *segNum);
		if (*segNum != 0)
		{
			*resultDiv = division(*primNum, *segNum);
			activarFlag(validDiv);
		}
		else
		{

			printf(
					BHRED "Segundo operando invalido para realizar division.. " BHYEL "No debe ser 0\n" RESET);
			resetFlag(validDiv);
		}
		if (*primNum < 0 || *primNum > MAX_INT_FACT)
		{
			printf(
					BHRED "Valor invalido para sacar factorial del primer operando. " BHYEL "No debe ser negativo ni debe ser mayor a %d\n" RESET,
					MAX_INT_FACT);
			resetFlag(flagFactPrim);
		}
		else
		{
			*resultFactPrim = factorial(*primNum);
			activarFlag(flagFactPrim);
		}
		if (*segNum < 0 || *segNum > MAX_INT_FACT)
		{
			printf(
					BHRED "Valor invalido para sacar factorial del segundo operando. "BHYEL "No debe ser negativo ni debe ser mayor a %d\n" RESET,
					MAX_INT_FACT);
			resetFlag(flagFactSeg);
		}
		else
		{
			*resultFactSeg = factorial(*segNum);
			activarFlag(flagFactSeg);
		}
		if (*validDiv && *flagFactSeg && *flagFactPrim)
		{ //Se deja el mensaje visible para el usuario durante un segundo y medio
			printf(
			BHGRN "Todas las operaciones se realizaron satisfactoriamente\n");
		}

	}
	else
	{
		printf(
				BHYEL "No puede realizar todas las operaciones si no ingresa ambos operandos\n" RESET);
	}
	printf("---------------------------------------\n");
	printf(BHWHT"Presione enter para continuar...\n"RESET);
	fflush(stdin);
	getchar();
}

void mostrar(int *resultSum, int *resultRes, float *resultDiv,
		float *resultMult, unsigned long long *resultFactPrim,
		unsigned long long *resultFactSeg, int *flagPrimNum, int *flagSegNum,
		int *validDiv, int *flagFactPrim, int *flagFactSeg)
{
	if (*flagPrimNum && *flagSegNum)
	{
		printf("El resultado de A" BHMAG "+"RESET"B es %d\n", *resultSum);
		printf("El resultado de A"BHMAG"-"RESET"B es %d\n", *resultRes);
		if (*validDiv)
		{
			printf("El resultado de A"BHMAG"/"RESET"B es %.2f\n", *resultDiv);
		}
		else
		{
			printf(
					BHRED "ERROR. " RESET "Segundo operando invalido para realizar division. " BHYEL "No debe ser 0\n" RESET);
		}

		printf("El resultado de A"BHMAG"*"RESET"B es %.2f\n", *resultMult);
		if (*flagFactPrim)
		{
			printf("El factorial de A es: %I64d ", *resultFactPrim);
		}
		else
		{
			printf(
					BHRED "ERROR. " RESET "No se pudo calcular el factorial de A. " BHYEL "No debe ser 0 ni mayor que %d\n" RESET,
					MAX_INT_FACT);
		}

		if (*flagFactSeg)
		{
			printf("y El factorial de B es: %I64d\n", *resultFactSeg);
		}
		else
		{
			printf(
					BHRED "ERROR. " RESET "No se pudo calcular el factorial de B. " BHYEL "No debe ser 0 ni mayor que %d\n" RESET,
					MAX_INT_FACT);
		}
	}
	else
	{
		printf(BHRED "Ingrese ambos operandos para calcular\n" RESET);
	}
	printf("---------------------------------------\n");
	printf(BHWHT"Presione enter para continuar...\n"RESET);
	fflush(stdin);
	getchar();

}
