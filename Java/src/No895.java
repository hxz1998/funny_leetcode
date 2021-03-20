import java.util.HashMap;
import java.util.Map;
import java.util.Stack;
import java.util.TreeMap;

/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */
class FreqStack {
    private Map<Integer, Integer> frequency;
    private Map<Integer, Stack<Integer>> group;
    int maxFrequency = 0;

    public FreqStack() {
        frequency = new HashMap<>();
        group = new HashMap<>();
    }

    public void push(int val) {
        int f = frequency.getOrDefault(val, 0) + 1;
        frequency.put(val, f);
        maxFrequency = Math.max(maxFrequency, f);
        group.computeIfAbsent(f, z -> new Stack<>()).push(val);
    }

    public int pop() {
        int x = group.get(maxFrequency).pop();
        frequency.put(x, frequency.get(x) - 1);
        if (group.get(maxFrequency).size() == 0) maxFrequency--;
        return x;
    }
}

public class No895 {
    public static void main(String[] args) {
        FreqStack freqStack = new FreqStack();
        freqStack.push(5);
        freqStack.push(7);
        freqStack.push(5);
        freqStack.push(7);
        freqStack.push(4);
        freqStack.push(5);
        System.out.println(freqStack.pop());
        System.out.println(freqStack.pop());
        System.out.println(freqStack.pop());
        System.out.println(freqStack.pop());
        System.out.println(freqStack.pop());
        System.out.println(freqStack.pop());
    }
}
