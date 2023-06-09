// by love babbar 

#include<bits/stdc++.h>
using namespace std;
// partion function
int partion(int arr[],int s,int e){
        int pivot=arr[s];
        int count=0;
  
//   pahle count kar lenge kitna pivot se chota element hai
        for(int i=s+1; i<=e; i++){
                if(arr[i]<pivot) count++;
        }
//   pivot ka sahi index find kar lenge by adding just count 
        int pivotindex=s+count;
// pivot ko sahi place me rakh denge by 
        swap(arr[s],arr[pivotindex]);
        int i=s;
        int j=e;
//   jo left side me pivot se bada hoga usko swap karenge jo right side me pivot se chota hoga..
        while(i<pivotindex && j>pivotindex){
          
//           find karenge ke left side me kon bada hai pivot se hai....
                while(arr[i]<pivot){
                   i++;
                }
//           find karenge ke right side me kon chota hai pivot se..
                while(arr[j]>pivot){
                   j--;
                }
       //   swap karege ......
          
                if(i<pivotindex && j>pivotindex)
                    swap(arr[i],arr[j]);
        }
//   return kar denge pivotindex
        return pivotindex;

        
}
// recursive function for quicksort
void quickSort(int arr[],int s,int e){
        // base case 
        if(s>=e) return ;

        // partion hoga jo v index ayega wahan se;
        int p=partion(arr,s,e);

        // recrsion call for left partion
        quickSort(arr,s,p);
        // recurison call for right partionin
        quickSort(arr,p+1,e);
}

int main(){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++){
                cin>>arr[i];
        }
        quickSort(arr,0,n-1);
        for(int i=0; i<n; i++){
                cout<<arr[i]<<" ";
        }
        

}
