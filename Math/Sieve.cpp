int sv[MAX]; //-1 if prime, trivial divisor if not

void init(){
    memset(sv, -1, sizeof(sv));
    for(int i = 2; i<MAX; ++i)
        if(sv[i] < 0)
            for(int j = 1LL*i*i; j<MAX; j+=i) sv[j] = i;

}

map<int, int> factorize(int n){
    map<int, int> r;
    while(sv[n] >= 0) ++r[sv[n]], n/=sv[n];
    if(n>1) r[n]++;
    return r;
}
