/*
 * Copyright (c) 8/26/2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package interview;

import java.util.Arrays;
import java.util.HashSet;

public class No17dot13 {
    public int respace(String[] dictionary, String sentence) {
        HashSet<String> dict = new HashSet<>(Arrays.asList(dictionary));
        ParseResult result = split(dict, sentence, new ParseResult[sentence.length()], 0);
        String[] words = result.parse.split(" ");
        int ans = 0;
        for (String word : words) if (!dict.contains(word)) ans++;
        return ans;
    }

    private ParseResult split(HashSet<String> dict, String sentence, ParseResult[] memo, int start) {
        if (start >= sentence.length()) return new ParseResult(0, "");
        if (memo[start] != null) return memo[start];
        int bestInvalid = Integer.MAX_VALUE;
        String bestParse = null;
        String partial = "";
        int idx = start;
        while (idx < sentence.length()) {
            char c = sentence.charAt(idx);
            partial += c;
            // 记下来有多少个不符合要求的字符
            int invalid = dict.contains(partial) ? 0 : partial.length();
            if (invalid < bestInvalid) {
                ParseResult result = split(dict, sentence, memo, idx + 1);
                if (invalid + result.invalid < bestInvalid) {
                    bestInvalid = invalid + result.invalid;
                    bestParse = partial + " " + result.parse;
                    if (bestInvalid == 0) break;
                }
            }
            ++idx;
        }
        memo[start] = new ParseResult(bestInvalid, bestParse);
        return memo[start];
    }

    private static class ParseResult {
        public int invalid = Integer.MAX_VALUE;
        public String parse = "";
        public ParseResult(int v, String p) {
            invalid = v;
            parse = p;
        }
    }

    public static void main(String[] args) {
        No17dot13 no17dot13 = new No17dot13();
        no17dot13.respace(new String[]{"looked","just","like","her","brother"}, "jesslookedjustliketimherbrother");
    }
}
