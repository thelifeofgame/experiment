// DF.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#define MaxSize 100
#define INF 32767	//INF��ʾ��
#define	MAXV 100			//��󶥵����
typedef int InfoType;
using namespace std;
typedef struct 
{  	int no;				//������
	InfoType info;				//����������Ϣ
} VertexType;				//��������

typedef struct  				//ͼ�Ķ���
{  	int edges[MAXV][MAXV]; 		//�ڽӾ���
   	int n,e;   				//������,����
	VertexType vexs[MAXV];		//��Ŷ�����Ϣ
} MGraph;				//ͼ���ڽӾ�������

void Ppath(int path[],int i,int v)  		//ǰ��ݹ����·���ϵĶ���
{	int k;
	k=path[i];
	if (k==v)  return;			//�ҵ�������򷵻�
	Ppath(path,k,v);			//�Ҷ���k��ǰһ������
	printf("%d,",k);			//�������k
}
void Ppath_F(int path[][MAXV],int i,int j)  	//ǰ��ݹ����·���ϵĶ���
{	int k;
	k=path[i][j];
	if (k==-1) return;			//�ҵ�������򷵻�
	Ppath_F(path,i,k);			//�Ҷ���i��ǰһ������k
	printf("%d,",k);
	Ppath_F(path,k,j);			//�Ҷ���k��ǰһ������j
}

void Dispath(int dist[],int path[],int s[],int n,int v)
{	int i;
	for (i=0;i<n;i++)
		if (s[i]==1) 
		{printf("  ��%d��%d�����·������Ϊ:%d\t·��Ϊ:",v,i,dist[i]);
		printf("%d,",v);		//���·���ϵ����
		Ppath(path,i,v);		//���·���ϵ��м��
		printf("%d\n",i);		//���·���ϵ��յ�
		}
		else  printf("��%d��%d������·��\n",v,i);
}
void Dispath_F(int A[][MAXV],int path[][MAXV],int n)
{	int i,j;
	for (i=0;i<n;i++)
		for (j=0;j<n;j++) 
		{	if (A[i][j]==INF) 
			{if (i!=j) 
				printf("��%d��%dû��·��\n",i,j);
			}
			else 
			{	printf("  ��%d��%d=>·������: %d ·��:",
						i,j,A[i][j]);
				printf("%d,",i);	//���·���ϵ����
				Ppath_F(path,i,j);	//���·���ϵ��м��
				printf("%d\n",j);	//���·���ϵ��յ�
			}
		}
} 

void Dijkstra(MGraph g,int v)
{	int dist[MAXV],path[MAXV];	int s[MAXV];	int mindis,i,j,u;
	for (i=0;i<g.n;i++) 
	{	dist[i]=g.edges[v][i];   	//�����ʼ��
		s[i]=0;                		//s[]�ÿ�
		if (g.edges[v][i]<INF)	//·����ʼ��
			path[i]=v;
		else
		    	path[i]=-1;
	}
	s[v]=1;path[v]=0;        		//Դ����v����s��
	for (i=0;i<g.n;i++)    		//ѭ��ֱ�����ж�������·�������
	{	mindis=INF;		//mindis����С���ȳ�ֵ
		for (j=0;j<g.n;j++)     	//ѡȡ����s���Ҿ�����С����Ķ���u
			if (s[j]==0 && dist[j]<mindis) 
			{ 	u=j;	mindis=dist[j];	}
		s[u]=1;               		//����u����s��
		for (j=0;j<g.n;j++)     	//�޸Ĳ���s�еĶ���ľ���
			if (s[j]==0) 
				if (g.edges[u][j]<INF && dist[u]+g.edges[u][j]<dist[j]) 
				{	dist[j]=dist[u]+g.edges[u][j];
					path[j]=u;	}  
	}
	Dispath(dist,path,s,g.n,v);  	//������·��
}
void Floyd(MGraph g)
{	int A[MAXV][MAXV],path[MAXV][MAXV];
	int i,j,k;
	for (i=0;i<g.n;i++)
		for (j=0;j<g.n;j++) 
		{	A[i][j]=g.edges[i][j];
			path[i][j]=-1;
		}
	for (k=0;k<g.n;k++)
	{	for (i=0;i<g.n;i++)
			for (j=0;j<g.n;j++)
				if (A[i][j]>A[i][k]+A[k][j]) 
				{	A[i][j]=A[i][k]+A[k][j];
					path[i][j]=k;
				}
	}
	Dispath_F(A,path,g.n);   			//������·��
}

int _tmain(int argc, _TCHAR* argv[])
{
	int i,j;
	MGraph g;
	g.n=7;g.e=12;
	int a[7][MAXV]={
		{0,4,6,6,INF,INF,INF},
		{2,0,1,INF,7,INF,INF},
		{INF,INF,0,INF,6,4,INF},
		{INF,INF,2,0,INF,5,INF},
		{INF,INF,INF,INF,0,INF,6},
		{INF,INF,INF,INF,1,0,8},
		{INF,INF,INF,INF,INF,INF,0}};
	for (i=0;i<g.n;i++)		//����ͼ9.16��ʾ��ͼ���ڽӾ���
		for (j=0;j<g.n;j++)
			g.edges[i][j]=a[i][j];
	//printf("��С����������:\n");
	printf("D�㷨���·�������\n");
	Dijkstra(g,1);//D�㷨
	printf("F�㷨���·�������\n");
	Floyd(g);//F�㷨
	printf("\n");
	system("pause");
	return 0;
}

