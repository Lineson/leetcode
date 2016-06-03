#include "stdlib.h"
#include "stdio.h"

char* reverseString(char* s) {
    int len = 0;
    while (s[len]) len++;
    printf("len = %d\n", len);

    char c;
    int h = 0;
    int t = len -1;

    while (h < t) {
    	c = s[h];
    	s[h] = s[t];
    	s[t] = c;
    	h++;
    	t--;
    };
    return s;
}



int main(int argc, char const *argv[])
{
	char s[7] = "hel o0r";
	reverseString(&s[0]);
	printf("%s\n", s);
	return 0;
}