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

// vector<int> intersectionOfArrays(vector<int> &a, vector<int> &b)
// {   
//     int m = a.size();
//     int n = b.size();
//     vector<int> visited(n, 0);
//     vector<int> ans;
//     for(int i=0;i<m;i++){
//         int j=0;
//         while(j<n){
//             if(b[j]>a[i]) break;
//             if(a[i]==b[j] and visited[j]==0){
//                 ans.push_back(a[i]);
//                 visited[j]++;
//                 break;
//             }
//             j++;
//         }
//     }

//     return ans;
// }

vector<int> intersectionOfArrays(vector<int> &a, vector<int> &b)
{   
    int m = a.size();
    int n = b.size();
    vector<int> ans;
    int i=0,j=0;

    while(i<m and j<n){
        if(a[i]==b[j]){
            ans.push_back(a[i]);
            i++,j++;
        }
        else if(b[j]<a[i]) j++;
        else if(b[j]>a[i]) i++;
    }
    
    return ans;
}

int main()
{
    vector<int> v1 = {2,2,4,4,5,8,8,9};
    vector<int> v2 = {1,2,2,2,2,2,3,4,5,7,8};
    vector<int> ans = intersectionOfArrays(v1,v2);
    display(v1);
    display(v2);
    display(ans);
}