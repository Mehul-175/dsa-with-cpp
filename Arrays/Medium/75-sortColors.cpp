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

// void sortColors(vector<int> &nums){
//     int n = nums.size();
//     int noz=0,noo=0;
//     for(int ele: nums){
//         if(ele==0) noz++;
//         else if(ele==1) noo++;
//     }
//     int i=0;
//     while(noz>0){
//         nums[i]=0;
//         i++, noz--;
//     }
//     while(noo>0){
//         nums[i]=1;
//         i++, noo--;
//     }
//     while(i<n){
//         nums[i]=2;
//         i++;
//     }
// }

void sortColors(vector<int>& nums) {
        int low=0,mid=0,high=nums.size()-1;
        while(mid<=high){
            if(nums[mid]==0){
                swap(nums[mid], nums[low]);
                low++,mid++;
            }
            else if(nums[mid]==1) mid++;
            else {
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }

int main()
{
    vector<int> v = {0, 2, 0, 1, 2, 0, 0, 1, 1};
    display(v);
    sortColors(v);
    display(v);
}