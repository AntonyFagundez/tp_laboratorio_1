#ifndef FAGUNDEZ_MATH_H_INCLUDED
#define FAGUNDEZ_MATH_H_INCLUDED

/** \brief Funcion para realizar suma de dos enteros
 *
 * \param x primer numero
 * \param y segundo numero
 * \return int resultado
 *
 */
int sum(int x, int y);

/** \brief Funcion para realizar resta de dos enteros
 *
 * \param x primer numero
 * \param y segundo numero
 * \return int resultado
 *
 */
int res(int x, int y);

/** \brief Funcion para realizar multiplicacion de dos enteros hace cast para pasar a float
 *
 * \param x primer numero
 * \param y segundo numero
 * \return float resultado float
 *
 */
float mult(int x, int y);

/** \brief Funcion para realizar suma de dos enteros hace cast para pasar a float
 *
 * \param x primer numero
 * \param y segundo numero
 * \return float resultado
 *
 */
float division(int x, int y);

/** \brief Funcion recursiva para obtener el factorial
 *
 * \param x primer numero
 * \return long long int factorial
 *
 */
unsigned long long factorial(int);

#endif // FAGUNDEZ_MATH_H_INCLUDED
