/*
 * Copyright (c) 8/26/2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.Arrays;

public class No881 {

    public int numRescueBoats(int[] people, int limit) {
        Arrays.sort(people);
        int lightest = 0, heaviest = people.length - 1;
        int ans = 0;
        while (lightest <= heaviest) {
            if (people[lightest] + people[heaviest] <= limit) {
                lightest++;
                heaviest--;
            } else if (people[lightest] + people[heaviest] > limit) {
                heaviest--;
            }
            ++ans;
        }
        return ans;
    }

    public static void main(String[] args) {
        int[] people = {2, 2};
        No881 no881 = new No881();
        System.out.println(no881.numRescueBoats(people, 6));
    }
}
