/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class No554 {
    public int leastBricks(List<List<Integer>> walls) {
        Map<Integer, Integer> mapper = new HashMap<>();

        for (List<Integer> wall : walls) {
            int sum = 0;
            for (int i = 0; i < wall.size() - 1; ++i) {
                sum += wall.get(i);
                mapper.put(sum, mapper.getOrDefault(sum, 0) + 1);
            }
        }

        int ans = walls.size();
        for (Map.Entry<Integer, Integer> entry : mapper.entrySet()) {
            ans = Math.min(ans, walls.size() - entry.getValue());
        }
        return ans;
    }
}
