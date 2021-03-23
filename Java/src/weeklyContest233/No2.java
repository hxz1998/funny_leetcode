/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package weeklyContest233;

import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Queue;

public class No2 {
    private static final int MOD = 1000_000_007;

    static class Order {
        int price, amount, orderType;

        Order(int price, int amount, int orderType) {
            this.price = price;
            this.amount = amount;
            this.orderType = orderType;
        }
    }

    public int getNumberOfBacklogOrders(int[][] orders) {
        /**
         * 两个优先级队列，对于采购订单 buyQueue 按照价值大小从大到小排序
         * 对于销售订单 sellQueue 按照价值大小从小到大排序
         */
        PriorityQueue<Order> buyQueue = new PriorityQueue<>((o1, o2) -> o2.price - o1.price);
        PriorityQueue<Order> sellQueue = new PriorityQueue<>((o1, o2) -> o1.price - o2.price);
        for (int[] order : orders) {
            Order o = new Order(order[0], order[1], order[2]);
            switch (o.orderType) {
                case 1: {
                    // 是一笔销售订单
                    // 如果采购订单是空的，那么就直接把该订单放到销售订单队列中
                    if (buyQueue.isEmpty()) sellQueue.offer(o);
                    else {
                        while (o.amount > 0) {
                            // 拿出来采购订单中最前面的订单
                            Order buyOrder = buyQueue.poll();
                            // 看看价格大小是否符合要求
                            if (buyOrder.price >= o.price) {
                                // 看看订单数量中哪一个最小，因为不能减成负数了呀
                                int achieve = Math.min(o.amount, buyOrder.amount);
                                o.amount -= achieve;    // 减去配对完成的订单
                                buyOrder.amount -= achieve;
                            }
                            // 如果这个采购订单还有剩余，那就放回采购订单队列中
                            if (buyOrder.amount > 0) buyQueue.offer(buyOrder);
                            // 如果采购订单已经空了，或者最顶上的订单价格不符合要求，那么就中断循环
                            if (buyQueue.isEmpty() || buyQueue.peek().price < o.price) break;
                        }
                        // 如果这个销售订单还有剩余，就放到销售订单队列中
                        if (o.amount > 0) sellQueue.offer(o);
                    }
                    break;
                }
                case 0: {
                    // 是一笔采购订单，具体思路和上面差不多
                    if (sellQueue.isEmpty()) buyQueue.offer(o);
                    else {
                        while (o.amount > 0) {
                            Order sellOrder = sellQueue.poll();
                            if (sellOrder.price <= o.price) {
                                int achieve = Math.min(sellOrder.amount, o.amount);
                                o.amount -= achieve;
                                sellOrder.amount -= achieve;
                            }
                            if (sellOrder.amount > 0) sellQueue.offer(sellOrder);
                            if (sellQueue.isEmpty() || sellQueue.peek().price > o.price) break;
                        }
                        if (o.amount > 0) buyQueue.add(o);
                    }
                    break;
                }
            }
        }
        int ans = 0;
        for (Order order : buyQueue) {
            ans %= MOD;
            ans += (order.amount % MOD);
        }
        for (Order order : sellQueue) {
            ans %= MOD;
            ans += (order.amount % MOD);
        }
        return ans % MOD;
    }

    public static void main(String[] args) {
        int[][] orders = new int[][]{{10, 5, 0}, {15, 2, 1}, {25, 1, 1}, {30, 4, 0}};
        No2 no2 = new No2();
        System.out.println(no2.getNumberOfBacklogOrders(orders));
        orders = new int[][]{{7, 1000000000, 1}, {15, 3, 0}, {5, 999999995, 0}, {5, 1, 1}};
        System.out.println(no2.getNumberOfBacklogOrders(orders));
        orders = new int[][]{{944925198, 885003661, 0}, {852263791, 981056352, 0}, {16300530, 415829909, 0}, {940927944, 713835606, 0}, {606389372, 407474168, 1}, {139563740, 85382287, 1}, {700244880, 901922025, 1}, {972900669, 15506445, 0}, {576578542, 65339074, 0}, {45972021, 293765308, 0}, {464403992, 97750995, 0}, {29659852, 536508041, 0}, {799523481, 299864737, 0}, {711908211, 480514887, 1}, {354125407, 677598767, 1}, {279004011, 688916331, 0}, {263524013, 64622178, 0}, {375395974, 460070320, 0}, {971786816, 379275200, 1}, {577774472, 214070125, 1}, {987757349, 711231195, 0}};
        System.out.println(no2.getNumberOfBacklogOrders(orders));
    }
}
