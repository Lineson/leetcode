/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

/*Your runtime beats 86.75% of csubmissions.*/
int* twoSum(int* nums, int numsSize, int target) {
	int *res;
	res = (int *)malloc(2*sizeof(int));
	int hash[200000];
	for (int i = 0; i < 200000; ++i)
	{
		hash[i] = 200200;
	}
	int a;
	int b;

	for (int i = 0; i < numsSize; ++i)
	{
		b = target - nums[i];
		if (hash[100000+b] != 200200) {
			res[0] = hash[100000+b];
			res[1] = i;
			return res;
		}
		hash[100000 + nums[i]] = i;
	}
	return 0;    
}

// Note: Approach of Brute Force also [Accepted]