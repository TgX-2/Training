const int maxn = 107;
int n, m;
vector<int> g[maxn];
int dis[maxn][maxn];

void process() {
    cin >> n >> m;
    memo(dis, 0x3f);
    FOR(i, 1, n)
        dis[i][i] = 0;
    FOR(i, 1, m) {
        int u, v, w; cin >> u >> v >> w;
        dis[u][v] = dis[v][u] = w;
    }
    FOR(k, 1, n) FOR(u, 1, n) FOR(v, 1, n)
        if (dis[u][v] > dis[u][k] + dis[k][v])
            dis[u][v] = dis[u][k] + dis[k][v];

    pair<int, int> ans = {0, llongmax};

    FOR(i, 1, n) {
        int sum = 0;
        FOR(j, 1, n)
            sum += dis[i][j];
        if (ans.se > sum)
            ans = {i, sum};
    }
    cout << ans.fi _ ans.se ;
}
