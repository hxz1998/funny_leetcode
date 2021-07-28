/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class No243 {

    public int shortestDistance(String[] wordsDict, String word1, String word2) {
        int ans = wordsDict.length;
        int idx1 = -1;
        int idx2 = -1;
        for (int i = 0; i < wordsDict.length; ++i) {
            if (wordsDict[i].equals(word1)) idx1 = i;
            if (wordsDict[i].equals(word2)) idx2 = i;
            if (idx1 != -1 && idx2 != -1) ans = Math.min(ans, Math.abs(idx1 - idx2));
        }
        return ans;
    }
}
