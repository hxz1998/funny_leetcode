/*
 * Copyright (c) 8/24/2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package interview;

public class No16dot18 {
    public static void main(String[] args) {
        No16dot18 no16dot18 = new No16dot18();
        System.out.println(no16dot18.patternMatching("aaaa", "dogcatcatdog"));
    }

    public boolean patternMatching(String pattern, String value) {
        int countA = 0, countB = 0;
        for (char c : pattern.toCharArray()) {
            if (c == 'a') countA++;
            else countB++;
        }
        if (countA < countB) {
            int tmp = countA;
            countA = countB;
            countB = tmp;
            char[] chars = new char[pattern.length()];
            for (int idx = 0; idx < pattern.length(); ++idx) {
                chars[idx] = pattern.charAt(idx) == 'a' ? 'b' : 'a';
            }
            pattern = new String(chars);
        }
        if (value.length() == 0) return countB == 0;
        if (pattern.length() == 0) return false;
        for (int lenA = 0; lenA * countA <= value.length(); ++lenA) {
            int pos = 0;
            String aValue = "", bValue = "";
            boolean isCorrect = true;
            int rest = value.length() - countA * lenA;
            if ((countB == 0 && rest == 0) || (countB != 0 && rest % countB == 0)) {
                int lenB = countB == 0 ? 0 : rest / countB;
                for (char c : pattern.toCharArray()) {
                    if (c == 'a') {
                        String sub = value.substring(pos, pos + lenA);
                        if (aValue.length() == 0) aValue = sub;
                        else if (!aValue.equals(sub)) {
                            isCorrect = false;
                            break;
                        }
                        pos += lenA;
                    } else {
                        String sub = value.substring(pos, pos + lenB);
                        if (bValue.length() == 0) bValue = sub;
                        else if (!bValue.equals(sub)) {
                            isCorrect = false;
                            break;
                        }
                        pos += lenB;
                    }
                }
                if (!aValue.equals(bValue) && isCorrect) return true;
            }
        }
        return false;
    }
}
