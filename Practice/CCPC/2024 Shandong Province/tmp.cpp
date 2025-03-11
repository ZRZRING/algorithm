#include<bits/stdc++.h>
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#define int long long
#define inf (1ll<<30)
const int N = 5e5+50,M=2*N,MOD=1e9+7,INF=1e15;
int T=1,n,m,k,h,x,y,z,sum=0,q,d[N],u,v,w;
int b[N];
int a[N],ne[M],las[M];
int num[M];
std::pair<int,int> c[N];
std::string str[N];
std::vector<int> e[N];
std::pair<int,int> xy[N];
int p[N],invp[N];
int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
int val[N];
char ch;
bool vis[N];
bool oncyc[N];
int idx;
int l[N],r[N];
int pos[N];
int dep[N];
int pre[N],suf[N];
int sz[N];

bool s[M];
int primes[M];
int cnt=0;

inline void get_primes(int n){
    for (int i = 2; i <= n; i ++ ){
        if (!s[i]){
            primes[++cnt] = i;
            //pos[i]=cnt;
        } 
        for (int j = 1; primes[j] <= n / i; j ++ )
        {
            s[primes[j] * i] = true;
            if (i % primes[j] == 0) break;
        }
    }
}

inline void add(int &a,int b){
    a+=b;
    if(a>=MOD) a-=MOD;
}

inline int qmi(int a,int k,int mod){
    int res=1;
    while(k){
        if(k%2) res=res*a%mod;
        a=a*a%mod;
        k/=2;
    }
    return res;
}

template<class T>
struct SEGMENT{
    int a[N];
    
    struct INFO{
        int ma;
    };
    
    struct TAG{
        int add;
    };
    
    struct NODE{
        INFO val;
        TAG tag;
    }seg[4*N];
    
    inline friend const INFO operator + (const INFO &l,const INFO &r){
        INFO a;
        if(l.ma<r.ma){
            a.ma=r.ma;
        }
        else a.ma=l.ma;
        return a;
    }
    
    inline friend const TAG operator + (const TAG &t1,const TAG &t2){
        return {t1.add+t2.add};
    }
    
    inline friend const INFO operator + (const INFO &l,const TAG &t){
        return {l.ma+t.add};
    }
    
    inline void settag(int id,TAG t){
        seg[id].val=seg[id].val+t;
        seg[id].tag=seg[id].tag+t;
    }
    
    inline void update(int id){
        seg[id].val=seg[id*2].val+seg[id*2+1].val;
    }
    
    inline void push_down(int id){
        if(seg[id].tag.add!=0){
            settag(id*2,seg[id].tag);
            settag(id*2+1,seg[id].tag);
            seg[id].tag.add=0;
        }
    }
    
    inline void build(int id,int l,int r){
        if(l==r){
            seg[id].val={(l-1)*x};
            seg[id].tag={0};
            return ;
        }
        int mid = l+r>>1;
        push_down(id);
        build(id*2,l,mid);
        build(id*2+1,mid+1,r);
        update(id);
    }
    
    inline void modify(int id,int l,int r,int ql,int qr,TAG d){
        if(l==ql&&r==qr){
            settag(id,d);
            return ;
        }
        int mid=l+r>>1;
        push_down(id);
        if(qr<=mid) modify(id*2,l,mid,ql,qr,d);
        else if(ql>mid) modify(id*2+1,mid+1,r,ql,qr,d);
        else{
            modify(id*2,l,mid,ql,mid,d);
            modify(id*2+1,mid+1,r,mid+1,qr,d);
        }
        update(id);
    }
    
    inline INFO query(int id,int l,int r,int ql,int qr){
        if(l==ql&&r==qr){
            return seg[id].val;
        }
        push_down(id);
        int mid=l+r>>1;
        if(qr<=mid) return query(id*2,l,mid,ql,qr);
        else if(ql>mid) return query(id*2+1,mid+1,r,ql,qr);
        else return query(id*2,l,mid,ql,mid)+query(id*2+1,mid+1,r,mid+1,qr);
    }         
};
//SEGMENT<int> segtree;

template<class T>
struct DSU{
    int p[N];
    int sz[N];
    
    inline void init(int n){
        for(int i=1;i<=n;i++){
            p[i]=i;
            sz[i]=0;
        }
    }
    
    inline int find(int x){
        if(p[x]!=x) p[x]=find(p[x]);
        return p[x];
    }
    
    inline bool is_same(int a,int b){
        int pa=find(a),pb=find(b);
        if(pa==pb) return true;
        return false;
    }
    
    inline void merge(int a,int b){
        int pa=find(a),pb=find(b);
        p[pa]=pb;
        sz[pb]+=sz[pa];
    }
};
//DSU<int> dsu[11];

template<class T>
struct BIT{
	T c[M];
	int size;
	inline int lowbit(int x){
		return x&(-x);
	}
	inline void init(int s){
		size = s;
		for(int i=1;i<=s;i++) c[i]=0;
	}
	inline T query(int x){
		assert(x<=size);
		T s=0;
		for(int i=x;i>=1;i-=lowbit(i)){
			s+=c[i];
		}
		return s;
	}
	inline void add(int x,T s){
		assert(x!=0);
		for(int i=x;i<=size;i+=lowbit(i)){
			c[i]+=s;
		}
	}
};
//BIT<int> c1;

template<class T>
struct HASH{
    unsigned long long mod1=1e9+7;
    std::pair<unsigned long long,unsigned long long> f[M],g[M];
    unsigned long long p0[M],p1[M];
    
    inline void init(){
        p0[0]=p1[0]=1;
        for(int i=1;i<M;i++){
            p0[i]=p0[i-1]*131%mod1;
            p1[i]=p1[i-1]*1145191;
        }
    }
     
