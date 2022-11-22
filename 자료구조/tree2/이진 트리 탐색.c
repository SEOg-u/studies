// 이진 트리 탐색(삽입)
#include <stdio.h>
#include <stdlib.h>

typedef struct Treenode {
	int data;
	struct Treenode* left, * right;
} Treenode;

Treenode* new_node(int key)
{
	struct Treenode* new = (struct Treenode*)malloc(sizeof(struct Treenode));
	new->data = key;
	new->left = new->right = NULL;

	return new;
}
Treenode* insert(Treenode* node, int key)
{
	if (node == NULL) {
		return new_node(key);
	}

	if (node->data > key) {
		node->left = insert(node->left, key);
	}
	else if (node->data < key) {
		node->right = insert(node->right, key);
	}

	return node;
}

int main() {
	Treenode* root = NULL;

	root = insert(root, 30);
	root = insert(root, 20);
	root = insert(root, 10);
	root = insert(root, 40);
	root = insert(root, 60);
	root = insert(root, 50);

	printf("루트 노드는 %d\n", root->data);
	printf("루트의 오른쪽 자식의 오른쪽 자식은 %d\n", root->right->right->data);

	return 0;
}
