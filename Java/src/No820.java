import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

/**
 * Created by Xiaozhong on 2021/2/1.
 * Copyright (c) 2021/2/1 Xiaozhong. All rights reserved.
 */

public class No820 {
    public int minimumLengthEncoding(String[] words) {
        Set<String> goods = new HashSet<>(Arrays.asList(words));
        // 枚举每一个单词的后缀，然后从 goods 中删掉
        for (String word : words) {
            for (int k = 1; k < word.length(); ++k) {
                goods.remove(word.substring(k));
            }
        }
        int ans = 0;
        for (String word : goods) ans += word.length() + 1;
        return ans;
    }
}
