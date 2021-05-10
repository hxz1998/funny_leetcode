/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

public class No1662 {
    public boolean arrayStringsAreEqual(String[] word1, String[] word2) {
        StringBuilder builder1 = new StringBuilder();
        StringBuilder builder2 = new StringBuilder();
        for (String word : word1) builder1.append(word);
        for (String word : word2) builder2.append(word);

        return builder1.toString().equals(builder2.toString());
    }
}
