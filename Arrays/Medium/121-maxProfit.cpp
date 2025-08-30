#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_map>
#include <climits>
using namespace std;

void display(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}
int maxProfit(vector<int> &prices)
{
    int maxPro = 0;
    int minPrice = INT_MAX;
    for (int i = 0; i < prices.size(); i++)
    {
        maxPro = max(maxPro, prices[i] - minPrice);
        minPrice = min(minPrice, prices[i]);
    }
    return maxPro;
}

int main()
{
    vector<int> v = {7,1,5,3,6,4};
    display(v);
    cout << "The maximum profit will be: " << maxProfit(v);
}