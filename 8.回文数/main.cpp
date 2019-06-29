class Solution {
public:
    bool isPalindrome(int x) {
        //情况一：x<0不是回文数
        if(x<0)
            return false;
        //情况二：x为个位数
        if(!(int)(x/10))
            return true;
        
        //情况三:思路：先反转，再判等
        int ret =0;
        int weishu = 2;
        int temp = x;
        while((int)(temp/(pow(10,weishu)))) weishu++;
        //反转
        for(int i = weishu-1; i>=0; i--)
        {
            ret +=(int)( temp/(pow(10,i)) ) * (pow(10, weishu-1-i)); 
            
            temp = temp % (int)(pow(10,i));
        }
        
        if(ret == x)
            return true;
        else
            return false;
    }
};