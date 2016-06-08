
/*Your runtime beats 9.97% of csubmissions.*/
bool isPowerOfThree(int n) {
	while (n >= 3 && (n%3 == 0) ){
		n = n/3;
	}

	if (n == 1)
	 	return true;
    else
		return false;
}

/*Your runtime beats 68.28% of csubmissions.*/
bool isPowerOfThree(int n) {
	if (n>3 && n%3 != 0) return false;
	while (n >= 3 && (n%3 == 0) ){
		n = n/3;
	}

	if (n == 1)
	 	return true;
    else
		return false;
}