#include <bits/stdc++.h>
using namespace std;

// Tipos curtos (evite overflow: use long long em somas/produtos grandes)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;

// Constantes comuns
const int INF = 0x3f3f3f3f;           // ~1e9, "infinito" em int
const ll LINF = 4e18;                  // "infinito" em long long
const ll MOD = 1e9 + 7;

// Macros de conveniencia (opcionais - use so o que lembrar)
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(x) (int)(x).size()

int main() {
    ll a = 1e18;
    pii p = mp(3, 4);
    vi v = {1, 2, 3};
    cout << p.fi << " " << p.se << " " << sz(v) << "\n";
    return 0;
}
