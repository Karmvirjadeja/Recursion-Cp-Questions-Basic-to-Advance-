class Solution {
public:
    int solve(int idx, vector<int>& final, unordered_map<int,int>& mp, int n,vector<int>& dp) {
        if (idx >= n) return 0;
        if(dp[idx]!=-1) return dp[idx];
        // Option 1: Skip current element
        int skip = dp[idx]=solve(idx + 1, final, mp, n,dp);


        // Option 2: Take current element and skip adjacent elements
        int take = dp[idx]=final[idx] * mp[final[idx]];
        int next_idx = idx + 1;
        while (next_idx < n && final[next_idx] == final[idx] + 1) {
            ++next_idx;
        }
        int total_take = take + solve(next_idx, final, mp, n,dp);


        // Return maximum profit of both options
        return dp[idx]=max(skip, total_take);
    }


    int deleteAndEarn(vector<int>& nums) {
        unordered_map<int, int> mp;
        unordered_set<int> s;
        vector<int> dp(10001,-1);


        // Count occurrences of each number
        for (int num : nums) {
            mp[num]++;
            s.insert(num);
        }


        // Convert set to sorted vector
        vector<int> final(s.begin(), s.end());
        sort(final.begin(), final.end());


        int n = final.size();
        return solve(0, final, mp, n,dp);
    }
};

