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

unsigned long long factorial(int num)
{
  unsigned long long res;
  if (num == 0)
  {// Base case
      res =  1;
  }
  else
  {
    res = (num*factorial(num-1));
  }

  return res;
}
