#define NEUT 0
#define oper(a,b) (a+b)

struct STree { 
	vector<ll> st,lazy;ll n;
	STree(ll n): st(4*n+5,NEUT), lazy(4*n+5,0), n(n) {}
	void init(ll k, ll s, ll e, ll *a){
		lazy[k]=0;  
		if(s+1==e){st[k]=a[s];return;}
		ll m=(s+e)>>1;
		init(2*k,s,m,a);init(2*k+1,m,e,a);
		st[k]=oper(st[2*k],st[2*k+1]); 
	}
	void push(ll k, ll s, ll e){
		if(!lazy[k])return; 
		st[k]+=(e-s)*lazy[k];
		if(s+1<e){ 
			lazy[2*k]+=lazy[k];
			lazy[2*k+1]+=lazy[k];
		}lazy[k]=0;
	}
	void upd(ll k, ll s, ll e, ll a, ll b, ll v){
		push(k,s,e);
		if(s>=b||e<=a)return;
		if(s>=a&&e<=b){
			lazy[k]+=v; 
			push(k,s,e);return;
		}
		ll m=(s+e)>>1;
		upd(2*k,s,m,a,b,v);upd(2*k+1,m,e,a,b,v);
		st[k]=oper(st[2*k],st[2*k+1]); 
	}
	ll query(ll k, ll s, ll e, ll a, ll b){
		if(s>=b||e<=a)return NEUT; 
		push(k,s,e);
		if(s>=a&&e<=b)return st[k];
		ll m=(s+e)>>1;
		return oper(query(2*k,s,m,a,b),query(2*k+1,m,e,a,b));
	}
	void init(ll *a){init(1,0,n,a);}
	void upd(ll a, ll b, ll v){upd(1,0,n,a,b,v);}
	ll query(ll a, ll b){return query(1,0,n,a,b);}
}; // usage: STree rmq(n);rmq.init(x);rmq.upd(s,e,v);rmq.query(s,e);
