/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package interview;

import java.util.List;

public class No08dot06 {
    public void hanota(List<Integer> origin, List<Integer> buffer, List<Integer> destination) {
        move(origin.size(), origin, destination, buffer);
    }

    private void move(int n, List<Integer> origin, List<Integer> destination, List<Integer> buffer) {
        if (n <= 0) return;
        move(n - 1, origin, buffer, destination);
        destination.add(origin.get(origin.size() - 1));
        origin.remove(origin.size() - 1);
        move(n - 1, buffer, destination, origin);
    }
}
