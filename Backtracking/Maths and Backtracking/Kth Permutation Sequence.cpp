int fact[13];
void generate_factorials() {
    fact[0] = 1;
    int p = fact[0];
    for (int i = 1; i <= 12; i++) {
        p *= i;
        fact[i] = p;
    }
}

int factorial(int n) {
    if (n > 12) {
        return INT_MAX;
    }

    return fact[n];
}

string KthPermutation(int k, vector<int> &numbers)
{
    int n = numbers.size();

    if (n == 0 || k > factorial(n))
        return "";

    int f = factorial(n - 1);
    int pos = k / f;
    k %= f;

    string s = to_string(numbers[pos]);
    numbers.erase(numbers.begin() + pos);

    return s + KthPermutation(k, numbers);
}

string Solution::getPermutation(int n, int k) {

    generate_factorials();
    vector<int> numbers;

    for (int i = 1; i <= n; ++i)
        numbers.push_back(i);

    return KthPermutation(k - 1, numbers);
}

// https://www.interviewbit.com/problems/kth-permutation-sequence/