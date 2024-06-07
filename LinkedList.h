#include<stdlib.h>
#define MAX_LIST 200
#include<stdio.h>


typedef int Data;

typedef struct {
	Data items[MAX_LIST];
	int len;
} ArrayList;

void InitList(ArrayList* plist) {
	plist->len = 0;
}

bool IsEmpty(ArrayList* plist){
	return plist->len == 0;
}

bool IsFull(ArrayList* plist){
	return plist->len == MAX_LIST;
}

void InsertMiddle(ArrayList * plist,int pos,Data item){
	if (IsFull(plist) || pos<0 || pos>plist->len)
		exit(188);
	else 
		for(int i = plist->len-1; i >=pos; i--) {
			plist->items[i + 1] = plist->items[i];
	}
	plist->items[pos] = item;
	
	plist->len++;
}

void RemoveMiddle(ArrayList* plist, int pos){
	if (IsEmpty(plist) || pos<0 || pos>plist->len)
		exit(1);
	else 
		for (int i = pos + 1; i < plist->len; i++)
			plist->items[i] = plist->items[i + 1];
	plist->len--;
}

Data ReadItem(ArrayList* plist, int pos) {
	return plist->items[pos];
}

void PrintList(ArrayList* plist){
	for (int i = 0; i < plist->len; i++)
		printf("items[%d]=%d",i,plist->items[i]);
}

