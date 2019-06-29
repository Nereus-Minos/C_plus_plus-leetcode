
#if 0
//思路：为了避免重复，使用map去重
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<vector<int>> ret;
        vector<int> temp;
        map<vector<int>, int> ret_temp; //为了去重
        
        search_combine(candidates, temp, ret_temp, target, 0);
        
        for(map<vector<int>, int>::iterator iter = ret_temp.begin(); iter != ret_temp.end(); iter++) //iter != ret_temp.end()没有重载<比较符，所以只能用!=
            ret.push_back((*iter).first);
        
        return ret;
    }
    
private:
    void search_combine(vector<int>& candidates, vector<int> temp, map<vector<int>, int>& ret_temp, int& target, int count){
        if(count == target)
        {
            sort(temp.begin(), temp.end());
            if(ret_temp.find(temp) == ret_temp.end())
                ret_temp[temp] = 1;
            
            return ;
        }
        else if(count > target)
            return ;
        else
        {
            for(int i = 0; i < candidates.size(); i++)
            {
                temp.push_back(candidates[i]);
                count += candidates[i];
                search_combine(candidates, temp, ret_temp, target, count);
                temp.erase(temp.end()-1);
                count -= candidates[i];
            }
        }
    }
};
#endif

#if 1
//思路：为了避免重复，需要在递归的时候将start也传入
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
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
                temp.push_back(candidates[i]);
                count += candidates[i];
                search_combine(candidates, temp, ret, target, count, i);
                temp.erase(temp.end()-1);
                count -= candidates[i];
            }
        }
    }
};
#endif