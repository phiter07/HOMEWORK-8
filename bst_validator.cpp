#include<iostream>
#include <sstream>
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
  for(int i = 0; i < 1000; i++)
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
      std::cout<<"True";
    else 
      std::cout<<"False";
}
