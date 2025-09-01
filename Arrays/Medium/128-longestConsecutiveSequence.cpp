#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

//Brute Force
// int longestConsecutive(vector<int>& nums) {
//     int n = nums.size();
//     if(n == 0) return 0;
//     int longest = 1;

//     for(int i = 0; i < n; i++) {
//         int currentNum = nums[i];
//         int count = 1;

//         while(true) {
//             bool found = false;
//             for(int j = 0; j < n; j++) {
//                 if(nums[j] == currentNum + 1) {
//                     found = true;
//                     currentNum++;
//                     count++;
//                     break;
//                 }
//             }
//             if(!found) break;
//         }
//         longest = max(longest, count);
//     }
//     return longest;
// }

//Better
    // int longestConsecutive(vector<int>& nums) {
    //     int n = nums.size();
    //     if (n == 0)
    //         return 0;
    //     int longest = 1;

    //     sort(nums.begin(), nums.end());
    //     int count=1;
    //     for(int i=0;i<n-1;i++){
    //         if(nums[i]+1==nums[i+1]){
    //             count++;
    //         }
    //         else if(nums[i]==nums[i+1]) continue;
    //         else count = 1;
    //         longest = max(longest, count);    
    //     }

    //     return longest;
    // }

//Optimal
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return 0;
        int longest = 1;

        unordered_set<int> st;
        for(int ele: nums) st.insert(ele);

        for(int ele: st){
            int count = 1;
            if(st.find(ele-1)==st.end()){
                int currentElement = ele;
                while(st.find(currentElement+1)!=st.end()){
                    count++;
                    currentElement++;
                }
            }
            longest = max(count, longest);
        }

        return longest;
    }

int main() {
    vector<int> v = {100, 4, 200, 1, 3, 2};
    cout << longestConsecutive(v);
}
