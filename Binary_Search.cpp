#include<stdio.h>
const int maxn= 1000 + 10;
int T[maxn];  //默认排序从小到大 
int n;
/*----------以下为二分检索----------*/ 
int Binary_Search(int x){
	int pos=0;
	int l=1,r=n; 
	while(l<=r){
		int mid=(l+r)>>1;
		if(T[mid]==x){
			pos=mid;
			break;
		}
		if(T[mid]<x)l=mid+1;
		else r=mid-1;
	}
	return pos;
}
/*----------以上为二分检索----------*/ 
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&T[i]);
	int x;
	scanf("%d",&x);
	printf("下标j=%d\n",Binary_Search(x));
}
