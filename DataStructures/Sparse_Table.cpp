#define fun min
int spt[K][1<<K], n; // -> 2^K > n

void init(int *a){
    for(int i = 0; i<n;) spt[0][i] = a[i++];
    for(int k = 1; k<K; ++k)
        for(int i = 0; i<=n-(1<<k); ++i)
            spt[k][i] = fun(spt[k-1][i], spt[k-1][i+(1<<(k-1))]);
}

int query(int i, int j){
    int k = 31-__builtin_clz(j-i);
    return fun(spt[k][i], spt[k][j-(1<<k)]);
}
