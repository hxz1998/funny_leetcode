/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package interview;

public class No01dot05 {
    public boolean oneEditAway(String first, String second) {
        if (first.length() == second.length()) return oneEditReplace(first, second);
        else if (first.length() + 1 == second.length()) return oneEditInsert(second, first);
        else if (first.length() == second.length() + 1) return oneEditInsert(first, second);
        else return false;
    }

    private boolean oneEditReplace(String first, String second) {
        boolean founded = false;
        for (int idx = 0; idx < first.length(); ++idx) {
            if (first.charAt(idx) != second.charAt(idx)) {
                if (founded) return false;
                founded = true;
            }
        }
        return true;
    }

    private boolean oneEditInsert(String longString, String shortString) {
        int idx1 = 0, idx2 = 0;
        while (idx1 < longString.length() && idx2 < shortString.length()) {
            if (longString.charAt(idx1) != shortString.charAt(idx2)) {
                if (idx1 != idx2) return false;
                idx1++;
            } else {
                idx1++;
                idx2++;
            }
        }
        return true;
    }
}
