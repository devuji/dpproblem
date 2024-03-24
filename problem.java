import java.util.Arrays;

public class Main {
    public static int maxSubarrayProduct(int[] nums, int k, int m) {
        int n = nums.length;
        int[][] dpmax = new int[n + 1][m + 1];
        int[][] dpmin = new int[n + 1][m + 1];
        int result = Integer.MIN_VALUE;

        for (int i = 1; i <= n; ++i) {
            dpmax[i][1] = nums[i - 1];
            dpmin[i][1] = nums[i - 1];
            for (int j = 2; j <= Math.min(m, i); ++j) {
                int currentMax = nums[i - 1], currentMin = nums[i - 1];
                for (int l = i - 1; l >= Math.max(1, i - k + 1); --l) {
                    currentMax = Math.max(currentMax, Math.max(nums[l - 1], dpmax[l][j - 1] * nums[i - 1]));
                    currentMin = Math.min(currentMin, Math.min(nums[l - 1], dpmin[l][j - 1] * nums[i - 1]));
                }
                dpmax[i][j] = currentMax;
                dpmin[i][j] = currentMin;
            }
        }

        for (int i = k; i <= n; ++i) {
            for (int j = k; j <= m; ++j) {
                result = Math.max(result, dpmax[i][j]);
            }
        }

        return result;
    }

    public static void main(String[] args) {
        int[] nums = {2, -5, -2, -4, 3};
        int k = 2, m = 3;
        System.out.println(maxSubarrayProduct(nums, k, m));
    }
}
