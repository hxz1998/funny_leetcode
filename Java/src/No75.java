/**
 * Java
 *
 * @Description: TODO
 * @Author: cherry
 * @Create on: 2022/8/9
 **/

public class No75 {
    public void sortColors(int[] nums) {
        int n = nums.length;
        int left = 0, right = n - 1;
        for (int idx = 0; idx <= right; ++idx) {
            while (idx <= right && nums[idx] == 2) swap(nums, idx, right--);
            if (nums[idx] == 0) swap(nums, left++, idx);
        }
    }

    private void swap(int[] nums, int l, int r) {
        int temp = nums[l];
        nums[l] = nums[r];
        nums[r] = temp;
    }

    public static void main(String[] args) {
        int[] nums = new int[]{2, 0, 2, 1, 0, 1, 1, 1, 0};
        new No75().sortColors(nums);
        System.out.println();
    }
}
