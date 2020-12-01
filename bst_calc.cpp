#include <iostream>
#include <sstream>
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
int mini(Node* root) {
int a=0;
	if(root->left==NULL)
	return root->data;
	else a=mini(root->left);
  return a;
}
int maxi(Node* root) {
int a=0;
	if(root->right==NULL)
	return root->data;
	else a= maxi(root->right);
  return a;
}



int main () {
  Node* root = NULL;

  int sum=0;
  int i=0;
  
  string line;int enterNumber;
  getline(cin, line);
  istringstream iss(line);

  while (iss >> enterNumber) {
     root = addNode(root, (int)enterNumber);
     	sum=sum+ (int)enterNumber;i++;
  }

  float avg=(float)sum/i;

std::cout << "min="<<mini(root)<<endl<<"max="<<maxi(root)<<endl<<"AVG="<<avg;
}