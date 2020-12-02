#include<iostream>
#include <sstream>
#include <array>
#include <string>
using namespace std;

bool validbst(int arr[],int n) {
  for(int i=0;i<n;i++) {
    int l= 2*i+1;// left chile
    int r = 2*i+2;//right child
    if( l<n) {
      if(arr[l]>arr[i])//if left child greater then root then return false
      return false;
    }       
    if( r<n ) {
      if(arr[r]<arr[i])//if right child less then root return flase
      return false;
    }
  }
    return true;
}

int main() {
	int arr[1000];
    arr[i] = 0;
	int i=0;
  string line;
  int enterNumber;
getline(cin, line);
istringstream iss(line);
while (iss >> enterNumber)
{
    //numbers.push_back(enterNumber);
     arr[i]=(int) enterNumber;
     i++;
}
    int chk=validbst(arr,i);
    if(chk==1)
      cout<<"True";
    else 
      cout<<"False";
}






/*
bool right_child(int tree[], int root, int rightMin, bool validBST) {
  if(tree[2*root] == 0 && tree[2*root+1] == 0) 
    return true;
  
  if (tree[(2*root)] < rightMin)
    return false;

  if (tree[2*root] != 0) {
    if (tree[2*root] < tree[root]) {
      validBST = right_child(tree, (2*root), rightMin, validBST);
    }
    else
    validBST = false;
  }

  if(!validBST)
    return validBST;

  if(tree[(2*root)+1] !=0) 


}
*/

