/**
 * Java
 *
 * @Description: TODO
 * @Author: cherry
 * @Create on: 2022/8/1
 **/

public class No1374 {
    public String generateTheString(int n) {
        StringBuilder builder = new StringBuilder();
        for (int idx = 0; idx < n - (1 - n % 2); ++idx) {
            builder.append('a');
        }
        if (builder.length() < n) builder.append('b');
        return builder.toString();
    }
}
