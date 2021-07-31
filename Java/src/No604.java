/*
 * Copyright (c) 7/30/2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.Deque;
import java.util.LinkedList;
import java.util.Queue;

public class No604 {
    class StringIterator {
        class Pair {
            char c;
            int cnt;

            Pair(char c, int cnt) {
                this.c = c;
                this.cnt = cnt;
            }
        }

        private Deque<Pair> queue = null;

        public StringIterator(String compressedString) {
            queue = new LinkedList<>();
            int idx = 0;
            while (idx < compressedString.length()) {
                char c = compressedString.charAt(idx++);
                int num = 0;
                while (idx < compressedString.length() && Character.isDigit(compressedString.charAt(idx))) {
                    num = num * 10 + compressedString.charAt(idx++) - '0';
                }
                queue.addLast(new Pair(c, num));
            }
        }

        public char next() {
            if (!hasNext()) return ' ';
            Pair pair = queue.pollFirst();
            assert pair != null;
            char ret = pair.c;
            pair.cnt--;
            if (pair.cnt > 0) queue.addFirst(pair);
            return ret;
        }

        public boolean hasNext() {
            return !queue.isEmpty();
        }
    }
}
