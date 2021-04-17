/*
 * fagundez_utils.c
 *
 *  Created on: 17 abr. 2021
 *      Author: Antony
 */
#include <stdio.h>
#include "fagundez_utils.h"
#include "fagundez_colors.h"


char getChar(char *texto)
{
	char result;


	printf(texto);
	fflush(stdin);
    scanf("%c", &result);

	return result;
}

int getInt(char *texto)
{
	int success = 0;
	int result;

	printf(texto);
	fflush(stdin);
	success = scanf("%d", &result);
	while (!success)
	{
		printf( BHRED "ERROR." RESET "Debe ingresar digitos\n");
		printf(texto);
		fflush(stdin);
		success = scanf("%d", &result);
	}

	return result;
}

void activarFlag(int *pflag)
{
	*pflag = 1;
}
void resetFlag(int *pflag)
{
	*pflag = 0;
}


