function maxSubarrayProduct(nums, k, m) {
    const n = nums.length;
    const dpmax = Array.from({ length: n + 1 }, () => Array(m + 1).fill(0));
    const dpmin = Array.from({ length: n + 1 }, () => Array(m + 1).fill(0));
    let result = Number.MIN_SAFE_INTEGER;

    for (let i = 1; i <= n; ++i) {
        dpmax[i][1] = nums[i - 1];
        dpmin[i][1] = nums[i - 1];
        for (let j = 2; j <= Math.min(m, i); ++j) {
            let currentMax = nums[i - 1];
            let currentMin = nums[i - 1];
            for (let l = i - 1; l >= Math.max(1, i - k + 1); --l) {
                currentMax = Math.max(currentMax, Math.max(nums[l - 1], dpmax[l][j - 1] * nums[i - 1]));
                currentMin = Math.min(currentMin, Math.min(nums[l - 1], dpmin[l][j - 1] * nums[i - 1]));
            }
            dpmax[i][j] = currentMax;
            dpmin[i][j] = currentMin;
        }
    }

    for (let i = k; i <= n; ++i) {
        for (let j = k; j <= m; ++j) {
            result = Math.max(result, dpmax[i][j]);
        }
    }

    return result;
