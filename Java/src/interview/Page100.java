/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package interview;

public class Page100 {
    private static boolean[] sieveOfEratosthenes(int max) {
        boolean[] flags = new boolean[max + 1];
        for (int i = 2; i <= max; ++i) flags[i] = true;
        int prime = 2;
        while (prime <= Math.sqrt(max)) {
            crossOff(flags, prime);
            prime = getNextPrime(flags, prime);
        }
        return flags;
    }

    private static void crossOff(boolean[] flags, int prime) {
        for (int i = prime * prime; i < flags.length; i += prime) flags[i] = false;
    }

    private static int getNextPrime(boolean[] flags, int prime) {
        ++prime;
        while (prime < flags.length && !flags[prime]) ++prime;
        return prime;
    }

    public static void main(String[] args) {
        boolean[] primes = sieveOfEratosthenes(100);
        for (int i = 2; i <= 100; ++i) if (primes[i]) System.out.print(i + " ");
    }
}
