#include <iostream>

using namespace std;

bool validbst(int arr[], int n) {
  for (int i=0; i<n; i++) {
    int l= 2*i+1;// left chile
    int r = 2*i+2;//right child
  
  if(l<n) {
    if(arr[l]>arr[i])
    return false;
  }
  if(r<n) {
    if(arr[r]<arr[i])
    return false;
  }
  }
  return true;
}

int main(){
  int arr[]={2,4,5};
  //int arr[]={10,5,15,3,8,12,25};

  int n= sizeof(arr) / sizeof(arr[0]);
  
  for(int i = 0; i < n; i++) {
    std::cout<<arr[i]<<" ";
  }

  std::cout<<endl;
  int chk=validbst(arr,n);
  if(chk==1)
  std::cout<<"True";
  else
  std::cout<<"False";
}
