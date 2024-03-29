import java.util.HashSet;
import java.util.Set;

/**
 * Created by Xiaozhong on 2021/2/1.
 * Copyright (c) 2021/2/1 Xiaozhong. All rights reserved.
 */

public class No822 {
    public int flipgame(int[] fronts, int[] backs) {
        Set<Integer> same = new HashSet<>();
        for (int i = 0; i < fronts.length; ++i) {
            if (fronts[i] == backs[i]) same.add(fronts[i]);
        }

        int ans = 9999;
        for (int x : fronts) {
            if (!same.contains(x)) ans = Math.min(ans, x);
        }
        for (int x : backs) {
            if (!same.contains(x)) ans = Math.min(ans, x);
        }
        return ans % 9999;
    }
}
