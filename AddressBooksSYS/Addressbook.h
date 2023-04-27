#ifndef ADDRESSBOOK_H
#define ADDRESSBOOK_H
//addressbook.h
#include <string>

using namespace std;
#define MAX 100
#define  EXIT    0
#define  ADD     1
#define  SHOW    2
#define  DEL     3
#define  FIND    4
#define  MOD     5
#define  CLC     6

extern int num;//记录所需操作人的ID
extern bool QuitFlag;//退出该系统的flag

struct System//联系人结构体
{
    string name;
    string sex;
    int age;
    int tel;
    string add;
};

struct Address
{
    System array[MAX];//存放联系人
    int size;//记录联系人个数

};

extern void Show_Menu(void);//显示菜单界面
extern void Show_Person(Address *var);//显示联系人
extern bool IsExit(Address *val,string name);//判断联系人是否存在
extern void Del_Person(Address* var);//删除指定联系人
extern void Search_Person(Address *var);//查询指定联系人
extern void Modify_Person(Address *var);//修改指定联系人
extern void Clear_Person(Address *var);//清空联系人
extern void Add_Person(Address *var);//增加联系人
extern void Select(int selectflag,Address *var);//选择处理函数

#endif