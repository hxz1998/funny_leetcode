/**
 * Java
 *
 * @Description: TODO
 * @Author: cherry
 * @Create on: 2022/7/16
 **/
package offer2;

import java.util.LinkedList;

public class No41 {
    class MovingAverage {
        private int size;
        private int sum;
        private LinkedList<Integer> data;

        public MovingAverage(int size) {
            this.size = size;
            this.data = new LinkedList<>();
        }

        public double next(int val) {
            assert size >= 1;
            data.push(val);
            this.sum += val;
            if (this.data.size() > size) sum -= data.pollFirst();
            return this.sum * 1.0 / this.data.size();
        }
    }
}
