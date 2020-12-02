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
int lca(Node* root, int n1, int n2)  
{  
    if (root == NULL) return -1;  
  
    // If both n1 and n2 are smaller 
    // than root, then LCA lies in left  
    if (root->data > n1 && root->data > n2)  
        return lca(root->left, n1, n2);  
  
    // If both n1 and n2 are greater than  
    // root, then LCA lies in right  
    if (root->data < n1 && root->data < n2)  
        return lca(root->right, n1, n2);  
  
    return root->data;  
}  


int main () {
  Node* root = NULL;

 
 string line;int enterNumber;
getline(cin, line);
istringstream iss(line);
while (iss >> enterNumber)
{
   
     root = addNode(root, (int)enterNumber);
     	
}
 
 	int n1,n2;
 	cin>>n1;
   cin>>n2;
 std::cout<<"lca ="<<lca(root,n1,n2);	
  
}