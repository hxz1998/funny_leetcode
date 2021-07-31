/*
 * Copyright (c) 7/28/2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.HashMap;
import java.util.Map;

public class No246 {
    public boolean isStrobogrammatic(String num) {
        Map<Character, Character> mapper = new HashMap<>();
        mapper.put('9', '6');
        mapper.put('6', '9');
        mapper.put('0', '0');
        mapper.put('1', '1');
        mapper.put('8', '8');
        int left = 0, right = num.length() - 1;
        while (left <= right) {
            if (left == right)
                return mapper.containsKey(num.charAt(left)) && mapper.get(num.charAt(left)) == num.charAt(right);
            if (!mapper.containsKey(num.charAt(left)) || mapper.get(num.charAt(left)) != num.charAt(right)) return false;
            left++;
            right--;
        }
        return true;
    }

    public static void main(String[] args) {
        No246 no246 = new No246();
        System.out.println(no246.isStrobogrammatic("25"));
    }
}
