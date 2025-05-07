#include <bits/stdc++.h>
using namespace std;

#define SET(m, i) ((m) | (1ULL << (i)))
#define TEST(m, i) ((m) & (1ULL << (i)))
#define CLEAR(m, i) ((m) &~ (1ULL << (i)))
#define slice(a, n) ranges::subrange(a, a+n)
#define DEBUG(n) cout<<#n<<" = "<<n<<endl
#define DEBUG_ALL(a) for(auto &ee:a) cout<<ee<<' ';cout<<endl;
#define ALL(v) (v).begin(), (v).end()
#define ALLR(a) (a), (a+n)
#define vec vector
#define snd second
#define fst first
#define pb push_back
#define ll long long
const ll MAX = 2e5+20, MOD = 1e9+7;
ll n;

void solve(){        
    cin>>n;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T=1;
    cin>>T;
    while(T--){
        solve();
        //cout<<(solve()? "YES" : "NO")<<endl;
    }return 0;
}
