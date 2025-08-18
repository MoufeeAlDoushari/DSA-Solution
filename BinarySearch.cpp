#include<bits/stdc++.h>
using namespace std;

int binarySreach(int arr[],int n,int t){
    long long low=0,high=n-1,mid;

    while(high>=low){
        mid=(low+high)/2;
        if(arr[mid]==t){
            return mid;
        }
        else if(arr[mid]>t){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return -1;
}



int main (){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<< binarySreach(arr,n,3) ;

}

