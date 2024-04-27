#include <stdio.h>
#include <stdlib.h>
void fun(int *num)
{
  *num = *num * 3;
}
int main()
{
  int i = 9;
  fun(&i);
  printf("%d\n", i);
  system("pause");
}