#include<math.h>
#include<stdio.h> 
#include<algorithm>
using namespace std;

const int N=100;
const int inf=0x3f3f3f3f;
double minn=inf;              //最小圆排列长度
int n;
double x[N],r[N];             //分别为每个圆心横坐标，每个圆半径
double res[N];                //最小圆排列的半径顺序
 
double calx(int t){         //计算第t个圆的圆心坐标
	double temp=0;
	for(int j=1;j<t;++j){     
		double now=x[j]+2.0*sqrt(r[t]*r[j]);  //判断与他之前的所有圆相切的情况 
		if(now>temp)        //取所求圆心的最小值 
			temp=now;
	}
	return temp;
}
void compute(){
	double left=inf,right=0;   //left是左边界，right是有边界 
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
			swap(r[t],r[j]);     //还原 
		}
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%lf",&r[i]);
	dfs(1);
	printf("最小圆排列长度为：%.4f\n",minn);
	printf("最小圆排列的顺序对应的半径分别为：\n");
	for(int i=1;i<=n;++i){
		if(i!=1)printf(" ");
		printf("%.4f",res[i]);
	}
	return 0;
}
