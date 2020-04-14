#include<stdio.h>
#include<algorithm>
using namespace std;
const int maxn=1000+10;
const int inf=0x3f3f3f3f;
int f[maxn][maxn];    //f[i][j]表示i~j区间的最优解 
int s[maxn][maxn];    //s[i][j]表示i~j区间的分割点 
int n;
int P[maxn];
int main(){
	scanf("%d",&n);
	for(int i=0;i<=n;++i)scanf("%d",&P[i]);
	for(int i=1;i<=n;++i)f[i][i]=0;
	for(int len=2;len<=n;++len){            //枚举区间长度 
		for(int l=1;l+len-1<=n;++l){        //枚举左边界 
			int r=l+len-1;
			f[l][r]=inf;
			s[l][r]=0;
			for(int i=l;i<r;++i){           //枚举割点 
				if(f[l][i]+f[i+1][r]+P[l-1]*P[i]*P[r]<f[l][r]){
					f[l][r]=f[l][i]+f[i+1][r]+P[l-1]*P[i]*P[r];
					s[l][r]=i;
				}
				
			}
		}
	}
	printf("%d\n",f[1][n]);
} 
