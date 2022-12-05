import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

/**
 * Java
 *
 * @Description: TODO
 * @Author: cherry
 * @Create on: 2022/7/25
 **/

public class No919 {
    private static class TreeNode {
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

    private static class CBTInserter {
        private TreeNode root = null;
        private Queue<TreeNode> curr = new LinkedList<>();

        public CBTInserter(TreeNode root) {
            this.root = root;
            Queue<TreeNode> queue = new LinkedList<>();
            queue.add(root);
            while (!queue.isEmpty()) {
                int size = queue.size();
                for (int i = 0; i < size; ++i) {
                    TreeNode node = queue.poll();
                    assert node != null;
                    if (node.left != null) queue.add(node.left);
                    if (node.right != null) queue.add(node.right);
                    else curr.add(node);
                }
            }
        }

        public int insert(int val) {
            TreeNode node = new TreeNode(val);
            TreeNode front = curr.peek();
            if (front.left == null) {
                front.left = node;
            } else {
                front.right = node;
                curr.poll();
            }
            curr.add(node);
            return front.val;
        }

        public TreeNode get_root() {
            return root;
        }
    }

    public static void main(String[] args) {
        TreeNode root = new TreeNode(1);
        CBTInserter cbtInserter = new CBTInserter(root);
        cbtInserter.insert(2);
        cbtInserter.insert(3);
        cbtInserter.insert(4);
        StringBuilder builder = new StringBuilder();
        List<Integer> list = new ArrayList<>();

    }
}
