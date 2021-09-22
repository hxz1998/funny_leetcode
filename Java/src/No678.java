/*
 * Copyright (c) 9/12/2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.LinkedList;

public class No678 {
    public boolean checkValidString(String s) {
        // 记录 * 的个数
        LinkedList<Integer> asterisk = new LinkedList<>();
        LinkedList<Integer> leftParenthesis = new LinkedList<>();
        for (int idx = 0; idx < s.length(); ++idx) {
            if (s.charAt(idx) == '(') leftParenthesis.add(idx);
            else if (s.charAt(idx) == '*') asterisk.add(idx);
            else {
                if (!leftParenthesis.isEmpty()) leftParenthesis.pollLast();
                else if (!asterisk.isEmpty()) asterisk.pollLast();
                else return false;
            }
        }
        if (leftParenthesis.size() > asterisk.size()) return false;
        for (int idx = leftParenthesis.size() - 1; idx >= 0; --idx) {
            if (leftParenthesis.peekLast() > asterisk.peekLast()) return false;
            leftParenthesis.pollLast();
            asterisk.pollLast();
        }
        return true;
    }

    public static void main(String[] args) {
        No678 no678 = new No678();
        System.out.println(no678.checkValidString("(((((*(()((((*((**(((()()*)()()()*((((**)())*)*)))))))(())(()))())((*()()(((()((()*(())*(()**)()(())"));
    }
}
