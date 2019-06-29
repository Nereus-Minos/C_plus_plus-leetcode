//思路一（递归累成、累加）；除特殊情况:首先将num2的每位与num1相乘等到的字符串存入v_temp中，然后将v_temp中的字符串累加
class Solution {
public:
    string multiply(string num1, string num2) {
        //特殊情况
        if(num1.size() == 0 || num2.size() == 0 || num1 == "0" || num2 == "0")
            return "0";
        
        int temp, i = num2.size()-1, carry = 0;
        string str_temp;
        vector<string> v_temp;
        
        int k = 0;
        
        for(; i>=0; i--)
        {
            str_temp = "";
            for(int j = 0; j < k; j++)
                str_temp.insert(0,1,48);
            k++;
            temp = num2[i]-48;
            temp_multi(num1, temp, str_temp, num1.size()-1, 0);
            cout<<str_temp<<endl;
            v_temp.push_back(str_temp);
        }
        
        //将vector中的相加得到最终结果
        for(i = 1; i<v_temp.size(); i++)
        {
            str_temp = "";
            temp_add(v_temp[0], v_temp[i], str_temp, v_temp[0].size()-1, v_temp[i].size()-1, carry);
        }
        
        return v_temp[0];
    }
    
private:
    void temp_add(string& num1, string& num2, string& str_temp, int i, int j, int carry){
        if(i < 0 || j < 0)
        {
            if(j >= 0)
            {
                int temp = (num2[j]-48) + carry;
                carry = temp / 10;
                temp -= (temp / 10)*10;
                str_temp.insert(0,1,(temp+48));
                temp_add(num1, num2, str_temp, i, j-1, carry);
            }
            else if(i >= 0)
            {
                int temp = (num1[i]-48) + carry;
                carry = temp / 10;
                temp -= (temp / 10)*10;
                str_temp.insert(0,1,(temp+48));
                temp_add(num1, num2, str_temp, i-1, j, carry);
            }
            
            else
            {
                if(carry != 0)
                    str_temp.insert(0,1,(carry+48));
            }
            num1 = str_temp;
        }
        else
        {
            int temp = (num1[i]-48)+ (num2[j]-48) + carry;
            carry = temp / 10;
            temp -= (temp / 10)*10;
            str_temp.insert(0,1,(temp+48));
            temp_add(num1, num2, str_temp, i-1, j-1, carry);
        }
    }
    
    void temp_multi(string& num1, int& num2, string& str_temp, int i, int carry){
        if(i < 0)
        {
            if(carry != 0)
                str_temp.insert(0,1,(carry+48));
        }
        else
        {
            int temp = (num1[i]-48)*num2 + carry;
            carry = temp / 10;
            temp -= (temp / 10)*10;
            str_temp.insert(0,1,(temp+48));
            temp_multi(num1, num2, str_temp, i-1, carry);
        }
    }
};