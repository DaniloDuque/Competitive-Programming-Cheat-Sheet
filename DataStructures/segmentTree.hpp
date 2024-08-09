#include <bits/stdc++.h>
using namespace std;


int MSB(int n){
    int msb = 0;
    for(int i = 0; i < 32; i++){
        if((1 << i) & n) msb = i;
    }
    return msb;
}




class segment{

public:
    vector<int> segTree;
    vector<int> list;
    void construct(vector<int> & list, int low, int high, int pos){
        if(low == high){
            segTree[pos] = list[high];
        } 
        int mid = (low + high) / 2;
        construct(list, low, mid, 2 * pos + 1);
        construct(list, mid + 1, low, 2 * pos + 2);
        segTree[pos] = min(segTree[pos * 2 + 1], segTree[pos * 2 + 2]);
        //can change to max for max heap GOD
    }

    segment(vector<int> & list){
        this->list = list;
        int n = list.size();
        if(!(n & (n - 1)) && n){
            segTree.assign(n * 2 - 1, (1 << 30)); // change for max heap;
        }
        else segTree.assign((1 << (MSB(n) + 1)) * 2 - 1, (1 << 30));
        construct(list, 0, n - 1, 0);
    }

    int rangeQuery(int qlow, int qhigh){
        return rangeQueryAux(qlow, qhigh, 0, list.size() - 1, 0);
    }

    int rangeQueryAux(int qlow, int qhigh, int low, int high, int pos){
        if(qlow <= low && qhigh >= high){
            return segTree[pos];
        }
        if(qlow > high || qhigh < low){
            return (1 << 30);
        }
        int mid = (low = + high) / 2; 
        return min(rangeQueryAux(qlow, qhigh, low, mid, pos * 2 + 1), rangeQueryAux(qlow, qhigh, mid + 1, high, pos * 2 + 2));
        //change for max heap
    }



};
