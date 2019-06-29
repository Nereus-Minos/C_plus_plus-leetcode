class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        //首先提取当前有的元素，放在三个vector<map<int,int>>
        vector<map<int,int>> row(9), col(9), sub(9);
        
        rowColSub(board, row, col, sub);
 
        int flag = 0;
        //然后在使用普通递归的方法找出答案
        solve(board, row, col, sub, 0, 0, flag); //必须立一个flag，因为当递归到最后，还需要返回到上一次，而之后的代码还原了board，所以需要判断是否需要还原！！！
        
    }

private:
    void rowColSub(vector<vector<char>>& board, vector<map<int,int>>& row, vector<map<int,int>>& col, vector<map<int,int>>& sub){
        
        for(int i =0; i<9; i++)
            for(int j=0; j<9;j++)
            {
                row[i][board[i][j]] = 1; 
                col[j][board[i][j]] = 1;  
                sub[(i/3)*3 + j/3][board[i][j]] = 1; 
            }
    }
    
    void solve( vector<vector<char>>& temp, vector<map<int,int>>& row, vector<map<int,int>>& col, vector<map<int,int>>& sub, int i, int j, int& flag){
       if(flag == 1)
           return ;
        
        if(j == 9)
        {
            j = 0;
            i++;
        }
        if(i == 9)  //已经解数独了
        {
            flag = 1;
            return ;
        }
        
        while(temp[i][j] != '.')  //确保每次递归回来的i和j是添加值的位置
        {
            j++;
            if(j == 9)
            {
                j = 0;
                i++;
            }
            if(i == 9)  //已经解数独了
            {
                flag = 1;
                return ;
            }
        }
        
        for(int k = 1; k <= 9; k++)
        {
            if(row[i].find(k+48) != row[i].end())
                continue;
            if(col[j].find(k+48) != col[j].end())
                continue;
            if(sub[(i/3)*3 + j/3].find(k+48) != sub[(i/3)*3 + j/3].end())
                continue;
            else
            {
                temp[i][j] = k+48;
                row[i][temp[i][j]] = 1; 
                col[j][temp[i][j]] = 1;  
                sub[(i/3)*3 + j/3][temp[i][j]] = 1; 
                
                solve(temp, row, col, sub, i, j+1, flag);   //递归
               
                if(flag == 1)  //判断是否需要还原
                    return ;
                
                row[i].erase(temp[i][j]); 
                col[j].erase(temp[i][j]);  
                sub[(i/3)*3 + j/3].erase(temp[i][j]); 
                temp[i][j] = '.';
            }
        }
        
        //没找到回到上一次添值的位置重新开始，所以要使用递归
        return ;
    }
};