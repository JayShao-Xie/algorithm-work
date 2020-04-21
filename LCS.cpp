#include<stdio.h>
#include<string.h>
const int maxn=1000+10;
char x[maxn],y[maxn];
int dp[maxn][maxn];
int b[maxn][maxn];   //b[i][j]=0为删除两个，b[i][j]=1为删除x，b[i][j]=2为删除y 
char lcs[maxn];
int n,m;             //n为字符串x的长度，m为字符串y的长度 
int main(){
	scanf("%d",&n);
	scanf("%s",x+1);
	scanf("%d",&m);
	scanf("%s",y+1);
	//初始化 
	for(int i=0;i<=m;++i)dp[0][i]=0;
	for(int i=0;i<=n;++i)dp[i][0]=0;
	
	/*----------以下为求最长公共子序列长度----------*/ 
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			if(x[i]==y[j]){
				dp[i][j]=dp[i-1][j-1]+1;
			}
			else{
				if(dp[i-1][j]>dp[i][j-1]){
					b[i][j]=1;
					dp[i][j]=dp[i-1][j];
				}
				else{
					b[i][j]=2;
					dp[i][j]=dp[i][j-1];
				}
			}
		}
	}
	/*----------以上为求最长公共子序列长度----------*/ 
	
	/*----------以下为求最长公共子序列----------*/
	int i=n,j=m;
	while(i!=0&&j!=0){     
		if(b[i][j]==0){
			lcs[dp[i][j]]=x[i];
			i--,j--;
		}
		else if(b[i][j]==1){
			i--;
		}
		else{
			j--;
		}
	}
	/*----------以上为求最长公共子序列----------*/ 
	
	printf("最长公共子序列长度为：%d\n",dp[n][m]);
	if(dp[n][m]!=0){
		printf("最长公共子序列为：");
		for(int i=1;i<=dp[n][m];++i){
			printf("%c",lcs[i]);
		}
	}
} 
