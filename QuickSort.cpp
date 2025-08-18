#include<bits/stdc++.h>
using namespace std;

int partition(int low,int high,int arr[]){
    int pivot=arr[low],i=low+1,j=high;
    while(i<=j){
        while(i<=high &&arr[i]<=pivot){
            i++;
        }
        while(j>=low+1 && arr[j]>pivot){
            j--;
        }
        if(i<j){
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[low],arr[j]);
    return j;
}

void quickSort(int low,int high,int arr[]){
    if(low>=high){
        return;
    }
    int p=partition(low,high,arr);
    quickSort(low,p-1,arr);
    quickSort(p+1,high,arr);

}


int main () {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    quickSort(0,n-1,arr);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
