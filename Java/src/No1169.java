/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.*;

public class No1169 {
    // 对象化每一个交易，添加了 id 字段，用来标记有么有放到返回值中
    static class Transaction {
        int time;
        int money;
        String address;
        int id;

        Transaction(int id, int time, int money, String address) {
            this.id = id;
            this.time = time;
            this.money = money;
            this.address = address;
        }
    }

    public List<String> invalidTransactions(String[] transactions) {
        // 返回值
        List<String> ans = new ArrayList<>();
        // 用来标记某一个值是否已经放到返回值中了，防止重复
        boolean[] inReturn = new boolean[1001];
        // 将每一个名字对应的交易放到一个列表中
        Map<String, List<Transaction>> mapper = new HashMap<>();
        int id = 0;
        for (String transaction : transactions) {
            // 首先切分字符串获取每一个交易的字段
            String[] items = transaction.split(",");
            String name = items[0];
            int time = Integer.parseInt(items[1]);
            int money = Integer.parseInt(items[2]);
            String address = items[3];
            // 检查交易额度是否超过了 1000
            if (money > 1000) {
                inReturn[id] = true;    // 顺便打上已经在返回值中的标记
                ans.add(transaction);   // 如果超过了，就放到返回值中，
            }
            // 然后获取这个名字下的所有交易列表，逐个检查
            List<Transaction> set = mapper.getOrDefault(name, new ArrayList<>());
            for (Transaction tran : set) {
                // 如果交易时间之差小于等于 60，而且地点不同，那么就说明该交易不合规
                if (Math.abs(tran.time - time) <= 60 && !tran.address.equals(address)) {
                    // 首先检查之前的交易是否已经放到了返回值中，如果没放到呢，才进行标记+发放到返回值中的操作
                    if (!inReturn[tran.id]) {
                        inReturn[tran.id] = true;
                        ans.add(name + "," + tran.time + "," + tran.money + "," + tran.address);
                    }
                    // 然后检查当前的交易是否放到了返回值中，同上
                    if (!inReturn[id]) {
                        ans.add(transaction);
                        inReturn[id] = true;
                    }
                }
            }
            // 不管是否有效，都要把这个交易放到这个人 name 名下的交易列表中
            set.add(new Transaction(id, time, money, address));
            mapper.put(name, set);
            // 用于标记每一个交易的 id 自增
            id++;
        }
        return ans;
    }

    public static void main(String[] args) {
        String[] transactions = {"alice,20,800,mtv", "alice,50,100,beijing"};
        No1169 no1169 = new No1169();
        System.out.println(no1169.invalidTransactions(transactions));
        transactions = new String[]{"alice,20,1220,mtv", "alice,20,1220,mtv"};
        System.out.println(no1169.invalidTransactions(transactions));
        transactions = new String[]{"alice,20,800,mtv", "alice,50,100,mtv", "alice,51,100,frankfurt"};
        System.out.println(no1169.invalidTransactions(transactions));
        transactions = new String[]{"bob,689,1910,barcelona", "alex,696,122,bangkok", "bob,832,1726,barcelona", "bob,820,596,bangkok", "chalicefy,217,669,barcelona", "bob,175,221,amsterdam"};
        System.out.println(no1169.invalidTransactions(transactions));
    }
}
