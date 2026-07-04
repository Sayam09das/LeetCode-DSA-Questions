class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.end(), nums2.begin(), nums2.end());

        sort(begin(nums1), end(nums1));

        int n = nums1.size();

        if (n % 2 == 1) {
            return nums1[n / 2];
        } else {
            double median = (nums1[n / 2 - 1] + nums1[n / 2]) / 2.0;
            return median;
        }
    }
};