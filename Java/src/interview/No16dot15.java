/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package interview;

import java.util.Arrays;

public class No16dot15 {
    public int[] masterMind(String solution, String guess) {
        int[] ans = new int[2];
        char[] solutionChars = solution.toCharArray();
        char[] guessChars = guess.toCharArray();
        for (int idx = 0; idx < 4; ++idx) {
            if (solutionChars[idx] == guessChars[idx]) {
                ans[0]++;
                solutionChars[idx] = ' ';
                guessChars[idx] = ' ';
            }
        }
        for (char c : guessChars) {
            if (c == ' ') continue;
            for (int idx = 0; idx < 4; ++idx) {
                if (c == solutionChars[idx]) {
                    ans[1]++;
                    solutionChars[idx] = ' ';
                    break;
                }
            }
        }
        return ans;
    }

    public static void main(String[] args) {
        No16dot15 no16dot15 = new No16dot15();
        System.out.println(Arrays.toString(no16dot15.masterMind("BGBG", "RGBA")));
    }
}
