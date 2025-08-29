#include <iostream>
#include <algorithm>
#include <vector>
#include<map>
#include<unordered_map>
#include<climits>
using namespace std;

void display(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

//  int maxSubArray(vector<int>& nums) {
//         int n=nums.size();
//         if(n==1) return nums[0];
//         int maxSum=0;
//         for(int i=0;i<n;i++){
//             int sum=0;
//             for(int j=i;j<n;j++){
//                 sum+=nums[j];
//                 if(sum>maxSum) maxSum=sum;
//             }
//         }
        
//         return maxSum;
// }

   int maxSubArray(vector<int>& nums) {
        int maxSum=INT_MIN;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            if(sum<0) sum=nums[i];
            else{
                sum+=nums[i];
            }
            maxSum = max(maxSum, sum);
        }
        return maxSum;
    }

int main()
{
    vector<int> v = {2,2,1,1,1,2,2};
    display(v);
    cout<<"The maximum subarray sum is: "<<maxSubArray(v);
}