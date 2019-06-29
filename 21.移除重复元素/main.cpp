
//思路一：简单

 for(j = 0; j<nums.size();j++)
 {
     if(nums[j] != val)
     {
         nums[i] = nums[j];
        i++;
     }
 }
return i;

//思路二：麻烦
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
       if(nums.empty())
            return 0;
            
        int i=0,j=0;
        
        for(i =0; i<nums.size(); i++)
        {
            if(j < i+1)
                j = i+1;
            
            if(nums[i] == val)
            {
                
                while((j < nums.size()) && nums[j] == val)
                    j++;
                
                if(j >= nums.size())
                    return i;
                
                nums[i] = nums[j];
                nums[j] = val;
            }
        }
        return i;
        }
};