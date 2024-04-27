#include <stdio.h>
#include <stdlib.h>
void exchange(int *Ix, int *Iy)
{
  int iTemp;
  iTemp = *Ix;
  *Ix = *Iy;
  *Iy = iTemp;
  printf("In main: a = %d,b = %d\n", *Ix, *Iy);
}
int main()
{
  int Num1 = 5, Num2 = 9;
  exchange(&Num1, &Num2);
  system("pause");
  return 0;
}