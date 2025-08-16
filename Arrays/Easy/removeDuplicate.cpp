#include<iostream>
using namespace std;

void display(int arr[], int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

int removeDuplicate(int arr[], int n){
    int i,j;
    for(i=0,j=1;j<n;j++){
        if(arr[j]!=arr[i]){
            arr[i+1]=arr[j];
            i++;
        }
    }
    return i+1;
}

int main(){
    int arr[] = {1,1,1,1,2,2,2,3,3,3,4,4,5,6,6,6,6,6,6,6};
    int size = sizeof(arr)/sizeof(arr[0]);
    display(arr, size);
    int newSize = removeDuplicate(arr, size);
    cout<<"\n"<<newSize<<"\n";
    display(arr, newSize);

}