/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package interview;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;

public class No04dot09 {
    static class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;

        TreeNode(int x) {
            val = x;
        }
    }

    public List<List<Integer>> BSTSequences(TreeNode root) {
        List<List<Integer>> results = new ArrayList<>();
        if (root == null) {
            results.add(new LinkedList<>());
            return results;
        }

        LinkedList<Integer> prefix = new LinkedList<>();
        prefix.add(root.val);

        List<List<Integer>> leftSequence = BSTSequences(root.left);
        List<List<Integer>> rightSequence = BSTSequences(root.right);

        for (List<Integer> left : leftSequence) {
            for (List<Integer> right : rightSequence) {
                ArrayList<LinkedList<Integer>> weaved = new ArrayList<>();
                weaveLists((LinkedList<Integer>) left, (LinkedList<Integer>) right, weaved, prefix);
                results.addAll(weaved);
            }
        }
        return results;
    }

    private void weaveLists(LinkedList<Integer> first, LinkedList<Integer> second, ArrayList<LinkedList<Integer>> results, LinkedList<Integer> prefix) {
        if (first.isEmpty() || second.isEmpty()) {
            LinkedList<Integer> result = (LinkedList<Integer>) prefix.clone();
            result.addAll(first);
            result.addAll(second);
            results.add(result);
            return;
        }
        int headFirst = first.removeFirst();
        prefix.addLast(headFirst);
        weaveLists(first, second, results, prefix);
        prefix.removeLast();
        first.addFirst(headFirst);

        int headSecond = second.removeFirst();
        prefix.addLast(headSecond);
        weaveLists(first, second, results, prefix);
        prefix.removeLast();
        second.addFirst(headSecond);

    }
}
