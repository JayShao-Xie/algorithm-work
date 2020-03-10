#include<stdio.h>
const int maxn= 1000 + 10;
int T[maxn];
int n;
/*----------以下为顺序检索----------*/ 
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
/*----------以上为顺序检索----------*/ 
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&T[i]);
	int x;
	scanf("%d",&x);
	printf("下标j=%d\n",Inorder(x));
}
