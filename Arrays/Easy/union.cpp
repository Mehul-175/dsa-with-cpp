#include <iostream>
#include <algorithm>
#include <vector>
#include<set>
using namespace std;

void display(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

// vector<int> unionOfArrays(vector<int> &nums1, vector<int> &nums2)
// {   
//     int m = nums1.size();
//     int n = nums2.size();
//     set<int> s;
//     for(int i=0;i<m;i++){
//         s.insert(nums1[i]);
//     }
//     for(int i=0;i<n;i++){
//         s.insert(nums2[i]);
//     }
//     vector<int> ans;
//     for(auto it=s.begin(); it!=s.end(); it++){
//         ans.push_back(*it);
//     }
//     return ans;
// }

vector<int> unionOfArrays(vector<int> &nums1, vector<int> &nums2)
{   
    int m = nums1.size();
    int n = nums2.size();
    vector<int> ans;
    int i=0,j=0;
    while(i<m and j<n){
        if(nums1[i]<=nums2[j]){
            if(ans.empty() or ans[ans.size()-1]!=nums1[i]) ans.push_back(nums1[i]);
            i++;
        } else {
            if(ans.empty() or ans[ans.size()-1]!=nums2[j]) ans.push_back(nums2[j]);
            j++;
        }
    }
    while(i<m){
        if(ans.empty() or ans[ans.size()-1]!=nums1[i]) ans.push_back(nums1[i]);
        i++;
    }
    while(j<n){
        if(ans.empty() or ans[ans.size()-1]!=nums2[j]) ans.push_back(nums2[j]);
        j++;
    }
    return ans;
}

int main()
{
    vector<int> v1 = {};
    vector<int> v2 = {1,2,2,2,2,2,3,4,5,7,8};
    vector<int> ans = unionOfArrays(v1,v2);
    display(v1);
    display(v2);
    display(ans);
}