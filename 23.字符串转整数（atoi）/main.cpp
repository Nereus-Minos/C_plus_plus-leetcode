class Solution {
public:
    int myAtoi(string str) {
        
        //思路：先找到第一个非空字符，然后判断是否为数字或'+'或'-',然后除去数字串前面的所有0！！！
        //使用flag来表示正负号；使用一个vecotr<int>存储数字
        //使用vector最后拼接成一个数
        
        //特殊情况 ""
        if(str.length() == 0)
            return 0;
        
        int i,j; //获取第一个非空字符
        bool flag = 0;  //表示正数
        
        for(i=0; i< str.length(); i++)
            if(str[i] != ' ')
                break;
        
        //判断
        if(( (str[i] < '0') || (str[i] > '9') ) && (str[i] != '+') && (str[i] != '-') )
            return 0;
        else if(str[i] == '-')
        {
            flag = 1;
            i++;
        }
        else if(str[i] == '+')
            i++;
            
        //当开始是0时！！！
        while(str[i]== '0')
            i++;
        
        cout<<i<<endl;
        vector<int> a;
        
        for(j=i; (j < str.length()) && ((str[j] >= '0') && (str[j] <= '9')); j++)
            a.push_back(str[j]-48);
        
        //将vector中的数字拼接成一个数
        j = a.size();
        
        if(j>10)
        {
            if(flag == 0)  //表示正数
               return INT_MAX;
            else
               return -2147483648;
        }
        
        else if(j == 0)
            return 0;
        
        else
        {
            //由于可能出现大于32位的数，所以用long
            long ret = 0;
            
            for(i = 0; i < j ; i++)
                ret += a[i] * pow(10, j - 1 - i);
            
            if(flag == 0)  //表示正数
            {
                if(ret > INT_MAX)
                    return INT_MAX;
                return ret;
            }
            else
            {
                if(ret > 2147483648)  //最小值
                    return -2147483648;
                return (int)(0 - ret);
            }
        }
        
    }
};