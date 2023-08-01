#include<stdio.h>
#include"sharedfile.h"

void CheckPrime(int iNo)
{
    int iCnt = 0;
  if (iNo <= 1) 
  {
    printf("%d is not a prime number.\n", iNo);
    return;
  }

    for (iCnt = 2; iCnt * iCnt <= iNo; iCnt++) {
        if (iNo % iCnt == 0) {
            printf("%d is not a prime number.\n", iNo);
            return;
        }
    }

    printf("%d is a PRIME number.\n", iNo);
}