/*
 * Copyright (c) 11/9/2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package interview;

import java.util.*;

public class No17dot07 {
    private static class Union {
        Map<String, String> parents;
        Map<String, Integer> size;

        Union() {
            parents = new HashMap<>();
            size = new HashMap<>();
        }

        public void put(String name, int s) {
            parents.put(name, name);
            size.put(name, s);
        }

        public String find(String node) {
            if (parents.get(node).equals(node)) return node;
            return find(parents.get(node));
        }

        public boolean exist(String node) {
            return parents.containsKey(node);
        }

        public void union(String lhs, String rhs) {
            String lhsParent = find(lhs);
            String rhsParent = find(rhs);
            if (lhsParent.compareTo(rhsParent) < 0) {
                parents.put(rhsParent, lhsParent);
                size.put(lhsParent, size.get(lhsParent) + size.get(rhsParent));
            } else if (lhsParent.compareTo(rhsParent) > 0) {
                parents.put(lhsParent, rhsParent);
                size.put(rhsParent, size.get(rhsParent) + size.get(lhsParent));
            }
        }
    }

    public String[] trulyMostPopular(String[] names, String[] synonyms) {
        ArrayList<String> list = new ArrayList<>(Arrays.asList(names));
        Union union = new Union();
        for (String name : names) {
            int start = name.indexOf("(");
            int end = name.indexOf(")");
            union.put(name.substring(0, ));
        }
    }

    public static void main(String[] args) {

    }
}
