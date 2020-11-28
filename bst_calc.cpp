#include <iostream>
using namespace std;

struct Node {
  int data;
  Node* left;
  Node* right;
};

Node* CreateNode(int data) {
  Node* new_node = new Node();
  new_node->data = data;     
  new_node->left = NULL;
  new_node->right = NULL;
  return new_node;
}

Node* addNode(Node* root, int data) {
  if(root == NULL){
    root = CreateNode(data);}
  else if(data <= root->data)
    root->left = addNode(root->left, data);
  else root->right = addNode(root->right, data);

  return root;
}
int mini(Node* root){

	if(root->left==NULL)
	return root->data;
	else mini(root->left);
}
int maxi(Node* root){

	if(root->right==NULL)
	return root->data;
	else maxi(root->right);
}

int main () {
  Node* root = NULL;

  int sum=0;
  int arr[] = {10,5,15,2,7,11,25,1};
  int size = sizeof(arr) / sizeof(arr[0]);

  for(int i = 0; i < size; i++) {
    root = addNode(root, arr[i]);
 	sum=sum+arr[i];
  }
  float avg=(float)sum/size;
cout << root->data << std::endl<<mini(root)<<endl<<maxi(root)<<endl<<avg;
}
