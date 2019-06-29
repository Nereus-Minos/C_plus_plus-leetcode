class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        //思路：变种二分查找法,有三种情况：一。当begin>end时，表明nums为空，则直接ret=0；二。当(begin == end - 1) || (begin == end)时，为正常二分查找到最后，需判断begin或end是否==target，或判断插入位置；三。递归二分查找
        int ret = 0;
        binary_search(nums, target, 0, nums.size()-1, ret);
        
        return ret;
    }
private: 
    void binary_search(vector<int>& nums, int target, int begin, int end, int& ret)
    {
        //终止条件
        if(begin > end)  //nums为kong
        {
            ret = 0;
            return ;
        }
        
        if((begin == end - 1) || (begin == end))
        {
            if(nums[begin] >= target)
                ret = begin;
            else if(nums[end] >= target)
                ret = end;
            else
                ret = end+1;
            return ;
        }
        
        int mid = (begin+end)/2;
        
        if(nums[mid] > target)
            binary_search(nums, target, begin, mid-1, ret);
        else if(nums[mid] < target)
            binary_search(nums, target, mid+1, end, ret);
        else
        {
            ret = mid;
            return ;
        }
    }
};