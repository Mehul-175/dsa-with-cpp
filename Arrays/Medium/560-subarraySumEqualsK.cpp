#include <iostream>
#include <algorithm>
#include <vector>
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

//Brute: Iterating every subarray: O(n^2)


//Optimal
int subarraySum(vector<int> &nums, int k)
{
    int n = nums.size();
    unordered_map<int, int> prefixMap;
    int sum = 0;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        sum += nums[i];
        if (sum == k)
            count++;
        int rem = sum - k;
        if (prefixMap.find(rem) != prefixMap.end())
            count += prefixMap[rem];
        prefixMap[sum]++;
    }
    return count;
}

int main()
{
    vector<int> v = {3, 1, 2, 8, -1, 5, -2, -5, 2, -4};
    display(v);
    int k = 5;
    cout << "The numbers of subarray with sum " << k << ": " << subarraySum(v, k);
}