//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
    
#include <bits/stdc++.h>

//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
     
using namespace std;
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
#define pll pair<long long, long long>
#define here cout << "HERE\n"
#define bruh cout << "BRUH\n"
#define all(x) (x).begin(),(x).end()
#define sqr(x) (x) * (x)
#define __ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define watch(x) cout << (#x) << " is " << (x) << endl
#define rep(i, a, n) for (int i = a; i <= n; i++)
#define TEST int TT; cin >> TT; for(int T = 1; T <= TT; T++)
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define lb lower_bound
#define ub upper_bound
#define pii pair<int, int>
    
int gcd(int a, int b) {if (a < b) swap(a, b); return b ? gcd(b, a % b) : a;}
ll gcd(ll a, ll b) {if (a < b) swap(a, b); return b ? gcd(b, a % b) : a;}
   
pair<int, int> dx[] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
     
int inf = 2e9 + 7;
ll INF = 9e18 + 7;
//const ld pi = 3.1415926535897932384626433;
db eps = 1e-6;
//const ld EPS = 1e-9;
int mod = 1e9 + 7;
int mod2 = 1000010029;
int BASE = 1000117;
ll MOD = 1e15 + 7;
    
//mt19937 lol(chrono::steady_clock::now().time_since_epoch().count());
//mt19937_64 rofl(chrono::steady_clock::now().time_since_epoch().count());
    
//random_device random_device;
//mt19937 generator(random_device());
    

void Add(int &a, int b) {
    a += b;
    if (a >= mod) a -= mod;
}
void Sub(int &a, int b) {
    a -= b;
    if (a < 0) a += mod;
}
int add(int a, int b) {
    a += b;
    if (a >= mod) a -= mod;
    return a;
}
int sub(int a, int b) {
    a -= b;
    if (a < 0) a += mod;
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
int inv(int a, int mOd = mod) {
    return bp(a, mOd - 2, mOd);
}


const bool multiple_tests = 1;
const int N = 1e5 + 7;

//#define int long long

struct node {
    int tl, tr;
    ll k, b;
    node *l;
    node *r;
    node(bool flag = 0) {
        k = 0;
        tl = -1e5;
        tr = 1e5 + 1;
        b = INF;
        if (flag) b = -INF;
        l = r = nullptr;
    }
    node(ll _k, ll _b): k(_k), b(_b) {}
} *rootmn, *rootmx;

ll f(node line, int x) {
    return line.k * x + line.b;
}

void init() {
    rootmn = new node(); 
    rootmx = new node(1);
}

void insertmn(node cur, node *v = rootmn) {
    int tm = (v->tl + v->tr) >> 1;
    bool l = f(cur, v->tl) < f(*v, v->tl);
    bool mid = f(cur, tm) < f(*v, tm);
    if (mid) {
        swap(cur.k, v->k);
        swap(cur.b, v->b);
    }
    if (v->tl == v->tr) 
        return;
    if (l != mid) {
        if (!v->l) {
            v->l = new node();
            v->l->tl = v->tl;
            v->l->tr = tm;
        }
        insertmn(cur, v->l);
    }
    else {
        if (!v->r) {
            v->r = new node();
            v->r->tl = tm + 1;
            v->r->tr = v->tr;
        }
        insertmn(cur, v->r);
    }
}

void insertmx(node cur, node *v = rootmx) {
    int tm = (v->tl + v->tr) >> 1;
    bool l = f(cur, v->tl) > f(*v, v->tl);
    bool mid = f(cur, tm) > f(*v, tm);
    if (mid) {
        swap(cur.k, v->k);
        swap(cur.b, v->b);
    }
    if (v->tl == v->tr) return;
    if (l != mid) {
        if (!v->l) {
            v->l = new node(1);
            v->l->tl = v->tl;
            v->l->tr = tm;
        }
        insertmx(cur, v->l);
    }
    else {
        if (!v->r) {
            v->r = new node(1);
            v->r->tl = tm + 1;
            v->r->tr = v->tr;
        }
        insertmx(cur, v->r);
    }
}

ll getmn(int x, node* v = rootmn) {
    ll tmp = f(*v, x);
    int tm = (v->tl + v->tr) >> 1;
    if (x <= tm) {
        if (!v->l) return tmp;
        return min(tmp, getmn(x, v->l));
    }
    if (!v->r) return tmp;
    return min(tmp, getmn(x, v->r));
}

ll getmx(int x, node* v = rootmx) {
    ll tmp = f(*v, x);
    int tm = (v->tl + v->tr) >> 1;
    if (x <= tm) {
        if (!v->l) return tmp;
        return max(tmp, getmx(x, v->l));
    }
    if (!v->r) return tmp;
    return max(tmp, getmx(x, v->r));
}

void solve() {
    //
}


signed main() { __
//  freopen("condense2.in", "r", stdin);
//  freopen("condense2.out", "w", stdout);
    int TT = 1;
    if (multiple_tests) cin >> TT;
    for (int testcase = 1; testcase <= TT; testcase++) {
        solve();
        cout << '\n';
    }
        
//    #ifndef SSYernar
//      cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
//    #endif
    return 0;
}
