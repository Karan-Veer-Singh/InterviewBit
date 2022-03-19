string Solution::solve(int A) {
	string s = "";

	if (A == 12 || A == 1 || A == 2) s = "Winter";
	else if (A >= 3 && A <= 5)   s = "Spring";
	else if (A >= 6 && A <= 8)   s = "Summer";
	else if (A >= 9 && A <= 11)  s = "Autumn";
	else    s = "Invalid";

	return s;
}


// https://www.interviewbit.com/problems/which-season/