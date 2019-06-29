#if 0
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //特殊情况;空字符串
        if(s.length() == 0)
            return 0;
        
        int start = 0, end = 1;   //最长子串的下标
        int ret = 1;  //最长子串的长度
        set<char>a;   //判断是否出现重复字符
        
        a.insert(s[start]);
        
        while(end < s.length())
        {
            if(a.find(s[end])!=a.end())
                a.erase(s[start++]);
            else
            {
                a.insert(s[end++]);
                ret = max(ret, end - start);
            } 
        }
        return ret;
    }
};
#endif

#if 1
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //特殊情况;空字符串
        if(s.length() == 0)
            return 0;
        
        int start = 0, end = 0;   //最长子串的下标
        int ret = 1;  //最长子串的长度
        map<char, int>a;   //判断是否出现重复字符
        map<char, int>::iterator iter;
        
        while(end < s.length())
        {
            if((iter = a.find(s[end])) != a.end())
                start = max(start, iter->second);
            
            //不能直接存储下标，因为没有重复的时候差值不对
            a[(s[end])] = end+1;  
            
            ret = max(ret, end - start + 1);
            
            end++;
        }
        return ret;
    }
};
#endif