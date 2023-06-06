#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure:
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/

void Left(TreeNode<int> * root, vector<int> & ans){
    TreeNode<int> *curr=root->left;
    while(curr){
        if(curr->right || curr->left) ans.push_back(curr->data);
        if(curr->left){
            curr=curr->left;

        }
        else{
            curr=curr->right;
        }
    }
}
void Right(TreeNode<int> * root, vector<int> & ans){
    TreeNode<int> *curr=root->right;
    vector<int> my;
    while(curr){
        if(curr->right || curr->left) my.push_back(curr->data);
        if(curr->right){
            curr=curr->right;

        }
        else{
            curr=curr->left;
        }
    }
    for(int i=my.size()-1;i>=0;i--){
        ans.push_back(my[i]);
    }
}
void leaves(TreeNode<int> * root, vector<int> & ans){
    if(root==NULL){
        return ;
    }
    if(!root->left && !root->right){
        ans.push_back(root->data);
        return ;
    }
    leaves(root->left,ans);
    leaves(root->right,ans);
}
vector<int> traverseBoundary(TreeNode<int>* root){
    // Write your code here.
    vector<int> ans;
    if(root==NULL){
        return {};
    }
    if(root->left || root->right) ans.push_back(root->data);
    Left(root,ans);
    leaves(root,ans);
    Right(root,ans);
    return ans;

}