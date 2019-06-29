#if 1
class Solution {
public:
    string convert(string s, int numRows) {
        
        //特殊情况，空字符串   特殊情况,numRows==1 特殊情况s长度<=numRows
        if(s.length() == 0 || s.length() <= numRows || numRows == 1)
            return s;
        
        //思路;建立二维数组，存放每行的子串，空字符用空格表示
        vector<vector<char>> a(numRows, vector<char>(s.length()));
        char* ret = new char[s.length()+1];  //必须多一个来作为终止符！！！
        
        for(int l = 0, step = 0; s[l] != 0; step++)
        {
            int line = step % (numRows-1);
            for(int i = 0; i < numRows; i++)    
            {
                 //终止条件
                    if(s[l] == 0)
                    {
                        line = numRows;
                        break;
                    }

                //一次分numRows列，
                if(line == 0) //第一列
                {
                    a[i][step] = s[l++]; 
                }
                else
                {
                    if(i == (numRows - line - 1))  
                        a[i][step] = s[l++];
                    else
                        a[i][step] = ' ';
                }
            }
           
        }
        
        //重构成输出
        int ret_len = 0;
        for(int m = 0, re=0; m < numRows; m++)
        {
            for(int n = 0; a[0][n] != 0; n++) //不能用a[0].length()==s.length()，不对
            {
                if(a[m][n] != ' ' && a[m][n] != 0)
                {
                    ret[re++] = a[m][n];
                    ret_len++;
                }
            }
        }
        //添加终止符
        ret[ret_len] = 0;
        
        return ret;
    }
};
#endif

#if 0
/*
方法二：按行访问:按照与逐行读取 Z 字形图案相同的顺序访问字符串。
算法:首先访问 行 0 中的所有字符，接着访问 行 1，然后 行 2，依此类推...
    行 0 中的字符位于索引 K(2⋅numRows−2); 
    行 numRows−1 中的字符位于索引 k (2⋅numRows−2)+numRows−1; 
    内部的 行 i中的字符位于索引 k(2⋅numRows−2)+i以及(k+1)(2⋅numRows−2)−i 处;

*/
class Solution {
public:
    string convert(string s, int numRows) {

        if (numRows == 1) return s;

        string ret;
        int n = s.size();
        int cycleLen = 2 * numRows - 2;

        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j + i < n; j += cycleLen) {
                ret += s[j + i];
                if (i != 0 && i != numRows - 1 && j + cycleLen - i < n)
                    ret += s[j + cycleLen - i];
            }
        }
        return ret;
    }
};
#endif