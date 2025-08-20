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

// int missingNumber(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> flag(n+1, 0);
//         for(int i=0;i<n;i++){
//             flag[nums[i]]++;
//         }
//         for(int i=0;i<n+1;i++){
//             if(flag[i]==0) return i;
//         }
//         return -1;
//     }

// int missingNumber(vector<int>& nums) {
//         int n = nums.size();
//         sort(nums.begin(), nums.end());
//         for(int i=0;i<n;i++){
//             if(nums[i]!=i) return i;
//         }
//         return n;
//     }


// int missingNumber(vector<int>& nums){
//     int n = nums.size();
//     int sum=0;
//     for(int i=0;i<n;i++){
//         sum+=nums[i];
//     }
//     return (n*(n+1))/2-sum;
// }

int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int xor1=n,xor2=0;
        for(int i=0;i<n;i++){
            xor1^=i;
            xor2^=nums[i];
        }
        return xor1^xor2;
    }

int main()
{
    vector<int> v = {0,1,2,3,4,5,6,7};
    display(v);
    cout<<"The missing number is : "<<missingNumber(v);
}