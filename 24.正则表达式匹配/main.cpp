#if 0
//方法一：回溯法(*不可能连续出现)
        //1.如果没有星号（正则表达式中的 * ），问题会很简单——我们只需要从左到右检查匹配串 s 是否能匹配模式串 p 的每一个字符。
        //2.如果模式串中有星号，它会出现在第二个位置，即 p[1]。（简化：不管 N 是多少，当前的选择只有两个：出现 0 次、出现 1 次。）这种情况下，我们可以直接忽略模式串中这一部分（即忽略p[0]、p[1]），或者(大前提：s[0]存在，不存在，只能用第一种)删除匹配串s的第一个字符(前提是它能够匹配模式串p当前位置字符，即 p[0])。如果两种操作中有任何一种使得剩下的字符串能匹配，那么初始时，匹配串和模式串就可以被匹配。 s=="aa"   p=="c*aa"  p=="a*a"  p=="a*"            *不可能连续出现!!!
class Solution {
public:
    bool isMatch(string s, string p) {
        //特殊情况
        if(p.length() == 0)
            return (s.length() == 0);
        
        bool is_match =(!s.empty()) && ( (p[0] == s[0]) || (p[0] == '.') );  //只能这样写，比如s=="aa" p=="a*"
        
        if(p.length()>=2 && (p[1] == '*'))
            return isMatch(s, p.substr(2)) || (is_match && isMatch(s.substr(1), p));
        
        else
            return (is_match && isMatch(s.substr(1), p.substr(1)) );  
    }
};
#endif

#if 0
//方法二：优化
        //用 dp(i, j) 来应对剩余相同参数的函数调用，这帮助我们节省了字符串建立操作所需要的时间
class Solution {
public:
    bool isMatch(string s, string p) {
        
        return dp(0, 0, s, p);
    }
private:
    bool dp(int i, int j, string &s, string &p){
        //特殊情况
        if(j == p.length())
            return (s.length() == i);
        
        bool is_match =(i<s.length()) && ( (s[i] == p[j]) || (p[j] == '.') );  //只能这样写，比如s=="aa" p=="a*"
        
        if(( j+1 < p.length() ) && (p[j+1] == '*'))
            return dp(i, j+2, s, p) || (is_match && dp(i+1, j, s, p));
        
        else
            return (is_match && dp(i+1, j+1,s ,p) );  
    }
};
#endif


#if 1
//方法三：动态规划
        //将 dp(i,j,s,p)中间结果存入备忘录，避免重复计算。
        //用 dp(i,j) 表示 text[i:] 和 pattern[j:]是否能匹配。
vector<vector<bool>> memo_bool;  //必须用全局的 ，，在函数中必须通过临时变量赋值，不能通过.resize变化，因为编译器差异，会使memo_bool的值初始化为1！！！

class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<bool>> temp(s.size()+1,vector<bool>(p.size()+1, NULL));
        memo_bool = temp;
        temp.clear();
        return dp(0, 0, s, p);
    }
private:
    bool dp(int i, int j, string &s, string &p){

        //终止条件
        if(memo_bool[i][j] != NULL)
            return memo_bool[i][j];
        
        bool ans;
        
        //特殊情况
        if(j == p.length())
            ans = (s.length() == i);
        else
        {
            bool is_match =(i<s.length()) && ( (s[i] == p[j]) || (p[j] == '.') );  //只能这样写，比如s=="aa" p=="a*"
        
            if(( j+1 < p.length() ) && (p[j+1] == '*'))
                ans = dp(i, j+2, s, p) || (is_match && dp(i+1, j, s, p));

            else
                ans = (is_match && dp(i+1, j+1,s ,p) );  
        }
        
        memo_bool[i][j] = ans;
        return ans;
    }
};
#endif