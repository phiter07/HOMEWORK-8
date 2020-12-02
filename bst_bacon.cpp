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

bool search(Node* root, int key) 
{ 
    // Base Cases: root is null or key is present at root 
    if (root->data == key) 
       return true; 
     
    // Key is greater than root's key 
    if (root->data < key) 
       return search(root->right, key); 
  
    // Key is smaller than root's key 
    return search(root->left, key);
	return false; 
}
int finddepth(Node* root, int key) 
{ 	cout<<" "<<root->data;
    // Base Cases: root is null or key is present at root 
    if (root->data == key) 
       return 0; 
     
    // Key is greater than root's key 
    if (root->data < key) 
       return 1+finddepth(root->right, key); 
  
    // Key is smaller than root's key 
    return 1+ finddepth(root->left, key);
	 
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
   int data;
   cin>>data;
 	if(search(root,data)){
     int depth=finddepth(root,data);
 		std::cout<<endl<<"dept="<<depth;
	 }
   else
   {
std::cout<<"node not available in tree";

   }
  
}