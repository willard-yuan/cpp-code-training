#include <map>
#include <vector>

using namespace std;

/*直接遍历方法
  时间复杂度太高O(n^2)
  提交不能AC，时间溢出
*/
class Solution {
 public:
  bool containsDuplicate(vector<int>& nums) {
    if (int(nums.size()) == 0 || int(nums.size()) == 1) return false;
    for (int i = 0; i < int(nums.size()); i++) {
      for (int j = i + 1; j < int(nums.size()); j++) {
        if (nums[i] == nums[j]) {
          return true;
        }
      }
    }
    return false;
  }
};

/*采用哈希表
  时间复杂度O(n)
  基于哈希表的unordered_set，参考资料
  1：http://www.zhihu.com/question/26078588
  2：http://blog.csdn.net/u013195320/article/details/23046305
*/
class Solution1 {
 public:
  bool containsDuplicate(vector<int>& nums) {
    if (int(nums.size()) == 0 || int(nums.size()) == 1) return false;
    std::unordered_set<int> set0(nums.begin(), nums.end());
    if (nums.size() == set0.size())
      return false;
    else
      return true;
  }
};
