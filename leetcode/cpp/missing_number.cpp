/*一个长度为n-1的递增排序数组中的所有数字都是唯一的，并且每个数字都在范围0～n-1之内。在范围0～n-1内的n个数字中有且只有一个数字不在该数组中，请找出这个数字。
示例

输入: [0,1,3]
输出: 2
示例 2:

输入: [0,1,2,3,4,5,6,7,9]
输出: 8

解题思路：有序，说明可以采用二分
*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        int mid = 0;
        while (left <= right) {
            mid = (left + right) / 2;
            if (mid == nums[mid]) {
                left = mid + 1;  // 说明左半部分是完全一样的，不一样的部分在右半部分
            } else {
                right = mid - 1;
            }
        }
        return left;
    }
};

