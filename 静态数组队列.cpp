#include"���нӿ�.cpp"
#include<stdio.h>
#include<assert.h>

#define QUEUE_SIZE 100 /*������Ԫ�ص��������*/
#define ARRAY_SIZE (QUEUE_SIZE+1)/*����ĳ���*/

/*
**���ڴ������Ԫ�ص������ָ�����ͷ��β��ָ�롣
*/
static QUEUE_TYPE queue[ARRAY_SIZE];
static size_t front=1;
static size_t rear=0;

void queue_insert(QUEUE_TYPE value)
{
	assert(!is_full());
	rear=(rear+1)%ARRAY_SIZE;
	queue[rear]=value;
}

void queue_delete(void)
{
	assert(!is_empty());
	front=(front+1)%ARRAY_SIZE;
}

QUEUE_TYPE first(void)
{
	assert(!is_empty());
	return queue[front];
}

int is_empty(void)
{
	return (rear+1)%ARRAY_SIZE==front;
}

int is_full(void)
{
	return (rear+2)%ARRAY_SIZE==front;
}



