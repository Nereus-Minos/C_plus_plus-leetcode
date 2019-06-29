#if 0
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        
        //思路一（只能通过大部分，少部分超时）：首先将words的全排列，然后将每个排列都组成一个string放在一个vector(即ret_str)中然后将即ret_str中的元素一一在s串中循环寻找         
        
        vector<string> ret_str;  //返回拼接完成后的所有情况      
        string temp_str;       
        vector<int> ret_temp, ret;        
        int temp;
        
        //求出所有可能子串
        full_prem(0, words, temp_str, ret_str);
        
        //查找子串
        for(vector<string>::iterator iter = ret_str.begin(); iter < ret_str.end(); iter++)
        {
            temp = s.find(*iter);
            while(temp != -1)
            {
                ret_temp.push_back(temp);
                temp = s.find(*iter, temp+1);
            }    
        }
        
        //最后去重
        sort(ret_temp.begin(), ret_temp.end());
        for(temp = 0; temp < ret_temp.size(); temp++)
        {
            if((temp == 0) || (ret_temp[temp-1] != ret_temp[temp]))
                ret.push_back(ret_temp[temp]);
        }
        
        return ret;
    }
    
private:
    //前缀加后续
    void full_prem(int i, vector<string>& words, string& temp, vector<string> &ret_str)
    {
        if(i == words.size()-1)
        {
            temp += words[i];
            
            ret_str.push_back(temp);
        }
        
        else
        {
            for(int j = i; j < words.size(); j++)
            {
                int k = temp.length();
                swap(words[i], words[j]);
                temp += words[i];
                full_prem(i+1, words, temp, ret_str);
                swap(words[i], words[j]);
                temp.erase(k); //注意要抹去的从k到最后的所有元素！！！
            }
        }
    }
    
    void swap(string &str1, string &str2){
        string temp = str1;
        str1 = str2;
        str2 = temp;
    }
};
#endif

#if 0
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        
        if(s.length() == 0 || words.size() == 0 || words[0].length() * words.size() > s.length())
            return {};
        
        vector<int> ret;
        
        map<string,int> words_map;
        
        int i,j;
        
        int words_len = words.size();
        
        int one_word_len = words[0].length();
        
        int all_words_len = one_word_len * (words.size());
        
        for(i = 0; i < words_len; i++)
             words_map[words[i]] += 1;
            
        for(i = 0; i < s.length() - all_words_len + 1; i++)
        {
            map<string,int> sub_map;
            for(j = 0; j < words_len; j++)
                sub_map[s.substr(i+j*one_word_len, one_word_len)] += 1;  //substr第二个参数是个数
            
            if( equal(words_map.begin(), words_map.end(), sub_map.begin(), sub_map.end()) )
                ret.push_back(i);
        }
        
        return ret;
    }
};
#endif


#if 1
//思路三:优化，每次在构造sub_map时，先检测是否在words_map中，不在则直接pass掉
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        
        if(s.length() == 0 || words.size() == 0 || words[0].length() * words.size() > s.length())
            return {};
        
        vector<int> ret;
        
        map<string,int> words_map;
        
        int i,j;
        
        int words_len = words.size();
        
        int one_word_len = words[0].length();
        
        int all_words_len = one_word_len * (words.size());
        
        for(i = 0; i < words_len; i++)
             words_map[words[i]] += 1;
            
        for(i = 0; i < s.length() - all_words_len + 1; i++)
        {
            map<string,int> sub_map;
            for(j = 0; j < words_len; j++)
            {
                string str_temp = s.substr(i+j*one_word_len, one_word_len);
                if(words_map.find(str_temp) == words_map.end()) //表明不在words中
                    goto conti;
                sub_map[str_temp] += 1;  //substr第二个参数是个数
            }
               
            if( equal(words_map.begin(), words_map.end(), sub_map.begin(), sub_map.end()) )
                ret.push_back(i);
            conti:  ;
        }
        
        return ret;
    }
};
#endif