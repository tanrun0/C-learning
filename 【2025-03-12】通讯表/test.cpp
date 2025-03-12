#include"contact.h"

//测试通讯录的基本功能

enum Option
{
	EXIT,//0
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SHOW,
	SORT
};
int main()
{
	int input = 0;
	Contact con;//通讯录
	do
	{
		menu();
		cout << "请输入你的选择：>" << endl;
		cin >> input;
		switch (input)
		{
		case ADD:
			con.ADDContact();
			break;
		case DEL:
			con.DELContact();
			break;
		case SEARCH:
			con.SEARCHContact();
			break;
		case MODIFY:
			con.MODIFYContact();
			break;
		case SHOW:
			con.SHOWContact();
			break;
		case SORT:
			con.SORTContact();
			break;
		case EXIT:
			cout << "退出通讯录" << endl;
			break;
		default:
			cout << "选择错误，重新选择" << endl;
			break;
		}
	} while (input);
	return 0;
}