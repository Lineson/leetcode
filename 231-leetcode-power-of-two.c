/*Your runtime beats 52.46% of csubmissions.*/
bool isPowerOfTwo(int n) {
	while (n >= 2 && (n%2 == 0) ){
		n = n/2;
	}

	if (n == 1)
	 	return true;
    else
		return false;
}

/*Your runtime beats 4.93% of csubmissions.*/
bool isPowerOfTwo(int n) {
	if (n>2 && n%2 != 0) return false;
	while (n >= 2 && (n%2 == 0) ){
		n = n/2;
	}

	if (n == 1)
	 	return true;
    else
		return false;
}