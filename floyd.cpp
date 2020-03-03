#include<stdio.h>
#include<string.h>
const int inf= 0x3f3f3f3f;
const int maxn= 100 + 10;
int dis[maxn][maxn];
int n,m;   //n表示顶点数量，m表示边的数量
//----------以下为floyd算法----------// 
void floyd(){
	for(int k=1;k<=n;++k){
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				if(dis[i][k]+dis[k][j]<dis[i][j])
					dis[i][j]=dis[i][k]+dis[k][j];
			}
		}
	} 
}
//----------以上为floyd算法----------// 
int main(){
	while(scanf("%d %d",&n,&m)!=EOF){
		memset(dis,inf,sizeof dis);      //初始化，令各个点之间的距离为无穷大 
		for(int i=1;i<=m;++i){
			int x,y,z;
			scanf("%d %d %d",&x,&y,&z);
			dis[x][y]=z;                //有向图 
		}
		for(int i=1;i<=n;++i)dis[i][i]=0;
		floyd();
		puts("以下为距离矩阵："); 
		for(int i=1;i<=n;++i){          //输出距离矩阵 
			printf("%d: ",i);
			for(int j=1;j<=n;++j){
				printf("%d%c",dis[i][j],j==n?'\n':' ');
			}
		}
	}
} 
