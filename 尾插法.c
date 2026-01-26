#include<stdio.h>
#include<stdlib.h>
struct node {
	int data;
	struct node* next;
};
struct node* head = NULL;
struct node* tail = NULL;
creat(int x)
{
	struct node* temp = (struct node*)malloc(sizeof(struct node));

	temp->data = x;
	temp->next = NULL;

	if (head == NULL)
	{
		head = temp;
		tail = temp;
	}
	else
	{
		tail->next = temp;
		tail = temp;
	}

}

int main()
{
	int n, x;
	printf("链表结点个数:");
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		printf("第%d个结点数据:", i + 1);
		scanf("%d", &x);
		creat(x);
	}
	struct node* p = head;
	while (p != NULL)
	{
		printf("%d->", p->data);
		p = p->next;
	}
	printf("NULL");
	p = head;
	while (p != NULL)
	{
		struct node* temp = (struct node*)malloc(sizeof(struct node));
		temp = p->next;
		free(p);
	    p = temp;
	}
	head = NULL;
	tail = NULL;
}