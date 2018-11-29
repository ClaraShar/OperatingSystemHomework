#include<iostream>
#include<queue>
using namespace std;

class PCB
{
private:
	int pid;
	int run_time;
public:
	PCB(int id,int time)
	{
		pid=id;
		run_time=time;
	}
	int get_pid()
	{
		return this->pid;
	}
	int get_time()
	{
		return this->run_time;
	}
	~PCB(){};
};

queue<PCB> ready,waiting,q,q1;

void create()
{
	cout<<"提示:进程池里已有五个进程"<<endl;
	int id,time;
	cout<<"请输入进程的id号和运行时间:"<<endl;
	cin>>id>>time;
	ready.push(PCB(id,time));
	q.push(PCB(id,time));
	q1.push(PCB(id,time));
	cout<<"就绪队列中有以下进程:"<<endl;
	while(!q.empty())
	{
		PCB temp=q.front();
		cout<<"进程号:"<<temp.get_pid()<<" 运行时间:"<<temp.get_time()<<endl;
		q.pop();
	}
	cout<<endl;
}

void working()
{
	cout<<"正在运行的进程为："<<endl;
	PCB temp=ready.front();
	ready.pop();
	cout<<"进程号："<<temp.get_pid()<<endl;
	cout<<endl;
}

void sleep()
{
	PCB temp=ready.front();
	cout<<"被挂起的进程为："<<endl;
	cout<<"进程号："<<temp.get_pid()<<endl;
	ready.pop();
	waiting.push(temp);
	cout<<endl;
}

void re_work()
{
	PCB temp=waiting.front();
	cout<<"被激活的进程为："<<endl;
	cout<<"进程号："<<temp.get_pid()<<endl;
	cout<<endl;
	waiting.pop();
	ready.push(temp);
}

void del()
{
	PCB temp=ready.front();
	cout<<"被撤销的进程为："<<endl;
	cout<<"进程号："<<temp.get_pid()<<endl;
	ready.pop();
	cout<<endl;
}

int main()
{
	int choice;
	ready.push(PCB(1,50));
	ready.push(PCB(2,100));
	ready.push(PCB(3,80));
	ready.push(PCB(4,70));
	ready.push(PCB(5,20));
	q.push(PCB(1,50));
	q.push(PCB(2,100));
	q.push(PCB(3,80));
	q.push(PCB(4,70));
	q.push(PCB(5,20));
	while(1)
	{
		cout<<"********************************************"<<endl;
		cout<<"*                 进程演示系统               *"<<endl;
		cout<<"*        1.创建进程          2.运行进程       *"<<endl;
		cout<<"*        3.挂起进程          4.激活进程       *"<<endl;
		cout<<"*        5.撤销进程          6.退出演示系统    *"<<endl;
		cout<<"********************************************"<<endl;
		cout<<"请选择（1～6）"<<endl;
		cin>>choice;
		switch(choice)
		{
		case 1:create();break;
		case 2:working();break;
	    case 3:sleep();break;
	    case 4:re_work();break;
	    case 5:del();break;
	    case 6:exit(0);
	    default:cout<<"输入有错!"<<endl;break;
		}
	}
	return 0;
}