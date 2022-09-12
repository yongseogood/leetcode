class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        ans.clear();
        target_ = target;
        vector<int> op;
        sort(candidates.begin(), candidates.end());
        solve(candidates, 0, 0, op);
        
        return ans;
    }

private:
    int target_;
    vector<vector<int>> ans;

    void solve(vector<int>& arr, int i, int sum, vector<int> op)
    {
        if(i >= arr.size()) return;
        
        if(arr[i] + sum == target_)
        {
            op.push_back(arr[i]);
            ans.push_back(op);
            return;
        }
        
        if(arr[i] + sum < target_)
        {
            vector<int> op1 = op;
            vector<int> op2 = op;
            
            op2.push_back(arr[i]);
            solve(arr, i, sum + arr[i], op2);
            solve(arr, i + 1, sum, op1);
        }
        else solve(arr, i + 1, sum, op);
    }
};
