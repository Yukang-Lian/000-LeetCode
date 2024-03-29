/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        int a,b,c,d;
        int ptr1,ptr2;
        vector<vector<int>> output;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<n-3;i++){
            if((i>0)&&(nums[i]==nums[i-1])) continue;
            if ((long) nums[i] + nums[i+1] + nums[i+2] + nums[i+3] > target) {
                break;
            }
            if ((long) nums[i] + nums[n-3] + nums[n-2] + nums[n-1] < target) {
                continue;
            }
            for(int j=i+1;j<n-2;j++){
                if((j>i+1)&&(nums[j]==nums[j-1])) continue;
                ptr1=j+1;
                ptr2=n-1;
                while(ptr1<ptr2){
                    if((long)nums[i]+nums[j]+nums[ptr1]+nums[ptr2]==target){
                        if(ptr1>j+1 && nums[ptr1]==nums[ptr1-1]) {
                            ptr1++;
                            continue;
                        } 
                        if(ptr2<n-1 && nums[ptr2]==nums[ptr2+1]) {
                            ptr2--;
                            continue;
                        }
                        output.push_back({nums[i],nums[j],nums[ptr1],nums[ptr2]});
                        ptr1++;
                        ptr2--;
                        continue;
                    }
                    if((long)nums[i]+nums[j]+nums[ptr1]+nums[ptr2]<target){
                        ptr1++;
                        continue;
                    }
                    if((long)nums[i]+nums[j]+nums[ptr1]+nums[ptr2]>target){
                        ptr2--;
                        continue;
                    }
                }
            }
        }
        return output;
    }
};
// @lc code=end

