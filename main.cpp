#include<bits/stdc++.h>
#define f(i,a,b) for(i=a;i<b;i++)
#define f_(i,a,b) for(i=a;i>=b;i--)
#define T_ ll t; cin>>t; while(t--)
#define NeedForSpeed ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pb push_back
#define mod 1000000007
#define mp make_pair
#define read(a,n) for(i=0;i<n;i++) cin>>a[i]
#define pr(a,n)  for(i=0;i<n;i++) cout<<a[i] << " "; cout<<"\n"
#define ff first
#define ss second
#define iof freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#define sp << " " <<
#define nl << "\n"
#define all(s) s.begin(),s.end()
#define minv(a) *min_element(all(a))
#define maxv(a) *max_element(all(a))
#define sumv(a) accumulate(all(a),0)
#define lb lower_bound //lower_bound returns an iterator pointing to the first element in the range [first,last) which has a value not less than ‘val’.
#define ub upper_bound //upper_bound returns an iterator pointing to the first element in the range [first,last) which has a value greater than ‘val’.
#define vi vector<ll>
#define iii = tuple<int, int, ll>
#define vvi = vector<vi>
#define viii = vector<iii>
#define setpre(a) cout << setprecision(a) << fixed

typedef long long ll ; typedef long double ld;
using namespace std;
//const int INF=0x3f3f3f3f;
ll po(ll a, ll b, ll M) {ll res = 1;a = a % M;while (b) {if (b % 2)res = (res * a) % M;b /= 2;a = (a * a) % M;}return res;}
ll pw(ll x, ll y){if (y == 0)return 1;else if (y % 2 == 0)return po(x, y / 2,mod)%mod * po(x, y / 2,mod)%mod;else return x * po(x, y / 2,mod) %mod* po(x, y / 2,mod)%mod;}
ll modInverse(ll n, ll M){return po(n, M - 2, M);}
ll nCrModPFermat(ll n, ll r, ll M){if (!r)return 1;ll fac[n + 1];fac[0] = 1;ll i;f(i, 1, n + 1){fac[i] = fac[i - 1] * i % M;}return (fac[n] * modInverse(fac[r], M) % M *modInverse(fac[n - r], M) % M) %M;}
ll logk(ll a, ll b){return log(a) / log(b);}
bool isPrime(ll N){for (ll i = 2; i * i <=N; ++i){if (N % i == 0)return false;}return true;}
ll gcd(ll a, ll b){if(b==0) return a;return gcd(b, a%b);}
bool comp(const pair<int,int> &a,const pair<int,int> &b){
    if(a.first==b.first)
        return a.first<b.first;
    else
        return a.second<b.second;
}
bool sortin(const pair<int,int> &a,const pair<int,int> &b){
    if(a.second==b.second)
        return a.second<b.second;
    else
        return a.first<b.first;
}
vector<bool>prime(100005, true);
void SieveOfEratosthenes(ll n)
{
    for (ll p=2; p*p<=n; p++){
        if (prime[p] == true){
            for (ll i=p*p; i<=n; i += p)
                prime[i] = false;
        }
    }
}


//ll inf=(1LL << 60);
//const int dx[4] = {-1, 0, 0, 1};
//const int dy[4] = {0, -1, 1, 0};
//
//char a[1000 + 1][1000 + 1];
//ll n, m;
//bool isValid(ll x,ll y){
//    if(x<0 || y<0 || y>m-1 || x>n-1){
//        return false;
//    }
//    if(a[x][y]=='#')
//        return false;
//    return true;
//}

//ll c[100000+5];
//vector<ll>arr[100005];
//vector<ll>ans;
//int vis[100005];
//void dfs(ll node) {
//    vis[node] = 1;
//    ll f=1;
//    if(c[node]==0) {
//        f = 0;
//    }
//    for (auto child:arr[node]) {
//        if (!vis[child]) {
//            if(c[child]==0){
//                f=0;
//            }
//            dfs(child);
//        }
//    }
//    if(f)
//        ans.pb(node);
//}
//vector<vector<pair<ll,ll>>>v(1000001);
//int dist[1001][1001];
//void bfs(ll i,ll j) {
//    queue<pair<ll, ll>> q;
//    q.push({i, j});
//    dist[i][j] = 0;
//    a[i][j]='#';
//    v[dist[i][j]].pb({i,j});
//    while (!q.empty()) {
//        ll x = q.front().first;
//        ll y = q.front().second;
//        q.pop();
//        for (ll k = 0; k < 4; k++) {
//            ll x1 = x + dx[k], y1 = y + dy[k];
//            if (isValid(x1, y1)) {
//                q.push({x1, y1});
//                dist[x1][y1] = dist[x][y] + 1;
//                a[x1][y1] = '#';
//                v[dist[x1][y1]].pb({x1,y1});
//            }
//        }
//    }
//}
//vector<vector<ll>> dp(200005, vector<ll> (3, -1));
//ll dp[300005][3],x;
//ll dpsoln(ll n,ll w) {
//    if (n == 0) {
//        return 0;
//    }
//    if (dp[n][w] != -1) {
//        return dp[n][w];
//    }
//    dp[n][w]=0;
//    if(w!=2){
//        dp[n][w]=max(x*a[n]+dpsoln(n-1,2),x*a[n]+dpsoln(n-1,1));
//    }
//    dp[n][w]=max(dp[n][w],0LL);
//    ll temp=w;
//    if(w==1)
//        temp=2;
//    dp[n][w] = max(dp[n][w],a[n]+dpsoln(n-1,temp));
//    return dp[n][w];
//}
int main() {
    NeedForSpeed;
    T_ {
        string s;
        cin >> s;
        ll last = -1, ans = 0,i;
        for (i = 0; i < s.size(); i++) {
            if (s[i] == 'L') ans = max(ans, i - last);
            else last = i;
        }
        cout << ans + 1 << "\n";
    }
    return 0;
}
