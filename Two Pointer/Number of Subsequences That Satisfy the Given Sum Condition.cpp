class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        const int M = 1e9 + 7;

        sort(nums.begin(), nums.end());

        int n = nums.size();

        vector<int> power(n);
        power[0] = 1;

        for (int i = 1; i < n; i++) {
            power[i] = (power[i - 1] * 2LL) % M;
        }

        int l = 0;
        int r = n - 1;
        int ans = 0;

        while (l <= r) {
            if (nums[l] + nums[r] <= target) {
                ans = (ans + power[r - l]) % M;
                l++;
            } else {
                r--;
            }
        }

        return ans;
    }
};
