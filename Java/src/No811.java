import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/**
 * Java
 *
 * @Description: TODO
 * @Author: cherry
 * @Create on: 2022/10/5
 **/

public class No811 {
    public List<String> subdomainVisits(String[] cpdomains) {
        Map<String, Integer> counter = new HashMap<>();
        for (String cpdomain : cpdomains) {
            Token token = new Token(cpdomain);
            for (String domain : token.items) {
                counter.put(domain, counter.getOrDefault(domain, 0) + token.count);
            }
        }
        List<String> ans = new ArrayList<>();
        for (Map.Entry<String, Integer> entry : counter.entrySet()) {
            ans.add(entry.getValue() + " " + entry.getKey());
        }
        return ans;
    }

    private static class Token {
        int count;
        String[] items;

        Token(String cpdomain) {
            parse(cpdomain);
        }

        private void parse(String cpdomain) {
            String[] pair = cpdomain.split(" ");
            this.count = Integer.parseInt(pair[0]);
            String[] domains = pair[1].split("\\.");
            this.items = new String[domains.length];
            for (int idx = domains.length - 1; idx >= 0; --idx) {
                if (idx == domains.length - 1) items[idx] = domains[idx];
                else {
                    items[idx] = domains[idx] + "." + items[idx + 1];
                }
            }
        }
    }
}
