/**
 * Java
 *
 * @Description: TODO
 * @Author: cherry
 * @Create on: 2022/8/30
 **/

public class No654 {
    class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;

        TreeNode() {
        }

        TreeNode(int val) {
            this.val = val;
        }

        TreeNode(int val, TreeNode left, TreeNode right) {
            this.val = val;
            this.left = left;
            this.right = right;
        }
    }


    public TreeNode constructMaximumBinaryTree(int[] nums) {
        int n = nums.length;
        if (n == 0) return null;
        return helper(nums, 0, n - 1);
    }


    private TreeNode helper(int[] nums, int left, int right) {
        if (left == right) return new TreeNode(nums[left]);
        if (left > right) return null;
        int index = left;
        for (int idx = left + 1; idx <= right; ++idx) {
            if (nums[idx] > nums[index]) index = idx;
        }
        TreeNode root = new TreeNode(nums[index]);
        root.left = helper(nums, left, index - 1);
        root.right = helper(nums, index + 1, right);
        return root;
    }

    public TreeNode insertIntoMaxTree(TreeNode root, int val) {
        if (root == null || root.val < val) return new TreeNode(val);
        return insertIntoMaxTree(root.left, val);
    }


}
