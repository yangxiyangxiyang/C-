#include<stdlib.h>
#include<malloc.h>
#include<assert.h>
#include<stdio.h>
#define STACK_TYPE int
#define FALSE 0

int is_empty(void);
int is_full(void);
void pop(void);


/*
**����һ���ṹ�Դ����ջԪ�أ�����link�ֶν�ָ���ջ����һ��Ԫ�ء�
*/
typedef struct STACK_NODE
{
	STACK_TYPE value;
	struct STACK_NODE *next;
}   StackNode ;

/*
**ָ���ջ�е�һ���ڵ��ָ�롣
*/
struct STACK_NODE *stack;

void craete_stack(size_t size)
{
}

void destory_stack(void)
{
	while(!is_empty());
	pop();
}

void push(STACK_TYPE value)
{
	StackNode *new_node;

	new_node=(StackNode*)malloc(sizeof(StackNode));
	assert(new_node!=NULL);
	new_node->value=value;
	new_node->next=stack;
	stack=new_node;
}

void pop(void)
{
	StackNode *first_node;

	assert(!is_empty());
	first_node=stack;
	stack=first_node->next;
	free(first_node);
}

STACK_TYPE top(void)
{
	assert(!is_empty());
	return stack->value;
}

int is_empty(void)
{
	return stack==NULL;
}
int is_full(void)
{
	return FALSE;
}
	

