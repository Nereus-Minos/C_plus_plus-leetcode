#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i = 0; i < nums.size(); i++)
            for(int j = i+1; j < nums.size(); j++)
                if(nums[i] + nums[j] == target)
                    return {i, j};
        exit(-1);
    };
};

int main(){
	vector<int> a;
	a = {1,2};

	return 0;
}
