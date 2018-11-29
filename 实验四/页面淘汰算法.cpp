#include <iostream>
#include <vector>
#include <queue>
using namespace std;

queue<int> q;
vector<int> go,help;//页面走向,辅助检查是否命中
int page_num,n,Count=0;

void FIFO()
{
	int j;
	for(int i=0;i<page_num;i++)//先将队列填满
	{
		q.push(go[i]);
		help.push_back(go[i]);
		Count++;
	}
	for(int i=page_num;i<n;i++)
	{
		for(j=0;j<help.size();j++)
		{
			if(help[j]==go[i])
				break;
		}
		if(j==help.size())//未命中
		{
			Count++;
			q.push(go[i]);
			help.push_back(go[i]);
			if(q.size()>page_num)
			{
				q.pop();
				help.erase(help.begin());
			}
		}
	}
	cout<<"缺页次数为："<<Count;
	cin>>Count;
}

void LRU()
{
	int j;
	for(int i=0;i<page_num;i++)//先将队列填满
	{
		help.push_back(go[i]);
		Count++;
	}
	for(int i=page_num;i<n;i++)
	{
		for(j=0;j<help.size();j++)
		{
			if(help[j]==go[i])
				break;
		}
		if(j==help.size())//未命中
		{
			Count++;
			help.push_back(go[i]);
			if(help.size()>page_num)
				help.erase(help.begin());
		}
		else//与FIFO不同的是，如果命中也要调换队列顺序。
		{
			for(vector<int>::iterator it=help.begin();it!=help.end();it++)  
		    {
		    	if(*it==go[i])
		    	{
		    		help.erase(it);
		    		break;
		    	}  
		    } 
			help.push_back(go[i]);
		}
	}
	cout<<"缺页次数为："<<Count;
	cin>>Count;
}

int main()
{
	int temp;
	cout<<"请输入页框大小："<<endl;
	cin>>page_num;
	cout<<"请输入页面走向个数："<<endl;
	cin>>n;
	cout<<"请输入页面走向："<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>temp;
		go.push_back(temp);
	}
	cout<<"---------请选择一种算法----------"<<endl;
	cout<<"    1.先进先出页面置换算法（FIFO） "<<endl;
	cout<<"    2.最近最少使用页面置换算法（LRU）"<<endl;
	int choice;
	cin>>choice;
	switch(choice)
	{
		case 1:
			FIFO();
			break;
		case 2:
			LRU();
			break;
		default:
			cout<<"输入错误！"<<endl;
			break;
	}
	system("pause");
	return 0;
}