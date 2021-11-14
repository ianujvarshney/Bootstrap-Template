#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i=(j);i<=(k);i++)
#define per(i,j,k) for(int i=(j);i>=(k);i--)
#define ll long long
const int N=2014514;
int n,m,ct,a[N],b[N],tr[N],c[N],d[N],p[N];
ll as;
void add(int x){while(x){tr[x]++;x-=x&(-x);}}
int ask(int x,int k=0){while(x<=ct)k+=tr[x],x+=x&(-x);return k;} 
void sol(int l,int r,int sl,int sr){if(l>r)return;
	int mi=(l+r)>>1,ps=0,s=0,rs=n+1;
	rep(i,sl,sr){if(rs>s)rs=s,ps=i;
		s+=(a[i]>b[mi])-(a[i]<b[mi]);
	}p[mi]=ps;sol(l,mi-1,sl,ps);sol(mi+1,r,ps,sr);
}
int main(){int t;cin>>t;while(t--){
	scanf("%d%d",&n,&m);
	rep(i,1,n)scanf("%d",&a[i]);rep(i,1,m)scanf("%d",&b[i]);	
	sort(b+1,b+m+1);sol(1,m,1,n+1);ct=as=0;int j=1;
	rep(i,1,n+1){
		while(j<=m&&p[j]<=i)c[++ct]=b[j],j++;if(i<=n)c[++ct]=a[i];		
	}rep(i,1,ct)d[i]=c[i];sort(d+1,d+ct+1);ct=unique(d+1,d+ct+1)-d-1;
	rep(i,1,n+m){int x=lower_bound(d+1,d+ct+1,c[i])-d;
		as+=ask(x+1);add(x);
	}rep(i,1,ct)tr[i]=0;printf("%lld\n",as);
}}