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

    public void generate(String tokenId, int currentTime) {
        tokens.put(tokenId, currentTime);
    }

    public void renew(String tokenId, int currentTime) {
        if (tokens.containsKey(tokenId)) {
            int time = tokens.get(tokenId);
            if (currentTime - time < timeToLive) tokens.put(tokenId, currentTime);
        }
    }

    public int countUnexpiredTokens(int currentTime) {
        int ans = 0;
        for (Map.Entry<String, Integer> entry : tokens.entrySet()) {
            if (currentTime - entry.getValue() < timeToLive) ++ans;
        }
        return ans;
    }
}

public class No2 {

}
