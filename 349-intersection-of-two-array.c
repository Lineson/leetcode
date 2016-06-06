#include "stdlib.h"
#include "stdio.h"


void swap(int *a, int *b){
    int tmp = *b;
    *b = *a;
    *a = tmp;
    return; 
}

void quick_sort(int *arr, int h, int t) {
    if (h >= t) return;

    int flag = arr[h];
    int i = h+1;
    int j = t;
    while(i <= j) { //make sure <=
        while(arr[i] <= flag && i<j) i++;
        while(arr[j] > flag) j--;
        if (i>=j) break;
        swap(&arr[i], &arr[j]);
    }

    swap(&arr[h], &arr[j]);

    quick_sort(arr, h, j-1);
    quick_sort(arr, j+1, t);
    return;
}

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* intersection_quick_sort(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) { 
    int tmp_res[nums1Size];
    
    quick_sort(nums1, 0, nums1Size-1);
    quick_sort(nums2, 0, nums2Size-1);
    
    int i = 0;
    int j = 0; 
    int last = 0x0fffffff;

    while(i<nums1Size && j<nums2Size) {
        if (nums1[i] == nums2[j] && nums1[i] != last) {
            tmp_res[(*returnSize)++] = nums1[i]; 
            last = nums1[i];
            i++;
            j++;
        }
        else if (nums1[i] < nums2[j] ) {
            i++;
        }
        else {
            j++;
        }
    }

    int *res;
    res = (int *)malloc( (*returnSize) * sizeof(int));
    for (i = 0; i < *returnSize; ++i) 
        res[i] = tmp_res[i];
    return res;

}



/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) { 
    int tmp_res[nums1Size];
    int tmp_num = 0;
    
    int bucket[10000] = {0};
    for (int i = 0; i < nums1Size; ++i) {
        bucket[nums1[i]] = 1; 
    }

    for (int i = 0; i < nums2Size; ++i) {
        if (bucket[nums2[i]] == 1) {
            tmp_res[tmp_num++] = nums2[i];
            bucket[nums2[i]] += 1;             
        } 
    }

    *returnSize = tmp_num;
    int *res;
    res = (int *)malloc( (*returnSize) * sizeof(int));
    for (int i = 0; i < *returnSize; ++i) 
        res[i] = tmp_res[i];
    return res;
}




int main(int argc, char const *argv[])
{
    int a[6] = {7,3,4,2,4,5};
    int b[2] = {2,4};
    int size = 0;
    int *res;
    res = intersection(&a[0], 6, &b[0], 2, &size);

    int i = 0;
    for (i = 0; i < size; ++i)
    {
        printf("%d ", res[i]);
    }
 
	return 0;
}