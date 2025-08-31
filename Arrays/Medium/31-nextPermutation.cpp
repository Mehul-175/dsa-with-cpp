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

void nextPermutation(vector<int> &nums)
{
    int n = nums.size();
    int index = -1;
    for (int i = n - 2; i >= 0; i--)
    {
        if (nums[i + 1] > nums[i])
        {
            index = i;
            break;
        }
    }
    if (index == -1)
    {
        reverse(nums.begin(), nums.end());
        return;
    }
    reverse(nums.begin() + index + 1, nums.end());
    for (int i = index + 1; i < n; i++)
    {
        if (nums[i] > nums[index])
        {
            swap(nums[index], nums[i]);
            break;
        }
    }
}

int main()
{
    vector<int> v = {3, 1, 2, 8};
    display(v);
    nextPermutation(v);
    display(v);
}