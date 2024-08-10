#include <bits/stdc++.h>
using namespace std;




class segment{

private:
    vector<int> segTree;
    vector<int> list;
    void coalesence(int pos){
        segTree[pos] = min(segTree[pos * 2 + 1], segTree[pos * 2 + 2]);
        if(pos) coalesence((pos - 1) / 2);
    }


    int MSB(int n){
        int msb = 0;
        for(int i = 0; i < 32; i++){
            if((1 << i) & n) msb = i;
        }
        return msb;
    }



public:

    void construct(int low, int high, int pos){
        if(low == high){
            segTree[pos] = list[high];
            return;
        } 
        int mid = (low + high) / 2;
        construct(low, mid, 2 * pos + 1);
        construct(mid + 1, high, 2 * pos + 2);
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
        construct(0, n - 1, 0);
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
        int mid = (low + high) / 2; 
        return min(rangeQueryAux(qlow, qhigh, low, mid, pos * 2 + 1), rangeQueryAux(qlow, qhigh, mid + 1, high, pos * 2 + 2));
        //change for max heap
    }

    void update(int index, int value){
        updateAux(index, value, 0, list.size() - 1, 0); 
    }
    void updateAux(int index, int value, int low, int high, int pos){
        if(low == high && low == index){
            segTree[pos] = value;
            coalesence((pos - 1) / 2);
            return;
        }
        int mid = (low + high) / 2;
        if(mid >= index) updateAux(index, value, low, mid, pos * 2 + 1);
        else updateAux(index, value, mid + 1, high, pos * 2 + 2);
    }

    void printTree(){
        for(int i : segTree){
            cout << i << " ";
        }
        cout << endl;
    }



};
