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
    while(i <= j) {
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
int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    quick_sort(nums1, 0, nums1Size-1);
    quick_sort(nums2, 0, nums2Size-1);

    if (nums1[0] > nums2[nums2Size-1] || nums1[nums1Size-1] < nums2[0])
    {
        *returnSize = 0;
        return NULL;
    }
    int i = 0;
    int j = 0;

    int count = 0;
    int tmp_res[nums1Size];

    // memset(&tmp_res[0], 0, sizeof(tmp_res));
    while(i<nums1Size && j<nums2Size){
        if (nums1[i] == nums2[j]) {
            tmp_res[count++] = nums1[i];
            i++;
            j++;
        }
        else if (nums1[i] < nums2[j]) {
            i++;
        }
        else {
            j++;
        }
    }

    *returnSize = count;

    int *res;
    res = (int *)malloc(count*sizeof(int));
    for (i = 0; i < count; ++i) {
        res[i] = tmp_res[i];
    }
    return res;
}


int main(int argc, char const *argv[])
{

    int a[] = {1,2};
    int b[] = {1};
    int size = 0;
    int *res;
    res = intersect(&a[0], sizeof(a)/sizeof(int), &b[0], sizeof(b)/sizeof(int), &size);

    int i = 0;
    for (i = 0; i < size; ++i)
    {
        printf("%d ", res[i]);
    }
	return 0;
}