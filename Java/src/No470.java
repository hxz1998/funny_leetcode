/*
 * Copyright (c) 9/6/2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

public class No470 {

    static class SolBase {
        public int rand7() {
            return 0;
        }
    }

    static class Solution extends SolBase {
        public int rand10() {
            int ret = (rand7() - 1) * 7 + rand7();
            while (ret > 10) ret = (rand7() - 1) * 7 + rand7();
            return ret;
        }
    }
}
