#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
    int m = img.size(), n = img[0].size();
    vector<vector<int>> ret(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        int num = 0, sum = 0;
        for (int x = i - 1; x <= i + 1; x++) {
          for (int y = j - 1; y <= j + 1; y++) {
            if (x >= 0 && x < m && y >= 0 && y < n) {
              num++;
              sum += img[x][y];
            }
          }
        }
        ret[i][j] = sum / num;
      }
    }
    return ret;
  }
};

void test1() {
  vector<vector<int>> img = {{100, 200, 100}, {200, 50, 200}, {100, 200, 100}};
  Solution solu;
  vector<vector<int>> ret = solu.imageSmoother(img);
  for (int i = 0; i < ret.size(); ++i) {
    for (int j = 0; j < ret[0].size(); ++j) {
      cout << ret[i][j] << " ";
    }
    cout << endl;
  }
  return;
}

void test2() {
  vector<vector<int>> img = {{2,3,4},{5,6,7},{8,9,10},{11,12,13},{14,15,16}};
  Solution solu;
  vector<vector<int>> ret = solu.imageSmoother(img);
  for (int i = 0; i < ret.size(); ++i) {
    for (int j = 0; j < ret[0].size(); ++j) {
      cout << ret[i][j] << " ";
    }
    cout << endl;
  }
  return;
}

int main() {
  test1();
  test2();
  return 0;
}