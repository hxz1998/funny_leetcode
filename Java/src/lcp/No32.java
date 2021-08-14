/*
 * Copyright (c) 8/13/2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package lcp;

import java.util.*;
import java.util.stream.Collectors;
import java.util.stream.Stream;

class Pair {
    public int slots;
    public int index;

    public Pair(int slots, int index) {
        this.slots = slots;
        this.index = index;
    }
}

class PairComparator implements Comparator<Pair> {
    @Override
    public int compare(Pair p1, Pair p2) {
        if (p1.slots > p2.slots || (p1.slots == p2.slots && p1.index > p2.index)) {
            return 1;
        } else if (p1.slots < p2.slots || p1.index < p2.index) {
            return -1;
        }
        return 0;
    }
}

// 参考的别人的题解
public class No32 {
    public int processTasks(int[][] tasks) {
        int n = tasks.length;
        var ts = new TreeSet<Integer>();
        for (var task : tasks) {
            ts.add(task[0]);
            ts.add(task[1] + 1);
        }
        var vt = new ArrayList<>(ts);
        int m = vt.size();
        var mp = new HashMap<Integer, Integer>(m);
        for (int i = 0; i < m; ++i) {
            mp.put(vt.get(i), i);
        }

        var starts = Stream.generate(ArrayList<Integer>::new)
                .limit(m)
                .collect(Collectors.toList());
        for (int i = 0; i < n; ++i) {
            starts.get(mp.get(tasks[i][0])).add(i);
        }

        int ans = 0;
        int extra = 0;
        var pq = new PriorityQueue<Pair>(n, new PairComparator());

        for (int i = 0; i < m - 1; ++i) {
            while (!pq.isEmpty() && tasks[pq.peek().index][1] < vt.get(i)) {
                pq.poll();
            }

            for (int u : starts.get(i)) {
                pq.add(new Pair(extra + tasks[u][1] - vt.get(i) + 1 - tasks[u][2], u));
            }

            int currentSeg = vt.get(i + 1) - vt.get(i);
            if (!pq.isEmpty()) {
                int minSlots = pq.peek().slots - extra;
                int slotsToDel = currentSeg;

                if (minSlots < currentSeg) {
                    int delta = currentSeg - minSlots;
                    ans += delta;
                    slotsToDel -= delta;
                }

                extra += slotsToDel;
            }
        }

        return ans;
    }
}
