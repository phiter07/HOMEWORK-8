#include <iostream> 
#include <string> 
#include <sstream> 
#include <vector>

using namespace std;

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