#include<iostream>
#include<climits>
using namespace std;

// int secondLargestElement(int arr[], int n){
//     int largest = INT_MIN;
//     for(int i=0;i<n;i++){
//         if(arr[i]>largest){
//             largest = arr[i];
//         }
//     }
//     int secondLargest = INT_MIN;
//     for(int i=0;i<n;i++){
//         if(arr[i]>secondLargest and arr[i]!=largest){
//             secondLargest = arr[i];
//         }
//     }

//     return secondLargest;
// }

int secondLargestElement(int arr[], int n){
    int largest = INT_MIN;
    int secondLargest = INT_MIN;
    for(int i=0;i<n;i++){
        if(arr[i]>largest){
            secondLargest = largest;
            largest = arr[i];
        }
        else if(arr[i]>secondLargest and arr[i]!=largest){
            secondLargest = arr[i];
        }
    }
    return secondLargest;
}

int main(){
    int arr[] = {1,2,5,3,6,2,10,18,2,7,1,3};
    int size = sizeof(arr)/sizeof(arr[0]);

    int element = secondLargestElement(arr, size);
    cout<<element;
}