/****************************************************************************************************************************
* @function:通讯录系统子函数
* @version:v1.0
* @author:chenjunlong
* @description:Store address book system function implementation function..
* @github:https://github.com/Kayll2000/Address-book-system.git
* @date:2023.04.27
* @lmodauthor:chenjunlong
* @lmoddate:2023.04.27
*           FUCTION:
                    1、查看联系人
                    2、添加联系人
                    3、修改联系人
                    4、删除联系人
                    5、清空联系人
                    6、······
            BUGFIX:
            MODIFY:

****************************************************************************************************************************/
#include "addressbook.h"
#include <iostream>
#include <string>
using namespace std;

int num = 0;
bool QuitFlag = false;//退出该系统的flag

void Show_Menu(void)//显示菜单界面
{
    cout<<"*********************"<<endl;
    cout<<"**** 1、添加联系人 ****"<<endl;
    cout<<"**** 2、显示联系人 ****"<<endl;
    cout<<"**** 3、删除联系人 ****"<<endl;
    cout<<"**** 4、查找联系人 ****"<<endl;
    cout<<"**** 5、修改联系人 ****"<<endl;
    cout<<"**** 6、清空联系人 ****"<<endl;
    cout<<"**** 0、退出通讯录 ****"<<endl;
    cout<<"*********************"<<endl;
}

void Show_Person(Address *var)//显示联系人
{
    if(var->size == 0)
    {
        cout <<"联系人为空!"<<endl;
    }
    else
    {
        cout <<"通讯录的联系人数量为 "<<var->size + 1 <<endl;
        for(int i = 0;i<var->size;i++)
        {
            cout<<"第"<<i+1<<"个联系人信息如下："<<endl;
            cout<<"名字："<< var->array[i].name << endl;
            cout<<"性别："<< var->array[i].sex << endl;
            cout<<"年龄："<< var->array[i].age << endl;
            cout<<"电话："<< var->array[i].tel << endl;
            cout<<"地址："<< var->array[i].add << endl;
        }
    }
}

bool IsExit(Address *val,string name)//判断联系人是否存在
{
    for(int i = 0;i<val->size;i++){
        if(val->array[i].name == name)
        {
            return true;
            num = i;
        }
    }
    return false;
}

void Del_Person(Address* var)//删除指定联系人
{
    string name;
    cout <<"需要删除的名字："<<endl;
    cin >> name;
    bool checkflag = IsExit(var,name);
    if(checkflag)
    {
        for(int i = num;i<var->size;i++)
        {
            var->array[i] = var->array[i+1];//把数组所有元素往前移动
        }
        var->size--;
        cout <<"删除成功！"<<endl;
    }else{
        cout <<"此人已经删除！"<<endl;
    }
}

void Search_Person(Address *var)//查询指定联系人
{
    string name;
    cout <<"需要查找人的名字" << endl;
    cin >> name;
    bool checkflag = IsExit(var,name);
    if(checkflag)
    {
        cout<<"查到此人，信息如下："<<endl;
        cout<<"姓名"<<var->array[num].name<<endl;
        cout<<"性别"<<var->array[num].sex<<endl;
        cout<<"年龄"<<var->array[num].age<<endl;
        cout<<"电话"<<var->array[num].tel<<endl;
        cout<<"地址"<<var->array[num].add<<endl;
    }
    else{
        cout << "查无此人！" << endl;
    }
}

void Modify_Person(Address *var)//修改指定联系人
{
    string name;
    string newname;
    int newage;
    int newtel;
    string newadd;
    string sex = "男";
    //姓名
    cout << "需要修改的联系人姓名：" << endl;
    bool checkflag = IsExit(var,name);
    if(checkflag)
    {   
        cin >> newname;
        var->array[num].name = newname;
        //性别
        cout << "输入性别："<<endl;
        while(true)
        {
            cin >> sex;
            if(sex == "男" || sex == "女")
            {
                var->array[num].sex = sex;
                break;
            }
            cout << "输入格式错误，请重新输入" << endl;
        }
        //年龄
        cout<<"修改后的年龄："<<endl;
        cin >> newage;
        var->array[num].age = newage;
        //电话
        cout<<"修改后的电话： "<<endl;
        cin >> newtel;
        var->array[num].tel = newtel;
        //地址
        cout<<"修改后的地址："<<endl;
        cin >> newadd;
        var->array[num].add = newadd;
    }
    else{
        cout <<"查无此人！" <<endl;
    }
}

void Clear_Person(Address *var)//清空联系人
{
    var->size = 0;
    cout <<"联系人已经清空！"<<endl;
}

void Add_Person(Address *var)//增加联系人
{
    string name;
    string sex;
    string add;
    string flagstr = "Y";
    int age;
    int tel;
    bool flag = true;
    bool checkflag = IsExit(var,name);

    if(!checkflag)//如果没有该联系人则执行下面代码
    {
        while(flag)
        {
            var->size++;
            //姓名
            cout<<"输入你需要添加的联系人姓名："<<endl;
            cin >> name;

            if(IsExit(var,name))
            {
                cout << "此人已经存在" << endl;
                return;
            }
            var->array[num+1].name = name;
            //年龄
            cout<<"输入你需要添加联系人的年龄："<<endl;
            cin >> age;
            var->array[num+1].name = age;
            //性别
            cout<<"输入你需要添加联系人的性别"<<endl;
            while(true)
            {
                cin >> sex;
            if(sex == "男" || sex == "女")
            {
                var->array[num+1].sex = sex;
                break;
            }
            cout << "输入格式错误，请重新输入" << endl;
            }
            //电话
            cout<<"输入你需要添加联系人的电话："<<endl;
            cin >> tel;
            var->array[num+1].tel = tel;
            //地址
            cout<<"输入你需要添加联系人的地址"<<endl;
            cin >> add;
            var->array[num+1].add = add;

            cout<<"还需要继续添加吗？ Y/N "<<endl;
            cin >> flagstr;

            if(flagstr == "Y" || flagstr == "y")
            {
                cout <<"继续添加联系人！"<<endl;
                flag = true;
            }
            if(flagstr == "N" || flagstr == "n")
            {
                cout<<"添加结束！"<<endl;
                flag = false;
                break;
            }
        }
    }else{
        cout <<"该联系人已经存在！"<<endl;
    }
}

void Select(int selectflag,Address *var)
{
        switch(selectflag)
        {
            case EXIT:
                cout <<"***已经退出通讯录系统！***"<<endl;
                QuitFlag = true;
                break;;
            case ADD:
                system("pause");
                system("clc");
                Add_Person(var);
                break;
            case SHOW:
                system("pause");
                system("clc");
                Show_Person(var);
                break;
            case DEL:
                system("pause");
                system("clc");
                Del_Person(var);
                break;
            case FIND:
                system("pause");
                system("clc");
                Search_Person(var);
                break;
            case MOD:
                system("pause");
                system("clc");
                Modify_Person(var);
                break;
            case CLC:
                system("pause");
                system("clc");
                Clear_Person(var);
                break;
            default:
                break;
        }
}
