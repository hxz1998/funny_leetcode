/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.*;

public class No690 {
    class Employee {
        public int id;
        public int importance;
        public List<Integer> subordinates;
    }

    public int getImportance(List<Employee> employees, int id) {
        Map<Integer, Employee> mapper = new HashMap<>();
        for (Employee employee : employees) mapper.put(employee.id, employee);
        Queue<Integer> queue = new ArrayDeque<>();
        int ans = 0;
        queue.offer(id);
        while (!queue.isEmpty()) {
            Employee employee = mapper.get(queue.poll());
            ans += employee.importance;
            for (int item : employee.subordinates) queue.offer(item);
        }
        return ans;
    }
}
