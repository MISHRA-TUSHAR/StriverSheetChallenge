#include <iostream>
#include <string>
#include <climits>

bool isPalindrome(const std::string& s, int i, int j) {
    while (i < j) {
        if (s[i] != s[j]) {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

int func(const std::string& s, int i, int j) {
    if (i >= j) {
        return 0;
    }
    if (isPalindrome(s, i, j)) {
        return 0;
    }

    int mini = INT_MAX;

    for (int k = i; k <= j - 1; k++) {
        int temp = 1 + func(s, i, k) + func(s, k + 1, j);
        mini = std::min(temp, mini);
    }
    return mini;
}

int palindromePartitioning(const std::string& str) {
    return func(str, 0, str.length() - 1);
}

int main() {
    std::string str = "example";
    int result = palindromePartitioning(str);
    std::cout << "Minimum number of partitions: " << result << std::endl;
    return 0;
}
