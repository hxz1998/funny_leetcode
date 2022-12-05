import sun.misc.Unsafe;

import java.lang.reflect.Constructor;
import java.lang.reflect.Field;
import java.lang.reflect.InvocationTargetException;

/**
 * Java
 *
 * @Description: TODO
 * @Author: cherry
 * @Create on: 2022/8/9
 **/

public class No142 {
    private static class ListNode {
        int val;
        ListNode next;

        ListNode(int x) {
            val = x;
            next = null;
        }
    }

    public ListNode detectCycle(ListNode head) {
        ListNode fast = head, slow = head;
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
            if (fast == slow) {
                ListNode ptr = head;
                while (ptr != slow) {
                    ptr = ptr.next;
                    slow = slow.next;
                }
                return ptr;
            }
        }
        return null;
    }

    static class A {
        String str = "11";
        int num = 0;
        byte b = 0x1;
    }

    private static Unsafe getUnsafeInstance() {
        try {
            Constructor<Unsafe> constructor = Unsafe.class.getDeclaredConstructor();
            constructor.setAccessible(true);
            return constructor.newInstance();
        } catch (Exception e) {
            return null;
        }
    }

    public static void main(String[] args) throws NoSuchMethodException, InvocationTargetException, InstantiationException, IllegalAccessException, NoSuchFieldException {
        Unsafe unsafe = getUnsafeInstance();
        assert unsafe != null;
        for (Field field : A.class.getDeclaredFields()) {
            System.out.println(field + ": " + unsafe.objectFieldOffset(field));
        }
    }
}
