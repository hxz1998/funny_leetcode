import java.util.Map;
import java.util.TreeMap;

/**
 * Java
 *
 * @Description: TODO
 * @Author: cherry
 * @Create on: 2022/7/19
 **/
class MyCalendarTwo {
    TreeMap<Integer, Integer> book;

    public MyCalendarTwo() {
        book = new TreeMap<>();
    }

    public boolean book(int start, int end) {
        book.put(start, book.getOrDefault(start, 0) + 1);
        book.put(end, book.getOrDefault(end, 0) - 1);
        int maxValue = 0;
        for (Map.Entry<Integer, Integer> entry : book.entrySet()) {
            maxValue += entry.getValue();
            if (maxValue > 2) {
                book.put(start, book.getOrDefault(start, 0) - 1);
                book.put(end, book.getOrDefault(end, 0) + 1);
                return false;
            }
        }
        return true;
    }
}

public class No731 {

}
