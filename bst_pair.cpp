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
} int a=0;
bool paircheck(Node* root, int n1)  
{  

    if (root == NULL) return 0;  
  
   
    if(root->left!=NULL){
	
    if (root->data+ root->left->data == n1 ){

		a=1;  }
        else paircheck(root->left, n1);  
}
   
    if(root->right !=NULL){
    if (root->data + root->right->data ==n1 ){
	
	a=1; }
        else paircheck(root->right, n1);  
  
    }
 if(a==1){
 	return true;
 }
 return false;
}


int main () {
   Node* root = NULL;
string line;int enterNumber;
getline(cin, line);
istringstream iss(line);
while (iss >> enterNumber)
{
   
     root = addNode(root, (int) enterNumber);
}
      
 	int n1;
 	cin>>n1;
   
   int a=paircheck(root,n1);
   if(a==1)
 std::cout<<"True";
 else
 	std::cout<<"False";
}