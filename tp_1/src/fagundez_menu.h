/*
 * fagundez_menu.h
 *
 *  Created on: 17 abr. 2021
 *      Author: Antony
 */

#ifndef FAGUNDEZ_MENU_H_
#define FAGUNDEZ_MENU_H_

/** \brief Funcion para mostrar menu y guardar valores en las direcciones de memoria
 *
 * @param primNum direccion de memoria de primer numero
 * @param segNum direccion de memoria de segundo numero
 * @param flagPrimNum flag del primer numero
 * @param flagSegNum flag de segundo numero
 * @return char con las opciones del switch
 *
 */
int menu(int*primNum, int*segNum, int flagPrimNum, int flagSegNum);


/** \brief Funcion para calcular todos los valores, guardar en sus direcciones de memoria respectivas y mostrar mensajes de error si corresponde
 *
 * @param primNum direccion de memoria de primer numero
 * @param segNum direccion de memoria de segundo numero
 * @param resultSum direccion de memoria de resultado suma
 * @param resultRes direccion de memoria de resultado resta
 * @param resultMult direccion de memoria de  resultado multiplicacion
 * @param resultDiv direccion de memoria de resultado division
 * @param resultFactPrim direccion de memoria de resultado factorial primer numero
 * @param resultFactSeg direccion de memoria de  resultado factorial segundo numero
 * @param flagPrimNum direccion de memoria de flag si existe el primer numero
 * @param flagSegNum direccion de memoria de flag si existe el segundo numero
 * @param validDiv direccion de memoria de flag de division valida
 * @param flagFactPrim direccion de memoria de flag de factorial del primer numero valido
 * @param flagFactSeg direccion de memoria de flag de factorial del segundo numero valido
 *
 */
void calcular(int *primNum, int *segNum, int *resultSum, int *resultRes,
		float *resultMult, float *resultDiv, unsigned long long *resultFactPrim,
		unsigned long long *resultFactSeg, int *flagPrimNum, int *flagSegNum,
		int *validDiv, int *flagFactPrim, int *flagFactSeg);



/** \brief Funcion para mostrar todos los valores y/o errores si corresponde
 *
 * @param resultSum direccion de memoria de resultado suma
 * @param resultRes direccion de memoria de resultado resta
 * @param resultMult direccion de memoria de  resultado multiplicacion
 * @param resultDiv direccion de memoria de resultado division
 * @param resultFactPrim direccion de memoria de resultado factorial primer numero
 * @param resultFactSeg direccion de memoria de  resultado factorial segundo numero
 * @param flagPrimNum direccion de memoria de flag si existe el primer numero
 * @param flagSegNum direccion de memoria de flag si existe el segundo numero
 * @param validDiv direccion de memoria de flag de division valida
 * @param flagFactPrim direccion de memoria de flag de factorial del primer numero valido
 * @param flagFactSeg direccion de memoria de flag de factorial del segundo numero valido
 *
 */
void mostrar(int *resultSum, int *resultRes, float *resultDiv,
		float *resultMult, unsigned long long *resultFactPrim,
		unsigned long long *resultFactSeg, int *flagPrimNum, int *flagSegNum,
		int *validDiv, int *flagFactPrim, int *flagFactSeg);


#endif /* FAGUNDEZ_MENU_H_ */
