#if 0
//方法一：考虑给定字符串中每种可能的非空偶数长度子字符串，检查它(非空偶数长度子字符串)是否是一个有效括号字符串序列。为了检查有效性，我们可以使用栈的方法，栈占用时间多，所以可以使用left记录(个数即可。
class Solution {
public:
    int longestValidParentheses(string s) {
       
        int i = 0, j = 0, k =0, count = 0, left = 0;
        
        //检测每个偶数子串
        for(i = 0; i <= s.length() - 2 + (s.length() % 2); i += 2)  //子串长：s.length()-(s.length() % 2)-i
        {
            for(j = 0; j <= (s.length() % 2)+i; j++)   //控制子串起点
            {
                count = 0;
                left = 0;
                int temp = (s.length()-(s.length() % 2)-i) + j;
                for(k = j; k < temp; k++)   //子串内部
                {
                    if(s[k] == '(')
                        left++;
                    else
                    {
                        if(left == 0)
                            break;
                        left--;
                        count += 2;
                    }
                }
                if(k == temp && left == 0)
                    return count;
            }
        }
        return 0;
    }
};
#endif

//方法二：栈存(的下标，首先在栈底放-1，标志从头的下一个位置开始计算匹配的括号数；当遇到多余)时，弹出-1，更换为此时的下标，表明从此位置的下一个位置开始往后计算匹配的括号数！！！
    //具体做法：对于遇到的每个 ‘(’，我们将它的下标放入栈中。 对于遇到的每个 ‘)’，我们弹出栈顶的元素，当此时栈不为空时，将当前元素的下标与此时栈顶元素下标作差，得出当前有效括号字符串的长度，为空时，将此时下标压入栈中，continue。通过这种方法，我们继续计算有效子字符串的长度，并最终返回最长有效子字符串的长度。
#if 1
class Solution {
public:
    int longestValidParentheses(string s) {
       
        int i = 0, ret = 0;
        stack<int> temp;
        temp.push(-1);
        
        for(i = 0; i<s.length(); i++)
        {
            if(s[i] == '(')
                temp.push(i);
            else
            {
                temp.pop();  //移除
                if(temp.empty())
                {
                    temp.push(i);
                    continue;
                }
                if(ret < (i - temp.top())) //没有移除
                    ret = i - temp.top();
            }
        }
        return ret;
    }
};
#endif

//方法三：双指针，两次遍历
        //在这种方法中，我们利用两个计数器 left 和 right 。首先，我们从左到右遍历字符串，对于遇到的每个‘(’，我们增加 left计算器，对于遇到的每个‘)’，我们增加 right计数器。每当 left 计数器与 right计数器相等时，我们计算当前有效字符串的长度，并且记录目前为止找到的最长子字符串。如果 right计数器比 left计数器大时，我们将 left和 right计数器同时变回0。
        //当从左向右遍历后，再做一次从右向左遍历，过程类似！！目的: 从左向右遍历'(()'这样的不会得到值，因为不闭合！！！
#if 1
class Solution {
public:
    int longestValidParentheses(string s) {
       
        int i = 0, left = 0, right = 0, ret = 0;
        
        for(i = 0; i < s.length(); i++)
        {
            if(s[i] == '(')
                left++;
            else
                right++;
            
            if(right == left)
            {
                if(ret < 2*right)
                    ret = 2*right;
            }
                
            if(right>left)
                right = left = 0;
            
            
        }
        
        left = right = 0;
        for(i = s.length()-1; i >= 0; i--)
        {
            if(s[i] == '(')
                left++;
            else
                right++;
            
            if(right == left)
                if(ret < 2*left)
                    ret = 2*left;
                
            if(right<left)
                right = left = 0;
                
            
        }
        
        return ret;
    }
};
#endif