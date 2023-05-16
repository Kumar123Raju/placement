// isme hum first wale ko pick karte hai aur usko swap karte hai jo uske baad minimum hoga..
// simple: starting me sabse minimum ko swap karte hai aur i ko increase krte hai(ye first se sort hote jata hai )

//Time complexity o(n^2) and spacce complexity 0(1) 


#include<bits/stdc++.h>
using namespace std;
void  swap(int arr[],int i,int j){
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;

}
void selectionSort(int n,int arr[]){
   
    for(int i=0; i<n; i++){
        int minimum=i;
        
        for(int j=i; j<n; j++){
          if(arr[minimum]>arr[j]) minimum=j;
        }
        swap(arr,i,minimum);
    }

}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    selectionSort(n,arr);
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;

}
