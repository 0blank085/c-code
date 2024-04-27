#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
typedef struct node
{
  int i;
  struct node *next;
} LinkList;
typedef LinkList *CLink;
// 创建循环链表
CLink CreateLinkList(int n)
{
  LinkList *p, *head, *r, *s;
  head = (LinkList *)malloc(sizeof(LinkList));
  r = head;
  int i;
  for (i = 1; i <= n; i++)
  {
    p = (LinkList *)malloc(sizeof(LinkList));
    p->i = i;
    r->next = p;
    p->next = head->next;
    r = p;
  }
  s = head->next;
  free(head);
  return s;
}
int main()
{
  int n = 41;
  int m = 3;
  CLink r, p, k;
  r = CreateLinkList(n);
  // 筛选模块
  while (r->next->next != r)
  {
    for (int j = 1; j <= m - 1; j++)
    {
      k = r;
      r = r->next;
      if (j == 2)
      {
        p = r->next;
        k->next = r->next;
        printf("%d->", r->i);
        free(r);
        r = p;
        break;
      }
    }
  }
  printf("\n%d,%d\n", r->i, r->next->i);
  system("pause");
}