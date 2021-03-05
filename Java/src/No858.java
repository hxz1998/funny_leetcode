/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

public class No858 {
    public int mirrorReflection(int p, int q) {
        while ((q & 1) == 0 && (p & 1) == 0) {
            p >>= 1;
            q >>= 1;
        }
        if ((p & 1) == 0) return 2;
        else if ((q & 1) == 0) return 0;
        else return 1;
    }
}
