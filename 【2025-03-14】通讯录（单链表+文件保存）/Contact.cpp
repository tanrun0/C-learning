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
	ContactLoad(); // 程序启动时加载文件数据
}

contact::~contact() {
	ContactSave(); // 程序退出时保存数据
	DestroyContact();
}
PerInfo* contact::GETNode() {
	PerInfo* newnode = new PerInfo;
	cout << "请输入联系人的信息（按照姓名，年龄，电话，住址的顺序，用空格分隔）：" << endl;
	cin >> newnode->name >> newnode->age >> newnode->tele >> newnode->addr;
	return newnode;
}

void contact::AddContact() {
	PerInfo* newnode = GETNode();
	newnode->next = head->next;
	head->next = newnode;
	cout << "添加成功" << endl;
}
void contact::DelContact() {
	if (head->next == nullptr) {
		cout << "通讯录为空" << endl;
	}
	else {
		string name;
		cout << "请输入你要删除的联系人的名字" << endl;
		cin >> name;
		PerInfo* pre = head;
		PerInfo* cur = head->next;
		while (cur != nullptr && cur->name != name) {
			cur = cur->next;
			pre = pre->next;
		}
		if (cur == nullptr) {
			cout << "要删除的联系人不在通讯录中" << endl;
			return;
		}
		else {
			pre->next = cur->next;
			delete cur;
		}
		cout << "删除成功" << endl;
	}
}

//展示通讯录数据
void contact::ShowContact() {
	if (head->next == nullptr) {
		cout << "通讯录为空" << endl;
	}
	PerInfo* cur = head->next;
	cout << left << setw(20) << "姓名" << setw(10) << "年龄" << setw(20) << "电话" << setw(30) << "住址" << endl;
	while (cur != nullptr) {
		cout << left << setw(20) << cur->name << setw(10) << cur->age << setw(20) << cur->tele << setw(30) << cur->addr << endl;
		cur = cur->next;
	}
}

//查找通讯录数据
void contact::FindContact() {
	if (head->next == nullptr) {
		cout << "通讯录为空" << endl;
	}
	else {
		string name;
		cout << "请输入你要查找的联系人的名字" << endl;
		cin >> name;
		PerInfo* cur = head->next;
		while (cur != nullptr && cur->name != name) {
			cur = cur->next;
		}
		if (cur == nullptr) {
			cout << "要查找的联系人不在通讯录中" << endl;
			return;
		}
		else {
			cout << left << setw(20) << "姓名" << setw(10) << "年龄" << setw(20) << "电话" << setw(30) << "住址" << endl;
			cout << left << setw(20) << cur->name << setw(10) << cur->age << setw(20) << cur->tele << setw(30) << cur->addr << endl;
		}
	}
}


//修改通讯录数据
void contact::ModifyContact() {
	if (head->next == nullptr) {
		cout << "通讯录为空" << endl;
	}
	else {
		string name;
		cout << "请输入你要修改的联系人的名字" << endl;
		cin >> name;
		PerInfo* cur = head->next;
		while (cur != nullptr && cur->name != name) {
			cur = cur->next;
		}
		if (cur == nullptr) {
			cout << "要修改的联系人不在通讯录中" << endl;
			return;
		}
		else {
			cout << "请输入修改的联系人的信息（按照姓名，年龄，电话，住址的顺序，用空格分隔）：" << endl;
			cin >> cur->name >> cur->age >> cur->tele >> cur->addr;
		}
		cout << "修改成功" << endl;
	}
}


void contact::ContactSave()
{
	// 这里要以默认形式打开（即覆盖），因为读取文件后，文件的内容会存在于单链表中，追加的话，保存的时候会再写一遍
	ofstream outFile("Contact.txt");  

	// 检查文件是否成功打开
	if (outFile.is_open()) {
		PerInfo* cur = head->next;
		while (cur != nullptr) {
			outFile << left << setw(20) << cur->name << setw(10) << cur->age << setw(20) << cur->tele << setw(30) << cur->addr << endl;
			cur = cur->next;
		}
		// 关闭文件
		outFile.close();
		std::cout << "文件写入成功。" << std::endl;
	}
	else {
		std::cerr << "无法打开文件。" << std::endl;
	}
	printf("成功保存通讯录数据\n");
}

// 加载文件数据
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
		cout << "文件读取成功。" << endl;
	}
	else {
		cerr << "无法打开文件。" << endl;
	}
}

//销毁通讯录数据
void contact::DestroyContact() {
	// 析构也调用这个，进来cur == nullptr ，不会再次释放内存
		PerInfo* cur = head;
		while (cur != nullptr) {
			PerInfo* temp = cur;
			cur = cur->next;
			delete temp;
		}
		head = nullptr;
}