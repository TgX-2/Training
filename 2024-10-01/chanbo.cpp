const int maxn = 1e5 + 7;
int n, c, a[maxn];

bool check(int l) {
    int pre = a[1], cnt = 1;
    FOR(i, 2, n) {
        if (a[i] - pre >= l) {
            pre = a[i];
            cnt++;
            if (cnt == c) return 1;
        }
    }
    return 0;  
}

void process() {
    cin >> n >> c;
    FOR(i, 1, n) cin >> a[i];
    sort(a + 1, a + 1 + n);

    int l = a[1], r = a[n] - a[1], ans = 0;
    while(l <= r) {
        int mid = (l + r) >> 1;
        if (check(mid)) {
            ans = mid;
            l = mid + 1;
        } else r = mid - 1;
    }
    cout << ans;
}
