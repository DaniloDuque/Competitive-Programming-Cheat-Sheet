int N, tree[1<<18];

// add v to value at x
void set(int x, int v){
    while(x<=N) tree[x] += v, x += (x&-x);
}

// get cumulative sum up to and including x
int get(int x){
    int r = 0;
    while(x) r+=tree[x], x -= x&-x;
    return r;
}

// get largest value with cumulative sum less than or equal to x
int getIDX(int x){
    int idx = 0, msk = N;
    while(msk && idx < N){
        int t = idx + msk;
        if(x >= tree[t]) idx = t, x -= tree[t];
        msk >>= 1;
    }return idx;
}


