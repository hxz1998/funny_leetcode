/*
 * Copyright (c) 8/11/2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.*;

/**
 * 这道题没有做完，会员到期了呜呜呜
 */
public class No1236 {
    static interface HtmlParser {
        public List<String> getUrls(String url);
    }


    public List<String> crawl(String startUrl, HtmlParser htmlParser) {
        Set<String> visited = new HashSet<>();
        Queue<String> urlQueue = new LinkedList<>();
        String hostUrl = startUrl.substring(7).split("/")[0];
        List<String> urls = htmlParser.getUrls(startUrl);
        for (String url : urls) {
            if (isSameHost(url, hostUrl) && !visited.contains(url)) {
                urlQueue.offer(url);
                visited.add(url);
            }
        }
        while (!urlQueue.isEmpty()) {
            int size = urlQueue.size();
            for (int i = 0; i < size; ++i) {
                List<String> nextUrls = htmlParser.getUrls(urlQueue.poll());
                for (String item : nextUrls) {
                    if (!visited.contains(item)) {

                    }
                }
            }
        }
        return null;
    }

    private boolean isSameHost(String url, String hostUrl) {
        String host = url.substring(7).split("/")[0];
        if (host.equals(hostUrl)) return true;
        return false;
    }
}
