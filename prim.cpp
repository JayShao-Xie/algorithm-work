#include<bits/stdc++.h>
using namespace std;
const int maxn=100000+10;
const int maxm=100000+10;
int n,m;
int vis[maxn];        //用来判断该点是否在最小生成树中 
struct node{          //存边的信息 
	int to,dis;
	bool operator <(const node &a)const{
		return dis>a.dis;
	}
};
vector<node>e[maxn];             //用vector容器来存边 
priority_queue<node>q;           //优先队列优先选择边权最小的边 
/*----------以下为prim算法----------*/ 
void prim(){
	int ans=0;                   //表明最小生成树的权值 
	int cnt=0;                   //表明在最小生成树中的点的数量 
	q.push((node){1,0});
	while(!q.empty()&&cnt<n){
		node k=q.top();q.pop();
		if(vis[k.to])continue;   //表明该点已经在最小生成树中 
		vis[k.to]=1;
		ans+=k.dis;
		cnt++;
		for(int i=0;i<e[k.to].size();++i){
			if(!vis[e[k.to][i].to]){
				q.push((node){e[k.to][i].to,e[k.to][i].dis});
			}
		}
	}
	printf("%d\n",cnt==n?ans:-1);
}
/*----------以上为prim算法----------*/ 
void init(){                    //初始化 
	while(!q.empty())q.pop();
	for(int i=1;i<=n;++i)e[i].clear(),vis[i]=0;
}
int main(){
	while(scanf("%d %d",&n,&m)!=EOF){    //n代表点的数量，m代表边的数量 
		init();
		for(int i=1;i<=m;++i){
			int x,y,z;
			scanf("%d %d %d",&x,&y,&z);
			e[x].push_back((node){y,z});
			e[y].push_back((node){x,z});
		}
		prim();
	}
	return 0;
}
