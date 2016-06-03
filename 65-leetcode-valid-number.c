#include "stdlib.h"
#include "stdio.h"


#define bool int
#define false 0
#define true 1

bool isAnum(char a){
    if ( a>=48 && a<=57 )
        return true;
    else 
        return false;
}

bool isBlank(char *s){
    int i = 0;;
    while(s[i]){
        if (s[i] != 0x20) return false;
        i++;
    }
    return true;
}

bool isSeqnum(char *s){
    if ( !isAnum(s[0]) ) return false;

    int i = 0;
    while( isAnum(s[i]) ){
        i++;
    }
    return isBlank(&s[i]);
}

bool isScienceNum(char *s) {
    int i = 0;
    while(isAnum(s[i])) i++;
    if (s[i] != 0x65 || i==0 ) return false;
    return isSeqnum(&s[i+1]);

}


bool isNumber(char* s) {
    int i = 0;
    while( s[i] == 0x20 )  i++;
    if (!s[i]) return false;

    if (s[i] == 0x2D || s[i] == 0x2B) i++;  // - or +

    int point = 0;
    int ee = 0;
    bool hasNUM = 0;

    int flag_pe = 0;

    while(s[i]){
        if ( !isAnum(s[i]) ) {

            if (s[i] != 0x2E && s[i]!= 0x65 ) { // not point nor e
                if (s[i] != 0x20) return false;
                if (hasNUM && isBlank(&s[i]))
                    return true;
                else return false;
            }

            if(s[i] == 0x2E){ // is point
                point++;
                if (point>1) return false;
                if (s[i+1] == 0x65){
                    flag_pe = 1;
                    i++;
                }


                int j = i;
                int e_later = 0;
                while(s[j]) {
                    if (s[j] == 0x65)  e_later = 1; 
                    j++;
                }

                if (e_later == 1)
                {
                    if (hasNUM == 0) {
                        if (flag_pe == 0) {
                            return isSeqnum(&s[i+1]);
                        }
                        else {
                            return false;
                        }
                    }
                    else {
                        if (flag_pe == 0) {
                            return isSeqnum(&s[i+1]) + isBlank(&s[i+1]); 
                        }
                        else {
                            return isSeqnum(&s[i+1]);
                        }
                    }
                }
                else {
                    return isScienceNum(&s[i]);
                }


            }

            if(s[i] == 0x65){ // is e
                ee++;
                if (ee > 1 || hasNUM == 0) return false;

                return isSeqnum(&s[i+1]);
            }

        }
        else{
            hasNUM = 1;
        }

        i++;
    }
    return true;
}



int main(int argc, char const *argv[])
{
	char s[] = " .2e81 ";
	bool a = isNumber(&s[0]);
	printf("%d\n", a);
	return 0;
}