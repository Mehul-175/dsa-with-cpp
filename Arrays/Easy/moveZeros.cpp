#include<iostream>
#include<algorithm>
using namespace std;

void display(int arr[], int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}

void moveZeroes(int nums[],int n) {
        int j=-1;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                j=i;
                break;
            }
        }
        if(j==-1) return;
        for(int i=j+1;i<n;i++){
            if(nums[i]!=0){
                swap(nums[i],nums[j]);
                j++;
            }
        }
    }

int main(){
    int arr[] = {1,0,3,0,5,6,0,8,9};
    int size = sizeof(arr)/sizeof(arr[0]);
    display(arr, size);
    moveZeroes(arr, size);
    display(arr, size);

}