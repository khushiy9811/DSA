class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // int m =matrix[0].size();
        // int n =matrix.size();
        // int tr = -1;

        // for(int i = 0; i < n; i++) {
        //     if(matrix[i][m-1] >= target) {
        //         tr = i;
        //         break;
        //     }
        // }

        // if(tr == -1)
        //     return false;

        // for(int i = 0; i < m; i++) {
        //     if(matrix[tr][i] == target)
        //         return true;
        // }

        // return false;/






        // 2nd approach 

        int m =matrix.size();
        int n=matrix[0].size();
        int l=0;
        int h=(m*n-1);
        while(l<=h){
            int mid=l+(h-l)/2;
            int row = mid / n;
            int col = mid % n;

            if (matrix[row][col] == target)
                return true;
            else if (matrix[row][col] < target)
                l = mid + 1;
            else
                h = mid - 1;
        }
        return false;


    }
};