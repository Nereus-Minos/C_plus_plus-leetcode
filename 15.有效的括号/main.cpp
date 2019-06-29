class Solution {
public:
    bool isValid(string s) {
        
       //使用压栈出栈
        stack <char> temp;
        char temp_char;
        
        for(int i = 0; i < s.length(); i++)
        {
            if((s[i] == '(') || (s[i] == '{') || (s[i] == '['))
                temp.push(s[i]);
            else
            {
                if(temp.empty())
                    return false;
                temp_char = temp.top();
                temp.pop();  //弹出栈顶元素
                 
                switch(s[i]){
                    case ')':
                        {
                            if(temp_char != '(') return false;
                            else
                                break;
                        }
                    case '}':
                       { 
                           if(temp_char != '{') return false;
                           else
                                break;
                       }
                    case ']':
                       { 
                           if(temp_char != '[') return false;
                           else
                                break;
                           
                       }
                    default:
                        return false;
                }
            }
        }
        //当最后temp不为空时
        if(!temp.empty())
            return false;
        
        return true;
    }
};