class Solution {
public:
    vector<vector<int>> result;

    void solve(int start, vector<int>& temp, int sum, int count, int target) {
        // Base case: when count is 0 and sum is equal to target
        if(count == 0 && sum == target) {
            result.push_back(temp);
            return;
        }

        // If the count is 0 or the sum is greater than target, we need to stop
        if(count == 0 || sum > target) {
            return;
        }

        // Iterate over possible numbers starting from 'start'
        for(int i = start; i <= 9; ++i) {
            temp.push_back(i);
            sum += i;
           
            // Recur with next number, decreased count and updated sum
            solve(i + 1, temp, sum, count - 1, target);

            // Backtrack to explore other possibilities
            temp.pop_back();
            sum -= i;
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> temp;
        result.clear(); // Clear result for fresh start
        solve(1, temp, 0, k, n); // Start from 1 with sum 0 and count k
        return result;
    }
};



