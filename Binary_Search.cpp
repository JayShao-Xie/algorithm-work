#include<stdio.h>
const int maxn= 1000 + 10;
int T[maxn];  //Ĭ�������С���� 
int n;
/*----------����Ϊ���ּ���----------*/ 
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
/*----------����Ϊ���ּ���----------*/ 
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&T[i]);
	int x;
	scanf("%d",&x);
	printf("�±�j=%d\n",Binary_Search(x));
}
