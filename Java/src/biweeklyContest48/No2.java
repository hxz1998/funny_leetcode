/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package biweeklyContest48;

import java.util.HashMap;
import java.util.Map;

class AuthenticationManager {
    private int timeToLive;
    private Map<String, Integer> tokens;

    public AuthenticationManager(int timeToLive) {
        tokens = new HashMap<>();
        this.timeToLive = timeToLive;
    }

    /**
     * 根据题意，不需要考虑是否之前已经存在了，只需要把 tokenId-currentTime 更新/添加到哈希表中就好
     */
    public void generate(String tokenId, int currentTime) {
        tokens.put(tokenId, currentTime);
    }

    public void renew(String tokenId, int currentTime) {
        // 首先看看缓存（哈希表）中里面有没有对应的 tokenId，如果没有就什么都不用做了
        if (tokens.containsKey(tokenId)) {
            // 如果有的话，先记录下来它的上次生成时间
            int time = tokens.get(tokenId);
            // currentTime - time 就是上次生成时间和当前时间的差值
            // 如果差值严格小于生存时间 timeToLive ，那么就可以更新了，否则什么都不做
            if (currentTime - time < timeToLive) tokens.put(tokenId, currentTime);
        }
    }

    public int countUnexpiredTokens(int currentTime) {
        int ans = 0;
        // 对缓存（哈希表）中的每一个对象进行遍历，检查他们的生成时间和当前时间的差值是否满足要求
        for (Map.Entry<String, Integer> entry : tokens.entrySet()) {
            if (currentTime - entry.getValue() < timeToLive) ++ans;
        }
        return ans;
    }
}

public class No2 {

}
