#include<stdio.h>
#include<stdlib.h>

//representation 
typedef int BData;
typedef struct _bTreeNode {
	BData item;
	struct _bTreeNode* left_child;
	struct _bTreeNode* right_child;
} BTreeNode;

BTreeNode* CreateNode(BData item) {
	BTreeNode* node = (BTreeNode*)malloc(sizeof(BTreeNode));//노드 생성
	//초기화
	node->item = item;
	node->left_child = NULL;
	node->right_child = NULL;
}

void DestroyNode(BTreeNode* node) {
	free(node);
}

void CreateLeftSubtree(BTreeNode* root, BTreeNode* left) {
	if (root->left_child != NULL)//이미 존재한다면 
		exit(1);
	root->left_child = left;
}

void CreateRightSubtree(BTreeNode* root, BTreeNode* right) {
	if (root->right_child != NULL)//이미 존재한다면 
		exit(1);
	root->right_child = right;
}

int Nodes(BTreeNode* node) {
	int r = 0, l = 0;
	if (node->right_child != NULL)
		r = Nodes(node->right_child);
	if (node->left_child != NULL)
		l = Nodes(node->left_child);

	return 1 + r + l;
}
int Height(BTreeNode* node) {
	int r = 0, l = 0;
	if (node->right_child != NULL)
		r = Height(node->right_child);
	if (node->left_child != NULL)
		l = Height(node->left_child);
}
