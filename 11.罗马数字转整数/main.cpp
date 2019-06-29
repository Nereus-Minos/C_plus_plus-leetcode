/*
建立一个哈希表，然后一一判断，若前面的罗马数值比后面的罗马数值小，则将结果加上两者的正差值，若前面的罗马数值比后面的罗马数值大，则直接加上该罗马的对应数值。
*/

class Solution {
public:
    int romanToInt(string s) {
        int result=0;//存放结果
        map<char,int> luomab;//建立罗马表
        //插入对应关系
        luomab.insert(map<char,int>::value_type('I',1));
        luomab.insert(map<char,int>::value_type('V',5));
        luomab.insert(map<char,int>::value_type('X',10));
        luomab.insert(map<char,int>::value_type('L',50));
        luomab.insert(map<char,int>::value_type('C',100));
        luomab.insert(map<char,int>::value_type('D',500));
        luomab.insert(map<char,int>::value_type('M',1000));
        for(int i=0;i<s.length();i++)
        {
            cout<<luomab[s[i+1]]<<endl;
            if(luomab[s[i]]>=luomab[s[i+1]])
                result+=luomab[s[i]];
            else
            {
                result+=(luomab[s[i+1]]-luomab[s[i]]);
                i++;
            }
        }
        return result;
    }
};