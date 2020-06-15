#include<math.h>
#include<stdio.h> 
#include<algorithm>
using namespace std;

const int N=100;
const int inf=0x3f3f3f3f;
double minn=inf;              //��СԲ���г���
int n;
double x[N],r[N];             //�ֱ�Ϊÿ��Բ�ĺ����꣬ÿ��Բ�뾶
double res[N];                //��СԲ���еİ뾶˳��
 
double calx(int t){         //�����t��Բ��Բ������
	double temp=0;
	for(int j=1;j<t;++j){     
		double now=x[j]+2.0*sqrt(r[t]*r[j]);  //�ж�����֮ǰ������Բ���е���� 
		if(now>temp)        //ȡ����Բ�ĵ���Сֵ 
			temp=now;
	}
	return temp;
}
void compute(){
	double left=inf,right=0;   //left����߽磬right���б߽� 
	for(int i=1;i<=n;++i){
		if(x[i]-r[i]<left)
			left=x[i]-r[i];
		if(x[i]+r[i]>right)
			right=x[i]+r[i];
	}
	if(right-left<minn){
		minn=right-left;
		for(int i=1;i<=n;++i)
			res[i]=r[i];
	}
}
void dfs(int t){
	if(t==n+1){
		compute();
	}
	else{
		for(int j=t;j<=n;++j){
			swap(r[t],r[j]);
			double now=calx(t);
			if(now+r[t]+r[1]<minn){
				x[t]=now;
				dfs(t+1);
			}
			swap(r[t],r[j]);     //��ԭ 
		}
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%lf",&r[i]);
	dfs(1);
	printf("��СԲ���г���Ϊ��%.4f\n",minn);
	printf("��СԲ���е�˳���Ӧ�İ뾶�ֱ�Ϊ��\n");
	for(int i=1;i<=n;++i){
		if(i!=1)printf(" ");
		printf("%.4f",res[i]);
	}
	return 0;
}
