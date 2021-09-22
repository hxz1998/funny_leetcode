/*
 * Copyright (c) 9/16/2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package util;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;

public class InputFormat {
    public static void main(String[] args) throws Exception {
        BufferedReader reader = new BufferedReader(new FileReader("src/util/input.txt"));

        StringBuilder builder = new StringBuilder();
        String bf = null;
        while ((bf = reader.readLine()) != null) {
            bf = bf.replace("\"", "'").
                    replace("]", "}").
                    replace("[", "{");
            builder.append(bf);
        }
        BufferedWriter writer = new BufferedWriter(new FileWriter("src/util/input.txt"));
        writer.write(builder.toString());
        reader.close();
        writer.close();
    }
}
