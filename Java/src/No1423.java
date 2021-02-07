import java.util.Arrays;

/**
 * Created by Xiaozhong on 2021/2/6.
 * Copyright (c) 2021/2/6 Xiaozhong. All rights reserved.
 */

public class No1423 {
    public int maxScore(int[] cardPoints, int k) {
        int sum = 0;
        int windowSize = cardPoints.length - k;
        for (int i = 0; i < windowSize; ++i) sum += cardPoints[i];
        int minSum = sum, tmp = sum;
        for (int i = windowSize; i < cardPoints.length; ++i) {
            tmp = tmp + cardPoints[i] - cardPoints[i - windowSize];
            minSum = Math.min(minSum, tmp);
        }
        return Arrays.stream(cardPoints).sum() - minSum;
    }

    public static void main(String[] args) {
        int[] cardPoints = new int[]{1, 2, 3, 4, 5, 6, 1};
        System.out.println(new No1423().maxScore(cardPoints, 3));
    }
}
