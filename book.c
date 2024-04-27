#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
typedef int DataType;
typedef struct book
{
  int no;
  float t;
  char name[20];
  struct book *next;
} ListNode;
typedef ListNode *LinkList;
// 1.存入模块
LinkList CreativeNode(void)
{
  int i, j, no;
  float t;
  char name[20];
  ListNode *p, *r;
  LinkList head;
  head = (ListNode *)malloc(sizeof(ListNode));
  r = head;
  printf("请输入要存入书的种类数目:");
  scanf("%d", &i);
  for (j = 0; j < i; j++)
  {
    p = (ListNode *)malloc(sizeof(ListNode));
    printf("请输入书的编号:");
    scanf("%d", &no);
    printf("请输入书名:");
    scanf("%s", &name);
    printf("请输入书的单价:");
    scanf("%f", &t);
    p->no = no;
    strcpy(p->name, name);
    p->t = t;
    r->next = p;
    r = p;
  }
  r->next = NULL;
  return head;
}
// 2.根据第i个位置查找图书
LinkList GetNode(LinkList head, int i)
{
  ListNode *r;
  int j = 0;
  r = head;
  while (j < i)
  {
    r = r->next;
    j++;
  }
  if (j == i)
  {
    return r;
  }
  else
  {
    printf("输入位置不合法!");
    return NULL;
  }
}
// 3.根据书的编号查找图书
LinkList NumNode(LinkList head, int x)
{
  ListNode *r;
  r = head;
  while (r->no != x)
  {
    r = r->next;
  }
  if (r->no == x)
  {
    return r;
  }
  else
  {
    printf("输入的编号不存在！");
    return NULL;
  }
}
int main()
{
  int i, j, k;
  LinkList Head, r;
  printf("欢迎使用图书管理系统!\n");
  printf("请根据您的需要进行操作（输入1则为存入，2为根据位置查询图书数据，3为根据编号查询书的数据，若输入1~3以外的数字则为退出系统。）\n");
  printf("请输入操作(若您为第一次进行操作则请选择输入操作!):");
  scanf("%d", &i);
  while (i != 1)
  {
    if (i == 1)
    {
      break;
    }
    else
    {
      printf("输入有误，请重新输入:");
      scanf("%d", &i);
    }
  }
  while (i > 0 && i < 4)
  {
    switch (i)
    {
    case 1:
      Head = CreativeNode();
      break;
    case 2:
      printf("请输入需查询的位置:");
      scanf("%d", &j);
      r = GetNode(Head, j);
      printf("您查询到的数据为:编号为 %d，书名为 %s，单价为 %.2f。\n", r->no, r->name, r->t);
      break;
    case 3:
      printf("请输入书的编号:");
      scanf("%d", &k);
      r = NumNode(Head, k);
      printf("您查询到的数据为:编号为 %d，书名为 %s，单价为 %.2f。\n", r->no, r->name, r->t);
      break;
    default:
      break;
    }
    printf("请输入操作:");
    scanf("%d", &i);
  }
  printf("已退出系统!");
  system("pause");
  return 0;
}
