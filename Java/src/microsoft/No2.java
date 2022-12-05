/**
 * Java
 *
 * @Description: TODO
 * @Author: cherry
 * @Create on: 2022/8/6
 **/
package microsoft;

public class No2 {
    private int max = 1000000000;

    public int solution(String str) {
        int n = 0;
        int len = str.length();
        for (char c : str.toCharArray()) {
            if (c == 'R') n++;
        }
        int left = 0, right = len - 1;
        int ans = 0;
        // 0 1 2 3 4 5 6
        // W R R W W R W  n = 3
        // l           r  n = 3, ans = 0
        //   l       r    n = 1, ans = 2
        while (left < right) {
            if (str.charAt(left) == 'R' && str.charAt(right) == 'R') {
                n -= 2;
                ans += (right - left - 1 - n);
                ++left;
                --right;
            } else if (str.charAt(left) == 'W') left++;
            else right--;
        }
        return ans;
    }

    public static void main(String[] args) {
        System.out.println(new No2().solution("WRRWWR"));
        System.out.println(new No2().solution("WWRWWWRWR"));
        System.out.println(new No2().solution("WWW"));
        System.out.println(new No2().solution("RW"));
    }
}
