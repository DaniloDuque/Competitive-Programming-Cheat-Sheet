int dfn[MAX], low[MAX], scc[MAX], idx, color, instk[MAX];
vector<int> G[MAX];
stack<int> st;

void Tarjan(int u){
    int v;
    dfn[u]=low[u]=++idx;
    st.push(u); instk[u]=1;
    for(int &v : G[u]){
        if(!dfn[v]){
            Tarjan(v);
            low[u]=min(low[u], low[v]);
        }else if(instk[v]) low[u]=min(low[u], dfn[v]);
    }
    /* Check SCC here
    if(dfn[u] == low[u]) {
        ++color;
        do {
            v = st.top(), instk[v]=0;
            st.pop();
            scc[v] = color;
        } while(v!=u);
    } */
}

int scc() {
    mset0(dfn); mset0(low); mset0(block); ind = color = 0;
    mset0(instack); while (!sk.empty()) sk.pop();
    for (int i=1; i<=n; ++i) if (!dfn[i]) tarjan(i);
    return color;
}
