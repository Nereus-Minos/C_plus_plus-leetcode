class Solution {
public:
    vector<string> letterCombinations(string digits) {
        
        //特殊情况
        if(digits.size()==0) return {};
        
        //思路：建立map映射关系
        map<char, string>a;
        a.insert(pair<int,string>('2', "abc"));
        a.insert(pair<int,string>('3', "def"));
        a.insert(pair<int,string>('4', "ghi"));
        a.insert(pair<int,string>('5', "jkl"));
        a.insert(pair<int,string>('6', "mno"));
        a.insert(pair<int,string>('7', "pqrs"));
        a.insert(pair<int,string>('8', "tuv"));
        a.insert(pair<int,string>('9', "wxyz"));
        
        int i, j, k, index, cap = 1;
        
        vector<string> ret, temp;
        
        char c;
        
        //求出总容量
        for(i = 0; i < digits.length(); i++)
        {
                if(digits[i] != '7' && digits[i] != '9')
                    cap *= 3;
                else
                    cap *= 4;
        }
        
        ret.resize(cap);
        
        //将所有组合求出
        cap = 1;
        for(i = 0; i < digits.length(); i++)
        {
            index = 0;
            temp.assign(ret.begin(),ret.begin()+cap);
            for(j = 0; j < cap; j++)
            {
                for(k = 0; k < a[digits[i]].size(); k++)
                {
                    c = a[digits[i]][k];
                    ret[index] = temp[j] + c;
                    index++;
                }
            }
            
            cap *= a[digits[i]].size();
        }
        
        return ret;
    }
};