#include<bits/stdc++.h>
using namespace std;

void merge(int low,int high,int mid,int arr[]){
    vector<int>temp;
    int l=low,r=mid+1;
    while(l<=mid && r<=high){
        if(arr[l]<=arr[r]){
            temp.push_back(arr[l]);
            l++;
        }
        else{
            temp.push_back(arr[r]);
            r++;
        }
    }
    while(l<=mid){
        temp.push_back(arr[l]);
        l++;
    }
    while(r<=high){
        temp.push_back(arr[r]);
        r++;
    }
    for(int i=low;i<=high;i++){
        arr[i]=temp[i-low];
    }
}

void mergeSort(int low,int high,int arr[]){
    if(low>=high){
        return;
    }
    int mid=(low+high)/2;
    mergeSort(low,mid,arr);
    mergeSort(mid+1,high,arr);
    merge(low,high,mid,arr);
}

int main () {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    mergeSort(0,n-1,arr);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
