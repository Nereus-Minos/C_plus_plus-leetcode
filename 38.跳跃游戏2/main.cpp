class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size()<=1) return 0;
        int step=0, start=0,reach=0;
        while( reach <nums.size()-1 ){
            int farest=0;
            for(int i=start; i<=reach; ++i)
                farest=max(farest,i+nums[i]);
            start=reach+1;
            reach=farest;
            step++;
        }
        return step;
    }
};