    inline void hash1(std::string str){
        for(int i=1;i<=n;i++){
            f[i].first=f[i-1].first*131+str[i];
            f[i].first%=mod1;
        }
        for(int i=1;i<=n;i++){
            f[i].second=f[i-1].second*1145191+str[i];
        }
    }
     
    inline void hash2(std::string str){
        for(int i=1;i<=n;i++){
            g[i].first=g[i-1].first*131+str[i];
            g[i].first%=mod1;
        }
        for(int i=1;i<=n;i++){
            g[i].second=g[i-1].second*1145191+str[i];
        }
    }
     
    inline bool is_palindrome(int l,int r){
        //std::cout << l << " " << r << " " << n+1-l << " " << n+1-r << '\n';
        if(f[r].second-f[l-1].second*p1[r-l+1]!=g[n+1-l].second-g[n+1-r-1].second*p1[r-l+1]){
            return false;
        }
        //std::cout << "?" << '\n';
        if((f[r].first+g[n+1-r-1].first*p0[r-l+1]%mod1)%mod1!=(g[n+1-l].first+f[l-1].first*p0[r-l+1]%mod1)%mod1){
            return false;
        }
        return true;
    }
};
//HASH<int> hash;

template<class T>
struct TRIE{
    int son[N][26];
    int cnt[N][26];
    int idx;
    
    inline void init(int n){
        for(int i=0;i<=std::min(N,n*26);i++){
            for(int j=0;j<26;j++){
                son[i][j]=0;
                cnt[i][j]=0;
            }
        }
        idx=0;
    }
    
    inline void insert(std::string str){
        int p=0;
        for(char ch:str){
            int u=ch-'a';
            if(!son[p][u]) son[p][u]=++idx;
            cnt[p][u]++;
            p=son[p][u];
        }
    }
    
    inline int query(std::string str){
        int p=0,res=0;
        for(char ch:str){
            int u=ch-'a';
            res+=cnt[p][u];
            p=son[p][u];
        }
        return res;
    }
};
//TRIE<int> trie;

std::set<int> st;
std::map<int,std::vector<int>> mp;
int C,Q;

int dp[1100][1100];
std::vector<int> la[N];

inline int calculate(int i,int j,int k){
    int x1=c[i].first,y1=c[i].second;
    int x2=c[j].first,y2=c[j].second;
    int x3=c[k].first,y3=c[k].second;
    //int temp=abs(x1*y2+x2*y3+x3*y1-x1*y3-x2*y1-x3*y2);
    int res=x1*y2+x2*y3+x3*y1-x1*y3-x2*y1-x3*y2;
    if(res<0) res=-res;
    //std::cout << temp << " " << res << '\n';
    return res;
}

inline void solved(){
    std::cin >> n;
    for(int i=1;i<=n;i++){
        std::cin >> a[i];
        a[i+n]=a[i];
    }
    for(int i=1;i<=n;i++){
        std::cin >> c[i].first >> c[i].second;
        c[i+n]=c[i];   
    }
    for(int l=1;l<=2*n;l++){
        for(int r=1;r<=2*n;r++){
            dp[l][r]=0;
        }
        e[l].clear();
        e[l].push_back(l);
        la[l].clear();
        la[l].push_back(l);
    }
    int ans = 0;
    for(int len=2;len<=n;len++){//2*500*1000*500
        for(int l=1,r=l+len-1;r<=2*n;l++,r++){
            if(a[l]!=a[r]) continue;
            for(int l0=l+1;l0<r;l0++){
                pos[l0]=0;
            }
            for(int l0=l+1;l0<r;l0++){
                while(pos[l0]<e[l0].size()&&e[l0][pos[l0]]<r) pos[l0]++;
                pos[l0]--;
                int r0=e[l0][pos[l0]];
                dp[l][r]=std::max(dp[l][r],dp[l0][r0]+calculate(l,l0,r0)+calculate(l,r0,r)); 
                //std::cout << l << " " << r << " " << l0 << " " << r0 << " " << dp[l0][r0]+calculate(l,l0,r0)+calculate(l,r0,r) << '\n';
                /*if(l==4&&r==10){
                    std::cout << l << " " << r << " " << l0 << " " << r0 << " " << dp[l0][r0]+calculate(l,l0,r0)+calculate(l,r0,r) << '\n';
                }*/
            }
            for(int l0=l+1;l0<r;l0++){
                pos[l0]=0;
            }
            for(int r0=r-1;r0>l;r0--){
                while(pos[r0]<la[r0].size()&&la[r0][pos[r0]]>l) pos[r0]++;
                pos[r0]--;
                int l0=la[r0][pos[r0]];
                dp[l][r]=std::max(dp[l][r],dp[l0][r0]+calculate(l,l0,r0)+calculate(l,r0,r)); 
                //std::cout << l << " " << r << " " << l0 << " " << r0 << " " << dp[l0][r0]+calculate(l,l0,r0)+calculate(l,r0,r) << '\n';
                /*if(l==4&&r==10){
                    std::cout << l << " " << r << " " << l0 << " " << r0 << " " << dp[l0][r0]+calculate(l,l0,r0)+calculate(l,r0,r) << '\n';
                }*/
            }
            ans = std::max(ans,dp[l][r]);
            e[l].push_back(r);
            la[r].push_back(l);
        }
    }
    std::cout << ans << '\n';
}

signed main(){
    std::ios::sync_with_stdio(false),std::cin.tie(0),std::cout.tie(0);
    std::cin >> T;
    while(T--){
        solved();
    }
    return 0;
}