#include <iostream> 
#include <string> 
#include <sstream> 
#include <vector>

using namespace std;

struct Node 
{ 
    int data; 
    Node* left;
    Node* right; 
}; 
  
Node* newNode(int data) 
{ 
    Node* node = (Node*)malloc(sizeof(Node)); 
    node->data = data; 
    node->left = node->right = NULL; 
    return node; 
} 
  
Node* insertLevelOrder(vector<int>& arr, Node* root, int i, int n) { 
    // Base case for recursion 
    if (i < n) 
    { 
        Node* temp = newNode(arr[i]); 
        root = temp; 
  
        // insert left child 
        root->left = insertLevelOrder(arr, root->left, 2 * i + 1, n); 
  
        // insert right child 
        root->right = insertLevelOrder(arr, root->right, 2 * i + 2, n); 
    } 
    return root; 
} 
  
void inOrder(Node* root) 
{ 
    if (root != NULL) { 
        inOrder(root->left); 
        cout << root->data <<" "; 
        inOrder(root->right); 
    } 
}

int isBSTUtil(Node* t, int min, int max)  {  
	if (t == nullptr) {
    return 1;
  }
		 
		// cout<< "this is min1 " << min << endl;
    // cout << "this is max1 " << max << endl;
    // cout << "t->data1 " << t->data <<endl;

	if (t->data < min || t->data > max){
    // cout<< "this is min " << min << endl;
    // cout << "this is max " << max << endl;
    // cout << "t->data " << t->data << endl;
    return 0;
  } 
		 
	
	return isBSTUtil(t->left, min, t->data - 1) && isBSTUtil(t->right, t->data + 1, max); 
}  

int isBST(Node* t, vector<int>& arr)  {  
    
    double smallest = arr[0] ;
    for ( int i=1;  i < arr.size();  i++ ){
        if ( arr[i] < smallest ){
            smallest = arr[i];
        }
             
    }
    //cout << "min = "<< smallest << '\n' ;
    double largest = arr[0] ;
    for ( int i=1;  i < arr.size();  i++ ){
        if ( arr[i] > largest ){
          largest = arr[i] ;
        }
             
    }
    //cout << "min = "<< largest << '\n' ;
      int min = smallest;
      int max = largest;
    
    return(isBSTUtil(t, min, max));  
}  
  

int main() 
{ 
  string mystr;
  int tmp; 
  //cout << "What are the numbers" << endl;
  getline (cin, mystr);

  stringstream str_strm(mystr);
  vector<int> myvect; 
  while (str_strm >> tmp) {
      myvect.push_back(tmp);
  }
  //int n = sizeof(myvect)/sizeof(myvect[0]); 
  int n = myvect.size();

  Node *root;
  for(int i = 0; i < myvect.size(); i++){
    root = insertLevelOrder(myvect, root, 0, n); 
  }

  //inOrder(root);
  //cout << endl;

  if(isBST(root, myvect))  
        cout<<"True";  
    else
        cout<<"False"; 

} 


/*
bool validbst(int arr[],int n) {
        for(int i=0;i<n;i++) {
            int l= 2*i+1;   // left child
            int r = 2*i+2;  //right child
        if(l<n){
          if(arr[l]>arr[i])//if left child greater then root then return false
            return false;
        }     
         if( r<n ){
             if(arr[r]<arr[i])//if right child less then root return flase
                return false;
        }}
        return true;
    }


int main(){
	
	 int arr[]={2,4,5};
	 int n= sizeof(arr) / sizeof(arr[0]);
        cout<<validbst(arr,n);
}
*/