#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "BTreeNode.h"

#define MAX_STACK 	200
typedef BTreeNode* Data;

typedef struct {
	Data items[MAX_STACK];
	int top;
} Stack;

//초기화
void InitStack(Stack* pstack){
	pstack->top = -1;
}
bool IsFull(Stack* pstack) {
	return pstack->top == MAX_STACK - 1;
}

bool IsEmpty(Stack* pstack) {
	return pstack->top == -1;
}

Data Peek(Stack* pstack) {
	if (IsEmpty(pstack))
		exit(1);
	return pstack->items[pstack->top];
}

void Push(Stack* pstack, Data item) {
	if (IsFull(pstack))
		exit(1);
	pstack->items[++(pstack->top)] = item;
}

void Pop(Stack* pstack) {
	if (IsEmpty(pstack))
		exit(1);
	--(pstack->top);//top의 인덱스를 하나 낮추기
}
