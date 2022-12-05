/**
 * Java
 *
 * @Description: TODO
 * @Author: cherry
 * @Create on: 2022/8/14
 **/
package dji;

import java.util.*;

class Solution {

    /* Write Code Here */
    public int[] schedule(int[][] arr) {
        int n = arr.length;
        PriorityQueue<int[]> pq = new PriorityQueue<>((l, r) -> l[0] == r[0] ? l[1] == r[1] ? r[2] - l[2] : l[1] - r[1] : r[0] - l[0]);
        for (int idx = 0; idx < n; ++idx) {
            pq.add(new int[]{arr[idx][0], arr[idx][1], arr[idx][2], idx});
        }
        List<Integer> list = new ArrayList<>();
        int end = 0;
        int max = 0;
        while (!pq.isEmpty()) {
            int[] task = pq.poll();
            if (end == 0 || end <= task[1]) {
                list.add(task[3]);
                end = task[2];
                max += task[0];
            }
        }
        int max2 = 0;
        int end2 = 0;
        List<Integer> list2 = new ArrayList<>();
        Arrays.sort(arr, (l, r) -> l[1] == r[1] ? r[2] - l[2] : l[1] - r[1]);
        for (int idx = 0; idx < n; ++idx) {
            if (end2 <= arr[idx][1]) {
                end2 = arr[idx][2];
                max2 += arr[idx][0];
            }
        }
        LinkedList<Integer> ll = new LinkedList<>();
        if (max >= max2) {
            int[] ret = new int[list.size()];
            for (int idx = 0; idx < list.size(); ++idx) ret[idx] = list.get(idx);
            return ret;
        } else {
            int[] ret = new int[list2.size()];

        }
        return null;
    }
}

public class No1 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int[] res;

        int arr_rows = 0;
        int arr_cols = 0;
        arr_rows = in.nextInt();
        arr_cols = in.nextInt();

        int[][] arr = new int[arr_rows][arr_cols];
        for (int arr_i = 0; arr_i < arr_rows; arr_i++) {
            for (int arr_j = 0; arr_j < arr_cols; arr_j++) {
                arr[arr_i][arr_j] = in.nextInt();
            }
        }

        if (in.hasNextLine()) {
            in.nextLine();
        }


        res = new Solution().schedule(arr);
        for (int res_i = 0; res_i < res.length; res_i++) {
            System.out.println(String.valueOf(res[res_i]));
        }

    }
}

