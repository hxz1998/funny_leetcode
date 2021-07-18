package interview;

import java.util.Arrays;

public class No10dot11 {
    public void wiggleSort(int[] nums) {
        Arrays.sort(nums);
        int n = nums.length;
        int[] arr = new int[n];
        int left = 0, right = n - 1, idx = 0;
        while (left < right) {
            arr[idx++] = nums[left++];
            arr[idx++] = nums[right--];
        }
        if (n % 2 == 1) arr[idx] = nums[left];
        System.arraycopy(arr, 0, nums, 0, n);
    }
}
