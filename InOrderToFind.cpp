#include<stdio.h>
const int maxn= 1000 + 10;
int T[maxn];
int n;
/*----------����Ϊ˳�����----------*/ 
int Inorder(int x){
	int pos=0;
	for(int i=1;i<=n;++i){
		if(T[i]==x){
			pos=i;
			break;
		}
	}
	return pos;
}
/*----------����Ϊ˳�����----------*/ 
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&T[i]);
	int x;
	scanf("%d",&x);
	printf("�±�j=%d\n",Inorder(x));
}
