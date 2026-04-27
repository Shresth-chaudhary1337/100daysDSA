#include <iostream>
using namespace std;

int integerSqrt(int n) {
    long long low = 0, high = n;
    int ans = 0;

    while (low <= high) {
        long long mid = low + (high - low) / 2;

        if (mid * mid == n)
            return mid;
        else if (mid * mid < n) {
            ans = mid;        // store possible answer
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return ans;
}

int main() {
    int n;
    cin >> n;

    cout << integerSqrt(n);
    return 0;
}