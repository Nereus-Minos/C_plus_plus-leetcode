class Solution {
public:
    int divide(int dividend, int divisor) {
        //思路：使用 bool flag = ( (dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0))来表示最终的符号;0表示最终符号为负数
            // 关于溢出的问题，可以都先使用long存储结果，再进行判断
            // 采用二分查找的思想，divisor_temp = (dividend_temp + remain_temp)/2；
                //做法:每次dividend_temp -= divisor_temp;，每次dividend_temp<0时,使dividend_temp += divisor_temp;divisor_temp=divisor再开始运算，每次dividend_temp>0时divisor_temp += divisor_temp;每次dividend_temp=0；break
        
        //一般情况
        bool flag = ( (dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0));
        
        long ret = 0;
        
        long count = 1;
        
        long divisor_temp = abs((long)divisor);
        long dividend_temp = abs((long)dividend);
        
        while(dividend_temp >= abs((long)divisor))
        {
            dividend_temp -= divisor_temp;
            
            if(dividend_temp < 0)
            {
                dividend_temp += divisor_temp;
                
                divisor_temp = abs(divisor);
                
                count = 1;
            }
            
            else if(dividend_temp > 0)
            {
                ret += count;
                
                divisor_temp += divisor_temp;
                
                count += count;
            }
            
            else
            {
                ret += count;
                break;
            }
            
        }
        
        //符号处理 //溢出处理[−2^31,  2^31 − 1]
        if(flag)  // 正数
        {
            if(ret > pow(2,31)-1)
                return pow(2,31)-1;
            return (int)ret;
        }
        else
        {
            if(ret > pow(2,31))
                return pow(2,31)-1;
            return (int)(0-ret);
        }
        
    }
};