/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.*;

public class No1600 {
    static class ThroneInheritance {
        private Map<String, List<String>> tree;
        private Set<String> dead;
        private String king;

        public ThroneInheritance(String kingName) {
            this.king = kingName;
            this.tree = new HashMap<>();
            this.dead = new HashSet<>();
        }

        public void birth(String parentName, String childName) {
            List<String> node = tree.getOrDefault(parentName, new ArrayList<>());
            node.add(childName);
            tree.put(parentName, node);
        }

        public void death(String name) {
            dead.add(name);
        }

        public List<String> getInheritanceOrder() {
            List<String> ret = new ArrayList<>();
            preorder(ret, king);
            return ret;
        }

        private void preorder(List<String> ans, String parent) {
            if (!dead.contains(parent)) ans.add(parent);
            List<String> children = tree.getOrDefault(parent, new ArrayList<>());
            for (String child : children) preorder(ans, child);
        }
    }
}
