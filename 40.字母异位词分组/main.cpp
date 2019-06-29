//方法一，使用multimap的特性，自动排序，key值可以重复！！！
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        map<multimap<char, int>, int> a;
        
        multimap<char, int> temp;
        
        vector<vector<string>> ret;
        
        int i, j, count=0;
        for(i = 0; i < strs.size(); i++)
        {
            temp.clear();
            for(j = 0; j < strs[i].size(); j++)
                temp.insert(make_pair(strs[i][j],1));
            
            map<multimap<char, int>, int>::iterator it = a.find(temp);
            if(it != a.end())
                ret[(it->second)].push_back(strs[i]);
            else
            {
                a.insert(make_pair(temp,count));
                ret.push_back({strs[i]});
                count++;
            }
        }
        return ret;
    }
};
