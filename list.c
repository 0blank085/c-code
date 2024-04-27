#include <stdio.h>
#include <stdlib.h>
int main()
{
  int arr[10], *p, i;
  p = arr;
  for (i = 0; i < 10; i++)
  {
    scanf("%d", &arr[i]);
  }
  for (i = 0; i < 10; i++)
  {
    printf("%d ", *(p + i));
  }
  printf("\n");
  system("pause");
  return 0;
}