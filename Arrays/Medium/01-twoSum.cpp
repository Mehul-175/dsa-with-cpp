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

vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for(int i=0;i<n;i++){
            if(mp.find(target-nums[i])!=mp.end()){
                return {mp[target-nums[i]], i};
            }
            mp[nums[i]]=i;
        }
        return {};
    }

int main()
{
    vector<int> v = {3, 1, 2, 1, 0, 9, 10, 4};
    display(v);
    vector<int> ans = twoSum(v, 13);
    display(ans);
}