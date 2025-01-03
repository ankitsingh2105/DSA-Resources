//https://leetcode.com/problems/tallest-billboard/

class Solution {
public:
    int solve(vector<int>& newRods, int i, int difference, vector<vector<int>>& dp){
        if(i == newRods.size()){
            if(difference == 0){
                return 0;
            }
            return INT_MIN;
        }
        if(dp[i][difference + 5001] != -1) {
            return dp[i][difference + 5001];
        }
        int addInFirstSupport = newRods[i] + solve(newRods, i+1, difference + newRods[i], dp);
        int addInSecondSupport = solve(newRods, i+1, difference  - newRods[i], dp);
        int notAdding = solve(newRods, i+1, difference, dp);
        dp[i][difference + 5001] = max({addInFirstSupport, addInSecondSupport, notAdding});
        return dp[i][difference + 5001];
    }
    int tallestBillboard(vector<int>& rods) {
        int sum = 0;
        vector<vector<int>> dp(21, vector<int>( 2*5001, -1));
        int ans = solve(rods, 0, 0, dp);
        return ans;
    }
};
