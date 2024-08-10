int n, arr[MAX], lis[MAX], idx[MAX], path[MAX];

void printLIS(int end){
    if(end == -1) return;
    printLIS(path[end]);
    printf("%d ", end);
}

int LIS(){

    int end = 0, c = 0;
    for(int i = 0; i<n; i++){
        int index = lower_bound(lis, lis+c, arr[i]) - lis;
        lis[index] = arr[i];
        idx[index] = i;
        path[i] = (index)? idx[index-1]: -1;
        if(index == c) c++, end = i;
    }return c;

}
