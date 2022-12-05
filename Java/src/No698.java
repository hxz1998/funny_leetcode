/**
 * Java
 *
 * @Description: TODO
 * @Author: cherry
 * @Create on: 2022/9/20
 **/

public class No698 {
    public boolean canPartitionKSubsets(int[] nums, int k) {
        int sum = 0;
        int max = 0;
        for (int num : nums) {
            sum += num;
            max = Math.max(max, num);
        }
        if (sum % k != 0) return false;
        int target = sum / k;
        if (target < max) return false;
        return backtrack(nums, 0, new int[k], k, target);
    }

    private boolean backtrack(int[] nums, int index, int[] buckets, int k, int target) {
        if (index == nums.length) {
            for (int bucket : buckets) {
                if (bucket != target) return false;
            }
            return true;
        }
        for (int i = 0; i < k; ++i) {
            if (buckets[i] + nums[index] > target) continue;
            buckets[i] += nums[index];
            if (backtrack(nums, index + 1, buckets, k, target)) return true;
            buckets[i] -= nums[index];
        }
        return false;
    }
}
