

int aplusb(int a, int b) {
    // write your code here
    int carry = 0;
    
    for (int pos=0; pos < 31; pos++) {
        if ((a & b & (1 << pos)) || 
            (a & carry & (1 << pos)) || 
            (b & carry & (1 << pos)))
            
                carry |= 1 << (pos+1);
            
    }
    return a ^ b ^ carry;
}

int main() {
    int a, b;
    scanf("%d+%d", &a, &b);
    printf("%d", aplusb(a, b));
}
