/**
 * Created by Xiaozhong on 2021/1/26.
 * Copyright (c) 2021/1/26 Xiaozhong. All rights reserved.
 */

class No1128 {
    public int numEquivDominoPairs(int[][] dominoes) {
        int ans = 0;
        int[] num = new int[100];
        for (int[] item : dominoes) {
            int value = item[0] < item[1] ? item[0] * 10 + item[1] : item[1] * 10 + item[0];
            ans += num[value];
            num[value]++;
        }
        return ans;
    }

    public static void main(String[] args) {
        int[][] dominoes = {{1, 2}, {2, 1}, {3, 4}, {5, 6}};
        No1128 solution = new No1128();
        System.out.println(solution.numEquivDominoPairs(dominoes));
    }
}


