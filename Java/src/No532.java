import java.util.HashSet;
import java.util.Set;

/**
 * Java
 *
 * @Description: TODO
 * @Author: cherry
 * @Create on: 2022/6/16
 */

public class No532 {
    private static class Pair<T> {
        T[] data;

        Pair(T p1, T p2) {
            data = (T[]) new Object[2];
            data[0] = p1;
            data[1] = p2;
        }

        @Override
        public int hashCode() {
            return data[0].hashCode() | data[1].hashCode();
        }

        @Override
        public boolean equals(Object obj) {
            if (obj instanceof Pair) {
                Pair<T> other = (Pair<T>) obj;
                return data[0].equals(other.data[0]) && data[1].equals(other.data[1]);
            }
            return false;
        }
    }

    public int findPairs(int[] nums, int k) {
        int ans = 0;
        Set<Pair<Integer>> record = new HashSet<>();
        Set<Integer> set = new HashSet<>();
        for (int num : nums) {
            if (set.contains(k + num) && !record.contains(new Pair<>(num, num + k))) {
                record.add(new Pair<>(num, num + k));
                ans++;
            }
            if (set.contains(num - k) && !record.contains(new Pair<>(num - k, num))) {
                record.add(new Pair<>(num - k, num));
                ans++;
            }
            set.add(num);
        }
        return ans;
    }

    public static void main(String[] args) {

    }
}
