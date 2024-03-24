#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxSubarrayProduct(vector<int>& nums, int k, int m) {
    int n = nums.size();
    vector<vector<int>> dpmax(n + 1, vector<int>(m + 1, 0));
    vector<vector<int>> dpmin(n + 1, vector<int>(m + 1, 0));
    int result = INT_MIN;

    for (int i = 1; i <= n; ++i) {
        dpmax[i][1] = nums[i - 1];
        dpmin[i][1] = nums[i - 1];
        for (int j = 2; j <= min(m, i); ++j) {
            int currentMax = nums[i - 1], currentMin = nums[i - 1];
            for (int l = i - 1; l >= max(1, i - k + 1); --l) {
                currentMax = max(currentMax, max(nums[l - 1], dpmax[l][j - 1] * nums[i - 1]));
                currentMin = min(currentMin, min(nums[l - 1], dpmin[l][j - 1] * nums[i - 1]));
            }
            dpmax[i][j] = currentMax;
            dpmin[i][j] = currentMin;
        }
    }

    for (int i = k; i <= n; ++i) {
        for (int j = k; j <= m; ++j) {
            result = max(result, dpmax[i][j]);
        }
    }

    return result;
}

int main() {
    vector<int> nums = {2, -5, -2, -4, 3};
    int k = 2, m = 3;
    cout << maxSubarrayProduct(nums, k, m) << endl;
    return 0;
}
