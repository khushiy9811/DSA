class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {

        // Better Approach 
        // int n = grid.size();
        // unordered_map<int, int> mp;

        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < n; j++) {
        //         mp[grid[i][j]]++;
        //     }
        // }

        // vector<int> ans(2);

        // for (int i = 1; i <= n * n; i++) {
        //     if (mp[i] == 2)
        //         ans[0] = i;
        //     else if (mp[i] == 0)
        //         ans[1] = i;
        // }

        // return ans;


        // Optimal solution 
        vector<int> v(2);

        int m = grid.size();
        int n = m * m;

        long long sum = 0;
        long long square = 0;

        long long nsum = 1LL * n * (n + 1) / 2;
        long long nsquare = 1LL * n * (n + 1) * (2LL * n + 1) / 6;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                sum += grid[i][j];
                square += 1LL * grid[i][j] * grid[i][j];
            }
        }

        long long n1 = sum - nsum;
        long long n2 = (square - nsquare) / n1;

        int dup = (n1 + n2) / 2;
        int missing = dup - n1;

        v[0] = dup;
        v[1] = missing;

        return v;
    }
};