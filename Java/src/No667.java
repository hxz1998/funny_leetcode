import java.lang.reflect.Array;
import java.lang.reflect.InvocationTargetException;
import java.util.Arrays;

public class No667 {
    public int[] constructArray(int n, int k) {
        int[] ans = new int[n];
        int idx = 0;
        for (int i = 1; i < n - k; ++i) {
            ans[idx++] = i;
        }
        for (int i = n - k, j = n; i <= j; ++i, --j) {
            ans[idx++] = i;
            if (i != j) {
                ans[idx++] = j;
            }
        }
        return ans;
    }

    public static void main(String[] args) throws NoSuchMethodException, InvocationTargetException,
            InstantiationException, IllegalAccessException {
        No667 no667 = new No667();
        // [1, 5, 2, 4, 3] is correct, [5, 4, 3, 0, 0] is wrong.
        System.out.println(Arrays.toString(no667.constructArray(5, 4)));
        String str = String.class.getConstructor().newInstance();
        System.out.println(str.length());
        String str2 = getInstance(String.class);
        System.out.println(str2.length());
        String[] strs = (String[]) Array.newInstance(String.class, 2);
        System.out.println(strs.length);
    }

    private static <T> T getInstance(Class<T> clazz) throws NoSuchMethodException, InvocationTargetException,
            InstantiationException, IllegalAccessException {
        return clazz.getConstructor().newInstance();
    }

}

