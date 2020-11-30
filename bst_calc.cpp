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
int a=0;
	if(root->left==NULL)
	return root->data;
	else a=mini(root->left);
  return a;
}
int maxi(Node* root){
int a=0;
	if(root->right==NULL)
	return root->data;
	else a= maxi(root->right);
  return a;
}



int main () {
  Node* root = NULL;

  int sum=0;
  int arr[] = {10,5,15,2,7,11,25,1};
  int size = sizeof(arr) / sizeof(arr[0]);

  for(int i = 0; i < size; i++) {
     std::cout<<arr[i]<<" ";
    root = addNode(root, arr[i]);
 	sum=sum+arr[i];
  }
   std::cout<<endl;
  float avg=(float)sum/size;
std::cout << "min="<<mini(root)<<endl<<"max="<<maxi(root)<<endl<<"AVG="<<avg;
}