#if 1
//思路二（四次遍历O(n)）：1.先查找是否有1，没有直接返回1
//2.有就将负数，大于nums.size的数置1，
//3.然后借用哈希表思想（，设定例如，nums[2] 元素的负号意味着数字 3 出现在 nums 中。nums[3]元素的正号表示 4 没有出现在 nums 中。）遍历一遍数组，将出现的元素对应的下标所在位置的元素置为负数，
//4.最后在遍历一遍数组，第一个为正数的位置（即下标）就是缺失的第一正数！！！
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        if(nums.size() == 1)
            return (nums[0] == 1)?2:1;
        
        int i, temp;
        
        //第一次遍历
        for(i = 0; i < nums.size(); i++)
            if(nums[i] == 1)
                break;
        if(i == nums.size())
            return 1;
        
        //第二次遍历
        for(i = 0; i <nums.size(); i++)
        {
            if(nums[i] <= 0)
                nums[i] = 1;
            if(nums[i] > nums.size())
                nums[i] = 1;
        }
        
        //第三次遍历
        for(i = 0; i <nums.size(); i++)
        {
            temp = abs(nums[i]);
            if(temp <= 1) //temp=0或1
                continue;
            if(nums[temp-1] < 0)
                continue;
            nums[temp-1] = 0-nums[temp-1];
        }
        
        //第四次遍历
        for(i = 1; i <nums.size(); i++)
            if(nums[i] > 0)
                return i+1;
        return i+1;
    }
};
#endif

#if 0
//思路一(O(logn+n))：首先将数组排序；在进行情况分析：一。nums为空或最大的数小于1或最小的数大于1。二。nums长度为1。三。nums长度大于1且最大>1最小<1，此时需要二分查找找到接近1的位置，然后再进行依次查找到不存在的最小数
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        
        int ret = 1;
        
        if(nums.size() == 0 || ret > nums[nums.size()-1] || ret < nums[0])
            return ret;
        
        if(nums.size() == 1)
            return (nums[0] == 1)?2:1;
        
        //二分查找(两个数或两个数以上的数组查找)，查找到ret的位置或比ret大一点点的数
        int temp = binary_search(nums, ret, 0 , nums.size()-1);
        
        if(nums[temp] != ret)
            return ret;
        else
        {
            while(temp < nums.size() && nums[temp] == ret)
            {
                if((temp+1) < nums.size() && nums[temp+1] == nums[temp])  //例如：11122234
                {
                    temp++;
                    continue;
                }
                temp++;
                ret++;
            }
        }
        return ret;
    }
    
private:
    int binary_search(vector<int>& nums, int& target, int begin, int end)
    {
        if(begin == end-1) 
        {
            if(nums[end] < target)   //说明最后一次时end=mid-1
                return end+1;
            if(nums[begin] < target)  
                return end;
            else    //说明最后一次时begin=mid+1
                return begin;
        }
        else if(begin == end)
        {
            if(nums[begin] >= target)  //说明最后一次时begin=mid+1
                return begin;
            else  //说明最后一次时end=mid-1
                return begin+1;
        }
        
        else
        {
            int mid = (begin+end)/2;
            int ret;
            if(nums[mid] == target)
                ret = mid;
            else if(nums[mid] > target)
                ret = binary_search(nums, target, begin, mid-1);
            else
                ret = binary_search(nums, target, mid+1, end);
            return ret;
        }
    }
    
};
#endif