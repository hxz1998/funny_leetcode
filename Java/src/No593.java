import java.util.Arrays;

/**
 * Java
 *
 * @Description: TODO
 * @Author: cherry
 * @Create on: 2022/7/29
 **/

public class No593 {
    public boolean validSquare(int[] p1, int[] p2, int[] p3, int[] p4) {
        int[][] points = new int[4][2];
        points[0] = p1;
        points[1] = p2;
        points[2] = p3;
        points[3] = p4;
        Arrays.sort(points, (a, b) -> {
            return a[0] == b[0] ? b[1] - a[1] : a[0] - b[0];
        });

        return (distance(points[1], points[2]) - distance(points[3], points[0])) < 1e5
                && !(points[1][0] == points[2][0] && points[1][1] == points[2][1])
                && !(points[0][0] == points[3][0] && points[0][1] == points[3][1])
                && !(points[0][0] == points[1][0] && points[0][1] == points[1][1])
                && !(points[3][0] == points[2][0] && points[3][1] ==points[2][1]);
    }

    private double distance(int[] p, int[] q) {
        return Math.sqrt((p[0] - q[0]) * (p[0] - q[0]) + (p[1] - q[1]) * (p[1] - q[1]));
    }
}
