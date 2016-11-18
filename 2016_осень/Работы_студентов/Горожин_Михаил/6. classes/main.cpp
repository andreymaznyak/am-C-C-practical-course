
#include <iostream>

class BinaryTreeNode {
public:
  int datum;
  BinaryTreeNode* left;
  BinaryTreeNode* right;

  BinaryTreeNode(int datum){
    this->datum = datum;
    this->left = NULL;
    this->right = NULL;
  }

  void print(){
    if (this->left != NULL)
      this->left->print();
    std::cout << " " << this->datum << " ";
    if (this->right != NULL)
      this->right->print();
  }
};


class BinaryTree {
public:
  BinaryTreeNode* root;
  
  void print(){
    if (this->root == NULL){
      return;
    }

    BinaryTreeNode* rt = this->root;

    rt->print();
    std::cout << std::endl;
  }


  void append(int datum){
    if (this->root == NULL){
      this->root = new BinaryTreeNode(datum);
    }
    
    BinaryTreeNode* rt = this->root;
    while(true){
      if (rt->datum == datum){
	return;
      } else if (rt->datum > datum) {
	if (rt->left != NULL){
	  rt = rt->left;
	} else {
	  rt->left = new BinaryTreeNode(datum);
	  return;
	}
      } else {
	if (rt->right != NULL){
	  rt = rt->right;
	} else {
	  rt->right = new BinaryTreeNode(datum);
	  return;
	}
      }
    }
  }

  BinaryTreeNode* find(int datum){
    BinaryTreeNode* rt = this->root;
    while (rt != NULL){
      if (rt->datum == datum){
	return rt;
      } else if (rt->datum > datum) {
	rt = rt->left;
      } else {
	rt = rt->right;
      }
    }
    return NULL;
  }
  
  void remove(int datum){
    BinaryTreeNode* rt = this->root;
    if (rt == NULL) return;
    BinaryTreeNode* nodeToDelete = this->find(datum);
    if (nodeToDelete == NULL) return;

    BinaryTreeNode* parent = rt;
    
    while (parent != nodeToDelete &&
	   parent->left != nodeToDelete &&
	   parent->right != nodeToDelete){
      if (datum < parent->datum){
	parent = parent->left;
      } else {
	parent = parent->right;
      }
    }

   
    if (nodeToDelete->right == NULL || nodeToDelete->left == NULL){
      BinaryTreeNode* appendee = NULL;
      if (nodeToDelete->right != nodeToDelete->left)
	appendee = (nodeToDelete->right == NULL) ? nodeToDelete->left : nodeToDelete->right;
      if (parent != nodeToDelete){
	(parent->left == nodeToDelete) ? parent->left = appendee : parent->right = appendee;
      } else {
	this->root = appendee;
      }
    } else {
      BinaryTreeNode* prev = nodeToDelete;
      BinaryTreeNode* appendee = nodeToDelete->right;
      
      while (appendee->left != NULL){
	prev = appendee;
	appendee = appendee->left;
      }
      if (parent != nodeToDelete){
	prev->datum = appendee->datum;
      } else {
	(this->root)->datum = appendee->datum;	
      }
      
      (prev->left == appendee) ? prev->left = NULL : prev->right = NULL;    
    }
    return;
  }
};


int main(){
  BinaryTree tree = BinaryTree();
  tree.append(10);
  tree.append(5);
  tree.append(4);
  tree.append(6);
  tree.append(15);
  tree.append(14);
  tree.append(16);
  tree.print();
  tree.remove(10);
  
  tree.print();

}

