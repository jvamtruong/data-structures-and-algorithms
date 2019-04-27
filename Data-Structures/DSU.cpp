//http://vnoi.info/wiki/algo/data-structures/disjoint-set

// par[x] < 0 --> x la goc, -par[x] : so luong dinh nhan x la goc
// par[x] = y --> y la cha cua nut x

int root(int x) { 
    while (par[x] > 0) x = par[x];
    return x;
}

void merge(int x, int y) {
    x = root(x);
    y = root(y);
    if (x == y) return;
    if (par[x] < par[y]) {
        par[x] += par[y];
        par[y] = x;
    }
    else {
        par[y] += par[x];
        par[x] = y;
    }
}
