/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package lccup2021;

public class Group1 {
    public int storeWater(int[] bucket, int[] vat) {
        int n = bucket.length;
        int ans = 0, sum = 0;
        for (int i = 0; i < n; ++i){
            if (bucket[i] == 0 && vat[i] != 0) {
                bucket[i] = 1;
                ans++;
            }
            sum += vat[i];
        }
        if (sum == 0) return 0;
        int min = Integer.MAX_VALUE;
        for (int i = 0; i < n; ++i) {
            min = Math.min(min, vat[i] == 0 ? Integer.MAX_VALUE : (vat[i] - 1) / bucket[i] + 1);
        }
        ans += min;
        for (int i = 0; i < n; ++i) {
            ans += vat[i] == 0 ? 0 : min * bucket[i] >= vat[i] ? 0 : (vat[i] - 1) / min + 1 - 1;
        }
        return ans;
    }

    public static void main(String[] args) {
        int[] bucket = {1, 2, 3}, vat = {0, 0, 1};
        Group1 group1 = new Group1();
        System.out.println(group1.storeWater(bucket, vat));
    }
}
