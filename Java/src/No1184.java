import java.util.*;

/**
 * Java
 *
 * @Description: TODO
 * @Author: cherry
 * @Create on: 2022/7/24
 **/

public class No1184 {
    public int distanceBetweenBusStops(int[] distance, int start, int destination) {
        int clockwise = 0, anticlockwise = 0;
        int n = distance.length;
        int pos = start;
        while (pos != destination) {
            clockwise += distance[pos];
            pos = (pos + 1) % n;
        }
        pos = start;
        while (pos != destination) {
            pos = (pos - 1 + n) % n;
            anticlockwise += distance[pos];
        }
        return Math.min(anticlockwise, clockwise);
    }
}
