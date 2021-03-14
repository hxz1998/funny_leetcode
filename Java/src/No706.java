import java.util.Iterator;
import java.util.LinkedList;

/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */
class MyHashMap {
    static class Pair {
        int value, key;

        Pair(int key, int value) {
            this.key = key;
            this.value = value;
        }
    }

    private static final int BASE = 888;
    private LinkedList[] data;

    /**
     * Initialize your data structure here.
     */
    public MyHashMap() {
        data = new LinkedList[BASE];
        for (int i = 0; i < BASE; i++) {
            data[i] = new LinkedList<Pair>();
        }
    }

    /**
     * value will always be non-negative.
     */
    public void put(int key, int value) {
        int h = hash(key);
        Iterator<Pair> iter = data[h].iterator();
        while (iter.hasNext()) {
            Pair p = iter.next();
            if (p.key == key) {
                p.value = value;
                return;
            }
        }
        data[h].addLast(new Pair(key, value));
    }

    /**
     * Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key
     */
    public int get(int key) {
        int h = hash(key);
        Iterator<Pair> iter = data[h].iterator();
        while (iter.hasNext()) {
            Pair p = iter.next();
            if (p.key == key) return p.value;
        }
        return -1;
    }

    /**
     * Removes the mapping of the specified value key if this map contains a mapping for the key
     */
    public void remove(int key) {
        int h = hash(key);
        Iterator<Pair> iter = data[h].iterator();
        while (iter.hasNext()) {
            Pair p = iter.next();
            if (p.key == key) {
                data[h].remove(p);
                return;
            }
        }
    }

    private int hash(int key) {
        return key % BASE;
    }
}

public class No706 {

}
