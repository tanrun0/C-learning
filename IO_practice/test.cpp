#include <iostream>
#include <fstream>
#include <sstream>
#include <string>


using namespace std;

//int main()
//{
//
//	cout << cin.good() << endl; // 查看 cin 的 goodbit
//	int i;
//	cin >> i;
//	// 故意输入 字符 a 创造错误
//	cout << (cin.rdstate() & ios_base::failbit) << endl; // 看当前流的错误信息
//
//	cin.clear(); // 重置状态为: 1000
//	// 但是注意：此时字符 a 还在缓冲区没有被读走
//	// cin.get(); // 读走 cin 缓冲区的一个字符
//	
//	char c;
//	c = cin.peek();
//	while (!(c >= '0' && c <= '9')) // 把非数字都读走
//	{
//		c = cin.get();
//		cout << c;
//		c = cin.peek();
//	}
//	cin >> i; // 重新输入 10 
//	cout << i << endl;
//	cout << cin.good() << cin.bad() << cin.fail() << cin.eof() << endl;
//	return 0;
//}


//int main()
//{
//	// 这样打开文件就不会清空，文件指针在起始位置
//	ofstream outfile("log.txt", ios_base::out | ios_base::in); 
//	outfile.seekp(9, ios::cur); // 把指针从当前位置往后移动 9 个位置（以字节为单位）
//	outfile << "hello" << endl;
//	return 0;
//}


//int main()
//{
//	ifstream ifs("test.png", ios_base::in | ios_base::binary);
//	ofstream ofs("test_copy.png", ios_base::out | ios_base::binary);
//	int n = 0;
//	while (ifs && ofs) // 确保流的状态都是 good 的
//	{
//		char ch = ifs.get();
//		ofs << ch;
//		++n;
//	}
//	cout << n << endl;
//	return 0;
//}

//int main() {
//    // 输出字符串流 (ostringstream)
//    ostringstream oss;
//    oss << "Hello " << 32 << " world!";  // 会把 32 当字符
//    string str = oss.str(); // 获取字符串
//    cout << str << endl;
//
//    // 输入字符串流 (istringstream)
//    istringstream iss("100 200"); // 用"100 200"构造 iss底层的string
//    int a, b;
//    iss >> a >> b; //  >> 会以空格为分隔符
//    cout << a + b << endl;
//
//    // 输入输出字符串流 (stringstream)
//    stringstream ss;
//    ss << "3.14";
//    double pi;
//    ss >> pi; // 从 ss 流中读入 3,14 然后给了pi
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