#include"Contact.h"

void menu()
{
	printf("**********************************\n");
	printf("*****1.Add       2.del    ********\n");
	printf("*****3.Search    4.modify ********\n");
	printf("*****5.show      6.exit   ********\n");
	printf("**********************************\n");
}

contact::contact()
	:head(new PerInfo)
{
	head->next = nullptr;
	ContactLoad(); // ��������ʱ�����ļ�����
}

contact::~contact() {
	ContactSave(); // �����˳�ʱ��������
	DestroyContact();
}
PerInfo* contact::GETNode() {
	PerInfo* newnode = new PerInfo;
	cout << "��������ϵ�˵���Ϣ���������������䣬�绰��סַ��˳���ÿո�ָ�����" << endl;
	cin >> newnode->name >> newnode->age >> newnode->tele >> newnode->addr;
	return newnode;
}

void contact::AddContact() {
	PerInfo* newnode = GETNode();
	newnode->next = head->next;
	head->next = newnode;
	cout << "��ӳɹ�" << endl;
}
void contact::DelContact() {
	if (head->next == nullptr) {
		cout << "ͨѶ¼Ϊ��" << endl;
	}
	else {
		string name;
		cout << "��������Ҫɾ������ϵ�˵�����" << endl;
		cin >> name;
		PerInfo* pre = head;
		PerInfo* cur = head->next;
		while (cur != nullptr && cur->name != name) {
			cur = cur->next;
			pre = pre->next;
		}
		if (cur == nullptr) {
			cout << "Ҫɾ������ϵ�˲���ͨѶ¼��" << endl;
			return;
		}
		else {
			pre->next = cur->next;
			delete cur;
		}
		cout << "ɾ���ɹ�" << endl;
	}
}

//չʾͨѶ¼����
void contact::ShowContact() {
	if (head->next == nullptr) {
		cout << "ͨѶ¼Ϊ��" << endl;
	}
	PerInfo* cur = head->next;
	cout << left << setw(20) << "����" << setw(10) << "����" << setw(20) << "�绰" << setw(30) << "סַ" << endl;
	while (cur != nullptr) {
		cout << left << setw(20) << cur->name << setw(10) << cur->age << setw(20) << cur->tele << setw(30) << cur->addr << endl;
		cur = cur->next;
	}
}

//����ͨѶ¼����
void contact::FindContact() {
	if (head->next == nullptr) {
		cout << "ͨѶ¼Ϊ��" << endl;
	}
	else {
		string name;
		cout << "��������Ҫ���ҵ���ϵ�˵�����" << endl;
		cin >> name;
		PerInfo* cur = head->next;
		while (cur != nullptr && cur->name != name) {
			cur = cur->next;
		}
		if (cur == nullptr) {
			cout << "Ҫ���ҵ���ϵ�˲���ͨѶ¼��" << endl;
			return;
		}
		else {
			cout << left << setw(20) << "����" << setw(10) << "����" << setw(20) << "�绰" << setw(30) << "סַ" << endl;
			cout << left << setw(20) << cur->name << setw(10) << cur->age << setw(20) << cur->tele << setw(30) << cur->addr << endl;
		}
	}
}


//�޸�ͨѶ¼����
void contact::ModifyContact() {
	if (head->next == nullptr) {
		cout << "ͨѶ¼Ϊ��" << endl;
	}
	else {
		string name;
		cout << "��������Ҫ�޸ĵ���ϵ�˵�����" << endl;
		cin >> name;
		PerInfo* cur = head->next;
		while (cur != nullptr && cur->name != name) {
			cur = cur->next;
		}
		if (cur == nullptr) {
			cout << "Ҫ�޸ĵ���ϵ�˲���ͨѶ¼��" << endl;
			return;
		}
		else {
			cout << "�������޸ĵ���ϵ�˵���Ϣ���������������䣬�绰��סַ��˳���ÿո�ָ�����" << endl;
			cin >> cur->name >> cur->age >> cur->tele >> cur->addr;
		}
		cout << "�޸ĳɹ�" << endl;
	}
}


void contact::ContactSave()
{
	// ����Ҫ��Ĭ����ʽ�򿪣������ǣ�����Ϊ��ȡ�ļ����ļ������ݻ�����ڵ������У�׷�ӵĻ��������ʱ�����дһ��
	ofstream outFile("Contact.txt");  

	// ����ļ��Ƿ�ɹ���
	if (outFile.is_open()) {
		PerInfo* cur = head->next;
		while (cur != nullptr) {
			outFile << left << setw(20) << cur->name << setw(10) << cur->age << setw(20) << cur->tele << setw(30) << cur->addr << endl;
			cur = cur->next;
		}
		// �ر��ļ�
		outFile.close();
		std::cout << "�ļ�д��ɹ���" << std::endl;
	}
	else {
		std::cerr << "�޷����ļ���" << std::endl;
	}
	printf("�ɹ�����ͨѶ¼����\n");
}

// �����ļ�����
void contact::ContactLoad()
{
	ifstream inFile("Contact.txt");
	if (inFile.is_open()) {
		string name, age, tele, addr;
		while (inFile >> name >> age >> tele >> addr) {
			PerInfo* newnode = new PerInfo;
			newnode->name = name;
			newnode->age = age;
			newnode->tele = tele;
			newnode->addr = addr;
			newnode->next = head->next;
			head->next = newnode;
		}
		inFile.close();
		cout << "�ļ���ȡ�ɹ���" << endl;
	}
	else {
		cerr << "�޷����ļ���" << endl;
	}
}

//����ͨѶ¼����
void contact::DestroyContact() {
	// ����Ҳ�������������cur == nullptr �������ٴ��ͷ��ڴ�
		PerInfo* cur = head;
		while (cur != nullptr) {
			PerInfo* temp = cur;
			cur = cur->next;
			delete temp;
		}
		head = nullptr;
}