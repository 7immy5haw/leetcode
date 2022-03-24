#include <iostream>
#include <vector>

using namespace std;

class NumMatrix {
public:
  vector<vector<int>> sum;
  NumMatrix(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = m == 0 ? 0 : matrix[0].size();
    sum.resize(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= m; ++i) {
      for (int j = 1; j <= n; ++j) {
        sum[i][j] = sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1] + matrix[i - 1][j - 1];
      }
    }
  }
  
  int sumRegion(int row1, int col1, int row2, int col2) {
    ++row1; ++col1; ++row2; ++col2;
    return sum[row1 - 1][col1 - 1] + sum[row2][col2] - sum[row1 - 1][col2] - sum[row2][col1 - 1];
  }
};

void test1() {
  vector<vector<int>> matrix = {{3,0,1,4,2}, {5,6,3,2,1}, {1,2,0,1,5}, {4,1,0,1,7}, {1,0,3,0,5}};
  NumMatrix* obj = new NumMatrix(matrix);
  int ans = obj->sumRegion(1, 2, 2, 4);
  cout << ans << endl;
  return;
}

int main() {
  test1();
  return 0;
}