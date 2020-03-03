#include<stdio.h>
#include<string.h>
const int inf= 0x3f3f3f3f;
const int maxn= 100 + 10;
int dis[maxn][maxn];
int n,m;   //n��ʾ����������m��ʾ�ߵ�����
//----------����Ϊfloyd�㷨----------// 
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
//----------����Ϊfloyd�㷨----------// 
int main(){
	while(scanf("%d %d",&n,&m)!=EOF){
		memset(dis,inf,sizeof dis);      //��ʼ�����������֮��ľ���Ϊ����� 
		for(int i=1;i<=m;++i){
			int x,y,z;
			scanf("%d %d %d",&x,&y,&z);
			dis[x][y]=z;                //����ͼ 
		}
		for(int i=1;i<=n;++i)dis[i][i]=0;
		floyd();
		puts("����Ϊ�������"); 
		for(int i=1;i<=n;++i){          //���������� 
			printf("%d: ",i);
			for(int j=1;j<=n;++j){
				printf("%d%c",dis[i][j],j==n?'\n':' ');
			}
		}
	}
} 
