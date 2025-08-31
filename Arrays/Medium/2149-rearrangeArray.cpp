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

// vector<int> rearrangeArray(vector<int> &nums)
// {
//     vector<int> pos;
//     vector<int> neg;
//     for (int i = 0; i < nums.size(); i++)
//     {
//         if (nums[i] > 0)
//         {
//             pos.push_back(nums[i]);
//         }
//         else
//             neg.push_back(nums[i]);
//     }
//     int k = 0, l = 0;
//     for (int i = 0, j = 1; i < nums.size(); j += 2, i += 2)
//     {
//         nums[i] = pos[k++];
//         nums[j] = neg[l++];
//     }
//     return nums;
// }

// vector<int> rearrangeArray(vector<int> &nums)
// {
//     int n = nums.size();
//     vector<int> ans(n);
//     int pos = 0, neg = 1;
//     for (int i = 0; i < n; i++)
//     {
//         if (nums[i] > 0)
//         {
//             ans[pos] = nums[i];
//             pos += 2;
//         }
//         else
//         {
//             ans[neg] = nums[i];
//             neg += 2;
//         }
//     }

//     return ans;
// }

// IN CASE IF POSITIVES != NEGATIVES

vector<int> rearrangeArray(vector<int> &nums)
{
    vector<int> pos, neg;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] > 0)
        {
            pos.push_back(nums[i]);
        }
        else
            neg.push_back(nums[i]);
    }
    if (pos.size() > neg.size())
    {
        for (int i = 0; i < neg.size(); i++)
        {
            nums[i * 2] = pos[i];
            nums[(i * 2) + 1] = neg[i];
        }
        int index = neg.size() * 2;
        for (int i = neg.size(); i < pos.size(); i++)
        {
            nums[index++] = pos[i];
        }
    }
    else
    {
        for (int i = 0; i < pos.size(); i++)
        {
            nums[i * 2] = pos[i];
            nums[(i * 2) + 1] = neg[i];
        }
        int index = pos.size() * 2;
        for (int i = pos.size(); i < neg.size(); i++)
        {
            nums[index++] = neg[i];
        }
    }
    return nums;
}

int main()
{
    vector<int> v = {3, 1, 2, 8, -1, 5, -2, -5, 2, -4};
    display(v);
    vector<int> ans = rearrangeArray(v);
    display(ans);
}