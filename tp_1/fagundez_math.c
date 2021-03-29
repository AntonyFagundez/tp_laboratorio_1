#include "fagundez_math.h"

int sum(int firstNum, int secNumb)
{
    return firstNum + secNumb;
}

int res(int firstNum, int secNumb)
{
    return firstNum - secNumb;
}

float mult(int firstNum, int secNumb)
{
    return (float)firstNum * secNumb;
}

float division(int firstNum, int secNumb)
{
    return ((float)firstNum)/secNumb;
}

long long int factorial(int num)
{
  if (num == 0) // Base case
    return 1;
  else
    return (num*factorial(num-1));
}
