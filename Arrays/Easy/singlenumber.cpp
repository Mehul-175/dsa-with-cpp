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

int singleNumber(vector<int>& nums) {
        int xr=0;
        for(int i=0;i<nums.size();i++){
            xr^=nums[i];
        }
        return xr;
    }


int main()
{
    vector<int> v = {0,2,2,0,1,1,3,5,6,5,6};
    display(v);
    cout<<"The single number is : "<<singleNumber(v);
}