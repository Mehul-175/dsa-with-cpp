#include <iostream>
#include <vector>
using namespace std;

void display(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int ele : row) cout << ele << " ";
        cout << "\n";
    }
}

//Brute
// void setZeroes(vector<vector<int>>& matrix) {
//     int m = matrix.size();
//     if(m == 0) return;
//     int n = matrix[0].size();

//     for(int i = 0; i < m; i++) {
//         for(int j = 0; j < n; j++) {
//             if(matrix[i][j] == 0) {
//                 // Set all elements in row to zero
//                 for(int k = 0; k < n; k++) {
//                     if(matrix[i][k] != 0) matrix[i][k] = -1; // temporary marker
//                 }
//                 // Set all elements in column to zero
//                 for(int k = 0; k < m; k++) {
//                     if(matrix[k][j] != 0) matrix[k][j] = -1; // temporary marker
//                 }
//             }
//         }
//     }

//     // Replace all temporary markers with 0
//     for(int i = 0; i < m; i++) {
//         for(int j = 0; j < n; j++) {
//             if(matrix[i][j] == -1) matrix[i][j] = 0;
//         }
//     }
// }


//Better
// void setZeroes(vector<vector<int>>& matrix) {
//     int rows = matrix.size();
//     int cols = matrix[0].size();
//     vector<bool> row(rows, false);
//     vector<bool> col(cols, false);

//     for(int i = 0; i < rows; i++){
//         for(int j = 0; j < cols; j++){
//             if(matrix[i][j] == 0){
//                 row[i] = true;
//                 col[j] = true;
//             }
//         }
//     }

//     for(int i = 0; i < rows; i++){
//         for(int j = 0; j < cols; j++){
//             if(row[i] || col[j]) matrix[i][j] = 0;
//         }
//     }
// }


//Optimal
void setZeroes(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    int firstColFlag = 1;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == 0) {
                if (j == 0) {
                    firstColFlag = 0;
                } else {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
    }

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (matrix[i][0] == 0 || matrix[0][j] == 0)
                matrix[i][j] = 0;
        }
    }

    if (matrix[0][0] == 0) {
        for (int j = 0; j < n; j++)
            matrix[0][j] = 0;
    }

    if (firstColFlag == 0) {
        for (int i = 0; i < m; i++)
            matrix[i][0] = 0;
    }
}



int main() {
    vector<vector<int>> mat = {
        {1, 2, 3},
        {4, 0, 6},
        {7, 8, 9}
    };

    cout << "Original matrix:\n";
    display(mat);

    setZeroes(mat);

    cout << "\nMatrix after setZeroes:\n";
    display(mat);

    return 0;
}
