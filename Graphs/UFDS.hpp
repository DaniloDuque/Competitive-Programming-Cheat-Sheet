#include <bits/stdc++.h>

typedef long long int ll;

using namespace std;
class UnionFind {
private: vector<long long int> p, rank, size;
public:
    UnionFind(int n){
        rank.assign(n, 0);
        p.assign(n, 0);
        size.assign(n, 1);
        
        for(long long int i = 0; i < n; i++){
            p[i] = i;
        }
    }
    long long int find(long long int i){
        return (p[i] == i)? i : (p[i] = find(p[i]));
    }
    bool inSameSet(long long int i, long long int j){
        return find(i) == find(j);
    }
    
    void unionSet(long long int i, long long j){
        if(!inSameSet(i, j)){
            long long int x = find(i), y = find(j);
            if(rank[x] > rank[y] ) {
                p[y] = x;
                size[x] += size[y];
                size[y] = size[x];
                

            }
            else{
                p[x] = y;
                size[y] += size[x];
                size[x] = size[y];
                if(rank[x] == rank[y]) rank[y] ++;
            }
        }
    }
    ll largestSet(){
        ll largest = 0;
        ll index = 0;
        for(int i = 0; i < size.size(); i++){
            if(size[i] > largest){
                index = i;
                largest = size[i];
            }

        }
        return index;
    }



    
};


