#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void display(const vector<vector<int>> &matrix)
{
    for (const auto &row : matrix)
    {
        for (int ele : row)
            cout << ele << " ";
        cout << "\n";
    }
}

void displayVector(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}


//Optimal
vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> ans;
    if (matrix.empty()) return ans;

    int top = 0, bottom = matrix.size() - 1;
    int left = 0, right = matrix[0].size() - 1;

    while (top <= bottom && left <= right) {
        for (int j = left; j <= right; j++)
            ans.push_back(matrix[top][j]);
        top++;

        for (int i = top; i <= bottom; i++)
            ans.push_back(matrix[i][right]);
        right--;

        if (top <= bottom) {
            for (int j = right; j >= left; j--)
                ans.push_back(matrix[bottom][j]);
            bottom--;
        }

        if (left <= right) {
            for (int i = bottom; i >= top; i--)
                ans.push_back(matrix[i][left]);
            left++;
        }
    }

    return ans;
}

int main()
{
    vector<vector<int>> mat = {
        {1, 2, 3},
        {4, 0, 6},
        {7, 8, 9}};

    cout << "Original matrix:\n";
    display(mat);

    vector<int> Spiral = spiralOrder(mat);

    cout<<"Matrix Printed in spiral:\n";
    displayVector(Spiral);

    return 0;
}
