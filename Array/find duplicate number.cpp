class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        // Simple method

        // sort(nums.begin(), nums.end());
        // int n = nums.size();
        // for (int i = 0; i < n - 1; i++) {
        //     if (nums[i] == nums[i + 1]) {
        //         return nums[i];
        //     }
        // }
        // return -1; 
        

        //  WIthout modification
        // HAre and tortoise method 

        int n =nums.size();
        int s=nums[0];
        int f=nums[0];
        s=nums[s];
        f=nums[nums[f]];
        while(s!=f){
            s=nums[s];
            f=nums[nums[f]];
        }
        s=nums[0];
        while(s!=f){
            s=nums[s];
            f=nums[f];
        }
        return f;


    }
    
};