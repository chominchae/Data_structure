#include"BTreeNode.h"
#include "Queue.h"

//LCR
void Inorder(BTreeNode* root) {
	if (root != NULL) {
		Inorder(root->left_child);//L
		printf("%d", root->item);
		Inorder(root->right_child);//R
	}
}

//CLR
void Preorder(BTreeNode* root) {
	if (root != NULL) {
		printf("%d", root->item);//C
		Inorder(root->left_child);//L
		Inorder(root->right_child);//R
	}
}

//LRC
void Postorder(BTreeNode* root) {
	if (root != NULL) {
		printf("%d", root->item);//L
		Inorder(root->left_child);//R
		Inorder(root->right_child);//C
	}
}

void Levelorder(BTreeNode* root) {
	Queue queue;
	if (root == NULL) exit(1);
	InitQueue(&queue);
	EnQueue(&queue, root);//루트 노트 EnQueue

	while (!IsEmpty(&queue))
	{
		root = Peek(&queue);
		DeQueue(&queue);

		printf("%d ", root->item);
		if (root->left_child != NULL)
			EnQueue(&queue, root->left_child);
		if (root->right_child != NULL)
			EnQueue(&queue, root->left_child);
	}
}

int CalDirectorySize(BTreeNode* root) {
	int left_size, right_size;
	if (root == NULL) return 0;
	else {
		left_size = CalDirectorySize(root->left_child);
		right_size = CalDirectorySize(root->right_child);
		return (root->item + left_size + right_size);
	}
}
