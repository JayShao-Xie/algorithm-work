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
/*----------����Ϊͨ�����鼯ά����ͨ��----------*/
int fa[maxn];
int find(int x){
	return fa[x]==x?fa[x]:fa[x]=find(fa[x]);
}
void baba(int x,int y){
	int fx=find(x),fy=find(y);
	fa[fx]=fy;
}
/*----------����Ϊͨ�����鼯ά����ͨ��----------*/
/*----------����Ϊkruskal----------*/
int kruskal(){
	int cnt=1;                     //������������С�������ڵĵ������ 
	int res=0;                     //������С�������ı�Ȩ�� 
	sort(e+1,e+1+m,cmp);           //��ÿ���߰���Ȩֵ��С����������� 
	for(int i=1;i<=m;++i){
		int fx=find(e[i].from),fy=find(e[i].to);
		if(fx==fy)continue;        //����ͬһ��ͨ���ڣ����������ѭ�� 
		baba(e[i].from,e[i].to);   //��ͨe[i].from��e[i].to 
		cnt++;
		res+=e[i].cost;
		if(cnt==n)break;
	}
	return cnt==n?res:-1;   //��cnt������n,������޷�������С������,���-1 
}
/*----------����Ϊkruskal----------*/
void init(){  //��ʼ�� 
	for(int i=1;i<=n;++i)fa[i]=i;
}
int main(){
	while(scanf("%d %d",&n,&m)!=EOF){   //n��ʾ�������,m��ʾ�ߵ����� 
		init();
		for(int i=1;i<=m;++i){
			scanf("%d %d %d",&e[i].from,&e[i].to,&e[i].cost);
		}
		printf("%d\n",kruskal());
	}
}
