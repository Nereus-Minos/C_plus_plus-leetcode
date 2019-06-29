#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> all;
        vector<int> temp;
        
        sort(nums.begin(),nums.end());
        
        if(nums.empty() || nums.front()>0 || nums.back()<0)
            return {};
        
		// 特殊情况[0,0,0]
        for(int i = 0; i < nums.size() && nums[i]<=0 ; i++)
        {   
            // 去重 [-4,-1,-1,0,2]，和第三个-1匹配必定和第二个-1匹配
            if(i > 0 && nums[i-1] == nums[i])
                continue;
            // 两头堵思想
            for(int j = i+1, k = nums.size()-1; j < k; )
            {
                if(nums[i]+nums[j]+nums[k] < 0)
                {
                    j++;
                    continue;
                }
                else if(nums[i]+nums[j]+nums[k] > 0)
                {
                    k--;
                    continue;
                }
                else
                {	
					// 去重，[-2，0，0，2]
                    if(j-1 != i && nums[j-1] == nums[j])
                    {
                      j++;
                      continue;
                    }
                    temp = {nums[i],nums[j], nums[k]};
                    all.push_back(temp);
                    j++;
                    k--;
                    continue;
                }
                
                
            }

        }
        if(all.empty())
            return {};
        return all;
    }
};

int main(){

	vector<int>a = {-1,0,1,2,-1,-4};
	vector<vector<int>>b = new Solution().threeSum(a);
	
	if(a.empty()) 
		return 0;
	for(vector<int>::iterator iter = a.begin(); iter != a.end(); iter++)
	{
		//for(int i =0; i < (*iter).size(); i++)
			cout<<(*iter)<<endl;
	}

return 0;
}
