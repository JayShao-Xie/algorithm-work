#include<bits/stdc++.h>
using namespace std;
const int maxn=100000+10;
const int maxm=100000+10;
int n,m;
int vis[maxn];        //�����жϸõ��Ƿ�����С�������� 
struct node{          //��ߵ���Ϣ 
	int to,dis;
	bool operator <(const node &a)const{
		return dis>a.dis;
	}
};
vector<node>e[maxn];             //��vector��������� 
priority_queue<node>q;           //���ȶ�������ѡ���Ȩ��С�ı� 
/*----------����Ϊprim�㷨----------*/ 
void prim(){
	int ans=0;                   //������С��������Ȩֵ 
	int cnt=0;                   //��������С�������еĵ������ 
	q.push((node){1,0});
	while(!q.empty()&&cnt<n){
		node k=q.top();q.pop();
		if(vis[k.to])continue;   //�����õ��Ѿ�����С�������� 
		vis[k.to]=1;
		ans+=k.dis;
		cnt++;
		for(int i=0;i<e[k.to].size();++i){
			if(!vis[e[k.to][i].to]){
				q.push((node){e[k.to][i].to,e[k.to][i].dis});
			}
		}
	}
	printf("%d\n",cnt==n?ans:-1);
}
/*----------����Ϊprim�㷨----------*/ 
void init(){                    //��ʼ�� 
	while(!q.empty())q.pop();
	for(int i=1;i<=n;++i)e[i].clear(),vis[i]=0;
}
int main(){
	while(scanf("%d %d",&n,&m)!=EOF){    //n������������m����ߵ����� 
		init();
		for(int i=1;i<=m;++i){
			int x,y,z;
			scanf("%d %d %d",&x,&y,&z);
			e[x].push_back((node){y,z});
			e[y].push_back((node){x,z});
		}
		prim();
	}
	return 0;
}
