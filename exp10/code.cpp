#include <bits/stdc++.h>
 
using namespace std;
 
#define ll              long long
#define l1(i, n)        for (ll i = 1; i <= n; i++)
#define l0(i, n)        for (ll i = 0; i < n; i++)
#define lo(i, s, n)     for (ll i = s; i <= n; i++)
#define sca(n)          scanf("%lld", &n)
#define pri(n)          printf("%lld", n)
#define pb              push_back
#define mp              make_pair
#define sorted(x)       sort(x.begin(), x.end())
#define reversed(x)     reverse(x.begin(), x.end())
#define all(x)          x.begin(), x.end()
#define ms(a, b)        memset(a, b, sizeof(a));
#define cases(tc)       cout<<"Case "<<tc<<": "
#define nl              cout<<"\n";
#define pnl             printf("\n");
#define pi              acos(-1)
#define mod             1000000007
#define inf             999999999999999999
#define maxn            100001
			
 
ll seg[60*maxn];
ll dt[maxn];
ll lef[60*maxn];
ll rig[60*maxn];
ll ver[maxn];
ll nf=2;
vector <ll> last[maxn];
 
void build(ll st, ll en, ll nd){
    if(st==en){
        seg[nd]=0;
        return;
    }
    lef[nd]=nf++;
    rig[nd]=nf++;
    ll mid=(st+en)/2;
    build(st, mid, lef[nd]);
    build(mid+1, en, rig[nd]);
    seg[nd]=seg[lef[nd]]+seg[rig[nd]];
}
 
ll update(ll st, ll en, ll nd, ll l, ll r, ll val){
    if(st>r || en<l){
        return nd;
    }
    ll nnd=nf++;
    if(st>=l && en<=r){
        seg[nnd]=seg[nd];
        seg[nnd]+=val;
        return nnd;
    }
    ll mid=(st+en)/2;
    lef[nnd]=update(st, mid, lef[nd], l, r, val);
    rig[nnd]=update(mid+1, en, rig[nd], l, r, val);
    seg[nnd]=seg[lef[nnd]]+seg[rig[nnd]];
    return nnd;
}
 
ll query(ll st, ll en, ll nd, ll l, ll r){
    if(st>r || en<l){
        return 0;
    }
    if(st>=l && en<=r){
        return seg[nd];
    }
    ll mid=(st+en)/2;
    return query(st, mid, lef[nd], l, r) + query(mid+1, en, rig[nd], l, r);
}
 
 
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
 
 
    ll t;
    t=1;
    while(t--){
        ll n, k;
        cin>>n>>k;
        l1(i, n) cin>>dt[i];
        l1(i, n){
            last[dt[i]].pb(i);
            ll ind=last[dt[i]].size()-k-1;
            if(ind<0) dt[i]=0;
            else dt[i]=last[dt[i]][ind];
        }
        build(1ll, n, 1ll);
        ver[0]=1;
        l1(i, n){
            if(dt[i]) ver[i]=update(1ll, n, ver[i-1], dt[i], dt[i], 1ll);
            else ver[i]=update(1ll, n, ver[i-1], dt[i], dt[i], 0ll);
        }
        ll q;
        cin>>q;
        ll ans=0;
        while(q--){
            ll l, r;
            cin>>l>>r;
            l=(l+ans)%n+1;
            r=(r+ans)%n+1;
            if(l>r) swap(l, r);
            ans=r-l+1-query(1ll, n, ver[r], l, n);
            cout<<ans;
            nl
        }
 
    }
    return 0;
}
