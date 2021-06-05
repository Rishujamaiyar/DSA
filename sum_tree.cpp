#include <bits/stdc++.h>
using namespace std;

struct node{
	int data;
	node* left;
	node* right;
};

struct node* new_node(int x){
	node* temp = new node();
	temp->data=x;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

void inorder(node* root){
	if(root==NULL)
		return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}

int func(node* root){
	if(root==NULL){
		return 0 ;
	}
	int temp = root->data;
	root->data = func(root->left)+func(root->right);
	return temp+root->data;
}
int main(){
node *root1 = new_node(1);            /*         1          */                      
    root1->left = new_node(3);            /*       /   \        */
    root1->right = new_node(2);           /*      3     2       */ 
    root1->right->left = new_node(5);     /*          /   \     */  
    root1->right->right = new_node(4);    /*         5     4    */
      
    // 2nd binary tree formation     
    node *root2 = new_node(1);            /*         1          */                      
    root2->left = new_node(2);            /*       /   \        */
    root2->right = new_node(3);           /*      2     3       */
    root2->left->left = new_node(5);      /*    /   \           */
    root2->left->left->left = new_node(4);

    inorder(root1);
    cout<<endl;
    int x = func(root1);
    cout<<x<<endl;
    inorder(root1); 
}