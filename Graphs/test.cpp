#include <bits/stdc++.h>
using namespace std;

#define int unsigned long long
#define SET(m, i) ((m)|(1<<(i)))
#define TEST(m, i) ((m)&(1<<(i)))
#define CLEAR(m, i) ((m)&~(1<<(i)))
#define vi vector<int>
#define vvi vector<vi>

vvi G;
int n;

int intersection(int C, vi &N){
    int auxS = 0;
    for(int &i : N) auxS = SET(auxS, i);
    return C & auxS;
}

int countBits(int k){
    int c = 0;
    for(;n; c += n&1) n -= n&-n;
    return c;
}

int pivot(int &P, int &X){
    for(int i = 0; i<n; ++i) if(TEST(P|X, i)) return i;
    return -1;
}

int maxClique(int R, int P, int X){
    
    if(!(P|X)) return countBits(R);
    int max = 1, intr = intersection(P, G[pivot(P, X)]);
    for(int i = 0; i<n; ++i)
        if(TEST(P, i) && !TEST(intr, i)){
            max = std::max(max, maxClique(SET(R, i), intersection(P, G[i]), intersection(X, G[i])));
            P = CLEAR(P, i); X = SET(X, i);
        }
    return max;    
}

signed main(){
    
    
    return 0;

}
