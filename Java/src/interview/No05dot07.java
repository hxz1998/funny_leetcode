/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package interview;

public class No05dot07 {
        public int exchangeBits(int num) {
            return ((num & 0xAAAAAAAA) >>> 1) | ((num & 0x55555555) << 1);
    }
}
