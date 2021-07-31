/*
 * Copyright (c) 7/31/2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.ArrayList;
import java.util.List;

public class No293 {
    public List<String> generatePossibleNextMoves(String currentState) {
        List<String> ans = new ArrayList<>();
        for (int idx = 0; idx < currentState.length() - 1; ++idx) {
            if (currentState.charAt(idx) == currentState.charAt(idx + 1) && currentState.charAt(idx) == '+') {
                ans.add(currentState.substring(0, idx) + "--" + currentState.substring(idx + 2));
            }
        }
        return ans;
    }
}
