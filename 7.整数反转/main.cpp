class Solution {
public:
    int reverse(int x) {
        
        if(x<= (0-pow(2,31)) || x >= (pow(2,31)-1))
            return 0;
        
        int weishu = 1;
        while((int)(x / pow(10 , weishu)))
        {
            weishu++;
        }
        
        int ret=0;
        int temp;
        
        for(int i = weishu-1, j=0; i>=0; i--,j++)
        {
            temp = (x / (pow(10 , i)));
            ret += temp*(pow(10 , j)); 
            x = x- temp*(pow(10 , i));
        }
        
        if(ret<= (0-pow(2,31)) || ret >= (pow(2,31)-1))
            return 0;
        
        return ret;
    }
};