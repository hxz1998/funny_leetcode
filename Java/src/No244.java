import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.TreeMap;

/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */
class WordDistance {
    private HashMap<String, List<Integer>> mapper;

    public WordDistance(String[] wordsDict) {
        mapper = new HashMap<>();
        for (int index = 0; index < wordsDict.length; ++index) {
            List<Integer> list = mapper.getOrDefault(wordsDict[index], new ArrayList<>());
            list.add(index);
            mapper.put(wordsDict[index], list);
        }
    }

    public int shortest(String word1, String word2) {
        List<Integer> l1 = mapper.get(word1);
        List<Integer> l2 = mapper.get(word2);
        int ans = Integer.MAX_VALUE;
        for (int i1 = 0, i2 = 0; i1 < l1.size() && i2 < l2.size(); ) {
            ans = Math.min(ans, Math.abs(l1.get(i1) - l2.get(i2)));
            if (l1.get(i1) < l2.get(i2)) ++i1;
            else ++i2;
        }
        return ans;
    }
}

public class No244 {
    public static void main(String[] args) {
        String[] wordsDict = {"practice", "makes", "perfect", "coding", "makes"};
        WordDistance wordDistance = new WordDistance(wordsDict);
        System.out.println(wordDistance.shortest("coding", "practice"));
        System.out.println(wordDistance.shortest("makes", "coding"));
    }
}
