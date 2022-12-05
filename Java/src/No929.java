/**
 * Created by Xiaozhong on 2022/6/4.
 * Copyright (c) 2022/6/4 Xiaozhong. All rights reserved.
 */

import java.util.HashSet;
import java.util.Set;


public class No929 {
    private static class Solution {
        public int numUniqueEmails(String[] emails) {
            Set<String> set = new HashSet<>();
            for (String email : emails) {
                String[] nameAndHost = email.split("@");
                String name = nameAndHost[0], host = nameAndHost[1];
                name = name.substring(0, name.indexOf("+")).replace(".", "");
                set.add(name + "@" + host);
            }
            return set.size();
        }
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        String[] emails = {"test.email+alex@leetcode.com","test.email.leet+alex@code.com"};
        System.out.println(solution.numUniqueEmails(emails));
    }
}


