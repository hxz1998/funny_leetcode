/*
 * Copyright (c) 8/26/2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package interview;

import java.util.Arrays;
import java.util.HashMap;

public class No17dot15 {
    public String longestWord(String[] words) {
        HashMap<String, Boolean> mapper = new HashMap<>();
        for (String word : words) mapper.put(word, true);
        Arrays.sort(words, ((o1, o2) -> o2.length() - o1.length()));
        for (String word : words) {
            if (canBuild(word, true, mapper)) return word;
        }
        return "";
    }

    private boolean canBuild(String str, boolean isOriginal, HashMap<String, Boolean> mapper) {
        if (mapper.containsKey(str) && !isOriginal) return mapper.get(str);
        for (int i = 1; i < str.length(); ++i) {
            String left = str.substring(0, i);
            String right = str.substring(i);
            if (mapper.containsKey(left) && mapper.get(left) && canBuild(right, false, mapper)) {
                return true;
            }
        }
        mapper.put(str, false);
        return false;
    }

    public static void main(String[] args) {
        No17dot15 no17dot15 = new No17dot15();
        System.out.println(no17dot15.longestWord(new String[]{
                "qlmql","qlmqlmqqlqmqqlq","mqqlqmqqlqmqqlq","mqqlq","mqqlqlmlsmqq","qmlmmmmsm","lmlsmqq","slmsqq","mslqssl","mqqlqmqqlq"
        }));
        System.out.println("mqqlqmqqlqmqqlq");
    }
}
