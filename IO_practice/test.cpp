#include <iostream>
#include <fstream>
#include <sstream>
#include <string>


using namespace std;

//int main()
//{
//
//	cout << cin.good() << endl; // �鿴 cin �� goodbit
//	int i;
//	cin >> i;
//	// �������� �ַ� a �������
//	cout << (cin.rdstate() & ios_base::failbit) << endl; // ����ǰ���Ĵ�����Ϣ
//
//	cin.clear(); // ����״̬Ϊ: 1000
//	// ����ע�⣺��ʱ�ַ� a ���ڻ�����û�б�����
//	// cin.get(); // ���� cin ��������һ���ַ�
//	
//	char c;
//	c = cin.peek();
//	while (!(c >= '0' && c <= '9')) // �ѷ����ֶ�����
//	{
//		c = cin.get();
//		cout << c;
//		c = cin.peek();
//	}
//	cin >> i; // �������� 10 
//	cout << i << endl;
//	cout << cin.good() << cin.bad() << cin.fail() << cin.eof() << endl;
//	return 0;
//}


//int main()
//{
//	// �������ļ��Ͳ�����գ��ļ�ָ������ʼλ��
//	ofstream outfile("log.txt", ios_base::out | ios_base::in); 
//	outfile.seekp(9, ios::cur); // ��ָ��ӵ�ǰλ�������ƶ� 9 ��λ�ã����ֽ�Ϊ��λ��
//	outfile << "hello" << endl;
//	return 0;
//}


//int main()
//{
//	ifstream ifs("test.png", ios_base::in | ios_base::binary);
//	ofstream ofs("test_copy.png", ios_base::out | ios_base::binary);
//	int n = 0;
//	while (ifs && ofs) // ȷ������״̬���� good ��
//	{
//		char ch = ifs.get();
//		ofs << ch;
//		++n;
//	}
//	cout << n << endl;
//	return 0;
//}

//int main() {
//    // ����ַ����� (ostringstream)
//    ostringstream oss;
//    oss << "Hello " << 32 << " world!";  // ��� 32 ���ַ�
//    string str = oss.str(); // ��ȡ�ַ���
//    cout << str << endl;
//
//    // �����ַ����� (istringstream)
//    istringstream iss("100 200"); // ��"100 200"���� iss�ײ��string
//    int a, b;
//    iss >> a >> b; //  >> ���Կո�Ϊ�ָ���
//    cout << a + b << endl;
//
//    // ��������ַ����� (stringstream)
//    stringstream ss;
//    ss << "3.14";
//    double pi;
//    ss >> pi; // �� ss ���ж��� 3,14 Ȼ�����pi
//    cout << pi * 2 << endl;
//
//    return 0;
//}

class Date
{
public:

	friend ostream& operator<<(ostream& out, const Date& d);

	Date(int y, int m, int d)
		:_year(y),
		_month(m),
		_day(d)
	{}

private:
	int _year;
	int _month;
	int _day;
};

ostream& operator<<(ostream& out, const Date& d)
{
	out << d._year << "/" << d._month << "/" << d._day;
	return out;
}

int main()
{
	stringstream ss;
	Date date1(2025, 6, 3);
	ss << date1 << " hello world!" << endl;
	cout << ss.str() << endl;
	return 0;
}