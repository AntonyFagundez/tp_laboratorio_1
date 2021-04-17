/*
 ============================================================================
 Name        : tp_1.c
 Author      : Antony Fagundez
 Version     : 1.0
 Copyright   : MIT
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "fagundez_menu.h"
#include "fagundez_utils.h"
#include "fagundez_colors.h"

#define ING_PRIM_OPER 1
#define ING_SEG_OPER 2
#define CALCULAR 3
#define MOSTRAR 4
#define SALIR 5

int main(void)
{
	setbuf(stdout, NULL);
	int primNum;
	int segNum;
	int flagFactPrim;
	int flagFactSeg;
	int flagPrimNum;
	int flagSegNum;
	int validDiv;

	int resultSum;
	int resultRes;
	float resultMult;
	float resultDiv;
	unsigned long long resultFactPrim;
	unsigned long long resultFactSeg;

	char resp;
	char conf;

	flagFactPrim = 0;
	flagFactSeg = 0;
	flagPrimNum = 0;
	flagSegNum = 0;
	validDiv = 0;

	resp = 's';

	do
	{
		switch (menu(&primNum, &segNum, flagPrimNum, flagSegNum))
		{
		case ING_PRIM_OPER:
			primNum = getInt("Ingrese primer operando: ");
			activarFlag(&flagPrimNum);
			break;
		case ING_SEG_OPER:
			segNum = getInt("Ingrese segundo operando: ");
			activarFlag(&flagSegNum);
			break;
		case CALCULAR:
			calcular(&primNum, &segNum, &resultSum, &resultRes, &resultMult,
					&resultDiv, &resultFactPrim, &resultFactSeg, &flagPrimNum,
					&flagSegNum, &validDiv, &flagFactPrim, &flagFactSeg);
			break;
		case MOSTRAR:
			mostrar(&resultSum, &resultRes, &resultDiv, &resultMult,
					&resultFactPrim, &resultFactSeg, &flagPrimNum, &flagSegNum,
					&validDiv, &flagFactPrim, &flagFactSeg);
			break;
		case SALIR:
			conf = getChar(BHYEL"Desea Salir?"RESET"(s/"BHWHT"n"RESET")\n");
			resp = conf == 's' ? 'n' : 's';
			break;

		}
	} while (resp == 's');

	return EXIT_SUCCESS;
}
