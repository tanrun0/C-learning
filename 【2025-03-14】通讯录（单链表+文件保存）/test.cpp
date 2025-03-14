#include "Contact.h"  // 假设你的头文件名为 Contact.h

int main() {


    // 创建通讯录对象
    contact myContact;
    int choice;
    do {
        // 显示菜单
        menu();
        cout << "请输入你的选择: ";
        cin >> choice;

        switch (choice) {
        case 1:
            // 添加联系人
            myContact.AddContact();
            break;
        case 2:
            // 删除联系人
            myContact.DelContact();
            break;
        case 3:
            // 查找联系人
            myContact.FindContact();
            break;
        case 4:
            // 修改联系人信息
            myContact.ModifyContact();
            break;
        case 5:
            // 展示通讯录
            myContact.ShowContact();
            break;
        case 6:
            // 退出程序
            // myContact.DestroyContact(); // 不能手动调用，不然析构又会调用
            cout << "退出通讯录程序，并保存数据" << endl;
            return 0;
        default:
            cout << "无效的选择，请重新输入。" << endl;
        }
    } while (choice != 0);

    // 程序结束时，对象自动调用析构函数销毁通讯录
    return 0;
}