/*
 * Copyright (c) 10/17/2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package weeklyContest263;

public class No2 {
    class Bank {
        // 最好呢，要分离出来每一个操作，当成一个独立的函数
        private long[] balance;
        private int n;

        public Bank(long[] balance) {
            this.balance = balance;
            n = balance.length;
        }

        public boolean transfer(int account1, int account2, long money) {
            if (account1 >= 1 && account1 <= n && account2 >= 1 && account2 <= n) {
                if (balance[account1 - 1] < money) return false;
                balance[account2 - 1] += money;
                balance[account1 - 1] -= money;
                return true;
            }
            return false;
        }

        public boolean deposit(int account, long money) {
            if (account >= 1 && account <= n) {
                balance[account - 1] += money;
                return true;
            }
            return false;
        }

        public boolean withdraw(int account, long money) {
            if (account >= 1 && account <= n && balance[account - 1] >= money) {
                balance[account - 1] -= money;
                return true;
            }
            return false;
        }
    }
}
