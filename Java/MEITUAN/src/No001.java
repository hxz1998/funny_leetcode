/*
 * Copyright (c) 8/13/2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.Scanner;

public class No001 {
    private static final String ACCEPT = "Accept", WRONG = "Wrong";

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        String[] ans = new String[T];
        for (int i = 0; i < T; ++i) {
            String username = sc.next();
            boolean containsDigit = false, containsChar = false;
            for (int idx = 0; idx < username.length(); ++idx) {
                if (idx == 0 && !Character.isLetter(username.charAt(idx))) {
                    ans[i] = WRONG;
                    break;
                } else {
                    if (Character.isLetter(username.charAt(idx))) containsChar = true;
                    else if (Character.isDigit(username.charAt(idx))) containsDigit = true;
                    else {
                        ans[i] = WRONG;
                        break;
                    }
                }
            }
            if (ans[i] == null && containsChar && containsDigit) ans[i] = ACCEPT;
            else ans[i] = WRONG;
        }
        for (String item : ans) System.out.println(item);
    }
}
