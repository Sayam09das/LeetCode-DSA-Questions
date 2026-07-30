class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
        vector<int> arr(matrix.size());

        for (int i = 0; i < matrix.size(); i++) {
            int count = 0;

            for (int j = 0; j < matrix.size(); j++) {
                if (matrix[i][j] == 1) {
                    count++;
                }
            }

            arr[i] = count;
        }

        return arr;
    }
};