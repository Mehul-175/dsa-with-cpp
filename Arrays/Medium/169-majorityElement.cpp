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

// int majorityElement(vector<int> &nums){
//     int n=nums.size();
//     unordered_map<int, int> mp;
//     for(int ele: nums){
//         mp[ele]++;
//         if(mp[ele]>n/2) return ele;
//     }
//     return -1;
// }

int majorityElement(vector<int> &nums){
    int n=nums.size();
    int count=0;
        int ele=0;
        for(int i=0;i<n;i++){
            if(count==0){
                ele=nums[i];
                count++;
            }
            else{
                if(nums[i]==ele) count++;
                else count--;
            }
        }
        return ele;
}

int main()
{
    vector<int> v = {2,2,1,1,1,2,2};
    display(v);
    cout<<"The majority element is: "<<majorityElement(v);
}