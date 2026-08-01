// l se r waale bits ko 1 kardo

int setBits(int n, int l, int r) {
    int mask = ((1 << (r - l + 1)) - 1) << l; 
    return n | mask;
}