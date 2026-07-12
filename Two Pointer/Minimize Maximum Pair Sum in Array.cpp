class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n =nums.size();
        int s=0;
        int e= n-1;
        int m=0;
        while(s<e){
            m=max(m,nums[s]+nums[e]);
            s++;
            e--;

        }
        return m;        
    }
};
