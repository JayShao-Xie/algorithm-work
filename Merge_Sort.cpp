#include<stdio.h>
const int maxn=1000+10;
int n;
int a[maxn];
int tmp[maxn];
/*----------以下为二分归并排序算法----------*/ 
void Merge_Sort(int a[],int l,int r){
	if(l>=r)return;
	int mid=(l+r)/2;
	Merge_Sort(a,l,mid);
	Merge_Sort(a,mid+1,r);
	int now=l-1;
	int i=l,j=mid+1;
	while(i<=mid&&j<=r){           //两部分合并 
		if(a[i]<a[j]){
			tmp[++now]=a[i];
			++i;
		}
		else{
			tmp[++now]=a[j];
			++j;
		}
	}
	while(i<=mid){
		tmp[++now]=a[i];
		++i;
	}
	while(j<=r){
		tmp[++now]=a[j];
		++j;
	}
	for(int i=l;i<=r;++i){
		a[i]=tmp[i];
	}
}
/*----------以上为二分归并排序算法----------*/ 
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	Merge_Sort(a,1,n);
	for(int i=1;i<=n;++i){
		printf("%d%c",a[i],i==n?'\n':' ');
	}
}
