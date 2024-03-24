def max_subarray_product(nums, k, m):
    n = len(nums)
    dpmax = [[0] * (m + 1) for _ in range(n + 1)]
    dpmin = [[0] * (m + 1) for _ in range(n + 1)]
    result = float('-inf')

    for i in range(1, n + 1):
        dpmax[i][1] = nums[i - 1]
        dpmin[i][1] = nums[i - 1]
        for j in range(2, min(m, i) + 1):
            current_max, current_min = nums[i - 1], nums[i - 1]
            for l in range(i - 1, max(0, i - k), -1):
                current_max = max(current_max, max(nums[l - 1], dpmax[l][j - 1] * nums[i - 1]))
                current_min = min(current_min, min(nums[l - 1], dpmin[l][j - 1] * nums[i - 1]))
            dpmax[i][j] = current_max
            dpmin[i][j] = current_min

    for i in range(k, n + 1):
        for j in range(k, m + 1):
            result = max(result, dpmax[i][j])

    return result

nums = [2, -5, -2, -4, 3]
k, m = 2, 3
print(max_subarray_product(nums, k, m))
