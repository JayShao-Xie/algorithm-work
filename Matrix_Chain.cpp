#include<stdio.h>
#include<algorithm>
using namespace std;
const int maxn=1000+10;
const int inf=0x3f3f3f3f;
int f[maxn][maxn];    //f[i][j]��ʾi~j��������Ž� 
int s[maxn][maxn];    //s[i][j]��ʾi~j����ķָ�� 
int n;
int P[maxn];
int main(){
	scanf("%d",&n);
	for(int i=0;i<=n;++i)scanf("%d",&P[i]);
	for(int i=1;i<=n;++i)f[i][i]=0;
	for(int len=2;len<=n;++len){            //ö�����䳤�� 
		for(int l=1;l+len-1<=n;++l){        //ö����߽� 
			int r=l+len-1;
			f[l][r]=inf;
			s[l][r]=0;
			for(int i=l;i<r;++i){           //ö�ٸ�� 
				if(f[l][i]+f[i+1][r]+P[l-1]*P[i]*P[r]<f[l][r]){
					f[l][r]=f[l][i]+f[i+1][r]+P[l-1]*P[i]*P[r];
					s[l][r]=i;
				}
				
			}
		}
	}
	printf("%d\n",f[1][n]);
} 
