#if 0
//方法一：分别写三个验证函数，行验证，列验证，3*3验证
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        //写三个函数分别验证
        return rowIsValid(board) && colIsValid(board) && threeIsValid(board);
    }
    
private:
    bool rowIsValid(vector<vector<char>>& board){
        
        for(int i = 0; i < 9; i++)
        {
            map<int, int> temp;
            for(int j = 0; j < 9; j++)
            {
                if(board[i][j] != '.')
                {
                    if(temp.find(board[i][j]) != temp.end())
                        return false;
                    else
                        temp[board[i][j]] = 1;
                }
            }
        }
        return true;
    }
    
    bool colIsValid(vector<vector<char>>& board){
        for(int i = 0; i < 9; i++)
        {
            map<int, int> temp;
            for(int j = 0; j < 9; j++)
            {
                if(board[j][i] != '.')
                {
                    if(temp.find(board[j][i]) != temp.end())
                        return false;
                    else
                        temp[board[j][i]] = 1;
                }
            }
        }
        return true;
    }
    
    bool threeIsValid(vector<vector<char>>& board){
        
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                map<int, int> temp;
                
                for(int k = 0; k < 9; k++)
                {
                    if(board[i*3+(k/3)][j*3+(k%3)] != '.')
                    {
                        if(temp.find(board[i*3+(k/3)][j*3+(k%3)]) != temp.end())
                            return false;
                        else
                            temp[board[i*3+(k/3)][j*3+(k%3)]] = 1;
                    }
                }
            }
        }
        return true;
    }
};
#endif

#if 1
//方法二：使用三个存放map的vecotr来一次遍历
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        vector<map<int,int>> row(9), col(9), sub(9);
        
        for(int i = 0; i < 9; i++)
        {
            for(int j = 0; j < 9; j++)
            {
                if(board[i][j] == '.')
                    continue;
                
                if(row[i].find(board[i][j]) != row[i].end())  //表明行中元素有重复
                    return false;
                   
                if(col[j].find(board[i][j]) != col[j].end())   //表明列中元素有重复
                    return false;
                
                if(sub[(i/3)*3 + j/3].find(board[i][j]) != sub[(i/3)*3 + j/3].end())  //表明3*3有重复
                    return false;
                
                row[i][board[i][j]] = 1;
                col[j][board[i][j]] = 1;
                sub[(i/3)*3 + j/3][board[i][j]] = 1;
            }
        }
       return true;
    }
    
};
#endif