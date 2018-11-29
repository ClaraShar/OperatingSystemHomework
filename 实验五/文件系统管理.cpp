#include <iostream>
#include <fstream>
#include <cstdio>
#include <unordered_map>
#include <string>
#include <list>
#include <vector>
using namespace std;

const int N=10;//用户数
const int M=10;//每个用户可保存的文件数

unordered_map<string,vector<string>> MFD;
vector<string> AFD;

void Create(string user_name)
{
	string file_name;
	cout<<"请输入文件名："<<endl;
	cin>>file_name;
	MFD[user_name].push_back(file_name);
	fstream tfile;
	tfile.open(file_name,ios::trunc);
	tfile.close();
	cout<<"创建成功！"<<endl;
	cout<<endl;
}

void Open(string user_name)
{
	cout<<"请输入您要打开的文件名："<<endl;
	string txt;
	cin>>txt;
	auto it=find(MFD[user_name].begin(),MFD[user_name].end(),txt);
	if(it!=MFD[user_name].end()&&AFD.size()<5)
	{
		AFD.push_back(txt);
		cout<<"正在运行的文件有："<<endl;
		for(int i=0;i<AFD.size();i++)
			cout<<AFD[0]<<endl;
	}
	else if(it!=MFD[user_name].end()&&AFD.size()==5)
	{
		cout<<"打开失败！当前正在运行的文件数已满5个，请先关闭一些文件"<<endl;
	}
	else
	{
		cout<<"该文件不存在！是否创建？如果是，请输入1"<<endl;
		int in;
		cin>>in;
		if(in==1)
		{
			MFD[user_name].push_back(txt);
			fstream tfile;
			tfile.open(txt,ios::trunc);
			tfile.close();
			cout<<"创建成功！"<<endl;
		}
		else
			cout<<"谢谢使用，再见！"<<endl;
	}
	cout<<endl;
}

void Read(string user_name)
{
	cout<<"请输入您要读取的文件名："<<endl;
	string txt,line;
	cin>>txt;
	ifstream txtfile;
	txtfile.open(txt,ios::in);
	if(!txtfile)
	{
		int in;
		cout<<"该文件不存在！是否创建？如果是，请输入1"<<endl;
		cin>>in;
		if(in==1)
		{
			MFD[user_name].push_back(txt);
			fstream tfile;
			tfile.open(txt,ios::trunc);
			tfile.close();
			cout<<"创建成功！"<<endl;
		}
		else
			cout<<"谢谢使用，再见！"<<endl;
	}
	else
	{
		cout<<"文件内容为："<<endl;
		while(!txtfile.eof())
		{
			txtfile>>line;
			cout<<line;
		}
		txtfile.close();
	}
	cout<<endl;
}
void Write(string user_name)
{
	cout<<"请输入您写入的文件名："<<endl;
	string txt,line;
	cin>>txt;
	ofstream txtfile;
	txtfile.open(txt,ios::out);
	if(!txtfile)
	{
		int in;
		cout<<"该文件不存在！是否创建？如果是，请输入1"<<endl;
		cin>>in;
		if(in==1)
		{
			MFD[user_name].push_back(txt);
			fstream tfile;
			tfile.open(txt,ios::trunc);
			tfile.close();
			cout<<"创建成功！"<<endl;
		}
		else
			cout<<"谢谢使用，再见！"<<endl;
	}
	else
	{
		cout<<"请输入您要写入的内容："<<endl;
		cin>>line;
		txtfile<<line;
		txtfile.close();
	}
	cout<<endl;
}

void Close(string user_name)
{
	cout<<"请输入您要关闭的文件名："<<endl;
	string txt;
	cin>>txt;
	auto it=find(MFD[user_name].begin(),MFD[user_name].end(),txt);
	if(it!=MFD[user_name].end())
	{
		AFD.erase(it);
		cout<<"正在运行的文件有："<<endl;
		for(int i=0;i<AFD.size();i++)
			cout<<AFD[0]<<endl;
	}
	else
	{
		cout<<"该文件没有运行！"<<endl;
	}
	cout<<endl;
}

void Delete(string user_name)
{
	cout<<"请输入您要删除的文件名："<<endl;
	char *savePath;
	cin>>savePath;
	string file_name=savePath;
	if(remove(savePath)==0)
    {
        cout<<"删除成功"<<endl;
        auto it=find(MFD[user_name].begin(),MFD[user_name].end(),file_name);
        MFD[user_name].erase(it);      
    }
    else
    {
        cout<<"删除失败"<<endl;        
    }
    cout<<endl;
}

void menu(string user_name)
{
	auto it=MFD.find(user_name);
	cout<<"用户："<<user_name<<"当前的文件数量为"<<(it->second).size()<<endl;
	while(1)
	{
		cout<<"请选择下列操作："<<endl;
		cout<<"1.创建文件  2.打开文件  3.读出文件  4.写入文件  5.关闭文件  6.删除文件  其他.退出系统"<<endl;
		int opt;
		cin>>opt;
		switch(opt)
		{
			case 1:
			{
				Create(user_name);
				continue;
			}
			case 2:
			{
				Open(user_name);
				continue;
			}
			case 3:
			{
				Read(user_name);
				continue;
			}
			case 4:
			{
				Write(user_name);
				continue;
			}
			case 5:
			{
				Close(user_name);
				continue;
			}
			case 6:
			{
				Delete(user_name);
				continue;
			}
			default:
			{
				cout<<"谢谢使用，再见！"<<endl;
				break;
			}
		}
		break;
	}
}

int main()
{
	vector<string> Zhao_s,Qian_s,Sun_s,Li_s,Zhou_s;
	MFD["Zhao"]=Zhao_s;
	MFD["Qian"]=Qian_s;
	MFD["Sun"]=Sun_s;
	MFD["Li"]=Li_s;
	MFD["Zhou"]=Zhou_s;

	string user_name;
	cout<<"欢迎进入文件系统，请输入您的用户名："<<endl;
	cin>>user_name;
	auto it=MFD.find(user_name);
	if(it!=MFD.end())
	{
		menu(user_name);//如果找到了，进入菜单管理
	}
	else
	{
		cout<<"该用户不存在，是否创建为新的用户？如果是，请输入1；否则，输入2，重新输入用户名；输入0，退出系统"<<endl;
		while(1)
		{
			int ans1;
			cin>>ans1;
			if(ans1==1)
			{
				vector<string> user_name_s;
				MFD[user_name]=user_name_s;
				cout<<"用户创建成功！是否继续管理文件？如果是，请输入1；否则，输入0，退出系统"<<endl;
				int ans2;
				cin>>ans2;
				if(ans2==1)
				{
					menu(user_name);
				}
				else if(ans2==0)
				{
					cout<<"谢谢使用，再见！"<<endl;
					return 0;
				}
				else
				{
					cout<<"输入错误！系统自动退出"<<endl;
					return 0;
				}
			}
			else if(ans1==2)
				continue;
			else if(ans1==0)
			{
				cout<<"谢谢使用，再见！"<<endl;
				return 0;
			}
			else
			{
				cout<<"输入错误！系统自动退出"<<endl;
				return 0;
			}
		}
	}
	return 0;
}