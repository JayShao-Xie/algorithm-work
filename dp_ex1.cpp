#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
const int maxn=100+10;
const int maxm=1000+10;
int f[maxn][maxm];      //f[i][j], ��ʾjԪͶ�ʸ�ǰi����Ŀ��������� 
int val[maxn][maxm];    //val[i][j],��ʾͶ�ʵ�i��jԪ������
int x[maxn][maxm];      //x[i][j],��ʾ���ܹ�����jԪʱ, ȡ�����Ч��ʱ�������i����Ŀ��Ǯ�� 
int n,m;                //n����Ʒ����Ͷ��mԪ 
int main(){
	scanf("%d %d",&n,&m);
	for(int i=0;i<=m;++i){
		printf("��Ͷ��%dԪʱ��������ÿ����Ʒ�����棺 ",i);    
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
	printf("�������Ϊ��%d\n",f[n][m]);
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
