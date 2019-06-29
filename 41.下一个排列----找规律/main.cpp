class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        //思路：先考虑特殊情况，数组为从大到小排序的，例如：3->2->1，这种直接将数组反转变成从小到大
        //      当为1->4->6->5->3->2时，将从右到左第一个a[i] > a[i-1]的a[i-1]替换成右边略大于他的数a[j]，然后将a[j]右边的数从小到大排序，例如：将4替换成5，然后将3->2从小到大排序
        int i, j, temp;
        
        //找到a[i-1]
        for(i = nums.size()-1; i > 0; i--)
            if(nums[i-1] < nums[i])
                break;

        if(i != 0)
        {
             //找到a[j]
            for(j = nums.size()-1; j > i; j--)
                if(nums[j] > nums[i-1])
                    break;
            
            //交换a[i-1]和a[j]
            temp = nums[i-1];
            nums[i-1] = nums[j];
            nums[j] = temp;
        }
        else
        {
            j = -1;
        }
        
        //从大到小排序a[j]后面的元素
        for(j = i; j <= (nums.size()-1+i)/2; j++)
        {
            temp = nums[j];
            nums[j] = nums[nums.size()-1-(j-i)];
            nums[nums.size()-1-(j-i)] = temp;
        }            
        
    }
};
