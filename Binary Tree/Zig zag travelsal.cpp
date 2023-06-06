#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode
    {
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

*************************************************************/

vector<int> zigZagTraversal(BinaryTreeNode<int> *root){
    // Write your code here!
        queue<BinaryTreeNode<int> *>q;
        if(root==NULL){
            return {};
        } 
        q.push(root);
        vector<int > ans;
        bool flag=true;
        while(q.size()){
            int size=q.size();
            stack<int> st;
            for(int i=0;i<size;i++){
                auto a=q.front();
                q.pop();
                if(flag){
                    ans.push_back(a->data);
                }
                else{
                    st.push(a->data);
                }
                if(a->left){
                    q.push(a->left);
                }
                if(a->right){
                    q.push(a->right);
                }
            }
            while(st.size()){
                ans.push_back(st.top());
                st.pop();
            }
            flag=!flag;
        }
        return ans;
    
}
