#include<stdio.h>
#include<algorithm>
using namespace std;
const int maxn=1000+10;
struct node{
	int start;
	int end;
	int id;
}a[maxn];  //结构体用来记录该项活动的开始时间，截止时间，编号 
bool cmp(struct node &a,struct node &b){
	return a.end<b.end;
}
int n,now=0;      //now用来记录当前活动结束的时间 
int cnt=0;        //cnt用来记录不相容的活动的个数 
int ans[maxn];    //记录不相容的活动的编号 
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d %d",&a[i].start,&a[i].end);
		a[i].id=i;
	}
	sort(a+1,a+1+n,cmp);         //按照截止时间从小到大排序 
	for(int i=1;i<=n;++i){
		if(a[i].start>=now){      //表明该活动可以被选择 
			ans[++cnt]=a[i].id;
			now=a[i].end;
		}
	}
	sort(ans+1,ans+1+cnt);
	printf("%d\n",cnt);
	for(int i=1;i<=cnt;++i){
		if(i!=1)printf(" ");
		printf("%d",ans[i]);
	}
}
