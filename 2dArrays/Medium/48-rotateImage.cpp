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

// Brute
// void rotate(vector<vector<int>> &matrix)
// {
//     int rows = matrix.size();
//     int cols = matrix[0].size();
//     vector<vector<int>> temp(rows, vector<int>(cols, 0));
//     int row = 0, col = 0;
//     for (int j = cols - 1; j >= 0; j--)
//     {
//         col = 0;
//         for (int i = 0; i < rows; i++)
//         {
//             temp[i][j] = matrix[row][col];
//             col++;
//         }
//         row++;
//     }
//     matrix = temp;
// }


//Optimal
    void rotate(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        for(int i=0;i<rows;i++){
            for(int j=i;j<cols;j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for(int i=0;i<rows;i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }

int main()
{
    vector<vector<int>> mat = {
        {1, 2, 3},
        {4, 0, 6},
        {7, 8, 9}};

    cout << "Original matrix:\n";
    display(mat);

    rotate(mat);

    cout << "\nMatrix after rotation:\n";
    display(mat);

    return 0;
}
