int exp(int b, int e){
    if(!e) return 1;
    int r = exp((b*b)%MOD, e>>1);
    return ((b*(e&1))*r)%MOD;
}

int inverse(int n){return exp(n, MOD-2);}
