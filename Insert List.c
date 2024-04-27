#include <stdio.h>
#include <stdlib.h>
#define MaxSize 80
typedef int DataType;
typedef struct
{
  DataType arr[MaxSize];
  int length;
} Sqlist;
typedef Sqlist *List;
// 1. 录入模块
void getElem(List L)
{
  int i, j, n;
  printf("请确定输入几次数据:");
  scanf("%d", &i);
  if (i > MaxSize)
  {
    printf("您输入的次数大于内存上限，输入失败。");
    exit(0);
  }
  if (i < 1)
  {
    printf("输入错误。");
    exit(0);
  }
  for (j = 0; j < i; j++)
  {
    printf("请输入数据:");
    scanf("%d", &n);
    L->arr[j] = n;
  }
  printf("你输入的数据为:");
  for (j = 0; j < i; j++)
  {
    printf("%d ", L->arr[j]);
  }
  printf("\n");
  L->length = i;
}
// 2. 插入模块
void Insert(List L)
{
  int j, timeId, num, i, length = L->length;
  printf("请输入要插入数据的位置:");
  scanf("%d", &i);
  if (i > MaxSize)
  {
    printf("超过上限，内存溢出");
    exit(0);
  }
  if (i < 1)
  {
    printf("输入错误。");
    exit(0);
  }
  for (j = length; j >= i; j--)
  {
    timeId = L->arr[j];
    L->arr[j] = L->arr[j - 1];
    L->arr[j - 1] = timeId;
  }
  printf("请输入要插入的数据:");
  scanf("%d", &num);
  L->arr[i - 1] = num;
  L->length++;
  printf("更新后的数据为:");
  for (j = 0; j < L->length; j++)
  {
    printf("%d ", L->arr[j]);
  }
  printf("\n");
}
// 3.删除模块
void Delete(List L)
{
  int i, j, timeId, length = L->length;
  printf("请输入您要删除的数据位置:");
  scanf("%d", &i);
  if (i > MaxSize)
  {
    printf("超过上限，内存溢出");
    exit(0);
  }
  if (i < 1)
  {
    printf("输入错误。");
    exit(0);
  }
  for (j = i - 1; j < length; j++)
  {
    L->arr[j] = L->arr[j + 1];
  }
  L->length--;
  printf("更新后的数据为:");
  for (j = 0; j < L->length; j++)
  {
    printf("%d ", L->arr[j]);
  }
  printf("\n");
}
// 4. 查找模块
void Seek(List L)
{
  int i;
  printf("请输入您要查找的数据编号(位置):");
  scanf("%d", &i);
  printf("\n");
  printf("您查找的数据为:%d", L->arr[i - 1]);
  printf("\n");
}
int main()
{
  List S;
  getElem(&S);
  Insert(&S);
  Delete(&S);
  Seek(&S);
  system("pause");
}