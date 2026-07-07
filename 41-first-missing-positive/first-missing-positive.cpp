class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            int e = nums[i];
            if (e >= 1 && e <= n) {
                int pos =e -1; // beacuse if the n = 5 then it should be store idx = 4;

                if (nums[pos] != e) {
                    swap(nums[pos], nums[i]); // swap pos to the number;
                    i--;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1)
                return i + 1;
        }

        return n + 1;
    }
};