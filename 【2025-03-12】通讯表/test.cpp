#include"contact.h"

//����ͨѶ¼�Ļ�������

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
	Contact con;//ͨѶ¼
	do
	{
		menu();
		cout << "���������ѡ��>" << endl;
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
			cout << "�˳�ͨѶ¼" << endl;
			break;
		default:
			cout << "ѡ���������ѡ��" << endl;
			break;
		}
	} while (input);
	return 0;
}