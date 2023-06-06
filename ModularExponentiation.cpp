#include <bits/stdc++.h>

int modularExponentiation(int x, int n, int m) {
    long result = 1;
    long base = x;

    while (n > 0) {
        if (n % 2 != 0) {
            result = ((result) % m * (base) % m) % m;
        }

        base = ((base) % m * (base) % m) % m;
        n = n >> 1;
    }

    return (int)(result % m);
}
