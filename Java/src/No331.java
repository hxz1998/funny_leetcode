/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

public class No331 {
    public boolean isValidSerialization(String preorder) {
        String[] nodes = preorder.split(",");
        int slots = 1;
        for (String node : nodes) {
            slots--;
            if (slots < 0) return false;
            if (!node.equals("#")) slots += 2;
        }
        return slots == 0;
    }

    public static void main(String[] args) {
        String preorder = "9,3,4,#,#,1,#,#,2,#,6,#,#";
        No331 no331 = new No331();
        System.out.println(no331.isValidSerialization(preorder));
    }
}
