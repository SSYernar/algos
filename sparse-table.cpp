// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
    
#include "bits/stdc++.h"

// #include <ext/rope>

// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
     
using namespace std;
// using namespace __gnu_cxx;
//using namespace __gnu_pbds;
     
void err(istream_iterator<string> it) {cout << '\n';}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
    string s = typeid(a).name();
    cout << "[" << *it << " = ";
    cout << a;
    cout << "] ";
    err(++it, args...);
}

void catchAlarm(int sig) {
    cout << "TL!!!!!";
    exit(0);
}
     
#define F first
#define S second
#define ll long long
#define ull unsigned ll
#define pb push_back
#define pf push_front
#define db double
#define ld long double
#define ofk order_of_key
#define fbo find_by_order
#define ppb pop_back
#define ppf pop_front
#define br cout << '\n'
#define pii pair<int, int>
#define pil pair<int, ll>
#define pli pair<ll, int>
#define pll pair<ll, ll>
#define here cout << "HERE\n"
#define bruh cout << "BRUH\n"
#define all(x) (x).begin(),(x).end()
#define speed ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define watch(x) cout << (#x) << " is " << (x) << endl
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define sqr(x) ((x) * (x))

void assertTL(bool stat) {while(!stat){}}
void assertML(bool stat) {vector<ll> v;while(!stat){v.pb(1);}}

int gcd(int a, int b) {if (a < b) swap(a, b); return b ? gcd(b, a % b) : a;}
ll gcd(ll a, ll b) {if (a < b) swap(a, b); return b ? gcd(b, a % b) : a;}
   
pair<int, int> dx2[] = {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
pair<int, int> dx[] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int inf = 2e9 + 7;
ll INF = 1e18 + 7;
ld pi = 3.1415926535897932384626433;
db eps = 1e-7;
ld EPS = 1e-9;
int mod = 1e9 + 7;
int mod2 = 1000010029;
int BASE = 1000117;
int base = 29;
ll MOD = 1e15 + 7;
    
mt19937 lol(chrono::steady_clock::now().time_since_epoch().count());

void Max(int &a, int b) {
    if (b > a) a = b;
}
void Min(int &a, int b) {
    if (b < a) a = b;
}   
void Max(ll &a, ll b) {
    if (b > a) a = b;
}
void Min(ll &a, ll b) {
    if (b < a) a = b;
}    
void Add(int &a, int b) {
    a += b;
    if (a >= mod) a -= mod;
    if (a < 0) a += mod;
}
void Sub(int &a, int b) {
    a -= b;
    if (a >= mod) a -= mod;
    if (a < 0) a += mod;
}
int add(int a, int b) {
    a += b;
    if (a >= mod) a -= mod;
    if (a < 0) a += mod;
    return a;
}
int sub(int a, int b) {
    a -= b;
    if (a < 0) a += mod;
    if (a >= mod) a -= mod;
    return a;
}
int mul(int a, int b) {
    return a * 1ll * b % mod;
}

int bp(int a, int n, int mOd = mod) {
    if (n == 0) return 1;
    int res = bp(a, n / 2, mOd);
    res = res * 1ll * res % mOd;
    if (n & 1) res = res * 1ll * a % mOd;
    return res;
}


const bool multiple_tests = 0;
const int N = 2e5 + 77;

// #define int long long

int n, a[N], p[N], t[N][20];

void build() {
    for (int j = 1; (1 << j) <= n; j++) {
        for (int i = 1; i + (1 << j) - 1 <= n; i++) {
            t[i][j] = min(t[i][j - 1], t[i + (1 << (j - 1))][j - 1]);
        }
    }
}

int get(int l, int r) {
    int pw = p[r - l + 1];
    return min(t[l][pw], t[r - (1 << pw) + 1][pw]);
}

void solve() { 
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        p[i] = log2(i);
        t[i][0] = a[i];
    }
    build();
}
// KEEP IT SIMPLE


signed main() { 
    speed;
    string file_name = "test";
    // file_name = "trains";
    #ifndef ONLINE_JUDGE
        signal(SIGALRM, catchAlarm);
        alarm(5);
        freopen((file_name + ".in").c_str(), "r", stdin);
        freopen((file_name + ".out").c_str(), "w", stdout);
    #endif
    int TT = 1;
    if (multiple_tests) cin >> TT;

    for (int testcase = 1; testcase <= TT; testcase++) {
        solve();
        cout << '\n';
    }
        
//    #ifndef ONLINE_JUDGE
//      cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
//    #endif
    return 0;
}