import java.util.Comparator;
import java.util.PriorityQueue;

/**
 * Java
 *
 * @Description: TODO
 * @Author: cherry
 * @Create on: 2022/8/31
 **/
class MedianFinder {
    private PriorityQueue<Integer> minHeap;
    private PriorityQueue<Integer> maxHeap;

    public MedianFinder() {
        minHeap = new PriorityQueue<>(Comparator.comparingInt(l -> l));
        maxHeap = new PriorityQueue<>((l, r) -> r - l);
    }

    public void addNum(int num) {
        maxHeap.add(num);
        minHeap.add(maxHeap.poll());
        if (minHeap.size() > maxHeap.size()) {
            maxHeap.add(minHeap.poll());
        }
    }

    public double findMedian() {
        if (maxHeap.size() > minHeap.size()) return maxHeap.peek();
        return 0.5 * (maxHeap.peek() + minHeap.peek());
    }
}

public class No295_2 {
    public static void main(String[] args) {
        MedianFinder medianFinder = new MedianFinder();
        medianFinder.addNum(1);
        medianFinder.addNum(2);
        medianFinder.addNum(3);
        System.out.println(medianFinder.findMedian());
    }
}
