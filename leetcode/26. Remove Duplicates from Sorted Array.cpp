class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty())return 0;
        int k = 1;
        for(int x : nums){
            if(x != nums[k - 1]){
                nums[k++] = x;
            }
        }
        return k;
    }
};