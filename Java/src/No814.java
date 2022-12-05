import java.lang.reflect.InvocationTargetException;

/**
 * Java
 *
 * @Description: TODO
 * @Author: cherry
 * @Create on: 2022/7/21
 **/

public class No814 {
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

    public TreeNode pruneTree(TreeNode root) {
        if (root == null) return null;
        boolean ret = dfs(root);
        return ret ? root : null;
    }

    private boolean dfs(TreeNode root) {
        if (root == null) return true;
        boolean left = dfs(root.left);
        boolean right = dfs(root.right);
        if (!left) root.left = null;
        if (!right) root.right = null;
        return root.val == 1 || left || right;
    }

    private static class B {
        // 删了之后抛异常 NoSuchMethodException
        public void hello() {
            System.out.println("hello");
        }

        public void hello(String name) {
            System.out.println(name);
        }
    }

    public static void main(String[] args) throws NoSuchMethodException, InvocationTargetException, IllegalAccessException {
        B b = new B();
        b.getClass().getMethod("hello").invoke(b); // hello


        String s1 = "Hel" + new String("lo");
        String s2 = s1.intern();
        String s3 = "Hello";
        String s4 = "Hel" + "lo";
        String s5 = new String("Hello");
        String s6 = s5.intern();
        String s7 = "H";
        String s8 = "ello";
        String s9 = s7 + s8;
        final String s10 = "H";
        final String s11 = "ello";
        String s12 = s10 + s11;
        //jdk1.7+结果
        System.out.println(s3 == s1);// true
        System.out.println(s3 == s2);// true
        System.out.println(s3 == s4);// true
        System.out.println(s3 == s5);// false
        System.out.println(s3 == s6);// true
        System.out.println(s3 == s9);// false
        System.out.println(s3 == s12);// true
    }
}
