class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ret;
        
        string str(n, '.');
        vector<string> temp(n, str);
        
        solve(0, n, temp, ret);
        
        return ret;
    }
    
private:
    void solve(int i, int& n, vector<string> temp, vector<vector<string>>& ret){
        
        if(i == n)
        {
            ret.push_back(temp);
        }
        
        else
        {
            for(int j = 0; j < n; j++)
            {
                
                if(!isValid(temp,i,j,n))
                    continue;
                
                temp[i][j] = 'Q';
                
                solve(i+1, n, temp, ret);
                
                //消除
                temp[i][j] = '.';
            }
        }
    }
    
    bool isValid(vector<string> &temp, int& i, int& j, int& n){
        int k, l;
        for(k = 0; k < i; k++) //正上检查
        {
            if('Q'==temp[k][j])
                return false;
        }

        k = i;
        l = j;
        while(k >= 0 && l >= 0)   //左上检查
        {
            if('Q'==temp[k][l])
                return false;
            k -= 1;
            l -= 1;
        }

        k = i;
        l = j;
        while(k >= 0 && l < n)    //右上检查
        {
            if('Q'==temp[k][l])
                return false;
            k -= 1;
            l += 1;
        }

        return true;    
    }
};