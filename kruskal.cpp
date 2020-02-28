#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=100000+10;
const int maxm=100000+10;
int n,m;
struct edge{
	int from,to,cost;
}e[maxm];
bool cmp(struct edge &a,struct edge &b){
	return a.cost<b.cost;
}
/*----------以下为通过并查集维护联通快----------*/
int fa[maxn];
int find(int x){
	return fa[x]==x?fa[x]:fa[x]=find(fa[x]);
}
void baba(int x,int y){
	int fx=find(x),fy=find(y);
	fa[fx]=fy;
}
/*----------以上为通过并查集维护联通快----------*/
/*----------以下为kruskal----------*/
int kruskal(){
	int cnt=1;                     //表明包含在最小生成树内的点的数量 
	int res=0;                     //表明最小生成树的边权和 
	sort(e+1,e+1+m,cmp);           //将每条边按照权值从小到大进行排序 
	for(int i=1;i<=m;++i){
		int fx=find(e[i].from),fy=find(e[i].to);
		if(fx==fy)continue;        //若在同一联通块内，则调过本次循环 
		baba(e[i].from,e[i].to);   //联通e[i].from和e[i].to 
		cnt++;
		res+=e[i].cost;
		if(cnt==n)break;
	}
	return cnt==n?res:-1;   //若cnt不等于n,则表明无法生成最小生成树,输出-1 
}
/*----------以上为kruskal----------*/
void init(){  //初始化 
	for(int i=1;i<=n;++i)fa[i]=i;
}
int main(){
	while(scanf("%d %d",&n,&m)!=EOF){   //n表示点的数量,m表示边的数量 
		init();
		for(int i=1;i<=m;++i){
			scanf("%d %d %d",&e[i].from,&e[i].to,&e[i].cost);
		}
		printf("%d\n",kruskal());
	}
}
