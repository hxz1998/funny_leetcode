package interview;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;

public class No10dot02 {
    public List<List<String>> groupAnagrams(String[] strs) {
        HashMap<String, List<String>> hashMapList = new HashMap<>();
        for (String str : strs) {
            String key = sortChars(str);
            List<String> list = hashMapList.getOrDefault(key, new ArrayList<>());
            list.add(str);
            hashMapList.put(key, list);
        }
        return new ArrayList<>(hashMapList.values());
    }

    private String sortChars(String s) {
        char[] cs = s.toCharArray();
        Arrays.sort(cs);
        return new String(cs);
    }

    public static void main(String[] args) {
        String[] strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
        No10dot02 no10dot02 = new No10dot02();
        var ret = no10dot02.groupAnagrams(strs);
        for (var list : ret) {
            System.out.println(list.toString());
        }
    }
}
