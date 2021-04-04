/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

public class No74 {
    /*public boolean searchMatrix(int[][] matrix, int target) {
        int m = matrix.length, n = matrix[0].length;
        // 首先检查前 n - 1 行，两两比较第一个元素，看看当前行 i 第一个元素是否是最后一个小于 target 的元素
        for (int i = 0; i < m - 1; ++i) {
            if (matrix[i][0] <= target && matrix[i + 1][0] > target) {
                // 如果是的话，就在当前行开始二分查找
                return binarySearch(matrix[i], 0, n, target);
            }
        }
        // 因为没有检查最后一行是否满足需要，所以这里再补上最后一行的检查
        if (matrix[m - 1][0] <= target && binarySearch(matrix[m - 1], 0, n, target)) return true;
        return false;
    }
    // 二分查找
    private boolean binarySearch(int[] vector, int left, int right, int target) {
        // 只要左端点小于右端点，就一直循环下去
        while (left < right) {
            // 之所以要 left + (right - left) / 2是防止直接相加造成了溢出
            int mid = left + (right - left) / 2;
            // 如果找到了的话，就直接返回来就可以了
            if (vector[mid] == target) return true;
                // 如果中间元素小了，就让左端点移到中间右边一点
            else if (vector[mid] < target) left = mid + 1;
                // 如果大了，就让右端点移动到中间
            else right = mid;
        }
        return false;
    }
    */
    public boolean searchMatrix(int[][] matrix, int target) {
        int m = matrix.length, n = matrix[0].length;
        // 假设是一个一维向量，那么最右边肯定是总的个数 - 1
        int low = 0, high = m * n - 1;
        while (low <= high) {
            // 找到中间位置的一维表示
            int mid = low + (high - low) / 2;
            // mid/n 就是行号，mid%n就是列号，这是一个小技巧
            int value = matrix[mid / n][mid % n];
            if (value == target) return true;
            else if (value < target) low = mid + 1;
            else high = mid - 1;
        }
        return false;
    }

    public static void main(String[] args) {
        No74 no74 = new No74();
        int[] vector = {10, 11, 16, 20};
//        System.out.println(no74.binarySearch(vector, 0, vector.length, 11));
        int[][] matrix = {{1}, {3}};
        System.out.println(no74.searchMatrix(matrix, 3));
    }
}
