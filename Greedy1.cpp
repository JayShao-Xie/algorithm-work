#include<stdio.h>
#include<algorithm>
using namespace std;
const int maxn=1000+10;
struct node{
	int start;
	int end;
	int id;
}a[maxn];  //�ṹ��������¼�����Ŀ�ʼʱ�䣬��ֹʱ�䣬��� 
bool cmp(struct node &a,struct node &b){
	return a.end<b.end;
}
int n,now=0;      //now������¼��ǰ�������ʱ�� 
int cnt=0;        //cnt������¼�����ݵĻ�ĸ��� 
int ans[maxn];    //��¼�����ݵĻ�ı�� 
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d %d",&a[i].start,&a[i].end);
		a[i].id=i;
	}
	sort(a+1,a+1+n,cmp);         //���ս�ֹʱ���С�������� 
	for(int i=1;i<=n;++i){
		if(a[i].start>=now){      //�����û���Ա�ѡ�� 
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
