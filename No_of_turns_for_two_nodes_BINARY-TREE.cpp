#include <bits/stdc++.h> 
using namespace std; 

 
struct Node { 
	struct Node* left, *right; 
	int data; 
}; 

Node* newNode(int key) 
{ 
	Node* temp = new Node; 
	temp->data = key; 
	temp->left = temp->right = NULL; 
	return temp; 
} 
 
Node* lca(Node* root,int p,int q){
    if(root==NULL) 
        return NULL;
    
    if(root->data==p || root->data==q)
        return root;
    
    Node* left = lca(root->left,p,q);
    Node* right = lca(root->right,p,q);

    if(left && right) return root;
    
    if(left) return left;
    if(right) return right;
    
    return NULL;
}

bool  dist(Node* root,int p,int turn,bool left,int& count){
    if(root==NULL) return false;
    if(root->data == p)
    	return true;
    
    if(left){
    	if(dist(root->left,p,turn,true,count))
    	return true;
    	if(dist(root->right,p,turn+1,false,count)){
    		count++;
    		return true;
    	}
    	
    }
    else{
    	if(dist(root->right,p,turn,false,count))
    	return true;
    	if(dist(root->left,p,turn+1,true,count)){
    		count++;
    		return true;
    	}
    }

  return false;  
}

int main() 
{ 
	// Let us create binary tree given in the above 
	// example 
	Node* root = newNode(1); 
	root->left = newNode(2); 
	root->right = newNode(3); 
	root->left->left = newNode(4); 
	root->left->right = newNode(5); 
	root->right->left = newNode(6); 
	root->right->right = newNode(7); 
	root->left->left->left = newNode(8); 
	root->right->left->left = newNode(9); 
	root->right->left->right = newNode(10); 

	int first =1;
	int second = 10;

  Node* lca_node = lca(root,first,second);

	
	int count1=0,count2=0;
	
		dist(lca_node->left,first,0,true,count1);
		dist(lca_node->right,first,0,false,count1);
		dist(lca_node->left,second,0,true,count2);
		dist(lca_node->right,second,0,false,count2);

	if(lca_node->data!=first && lca_node->data!=second)
	cout<<(count1+count2+1)<<endl;

	if(count1+count2)
        cout<<count1+count2<<endl;


	

} 
