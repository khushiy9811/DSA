//  Brute Force
#include <iostream>
using namespace std;
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        vector<vector<int>> temp = matrix;

        int m = matrix.size();
        int n = matrix[0].size();

        for(int i = 0; i < m; i++) {

            for(int j = 0; j < n; j++) {

                if(matrix[i][j] == 0) {

                    for(int k = 0; k < n; k++) {
                        temp[i][k] = 0;
                    }

                    for(int k = 0; k < m; k++) {
                        temp[k][j] = 0;
                    }
                }
            }
        }

        matrix = temp;
    }
};





//  Better Solution 

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<bool> row(m,false);
        vector<bool> col(n,false);
        


        for(int i = 0; i < m; i++) {

            for(int j = 0; j < n; j++) {

                if(matrix[i][j] == 0) {
                    row[i]=true;
                    col[j]=true;
                    }}}
                for(int i=0;i<m;i++){
                    for(int j=0;j<n;j++){
                        if(row[i]==true || col[j]==true){
                            matrix[i][j]=0;
                        }
                    }
                }   
            }
        

    
};


// Optimal Solution 



class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        int m = matrix.size();
        int n = matrix[0].size();

        bool firstRowImpacted = false;
        bool firstColumnImpacted = false;

        // Step 1: Check if the first row contains any zero
        for (int j = 0; j < n; j++) {
            if (matrix[0][j] == 0) {
                firstRowImpacted = true;
                break;
            }
        }

        // Step 2: Check if the first column contains any zero
        for (int i = 0; i < m; i++) {
            if (matrix[i][0] == 0) {
                firstColumnImpacted = true;
                break;
            }
        }

        // Step 3: Use first row and first column as markers
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // Step 4: Set cells to zero based on markers
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        // Step 5: Zero out the first row if needed
        if (firstRowImpacted) {
            for (int j = 0; j < n; j++) {
                matrix[0][j] = 0;
            }
        }

        // Step 6: Zero out the first column if needed
        if (firstColumnImpacted) {
            for (int i = 0; i < m; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};

