/**
 * Java
 *
 * @Description: TODO
 * @Author: cherry
 * @Create on: 2022/7/27
 **/

public class No592 {
    public String fractionAddition(String expression) {
        expression += "+0/1";
        if (!(expression.startsWith("+") || expression.startsWith("-"))) expression = "+" + expression;
        int denominator = 0, numberator = 0;
        int a = 0, b = 0;
        int sign = expression.startsWith("+") ? 1 : -1;
        boolean isNumberator = true;
        for (char c : expression.toCharArray()) {
            if (c == '-') {
                isNumberator = true;
            } else if (c == '+') {
                isNumberator = true;
            } else if (c == '/') {
                isNumberator = false;
            } else {
                if (isNumberator) {
                    a = a * 10 + (c - '0');
                } else {
                    b = b * 10 + (c - '0');
                }
            }
            if ((c == '-' || c == '+') && b != 0) {
                if (denominator != 0) {
                    int d = lcm(Math.max(b, denominator), Math.min(b, denominator));
                    numberator = numberator * (d / denominator);
                    denominator = d;
                    a *= (d / b);
                    numberator += sign * a;
                } else {
                    numberator = sign * a;
                    denominator = b;
                }
                a = 0;
                b = 0;
                if (c == '-') sign = -1;
                else sign = 1;
            }
        }
        int d = Math.abs(gcd(numberator, denominator));
        if (d != 1) {
            numberator /= d;
            denominator /= d;
        }
        return numberator + "/" + (numberator == 0 ? "1" : denominator);
    }

    private int gcd(int a, int b) {
        if (a % b == 0) return b;
        return gcd(b, a % b);
    }

    private int lcm(int a, int b) {
        return a * b / gcd(a, b);
    }

    public static void main(String[] args) {
        No592 no592 = new No592();
        System.out.println(no592.fractionAddition("7/2+2/3-3/4"));
        System.out.println(no592.gcd(2, 3));
        System.out.println(no592.lcm(2, 3));
    }
}
