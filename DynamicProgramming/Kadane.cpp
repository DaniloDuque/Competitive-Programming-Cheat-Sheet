int n, arr[MAX];

int Kadane(){
    int s = 0, mxs = 0;
    for(int i = 0; i<n;){
        s += arr[i++];
        mxs = max(mxs, s);
        s = max(s, 0);
    }return mxs;
}
