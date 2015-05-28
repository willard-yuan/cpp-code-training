/*Time Limit Exceeded*/
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if (int(nums.size())==0 || int(nums.size())==1)
            return false;
        for(int i=0;i<int(nums.size());i++){
            for(int j=i+1;j<int(nums.size());j++){
                if(nums[i] == nums[j]){
                    return true;
                }
            }
        }
        return false;
    }
};
