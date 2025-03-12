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
	cout << "������Ҫ��ӵ���ϵ�˵���Ϣ���������������䣬�Ա𣬵绰��סַ��˳���ÿո�ָ�����" << endl;
	PerInfo p;
	cin >> p._name >> p._age >> p._sex >> p._tele >> p._addr;
	_arry[_size] = p;
	_size++;
	cout << "������" << endl;
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
		cout << "ͨѶ¼Ϊ��" << endl;
	}
	string name;
	cout << "��������Ҫɾ������ϵ�˵�������";
	cin >> name;
	int i = FINDPerIndex(name);
	if (i == -1) {
		cout << "û���ҵ�����������" << endl;
		return;
	}
	// ͨ���ú�����Ϣ����ǰ����Ϣ�ķ�ʽ��ɾ��
	while (i < _size - 1) 
	{
		_arry[i] = _arry[i + 1];
		i++;
	}

	_size--;
	cout << "ɾ���ɹ�" << endl;
}


void Contact::SEARCHContact() {
	if (_size == 0) {
		cout << "ͨѶ¼Ϊ��" << endl;
	}
	string name;
	cout << "��������Ҫ���ҵ���ϵ�˵�������";
	cin >> name;
	int i = FINDPerIndex(name);
	if (i == -1) {
		cout << "û���ҵ�����������" << endl;
		return;
	}
	cout << left << setw(20) << _arry[i]._name << setw(10) << _arry[i]._age << setw(10) << _arry[i]._sex << setw(20) << _arry[i]._tele << setw(30) << _arry[i]._addr << endl;
}

void Contact::MODIFYContact() {
	if (_size == 0) {
		cout << "ͨѶ¼Ϊ��" << endl;
	}
	string name;
	cout << "��������Ҫ�޸ĵ���ϵ�˵�������";
	cin >> name;
	int i = FINDPerIndex(name);
	if (i == -1) {
		cout << "û���ҵ�����������" << endl;
		return;
	}
	cout << "��������д��ϵ�˵���Ϣ�����������������䣬�Ա𣬵绰��סַ��˳���ÿո�ָ�����" << endl;
	cin >> _arry[i]._name >> _arry[i]._age >> _arry[i]._sex >> _arry[i]._tele >> _arry[i]._addr;
	cout << "�޸ĳɹ�" << endl;
}

void Contact::SHOWContact() {
	if (_size == 0)
	{
		cout << "ͨѶ¼Ϊ��" << endl;
		return;
	}
	// �����ͷ

	cout << left << setw(20) << "����" << setw(10) << "����" << setw(10) << "�Ա�" << setw(20) << "�绰" << setw(30) << "סַ" << endl;
	int i = 0;
	for (int i = 0; i < _size; i++) {
		cout << left << setw(20) << _arry[i]._name << setw(10) << _arry[i]._age << setw(10) << _arry[i]._sex << setw(20) << _arry[i]._tele << setw(30) << _arry[i]._addr << endl;
	}
}

// ������ĸ��
void Contact::SORTContact() 
{
	if (_size == 0)
	{
		std::cout << "ͨѶ¼Ϊ��" << std::endl;
		return;
	}
	// ʹ��ð�������㷨
	for (int i = 0; i < _size - 1; ++i) {
		for (int j = 0; j < _size - i - 1; ++j) {
			if (_arry[j]._name > _arry[j + 1]._name) {
				// ��������Ԫ��
				PerInfo temp = _arry[j];
				_arry[j] = _arry[j + 1];
				_arry[j + 1] = temp;
			}
		}
	}
	cout << "�������" << endl;
}