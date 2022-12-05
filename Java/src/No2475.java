/**
 * Java
 *
 * @Description: TODO
 * @Author: cherry
 * @Create on: 2022/8/5
 **/

public class No2475 {
    public int reversePairs(int[] nums) {
        int n = nums.length;
        if (n == 0) return 0;
        int[] copy = new int[n];
        for (int idx = 0; idx < n; ++idx) {
            copy[idx] = nums[idx];
        }
        return reversePairs(nums, copy, 0, n - 1);
    }

    private int reversePairs(int[] nums, int[] aux, int left, int right) {
        if (left >= right) return 0;
        int mid = left + (right - left) / 2;
        int leftPairs = reversePairs(nums, aux, left, mid);
        int rightPairs = reversePairs(nums, aux, mid + 1, right);
        if (nums[mid] <= nums[mid + 1]) return leftPairs + rightPairs;
        int crossCount = mergeAndCount(nums, aux, left, mid, right);
        return leftPairs + crossCount + rightPairs;
    }

    private int mergeAndCount(int[] nums, int[] aux, int left, int mid, int right) {
        for (int idx = left; idx <= right; ++idx) {
            aux[idx] = nums[idx];
        }
        int i = left, j = mid + 1;
        int count = 0;
        for (int idx = left; idx <= right; ++idx) {
            if (i == mid + 1) {
                nums[idx] = aux[j];
                j++;
            } else if (j == right + 1) {
                nums[idx] = aux[i];
                i++;
            } else if (aux[i] <= aux[j]) {
                nums[idx] = aux[i];
                i++;
            } else {
                nums[idx] = aux[j];
                j++;
                count += (mid - i) + 1;
            }
        }
        return count;
    }

    public static void main(String[] args) {

    }
}
