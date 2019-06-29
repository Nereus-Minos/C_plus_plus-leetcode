
//方法一：要求时间复杂度必须是 O(log n)，所以需要用二分查找法.
        //总共有以下几种情况：一.nums总长度为0，二.数组为升序排列，三.数组有旋转：1.target存在则只有可能出现在大数端；2.target存在则只有可能出现在小数端
        //当数组有旋转，且出现在大端时，注意将范围缩小到大端做法：(nums[hight] <= nums[nums_len-1]) && (nums[(low+hight)/2] < nums[hight])//表明中间点还在小的一端
class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int nums_len = nums.size();
        
        //特殊情况
        if(nums_len == 0)
            return -1;
        
        int low = 0, hight = nums_len - 1;
        
        if(nums[nums_len - 1] >= nums[0])   //升序排列的数组
        {
            while(low <= hight) 
            { 
                if(nums[(low+hight)/2] == target)
                   return (low+hight)/2;    
                else if(nums[(low+hight)/2] > target)
                   hight = (low+hight)/2 - 1;   //防止偶数个
                else
                    low = (low+hight)/2 + 1;   //防止偶数个
            }
        }
       
        else if(target >= nums[0])  //表明target存在则只有可能出现在大数端
        {
            while(low <= hight) 
            {
                if( (nums[hight] <= nums[nums_len-1]) && (nums[(low+hight)/2] < nums[hight]) )  //表明中间点还在小的一端
                {
                        hight = (low+hight)/2 - 1;  
                }
                    
                else  //表明中间点落在了大的一端,二分查找
                {
                    if(nums[(low+hight)/2] == target)
                       return (low+hight)/2;    
                    else if(nums[(low+hight)/2] > target)
                       hight = (low+hight)/2 - 1;   //防止偶数个
                    else
                        low = (low+hight)/2 + 1;   //防止偶数个
                }
            }
        }
        
        else  //表明target存在则只有可能出现在小数端
        {
            while(low <= hight)
            {
                if(nums[(low+hight)/2] > nums[hight])  //表明中间点还在大的一端
                    {
                            low = (low+hight)/2 + 1;
                    }

                    else  //表明中间点落在了小的一端,二分查找
                    {
                        if(nums[(low+hight)/2] == target)
                           return (low+hight)/2;
                        else if(nums[(low+hight)/2] < target)
                           low = (low+hight)/2 + 1;
                        else
                            hight = (low+hight)/2 - 1;
                    }
            }
        }
        return -1;
    }
};