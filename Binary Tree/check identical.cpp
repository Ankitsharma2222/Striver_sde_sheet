#include <bits/stdc++.h> 
/**********************************************************

    Following is the Binary Tree Node class structure:

    template <typename T>

    class BinaryTreeNode {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;
		
        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

***********************************************************/

bool identicalTrees(BinaryTreeNode<int>* p, BinaryTreeNode<int>* q) {
    // Write your code here. 
        if(p==NULL && q==NULL){
            return true;
        }
        if(p==NULL && q !=NULL || q==NULL &&  p!=NULL){
            return false;
        }
        if(p->data != q->data){
            return false;
        }

        return identicalTrees(p->left,q->left) && identicalTrees(p->right ,q->right);    	 
}