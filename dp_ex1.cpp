#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
const int maxn=100+10;
const int maxm=1000+10;
int f[maxn][maxm];      //f[i][j], 表示j元投资给前i个项目的最大收益 
int val[maxn][maxm];    //val[i][j],表示投资第i件j元的收益
int x[maxn][maxm];      //x[i][j],表示在总共分配j元时, 取得最大效益时分配给第i个项目的钱数 
int n,m;                //n件物品，总投资m元 
int main(){
	scanf("%d %d",&n,&m);
	for(int i=0;i<=m;++i){
		printf("当投资%d元时，请输入每件物品的收益： ",i);    
		for(int j=1;j<=n;++j){
			scanf("%d",&val[j][i]);
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=0;j<=m;++j){
			for(int k=0;k<=j;++k){
				if(f[i-1][j-k]+val[i][k]>f[i][j]){
					f[i][j]=f[i-1][j-k]+val[i][k];
					x[i][j]=k;
				}
				
			}
		}
	} 
	for(int i=1;i<=m;++i){
		for(int j=1;j<=n;++j){
			printf(" %d %d ",f[j][i],x[j][i]);
		}
		printf("\n");
	}
	printf("最大收益为：%d\n",f[n][m]);
}
/*
4 5
0 0 0 0
11 0 2 20
12 5 10 21
13 10 30 22
14 15 32 23
15 20 40 24
*/
