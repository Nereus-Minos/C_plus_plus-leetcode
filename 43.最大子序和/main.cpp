#if 0
//方法一：（保证了每次计算和都是从正数开始）拿当前的和temp判断， <0则更新ret并且将temp=nums[j]，>0则继续累加，更新ret
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int temp = nums[0], ret = nums[0];
            
        for(int j = 1; j < nums.size(); j++)
        {
            if(temp <= 0)
            {
                ret = max(ret, max(temp, nums[j]));
                temp = nums[j];
            } 
            else
            {
                temp += nums[j];
                if(temp > ret)
                    ret = temp;
            }
        }
        return ret;
    }
    
};
#endif

#if 1
//方法二：分治法：其实就是它的最大子序和要么在左半边，要么在右半边，要么是穿过中间，对于左右边的序列，情况也是一样，因此可以用递归处理。中间部分的则可以直接计算出来，时间复杂度应该是 O(nlogn)-----递归
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int n = nums.size(); 
        //递归终止条件 
        if( n == 1 )
            return nums[0];
        else 
        { 
            vector<int> temp;
            //递归计算左半边最大子序和 
            temp.assign(nums.begin(), nums.begin()+(n/2));
            int max_left = maxSubArray(temp); 
            //递归计算右半边最大子序和 
            temp.assign(nums.begin()+(n/2), nums.end());
            int max_right = maxSubArray(temp); 
        
            //计算中间的最大子序和，从右到左计算左边的最大子序和，从左到右计算右边的最大子序和，再相加 
            // 左最大字序 (不包括n/2)
            int max_l = nums[n/2-1];
            int i, tmp = 0; 
            for(i = n / 2 - 1; i >= 0; i--)
            {
                tmp += nums[i]; 
                max_l = max(tmp, max_l); 
            }
            int max_r = nums[n/2];
            tmp = 0;
            for(i = n / 2; i < n; i++)
            {
                tmp += nums[i]; 
                max_r = max(tmp, max_r); 
            }
            // 返回三个中的最大值 
            return max(max_right,max(max_left,max_l+max_r));
        }
    }
};

#endif
