#include <iostream> 
#include "stdafx.h" 


struct Bin_tree {
	int data;
	Bin_tree *left, *right;
};





Bin_tree* Add(Bin_tree *&tree, int data) {

	if (tree == NULL) {
		Bin_tree *tree = new Bin_tree;
		tree->data = data;
		tree->left = NULL;
		tree->right = NULL;
		return tree;
		
		
	}

	else {

		if (data < tree->data)  {
			if (tree->left != NULL) Add(tree->left, data);
			else {
				tree->left = new Bin_tree;
				tree->left->left = NULL;
				tree->left->right = NULL;
				tree->left->data = data;
			}
		}

			if (data > tree->data)  {
				if (tree->right != NULL) Add(tree->right, data);
				else {
					tree->right = new Bin_tree;
					tree->right->left = NULL;
					tree->right->right = NULL;
					tree->right->data = data;
				}

			}

		}
	
	
}


		void print(Bin_tree *&root) {

			if (root != NULL) {
				print(root->left);
				printf("%d\n", root->data);
				print(root->right);

			}
		}

int main() {
	Bin_tree *root = NULL;
	
	root = Add(root, 5);
	Add(root, 10);
	Add(root, 8);
	Add(root, 7);
	Add(root, 9);
	Add(root, 1);
	Add(root, 3);

	print(root);
	getchar();
	
}

