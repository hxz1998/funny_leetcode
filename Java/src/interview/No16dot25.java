/*
 * Copyright (c) 7/12/2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package interview;

import java.util.HashMap;
import java.util.Map;

public class No16dot25 {
    static class LRUCache {
        private static class LinkedListNode {
            LinkedListNode next, prev;
            int key, value;

            LinkedListNode(int key, int value) {
                this.key = key;
                this.value = value;
            }
        }

        private int capacity;
        private int size;
        Map<Integer, LinkedListNode> mapper = new HashMap<>();
        LinkedListNode head = new LinkedListNode(0, 0);
        LinkedListNode tail = head;

        public LRUCache(int capacity) {
            this.capacity = capacity;
            this.size = 0;
        }

        public int get(int key) {
            if (!mapper.containsKey(key)) return -1;
            else {
                LinkedListNode node = mapper.get(key);
                removeAt(node);
                addFirst(node);
                return mapper.get(key).value;
            }
        }

        public void put(int key, int value) {
            if (size == 0) {
                LinkedListNode node = new LinkedListNode(key, value);
                addLast(node);
                mapper.put(key, node);
            } else if (mapper.containsKey(key)) {
                LinkedListNode node = mapper.get(key);
                node.value = value;
                addFirst(removeAt(node));
            } else if (size == capacity) {
                LinkedListNode node = removeLast();
                mapper.remove(node.key);
                node = new LinkedListNode(key, value);
                mapper.put(key, node);
                addFirst(node);
            } else {
                LinkedListNode node = new LinkedListNode(key, value);
                mapper.put(key, node);
                addFirst(node);
            }
        }

        private LinkedListNode removeLast() {
            --size;
            LinkedListNode node = tail;
            tail = tail.prev;
            tail.next = null;
            return node;
        }

        private void addFirst(LinkedListNode node) {
            if (size == 0) {
                addLast(node);
            } else {
                ++size;
                node.prev = head;
                node.next = head.next;
                head.next.prev = node;
                head.next = node;
            }
        }

        private void addLast(LinkedListNode node) {
            ++size;
            node.prev = tail;
            tail.next = node;
            tail = node;
        }

        private LinkedListNode removeAt(LinkedListNode node) {
            --size;
            if (tail == node) {
                tail = tail.prev;
                tail.next = null;
            } else {
                node.prev.next = node.next;
                node.next.prev = node.prev;
            }
            return node;
        }
    }

    public static void main(String[] args) {
//        LRUCache lruCache = new LRUCache(2);
//        lruCache.put(1, 1);
//        lruCache.put(2, 2);
//        System.out.println(lruCache.get(1));
//        lruCache.put(3, 3);
//        System.out.println(lruCache.get(2));
//        lruCache.put(4, 4);
//        System.out.println(lruCache.get(1));
//        System.out.println(lruCache.get(3));
//        System.out.println(lruCache.get(4));
//
//        LRUCache lruCache1 = new LRUCache(1);
//        lruCache1.put(2, 1);
//        System.out.println(lruCache1.get(2));

        LRUCache lruCache2 = new LRUCache(3);
        lruCache2.put(1, 1);
        lruCache2.put(2, 2);
        lruCache2.put(3, 3);
        lruCache2.put(4, 4);
        System.out.println(lruCache2.get(4));
        System.out.println(lruCache2.get(3));
        System.out.println(lruCache2.get(2));
        System.out.println(lruCache2.get(1));
        lruCache2.put(5, 5);
        System.out.println(lruCache2.get(1));
        System.out.println(lruCache2.get(2));
        System.out.println(lruCache2.get(3));
        System.out.println(lruCache2.get(4));
        System.out.println(lruCache2.get(5));
//        LRUCache lruCache3 = new LRUCache(1);
//        lruCache3.put(2, 1);
//        System.out.println(lruCache3.get(2));
//        lruCache3.put(3, 2);
//        System.out.println(lruCache3.get(2));
//        System.out.println(lruCache3.get(3));

    }
}
