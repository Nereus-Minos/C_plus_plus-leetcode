class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        //特殊情况，没有三个数
        if(nums.size() < 3)
            return 0;
        //排序
        sort(nums.begin(), nums.end());
        
        int ret = nums[0]+nums[1]+nums[2];
        
        for(int i = 0; i < nums.size()-2; i++)
        {
            for(int j = i+1, k = nums.size()-1; j < k ;)
            {
                if((target) == (nums[i]+nums[j]+nums[k]))
                    return target;
                
                if(abs(target-ret) > abs(target-nums[i]-nums[j]-nums[k]))
                    ret = nums[i]+nums[j]+nums[k];
                
                if(target < (nums[i]+nums[j]+nums[k]))
                     k--;
            
                else
                    j++;
            }
        }
        
        return ret;
    }
};
