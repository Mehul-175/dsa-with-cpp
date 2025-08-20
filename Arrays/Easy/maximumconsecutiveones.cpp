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

int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int maxones = 0;
        for(int i=0;i<n;i++){
            int currentMax=0;
            if(nums[i]==0) continue;
            while(i<n and nums[i]!=0){
                currentMax++;
                i++;
            }
            if(currentMax>maxones) maxones=currentMax;
        }
        return maxones;
    }


int main()
{
    vector<int> v = {0,1,1,1,0,0,0,1,1,0,1,1,1,1,1,1};
    display(v);
    cout<<"The max consicutive number of ones are : "<<findMaxConsecutiveOnes(v);
}