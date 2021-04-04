/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class No1436 {
    public String destCity(List<List<String>> paths) {
        Map<String, String> mapper = new HashMap<>();
        for (List<String> path : paths) mapper.put(path.get(0), path.get(1));
        String ans = paths.get(0).get(0);
        while (mapper.containsKey(ans)) {
            ans = mapper.get(ans);
        }
        return ans;
    }
}
