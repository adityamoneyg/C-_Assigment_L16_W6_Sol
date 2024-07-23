#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

void setZeroes(vector<vector<int>>& matrix) {
    if (matrix.empty()) return;

    int rows = matrix.size();
    int cols = matrix[0].size();
    
    unordered_set<int> zero_rows;
    unordered_set<int> zero_cols;

    // First pass: find all zeroes
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (matrix[i][j] == 0) {
                zero_rows.insert(i);
                zero_cols.insert(j);
            }
        }
    }

    // Second pass: set zeroes
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (zero_rows.find(i) != zero_rows.end() || zero_cols.find(j) != zero_cols.end()) {
                matrix[i][j] = 0;
            }
        }
    }
}

int main() {
    vector<vector<int>> matrix = {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}
    };

    setZeroes(matrix);

    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
