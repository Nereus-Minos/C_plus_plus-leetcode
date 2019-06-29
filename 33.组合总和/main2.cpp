
//思路;在前一题基础上加上判断if(i>start&&candidates[i-1]==candidates[i])  continue;
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        vector<vector<int>> ret;
        vector<int> temp;
        
        sort(candidates.begin(), candidates.end());
        
        search_combine(candidates, temp, ret, target, 0, 0);
        
        return ret;
    }
    
private:
    void search_combine(vector<int>& candidates, vector<int> temp, vector<vector<int>>& ret, int& target, int count, int start){
        if(count == target)
        {
            ret.push_back(temp);
            
            return ;
        }
        else if(count > target)
            return ;
        else
        {
            for(int i = start; i < candidates.size(); i++)
            {
                if(i>start&&candidates[i-1]==candidates[i])
                    continue;
                
                temp.push_back(candidates[i]);
                count += candidates[i];
                search_combine(candidates, temp, ret, target, count, i+1);
                temp.erase(temp.end()-1);
                count -= candidates[i];
            }
        }
    }
};