#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;



void display(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

/*
Problem Statement: Given an array A of positive integers, identify and return all the "leaders" present in the array. An element A[i] is considered a leader if it is strictly greater than all the elements to its right in the array. The rightmost element of the array is always considered a leader by definition, as there are no elements to its right. 
*/

//Brute force
// vector<int> leaders(vector<int>& nums){
//     int n = nums.size();
//     if(n==0 or n==1) return nums;
//     vector<int> ans;
//     for(int i=0;i<n-1;i++){
//         bool leader = true;
//         for(int j=i+1;j<n;j++){
//             if(nums[j]>nums[i]){
//                 leader=false;
//                 break;
//             }
//         }
//         if(leader) ans.push_back(nums[i]);
//     }
//     ans.push_back(nums[n-1]);
//     return ans;
// }


//Optimal
vector<int> leaders(vector<int>& nums){
    int n = nums.size();
    if(n==0 or n==1) return nums;
    vector<int> ans;
    ans.push_back(nums[n-1]);

    int currentMax = nums[n-1];
    for(int i=n-2;i>=0;i--){
        if(nums[i]>currentMax){
            ans.push_back(nums[i]);
            currentMax = nums[i];
        }
    }
    reverse(ans.begin(), ans.end());

    return ans;
}

int main()
{
    vector<int> v = {16, 17, 4, 3, 5, 2};
    display(v);
    vector<int> ans = leaders(v);
    display(ans);
}