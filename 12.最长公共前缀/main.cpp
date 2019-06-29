class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ret = "";
        int min_len = INT_MAX;
        
        char a;
        int str_len, i;
        
        if(strs.size() == 0)
            return "";
        
        //求出最小的字符串长度
        for(i = 0; i < strs.size(); i++)
        {
            str_len = (strs[i]).length();   //分开写，不然保错
            if(str_len == 0)
                return "";
            min_len = min(min_len, str_len);
        }
        
        //比较是否相等
        for(i = 0; i < min_len; i++)
        {
            a = strs[0][i];
            
            for(int j = 0; j <strs.size(); j++)
            {
                if(strs[j][i] != a)
                    goto BR;
            }
            ret += a;
        }
        
        BR:
            return ret;
    }
};