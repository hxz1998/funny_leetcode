/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */
class MyHashSet {

    private int[] hashSet;

    public MyHashSet() {
        hashSet = new int[1000_001];
    }

    public void add(int key) {
        hashSet[key] = 1;
    }

    public void remove(int key) {
        hashSet[key] = 0;
    }

    /**
     * Returns true if this set contains the specified element
     */
    public boolean contains(int key) {
        return hashSet[key] == 1;
    }
}

public class No705 {

}
