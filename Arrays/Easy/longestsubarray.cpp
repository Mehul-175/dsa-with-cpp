#include <iostream>
#include <algorithm>
#include <vector>
#include<map>
#include<unordered_map>
using namespace std;

void display(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}


// int longestSubarray(vector<int>& nums, int k) {
//     int n = nums.size();
//     int longest=0;

//     for(int i=0;i<n-1;i++){
//         int sum=nums[i];
//         int currentLongest=0;
//         for(int j=i+1;j<n;j++){
//             if(sum==k){
//                 currentLongest=j-i;
//             }
//             sum+=nums[j];
//         }
//         if(currentLongest>longest) longest=currentLongest;
//     }

//     return longest;
// }

int longestSubarray(vector<int>& nums, int k) {
    int n = nums.size();
    unordered_map<int, int> prefixMap;
    int sum=0;
    int maxLen=0;
    for(int i=0;i<n;i++){
        sum+=nums[i];
        if(sum==k) maxLen = i+1;
        int rem = sum - k;
        if(prefixMap.find(rem)!=prefixMap.end()){
            int len = i - prefixMap[rem];
            maxLen = max(maxLen, len);
        }
        if(prefixMap.find(sum)==prefixMap.end()){
            prefixMap[sum] = i;
        }
    }
    return maxLen;
}

int main()
{
    vector<int> v = {1, 2, 3};
    display(v);
    cout<<"The longest subarray is : "<<longestSubarray(v, 7);
}