/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

public class No825 {
    public int numFriendRequests(int[] ages) {
        int[] counter = new int[121];
        for (int age : ages) counter[age]++;
        int ans = 0;
        for (int ageA = 0; ageA <= 120; ++ageA) {
            for (int ageB = 0; ageB <= 120; ++ageB) {
                int countA = counter[ageA];
                int countB = counter[ageB];
                if (ageB <= 0.5 * ageA + 7) continue;
                if (ageB > ageA) continue;
                if (ageB > 100 && ageA < 100) continue;
                ans += countA * countB;
                if (ageA == ageB) ans -= countA;
            }
        }
        return ans;
    }

    public static void main(String[] args) {
        int[] ages = new int[]{16, 16};
        System.out.println(new No825().numFriendRequests(ages));
    }
}
