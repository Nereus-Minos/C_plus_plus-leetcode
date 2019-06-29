/*
思路:转置加翻转:最直接的想法是先转置矩阵，然后翻转每一行。这个简单的方法已经能达到最优的时间复杂度O(N^2)。
*/
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int i, j;
        for(i = 0;i<matrix.size();i++)
            for(j=i;j<matrix.size();j++)
                 RotateMatrix(matrix,i,j);
        
        for(i=0;i<matrix.size();i++)
            for(j=0;j<matrix.size()/2;j++)
                RowMatrix(matrix,i,j);
    }
    
private:
   void RotateMatrix(vector<vector<int>>& matrix, int i, int j){
       int temp = matrix[i][j];
       matrix[i][j] = matrix[j][i];
       matrix[j][i] = temp;
   }
    
   void RowMatrix(vector<vector<int>>& matrix,int i,int j){
       int temp = matrix[i][j];
       matrix[i][j] = matrix[i][matrix.size()-j-1];
       matrix[i][matrix.size()-j-1] = temp;
   }
       
};