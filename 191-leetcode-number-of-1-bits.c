
int hammingWeight_solution1(uint32_t n) {
    uint32_t c = 0x80000000;
    int cnt = 0;
    
    for(int i = 0; i<32; i++) {
        if(n >= c)  {
            cnt++;
        }
        n = n<<1;
    }
    return cnt;
}

int hammingWeight_solution2(uint32_t n) {
    int cnt = 0;    
    for(int i = 0; i<32; i++) {
        if (n%2 == 1) {
        	cnt++;
        }
        n /= 2;
    }
    return cnt;
}
