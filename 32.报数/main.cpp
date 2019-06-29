//思路：使用一个vecotr<int>temp1存储每次报数的数，如第一次存1，第二次存的是11，....，每次通过vecotr<int>temp2来更新,当报数到n时，停止，并将temp1中数字转换为字符串；
//求取下一次报数的数:每次判断temp1[j]是否等于temp1[j+1]，等于则将计数器加1；不等于说明同一个数结束，此时将count和temp1[j]压入temp2中。

class Solution {
public:
    string countAndSay(int n) {
        
        if(n == 1)
            return "1";
        
        vector<int> temp1, temp2;
        temp1.push_back(1);
        int count = 1;
        
        for(int i = 2; i<=n;i++)
        {
            for(int j = 0; j < temp1.size(); j++)
            {
               if((j+1 == temp1.size()) || ((j+1 < temp1.size()) && (temp1[j] != temp1[j+1])))
               {
                   temp2.push_back(count);
                   temp2.push_back(temp1[j]);
                   count = 1;
               }
               else if((j+1 < temp1.size()) && (temp1[j] == temp1[j+1]))
               {
                   count++;
               }
            }
            temp1 = temp2;
            temp2.clear();
        }
        
        //将数字转为字符串
        string ret;
        for(int i = 0; i < temp1.size(); i++)
            ret.append(1, (temp1[i]+48));
        
        return ret;
    }
};