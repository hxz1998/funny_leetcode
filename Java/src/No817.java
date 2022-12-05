import java.util.HashSet;
import java.util.Set;

/**
 * Java
 *
 * @Description: TODO
 * @Author: cherry
 * @Create on: 2022/10/12
 **/

public class No817 {
    public class ListNode {
        int val;
        ListNode next;

        ListNode() {
        }

        ListNode(int val) {
            this.val = val;
        }

        ListNode(int val, ListNode next) {
            this.val = val;
            this.next = next;
        }
    }

    public int numComponents(ListNode head, int[] nums) {
        int ret = 0;
        Set<Integer> seen = new HashSet<>();
        for (int num : nums) seen.add(num);
        boolean isHead = true;
        while (head != null) {
            if (seen.contains(head.val)) {
                if (isHead) {
                    ++ret;
                    isHead = false;
                }
            } else {
                isHead = true;
            }
            head = head.next;
        }
        return ret;
    }
}
