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
void display2(const vector<vector<int>>& res) {
     for (const auto &row : res)
    {
        cout<<"{ ";
        for (int ele : row)
            cout << ele << " ";
        cout << "} ";
    }
}

// Brute: three nested loops

//Better
    // vector<vector<int>> threeSum(vector<int>& nums) {
    //     int n = nums.size();
    //     set<vector<int>> st;
    //     for (int i = 0; i < n - 2; i++) {
    //         unordered_set<int> st2;
    //         st2.insert(nums[i+1]);
    //         for (int j = i + 2; j < n; j++) {
    //             int rem = -1*(nums[i]+nums[j]);
    //             if(st2.find(rem)!=st2.end()){
    //                 vector<int> temp = {nums[i], nums[j], rem};
    //                 sort(temp.begin(), temp.end());
    //                 st.insert(temp);
    //             }
    //             st2.insert(nums[j]);
    //         }
    //     }

    //     vector<vector<int>> ans(st.begin(), st.end());
    //     return ans;
    // }

//Optimal
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int i = 0, j = 1, k = n - 1;
        while (i < n - 2) {
            int sum = nums[i] + nums[j] + nums[k];
            if (sum == 0) {
                ans.push_back({nums[i], nums[j], nums[k]});
                j++, k--;
                while (j < k && nums[j] == nums[j - 1]) j++;
                while (j < k && nums[k] == nums[k + 1]) k--;
            } else if (sum < 0) {
                j++;
            } else {
                k--;
            }
            if (j >= k) {
                i++;
                while (i < n - 2 && nums[i] == nums[i - 1]) i++;
                j = i + 1, k = n - 1;
            }
        }
        return ans;
    }


int main() {
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    cout<<"Intput array:\n";
    display(nums);
    vector<vector<int>> result = threeSum(nums);
    cout<<"Answer:\n";
    display2(result);
    return 0;
}