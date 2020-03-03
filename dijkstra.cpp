#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
const int maxn = 1010;
const int inf = 0x3f3f3f3f;
int mp[maxn][maxn];
int dis[maxn];
bool vis[maxn];
int n, m;                                             //n��ʾ����������m��ʾ�ߵ����� 
//----------����Ϊdijkstra�㷨----------// 
void dijkstra(int s) {                                //��s����������������
	memset(vis, false, sizeof(vis));
	memset(dis, inf, sizeof(dis));
	vis[s] = 1;                                       //�жϸõ��Ƿ񱻼���
	for (int i = 1; i <= n; i++){
		dis[i] = mp[s][i];
	}
	 dis[s] = 0; 
	for (int time = 1; time <= n - 1; time++){         //��n������������n-1��//
		int minn = inf;
		int p = 1;
		for (int i = 1; i <= n; i++){                 //̰�� �ҳ��ֲ����Ž�
			if (dis[i] < minn&&vis[i] != 1) {
				minn = dis[i];
				p = i;
			}
		}
		vis[p] = 1;                                   //�жϸõ��Ƿ񱻼���
		for (int i = 1; i <= n; i++){                 //��p���Ż����е�
			dis[i] = min(dis[i], dis[p] + mp[p][i]);  //�Ƚ�
		}
	}
}
//----------����Ϊdijkstra�㷨----------// 
int main(){
	while(scanf("%d %d",&n,&m)!=EOF){
		memset(mp,inf,sizeof mp);         //��ʼ�����������֮��ľ���Ϊ����� 
		for(int i=1;i<=m;++i){
			int x,y,z;
			scanf("%d %d %d",&x,&y,&z);
			mp[x][y]=z;                //����ͼ 
		}
		dijkstra(1);
		printf("��1��n�����̾���Ϊ��%d\n",dis[n]);
	}
} 
