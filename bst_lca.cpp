#include <iostream> 
#include <string> 
#include <sstream> 
#include <vector>

using namespace std;

class BST {
    
    struct node {
        int data;
        node* left;
        node* right;
    };

    node* root;

    node* insert(int x, node* t)
    {
        if(t == NULL)
        {
            t = new node;
            t->data = x;
            t->left = t->right = NULL;
        }
        else if(x < t->data)
            t->left = insert(x, t->left);
        else if(x > t->data)
            t->right = insert(x, t->right);
        return t;
    }

    void inorder(node* t) {
      if(t == NULL)
            return;
        inorder(t->left);
        cout << t->data << " ";
        inorder(t->right);
    }
    node* LCA(node* root, int n1, int n2) {
      if (root == NULL){
        return NULL;
    }
      
      if (root->data > n1 && root->data > n2){
        return LCA(root->left, n1, n2);
    }
      
      if (root->data< n1 && root->data < n2){
        return LCA(root->right, n1, n2);
    }
      
    return root;
}


public:
    BST() {
        root = NULL;
    }

    void insert(int x) {
        root = insert(x, root);
    }

    void display() {
        inorder(root);
        cout << endl;
    }
    void lowestcommon(int n1, int n2){
      root = LCA(root, n1, n2);
      cout << "lca = " << root->data;
    }

};

int main() 
{ 
  BST t;
  string mystr;
  double n1, n2;
  int tmp; 
  
  getline (cin, mystr);
  cin >> n1;
  cin >> n2;

  stringstream str_strm(mystr);
  vector<int> myvect; 
  while (str_strm >> tmp) {
      myvect.push_back(tmp);
  }
  
  for(int i =0; i < myvect.size(); i++){
    t.insert(myvect[i]);
  }
  t.lowestcommon(n1, n2);
	 
} 