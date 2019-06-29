#if 1
//双指针法：每次遇到*就记录此时的两个位置，首先将*忽略继续查找，当不匹配后回到记录*的位置的下一个位置，并将记录*对应s串中的位置+1，以备下次失配时，回来*匹配多个字符
vector<vector<bool>> memo_bool;
//要考虑多个*的情况
class Solution {
public:
    bool isMatch(string s, string p) {
        int i = 0, j = 0, match = -1, s_start = -1;
        
        while(i < s.length())
        {
            if(j < p.length() && (p[j] == s[i] || p[j] == '?'))
            {
                i++;
                j++;
            }
            else if(j < p.length() && (p[j] == '*'))
            {
                match = j;
                s_start = i;
                j++;
            }
            else if(match != -1)
            {
                j = match + 1;
                i = s_start + 1;
                s_start += 1;
            }
            else
                return false;
        }
        while(j < p.length() && p[j] == '*')
            j++;
        if(j == p.length())
            return true;
        else
            return false;
    }
};
#endif


#if 0
//递归回溯法：思想类似于正则匹配，但是此方法只能通过一半的例子
vector<vector<bool>> memo_bool;
//要考虑多个*的情况
class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<bool>> temp(s.size()+1,vector<bool>(p.size()+1, NULL));
        memo_bool = temp;
        temp.clear();
       return matchSub(s, p, 0, 0);
    }
    
private:
    bool matchSub(string& s, string& p, int i, int j){
        //终止条件
        if(memo_bool[i][j] != NULL)
            return memo_bool[i][j];
        
        bool ans;
        
         if(s.length() == i)
        {
            if(p.length() == j)
                ans = true;
            int k;
            for(k = j; k < p.length(); k++)
                if(p[k] != '*')
                    break;
            if(k == p.length())
                ans = true;
            else 
                ans = false;
        }    
            
        else if(p.length() == j)
            ans = false;
        
        else if((p[j] == s[i]) || (p[j] == '?'))
           ans = matchSub(s, p, i+1, j+1);
        
        else
        {
            if(p[j] == '*')
            {
                while(j+1<p.length() && p[j+1] == p[j])
                    j++;
                ans = matchSub(s, p, i+1, j) || matchSub(s, p, i+1, j+1) || matchSub(s, p, i, j+1);
            }
            else
                ans = false;
        }
        
        memo_bool[i][j] = ans;
        return ans;
    }
};
#endif