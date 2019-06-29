#if 0
//方法一：先使用二分查找法查找出一个匹配的位置，然后使用双指针方法寻找上界和下界
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int low = 0, hight = nums.size()-1;
        int mid;
        int down, up;
        
        if(hight < 0)
            return {-1,-1};
        else
        {
            while(low <= hight)
            {
                mid = (hight + low)/2;
                if(nums[mid] < target)
                    low = mid + 1;
                else if(nums[mid] > target)
                    hight = mid - 1;
                else
                {
                    //找到一个匹配的后，查找其范围
                    //找下界
                    down = mid;
                    while((down > 0) && nums[down] == nums[down-1])
                        down -= 1;
                    up = mid;
                    while((up < nums.size()-1) && nums[up] == nums[up+1])
                        up++;
                    return {down, up};
                }
            }
            return {-1,-1};
        }
    }
};

#endif

#if 1
//方法二：使用递归实现二分查找法，当nums[mid] == target时使用二分查找法寻找第一个匹配的元素和最后一个匹配的元素位置
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int a = nums.size(), b = -1;
        binary_search(nums, target, 0, nums.size()-1, a, b);
        
        if(a < nums.size() && b > -1)
            return {a, b};
        else
            return {-1,-1};
    }
    
private:
    void binary_search(vector<int>& nums, int target, int begin, int end, int &a, int &b)  //a记录下边界，b记录上边界
    {
        if(begin > end) //  终止条件
            return ;
        
        int mid = (begin + end)/2;
        if(nums[mid] == target)
        {
            if(a > mid)
                a = mid;
            if(b < mid)
                b = mid;
            binary_search(nums, target, begin, mid-1, a, b);  //寻找下边界
            binary_search(nums, target, mid+1, end, a, b);    //寻找上边界
        }
        else if(nums[mid] > target)  //普通二分查找
            binary_search(nums, target, begin, mid-1, a, b);
        else        //普通二分查找
            binary_search(nums, target, mid+1, end, a, b);
    }
};
#endif