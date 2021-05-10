/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.regex.*;

public class No468 {
    private static final String IPV4 = "IPv4", IPV6 = "IPv6", NONE = "Neither";
    private Pattern ipv4Pattern = Pattern.compile("^(([0-9]|[1-9][0-9]|1[0-9][0-9]|2[0-4][0-9]|25[0-5])\\.){3}([0-9]|[1-9][0-9]|1[0-9][0-9]|2[0-4][0-9]|25[0-5])$");
    private Pattern ipv6Pattern = Pattern.compile("^(([0-9a-fA-F]{1,4})\\:){7}([0-9a-fA-F]{1,4})$");

    public String validIPAddress(String IP) {
        if (IP.contains(".")) return ipv4Pattern.matcher(IP).matches() ? IPV4 : NONE;
        else return ipv6Pattern.matcher(IP).matches() ? IPV6 : NONE;
    }
}
