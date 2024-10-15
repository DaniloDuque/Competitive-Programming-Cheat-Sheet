int exp(int b, int e){
    if(!e) return 1;
    if(e&1) return (b*exp((b*b)%MOD, e>>1))%MOD;
    return exp((b*b)%MOD, e>>1);
}

int inverse(int n){return exp(n, MOD-2);}
