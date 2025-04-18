BÀI 1:

int sumToN(int n) {
    vector<int> dp(n + 1, 0); // Mảng lưu tổng từ 1 đến i
    for (int i = 1; i <= n; ++i) {
        dp[i] = dp[i - 1] + i; // Tổng đến i = tổng đến (i-1) + i
    }
    return dp[n];
}


BÀI 2:

long long factorial(int n) {
    vector<long long> dp(n + 1, 1); // Mảng lưu giai thừa, dp[0] = 1
    for (int i = 1; i <= n; ++i) {
        dp[i] = i * dp[i - 1]; // i! = i × (i-1)!
    }
    return dp[n];
}

BÀI 3:

long long fibonacci(int n) {
    vector<long long> dp(n + 1, 0); // Mảng lưu số Fibonacci
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2]; // F(i) = F(i-1) + F(i-2)
    }
    return dp[n];
}

BÀI 4:

long long power(int x, int n) {
    vector<long long> dp(n + 1, 1); // Mảng lưu x^i
    dp[0] = 1; // x^0 = 1
    for (int i = 1; i <= n; ++i) {
        dp[i] = x * dp[i - 1]; // x^i = x × x^(i-1)
    }
    return dp[n];
}

BÀI 5:

int countDigits(int n) {
    if (n == 0) return 1; // Trường hợp đặc biệt: 0 có 1 chữ số
    int count = 0;
    while (n > 0) {
        n /= 10; // Chia n cho 10
        count++; // Tăng số chữ số
    }
    return count;
}

BÀI 6:

int sumOfDigits(int n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10; // Lấy chữ số cuối
        n /= 10;       // Loại bỏ chữ số cuối
    }
    return sum;
}

BÀI 7:

long long reverseNumber(int n) {
    long long revNum = 0;
    while (n > 0) {
        revNum = revNum * 10 + n % 10; // Thêm chữ số cuối vào revNum
        n /= 10;                       // Loại bỏ chữ số cuối
    }
    return revNum;
}