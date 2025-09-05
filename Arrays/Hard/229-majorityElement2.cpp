#include <iostream>
#include <algorithm>
#include <vector>
#include<climits>
#include <unordered_map>
using namespace std;

void display(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

// Brute: nested iteration and manual count: nearby O(n^2)

// Better
//  vector<int> majorityElement(vector<int>& nums) {
//      int n = nums.size();
//      unordered_map<int, int> mp;
//      vector<int> ans;
//      for(int i=0;i<n;i++){
//          mp[nums[i]]++;
//          if(mp[nums[i]]==(n/3)+1) ans.push_back(nums[i]);
//      }
//      return ans;
//  }

// Optimal
vector<int> majorityElement(vector<int> &nums)
{
    int n = nums.size();
    vector<int> ans;
    int ele1 = INT_MIN, ele2 = INT_MIN, count1 = 0, count2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (count1 == 0 and ele2 != nums[i])
        {
            ele1 = nums[i];
            count1++;
        }
        else if (count2 == 0 and ele1 != nums[i])
        {
            ele2 = nums[i];
            count2++;
        }
        else if (ele1 == nums[i])
            count1++;
        else if (ele2 == nums[i])
            count2++;
        else
        {
            count1--, count2--;
        }
    }
    count1 = 0, count2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == ele1)
            count1++;
        if (nums[i] == ele2)
            count2++;
    }
    if (count1 > n / 3)
        ans.push_back(ele1);
    if (count2 > n / 3)
        ans.push_back(ele2);
    return ans;
}

int main()
{
    vector<int> v = {3,2,3};
    display(v);
    vector<int> ans = majorityElement(v);
    display(ans);
}