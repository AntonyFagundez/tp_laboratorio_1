/*
 * fagundez_utils.h
 *
 *  Created on: 17 abr. 2021
 *      Author: Antony
 */

#ifndef FAGUNDEZ_UTILS_H_
#define FAGUNDEZ_UTILS_H_

/** \brief Funcion obtener un caracter
 *
 * @param Texto a mostrar a usuario
 *
 * @returns char con el valor obtenido
 *
 */
char getChar(char*);

/** \brief Funcion obtener un numero, comprueba que la mascara de printf reconzca el numero.
 *
 * @param Texto a mostrar a usuario
 *
 * @returns char con el valor obtenido
 *
 */
int getInt(char *texto);

/** \brief para activar "flag". Modifica el valor con la direccion de memoria pasada
 *
 * @param direccion de memoria con el flag (se espera inicializado en falso)
 *
 */
void activarFlag(int *pflag);

/** \brief para activar "flag". Modifica el valor con la direccion de memoria pasada
 *
 * @param direccion de memoria con el flag se vuelve a 0.
 *
 */
void resetFlag(int *pflag);

#endif /* FAGUNDEZ_UTILS_H_ */
