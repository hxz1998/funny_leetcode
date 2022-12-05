/**
 * Java
 *
 * @Description: TODO
 * @Author: cherry
 * @Create on: 2022/8/14
 **/
package dji;

import java.util.Scanner;

public class PracticeNo1 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        while (scanner.hasNext()) {
            double a = scanner.nextDouble(), b = scanner.nextDouble();
            System.out.printf("%.2f", func(a, b));
        }
    }

    private static double func(double a, double b) {
        double ans = 0;
        while (b-- > 0) {
            ans += a;
            a = Math.sqrt(a);
        }
        return ans;
    }
}
