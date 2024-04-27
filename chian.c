#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
// 0.链表的定义
typedef int DataType;
typedef struct node
{
	DataType data;
	struct node *next;
} ListNode;
typedef ListNode *LinkList; // 为啥*号写在 ListNode旁边呢？因为我的目的时定义 LinkList 为存放地址的一个容器，而typedef可以改变名称使 ListNode* === LinkList，方便定义和使用。

// 1. 头插法建表
LinkList CreativeF1(void)
/*建立头插法无节点的单链表*/
{
	int value;
	ListNode *p;					// *p用于指向新结点。
	LinkList head = NULL; // 令头节点的地址为空，方便后面的地址交换。
	printf("请输入数据，若输入为9999则结束输入。\n");
	printf("请输入数据:");
	scanf("%d", &value);
	while (value != 9999)
	{
		p = (ListNode *)malloc(sizeof(ListNode)); // 新建一个结点。
		if (!p)																		// 判断结点是否合理。
		{
			p->data = value;
			p->next = head;
		}
		head = p;
		printf("请输入数据:");
		scanf("%d", &value);
	}
	return head;
}
/*建立头插法有节点的单链表*/
LinkList CreativeF2(void)
{
	int value;
	LinkList head;
	ListNode *p;
	head = (ListNode *)malloc(sizeof(ListNode)); // 初始化一个空链表。
	head->next = NULL;													 // 令头结点内部的指针为空，便于后面的地址交换。
	printf("请输入数据，若输入为9999则结束输入。\n");
	printf("请输入数据:");
	scanf("%d", &value);
	while (value != 9999)
	{
		p = (ListNode *)malloc(sizeof(ListNode)); // 建立一个新结点。
		if (!p)																		// 判断结点建立是否合理。
		{
			p->data = value;
			p->next = head->next;
			head->next = p;
		}
		printf("请输入数据:");
		scanf("%d", &value);
	}
	return head;
}
// 2. 尾节点插入
// 用尾结点插入法插入无头结点的单链表
LinkList CreativeR1(void)
{
	int value;
	LinkList head = NULL;
	ListNode *p, *r;
	r = NULL;
	printf("请输入数据，若输入为9999则结束输入。\n");
	printf("请输入数据:");
	scanf("%d", &value);
	while (value != 9999)
	{
		p = (ListNode *)malloc(sizeof(ListNode));
		if (!p)
		{
			exit(0);
		}
		p->data = value;
		if (head == NULL)
		{
			head = p;
		}
		else
		{
			r->next = p;
		}
		r = p; // 此处意义为用r代替了p，方便后续对p中next的操作，避免了不必要的麻烦。
		printf("请输入数据:");
		scanf("%d", &value);
	}
	if (r != NULL)
	{
		r->next = NULL;
	}
	return head;
}
// 用尾结点插入法插入有头结点的单链表
LinkList CreativeR2(void)
{
	int value;
	LinkList head;
	ListNode *p, *r;
	r = head;
	printf("请输入数据，若输入为9999则结束输入。\n");
	printf("请输入数据:");
	scanf("%d", &value);
	while (value != 9999)
	{
		p = (ListNode *)malloc(sizeof(ListNode));
		if (!p)
		{
			exit(0);
		}
		p->data = value;
		r->next = p;
		r = p;
		printf("请输入数据:");
		scanf("%d", &value);
	}
	r->next = NULL;
	return head;
}
// 3.在i位置插入节点
void InsertList(LinkList head, DataType x, int i) // LinkList 代表链表头部，x 代表要插入的数据，i 代表插入的位置。
{
	int j;
	ListNode *p, *r;
	r = head;
	j = 0;
	while (r->next && j < i - 1)
	{
		r = r->next;
		j++;
	}
	if (j != i - 1)
	{
		printf("插入位置不合法!");
		exit(0);
	}
	p = (ListNode *)malloc(sizeof(ListNode));
	p->data = x;
	p->next = r->next;
	r->next = p;
}
// 4.删除结点
void Delete(LinkList head, int i)
{
	ListNode *r, *p;
	int j = 0;
	r = head;
	p = head->next;
	while (j < i - 1)
	{
		r = r->next;
		p = p->next;
		j++;
	}
	r->next = p->next;
	free(p);
}
// 5. 查找全部结点
void Pt(LinkList head)
{
	ListNode *r = head;
	printf("您目前输入的数据为:");
	while (r->next != NULL)
	{
		r = r->next;
		printf("%d ", r->data);
	}
	printf("\n");
}
// 6. 查找第i个位置的结点数据
LinkList GetNode(LinkList head, int i)
{
	ListNode *r = head;
	int j = 0;
	if (i < 1)
	{
		printf("输入位置不存在!");
		exit(0);
	}
	while (r->next && j < i)
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
		return NULL;
	}
}
int main()
{
	LinkList Head;
	Head = CreativeF1();
	printf("Head的地址为：%d Head中的数据为；%d\n", Head->next, Head->data);
	printf("%d\n", *(Head->next));
	system("pause");
}
