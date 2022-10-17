class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maximumPossible = 0;
        for(int i=0;i<nums.size() && maximumPossible >= i;++i){
            maximumPossible = max(maximumPossible, i+nums[i]);
        }
        return maximumPossible >= nums.size()-1;
    }
};