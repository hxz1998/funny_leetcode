/**
 * Java
 *
 * @Description: TODO
 * @Author: cherry
 * @Create on: 2022/8/14
 **/
package dji;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class PracticeNo2 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        while (scanner.hasNext()) {
            int m = scanner.nextInt();
            int n = scanner.nextInt();
            List<Integer> ret = func(m, n);
            if (ret.isEmpty()) System.out.println("no");
            else {
                for (int num : ret) System.out.print(num + " ");
            }
        }
    }

    private static List<Integer> func(int m, int n) {
        List<Integer> list = new ArrayList<>();
        for (int num = m; num <= n; ++num) {
            if (check(num)) list.add(num);
        }
        return list;
    }

    private static boolean check(int num) {
        int a = num % 10;
        int b = num / 10 % 10;
        int c = num / 100;
        return a * a * a + b * b * b + c * c * c == num;
    }
}
