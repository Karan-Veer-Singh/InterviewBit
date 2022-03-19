long long gcd(long long int a, long long int b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

long Solution::solve(int a, int b) {
	return (a / gcd(a, b)) * b;
}


// https://www.interviewbit.com/problems/lowest-common-multiple-lcm/