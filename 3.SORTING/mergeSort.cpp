#include<bits/stdc++.h>
using namespace std;
// void merge function
void merge(int arr[],int low,int mid,int high){
    int temp[100];
    int i=low;
    int j=mid+1;
    int k=low;
    while(i<=mid && j<=high){
        if(arr[i]<arr[j]){
            temp[k]=arr[i];
            i++;
        }else{
            temp[k]=arr[j];
            j++;
        }
        k++;
    }
    if(i>mid){
        while(j<=high){
            temp[k]=arr[j];
            k++;
            j++;
        }
    }else{
        while(i<=mid){
            temp[k]=arr[i];
            i++;
            k++;
        }
    }
    for(k=1; k<high; k++){
        arr[k]=temp[k];
    }
}

// merge sort using recursion
void mergeSort(int arr[],int low,int high){
    if(low>=high) return ;

    int mid=(low+high)/2;
//   
    mergeSort(arr,low,mid);
    mergeSort(arr,mid+1,high);
    merge(arr,low,mid,high);

}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    mergeSort(arr,0,n-1);
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;

}
