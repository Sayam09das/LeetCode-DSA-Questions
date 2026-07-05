class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;

        sort(begin(nums), end(nums));
        int n = nums.size();
        for (int i = 0; i < n - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1]){
                continue;
            }
            for (int j = i + 1; j < n - 2; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]){
                    continue;
                }
                int k = j + 1;
                int m = n - 1;

                while (k < m) {
                    long long sum = (long long)nums[i] + (long long)nums[j] +
                                    (long long)nums[k] + (long long)nums[m];

                    if (sum < target){
                        k++;
                    }else if (sum > target){
                        m--;
                    }
                    else {
                        ans.push_back({nums[i], nums[j], nums[k], nums[m]});
                        k++;
                        m--;

                        while (k < m && nums[k] == nums[k - 1]){
                            k++;
                        }
                        while (k < m && nums[m] == nums[m + 1]){
                            m--;
                        }
                    }
                }
            }
        }
        return ans;
    }
};