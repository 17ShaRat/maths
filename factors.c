#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>
#define ulint unsigned long long int
struct node
{
	ulint data;
	struct node * next;
};

struct node *head = NULL;
int STACK_SIZE = 0;
void push(ulint val)
{
	struct node *new_node = (struct node *) malloc(sizeof(struct node));
	new_node->data = val;
	new_node->next = head;
	head = new_node;
	STACK_SIZE++;
}

void pop()
{
	if (head == NULL)
		return;
	struct node *tmp = head;
	head = head->next;
	free(tmp);
	STACK_SIZE--;
}

long long top()
{
	if (!head)
		return -1;
	return head->data;
}

void clear()
{
	struct node *ptr, *tmp;
	ptr = head;
	while (ptr)
	{
		tmp = ptr->next;
		free(ptr);
		ptr = tmp;
	}

	head = NULL;
}

_Bool empty()
{
	return !STACK_SIZE;
}

void print_divisors(ulint num)
{
	ulint root = sqrt(num);
	for (ulint i = 1; i <= root; i++)
	{
		if (num % i == 0)
		{
			printf("%llu ", i);
			push(num / i);
		}
	}

	if (root *root == num)
		pop();
	while (!empty())
	{
		printf("%llu ", top());
		pop();
	}

	clear();

}

int main()
{
	ulint num;
	scanf("%llu", &num);
	print_divisors(num);
	printf("\n");

	return 0;
}
