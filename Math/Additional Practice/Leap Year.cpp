int Solution::solve(int year) {
	return (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
}


// https://www.interviewbit.com/problems/leap-year/