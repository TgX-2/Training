int n, k;
int f[35][35][3][3], a[35];

int gett(int id, int cnt, bool isless, bool isfirst) {
    if (id < 0) {
        return (cnt == k);
    }

    int &ans = f[id][cnt][isless][isfirst];
    if (ans != -1) return ans;
    ans = 0;

    int lim = a[id];
    
    FOR(digit, 0, 1) if (digit <= lim or isless) 
        ans += gett(id - 1, cnt + (digit == 0 and isfirst), isless | (digit < lim), isfirst | (digit == 1));
    

    return ans;
}

int get(int x) {
    memo(a, 0);
    a[0] = 0;
    int id = 0;
    while(x > 0) {
        a[id] = x % 2;
        x /= 2;
        id++;
    }

    memo(f, -1);
    return gett(id - 1, 0, 0, 0);
}

void process() {
	cin >> n >> k;
	cout << get(n) + (k == 1) - (k == 0);
}
