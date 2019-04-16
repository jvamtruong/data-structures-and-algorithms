// Bitmask

int getBit(int j, int i) {      // kt bit thu j cua i 
    return (i >> j - 1) & 1;
}

int offBit(int j, int i) {      // set bit thu j cua i la 0
    return i & ~(1 << j - 1);
}

int onBit(int j, int i) {      // neu tai bit thu j cua i la 0 set lai thanh 1 (bat bit)
    return i | (1 << j - 1);
}

int check(int i) {  // neu res = 0 --> i ko ton tai 2 bit 1 nao lien tiep
    return i & (i >> 1);
}

int lowest_index_1(int n) { // vi tri bit 1 thap nhat
    return n & ~(n - 1);
}
