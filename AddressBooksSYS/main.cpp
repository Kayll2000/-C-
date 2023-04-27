/****************************************************************************************************************************
* @function:通讯录系统主函数
* @version:v1.0
* @author:chenjunlong
* @description:The system realizes simple address book function.
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
#include <iostream>
#include "addressbook.h"

using namespace std;

int main()
{
    Address var;//创建通讯录结构体
    int selectflag;
    var.size = 0;//初始化人员数为 0
    while(true)
    {
        if(QuitFlag)
        {
            break;
        }
        Show_Menu();
        cin >> selectflag;
        Select(selectflag,&var);
    }
    return 0;
}