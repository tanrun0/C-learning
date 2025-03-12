#include"contact.h"

void menu()
{
	printf("**********************************\n");
	printf("*****1.Add       2.del    ********\n");
	printf("*****3.Search    4.modify ********\n");
	printf("*****5.show      6.sort   ********\n");
	printf("*****       0.exit        ********\n");
	printf("**********************************\n");
}


PerInfo::PerInfo()
	:_name("not added")
	, _age("not added")
	, _sex("not added")
	, _tele("not added")
	, _addr("not added")
	{ }

Contact::Contact(int capacity)
	: _arry(new PerInfo[capacity])
	, _size(0)
	, _capacity(capacity)
{}
Contact::~Contact()
{
	delete[] _arry;
	_arry = nullptr;
}

void Contact:: EXPContact() 
{
	if (_size == _capacity) 
	{
		int newcapacity = _capacity * 2;
		PerInfo* tmp = new PerInfo[newcapacity];
		for (int i = 0; i < _size; i++) {
			tmp[i] = _arry[i];
		}
		delete[] _arry;
		_arry = tmp;
		_capacity = newcapacity;

	}

}


void Contact::ADDContact() 
{
	EXPContact();
	cout << "请输入要添加的联系人的信息（按照姓名，年龄，性别，电话，住址的顺序，用空格分隔）：" << endl;
	PerInfo p;
	cin >> p._name >> p._age >> p._sex >> p._tele >> p._addr;
	_arry[_size] = p;
	_size++;
	cout << "添加完成" << endl;
}

int Contact::FINDPerIndex(const string& name) 
{
	int index = 0;
	bool find = false;
	for (index = 0; index < _size; index++) {
		if (_arry[index]._name == name) {
			return index;
		}
	}
	return -1;
}


void Contact::DELContact() 
{
	if (_size == 0) {
		cout << "通讯录为空" << endl;
	}
	string name;
	cout << "请输入你要删除的联系人的姓名：";
	cin >> name;
	int i = FINDPerIndex(name);
	if (i == -1) {
		cout << "没有找到该姓名的人" << endl;
		return;
	}
	// 通过用后面信息覆盖前面信息的方式来删除
	while (i < _size - 1) 
	{
		_arry[i] = _arry[i + 1];
		i++;
	}

	_size--;
	cout << "删除成功" << endl;
}


void Contact::SEARCHContact() {
	if (_size == 0) {
		cout << "通讯录为空" << endl;
	}
	string name;
	cout << "请输入你要查找的联系人的姓名：";
	cin >> name;
	int i = FINDPerIndex(name);
	if (i == -1) {
		cout << "没有找到该姓名的人" << endl;
		return;
	}
	cout << left << setw(20) << _arry[i]._name << setw(10) << _arry[i]._age << setw(10) << _arry[i]._sex << setw(20) << _arry[i]._tele << setw(30) << _arry[i]._addr << endl;
}

void Contact::MODIFYContact() {
	if (_size == 0) {
		cout << "通讯录为空" << endl;
	}
	string name;
	cout << "请输入你要修改的联系人的姓名：";
	cin >> name;
	int i = FINDPerIndex(name);
	if (i == -1) {
		cout << "没有找到该姓名的人" << endl;
		return;
	}
	cout << "请重新填写联系人的信息：（按照姓名，年龄，性别，电话，住址的顺序，用空格分隔）：" << endl;
	cin >> _arry[i]._name >> _arry[i]._age >> _arry[i]._sex >> _arry[i]._tele >> _arry[i]._addr;
	cout << "修改成功" << endl;
}

void Contact::SHOWContact() {
	if (_size == 0)
	{
		cout << "通讯录为空" << endl;
		return;
	}
	// 输出表头

	cout << left << setw(20) << "姓名" << setw(10) << "年龄" << setw(10) << "性别" << setw(20) << "电话" << setw(30) << "住址" << endl;
	int i = 0;
	for (int i = 0; i < _size; i++) {
		cout << left << setw(20) << _arry[i]._name << setw(10) << _arry[i]._age << setw(10) << _arry[i]._sex << setw(20) << _arry[i]._tele << setw(30) << _arry[i]._addr << endl;
	}
}

// 根据字母排
void Contact::SORTContact() 
{
	if (_size == 0)
	{
		std::cout << "通讯录为空" << std::endl;
		return;
	}
	// 使用冒泡排序算法
	for (int i = 0; i < _size - 1; ++i) {
		for (int j = 0; j < _size - i - 1; ++j) {
			if (_arry[j]._name > _arry[j + 1]._name) {
				// 交换两个元素
				PerInfo temp = _arry[j];
				_arry[j] = _arry[j + 1];
				_arry[j + 1] = temp;
			}
		}
	}
	cout << "排序完成" << endl;
}