#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
const int maxn = 1010;
const int inf = 0x3f3f3f3f;
int mp[maxn][maxn];
int dis[maxn];
bool vis[maxn];
int n, m;                                             //n表示顶点数量，m表示边的数量 
//----------以下为dijkstra算法----------// 
void dijkstra(int s) {                                //从s点出发，经过任意点
	memset(vis, false, sizeof(vis));
	memset(dis, inf, sizeof(dis));
	vis[s] = 1;                                       //判断该点是否被检查过
	for (int i = 1; i <= n; i++){
		dis[i] = mp[s][i];
	}
	 dis[s] = 0; 
	for (int time = 1; time <= n - 1; time++){         //共n个数，检查次数n-1次//
		int minn = inf;
		int p = 1;
		for (int i = 1; i <= n; i++){                 //贪心 找出局部最优解
			if (dis[i] < minn&&vis[i] != 1) {
				minn = dis[i];
				p = i;
			}
		}
		vis[p] = 1;                                   //判断该点是否被检查过
		for (int i = 1; i <= n; i++){                 //用p点优化所有点
			dis[i] = min(dis[i], dis[p] + mp[p][i]);  //比较
		}
	}
}
//----------以上为dijkstra算法----------// 
int main(){
	while(scanf("%d %d",&n,&m)!=EOF){
		memset(mp,inf,sizeof mp);         //初始化，令各个点之间的距离为无穷大 
		for(int i=1;i<=m;++i){
			int x,y,z;
			scanf("%d %d %d",&x,&y,&z);
			mp[x][y]=z;                //有向图 
		}
		dijkstra(1);
		printf("从1到n点的最短距离为：%d\n",dis[n]);
	}
} 
