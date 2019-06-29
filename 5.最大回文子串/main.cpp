#if 0
class Solution {
public:
    string longestPalindrome(string s) {
        //思路：寻找和s[i]相同字符的下一个字符位置，再使用双指针判断是否为回文子串
        
        //情况一：为空串
        if(s.length() == 0) 
            return "";
        
        //情况二：初始化为s[0]，因为"a", "abs"
        string ret(1,s[0]);
        int ne = 0;
        
        int i, j, k, f;  //f为寻找起始位置，从右开始找
        
        for(i = 0,f=s.length()-1; i < s.length()-1; )
        {
            ne = s.rfind(s[i], f);
            
            //如果没找到,则此字符位置的字符不可能出现在回文子串中
            if(ne == -1)
            {
                i++;
                f = s.length()-1;
                continue;
            }
     
            else
            {
                if(ret.length() >= (ne-i+1))
                {
                    i++;
                    f = s.length()-1;
                    continue;
                }
                
                //判断此字符到下一个相同字符之间是否回文
                for(j = i, k = ne; k > j; j++, k--)
                {
                    if(s[j] != s[k])
                    {
                         //寻找下一个匹配位置
                        f = ne - 1;

                        //表明已经到达最后
                        if(f > s.length()-1)
                        {
                            i++;
                            f = s.length()-1;
                        }
                        break;
                    }
                }
                
                //找到最长匹配
                if((k == j) || (k == (j-1)))
                {
                    //判断后再赋值
                    if(ret.length() < (ne-i+1))
                        ret.assign(s.substr(i, ne-i+1)); 
                    i++;
                    f = s.length()-1;
                    continue;
                }
            }
        }
        return ret;
    }
};
#endif


#if 0
/*
动态规划：
    dp[i][i]=1;//单个字符是回文串
    dp[i][i+1]=1 if s[i]=s[i+1];//连续两个相同字符是回文串
    
*/
class Solution {
public:
    string longestPalindrome(string s) {
        int len=s.size();
        if(len==0||len==1)
            return s;
        int start=0;//回文串起始位置
        int max=1;//回文串最大长度
        vector<vector<int>>  dp(len,vector<int>(len));//定义二维动态数组
        for(int i=0;i<len;i++)//初始化状态
        {
            dp[i][i]=1;
            if(i<len-1&&s[i]==s[i+1])
            {
                dp[i][i+1]=1;
                max=2;
                start=i;
            }
        }
        for(int l=3;l<=len;l++)//l表示检索的子串长度，等于3表示先检索长度为3的子串
        {
            for(int i=0;i+l-1<len;i++)
            {
                int j=l+i-1;//终止字符位置
                if(s[i]==s[j]&&dp[i+1][j-1]==1)//状态转移
                {
                    dp[i][j]=1;
                    start=i;
                    max=l;
                }
            }
        }
        return s.substr(start,max);//获取最长回文子串
    }
};
#endif

#if 0
/*
中心扩展法：
回文中心的两侧互为镜像。因此，回文可以从他的中心展开，并且只有2n-1个这样的中心(一个元素为中心的情况有n个，两个元素为中心的情况有n-1个)
*/
class Solution {
public:
    string longestPalindrome(string s) {
        int len=s.size();
        if(len==0||len==1)
            return s;
        int start=0;//记录回文子串起始位置
        int end=0;//记录回文子串终止位置
        int mlen=0;//记录最大回文子串的长度
        for(int i=0;i<len;i++)
        {
            int len1=expendaroundcenter(s,i,i);//一个元素为中心
            int len2=expendaroundcenter(s,i,i+1);//两个元素为中心
            mlen=max(max(len1,len2),mlen);
            if(mlen>end-start+1)
            {
                start=i-(mlen-1)/2;
                end=i+mlen/2;
            }
        }
        return s.substr(start,mlen);
        //该函数的意思是获取从start开始长度为mlen长度的字符串
    }
private:
    int expendaroundcenter(string s,int left,int right)
    //计算以left和right为中心的回文串长度
    {
        int L=left;
        int R=right;
        while(L>=0 && R<s.length() && s[R]==s[L])
        {
            L--;
            R++;
        }
        return R-L-1;
    }
};

#endif