// 给你一个正整数 n ，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的 n x n 正方形矩阵 matrix 。

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int> > generateMatrix(int n) {
    vector<vector<int> > res(n, vector<int>(n));
    int i = 1, left = 0, up = 0, right = n - 1, down = n - 1;
    while (i <= n * n) {
      for (int j = left; j <= right && i <= n * n; j++) res[up][j] = i++;
      up++;
      for (int j = up; j <= down && i <= n * n; j++) res[j][right] = i++;
      right--;
      for (int j = right; j >= left && i <= n * n; j--) res[down][j] = i++;
      down--;
      for (int j = down; j >= up && i <= n * n; j--) res[j][left] = i++;
      left++;
    }
    return res;
  }
};

int main() {
  Solution solution = Solution();
  vector<vector<int> > res = solution.generateMatrix(3);
  for (int i = 0; i < res.size(); ++i) {
    std::cout << "[";
    for (int j = 0; j < res[i].size() - 1; ++j) {
      std::cout << res[i][j] << ", ";
    }
    std::cout << res[i][res[i].size() - 1];
    std::cout << "]" << std::endl;
  }
  return 0;
}