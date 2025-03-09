#include<iostream>
using namespace std;
#define Test_Date
// �������ʵ��
class Date
{

public:
	friend ostream& operator<<(ostream& out, const Date& d);
	bool illegalDate(const Date& d) 
	{
		if (d._month > 13 || d._day > GetMonthDay(d._year, d._month))
		{
			return true;
		}
	}

	// ��ȡĳ��ĳ�µ�����
	int GetMonthDay(int year, int month) 
	{
		int arr[13] = { -1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		if (month == 2 && ((year % 4 == 0 && year % 100 != 0) or year % 400 == 0)) {
			return 29;
		}
		return arr[month];
	}

	// ȫȱʡ�Ĺ��캯��
	Date(int year = 1900, int month = 1, int day = 1) {
		_year = year;
		_month = month;
		_day = day;
	}

	// �������캯��
	Date(const Date& d) {
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}

	// ��ֵ���������
	Date& operator=(const Date& d) 
	{
		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		return *this;
	}
	// ��������

	~Date(){}

	// ����+=����

	Date& operator+=(int day) 
	{
		_day += day;
		while(_day > GetMonthDay(_year, _month)) 
		{
			_day -= GetMonthDay(_year, _month);
			++_month;
			if (_month > 12) 
			{
				_year++;
				_month = 1;
			}
		}
		return *this;
	}

	// ����+����
	Date operator+(int day) {
		Date tmp = *this;
		tmp += day;
		return tmp;
	}

	// ����-=����
	Date& operator-=(int day)
	{
		{
			_day -= day;
			while (_day <= 0)
			{
				if (_month == 1) {
					_month = 12;
					_year--;
				}
				else {
					_month--;
				}
				_day += GetMonthDay(_year, _month);
			}
			return *this;
		}
	}
	// ����-����
	Date operator-(int day) 
	{
		Date tmp = *this;
		tmp -= day;
		return tmp;
	}

	// ǰ��++
	Date& operator++() 
	{
		*this += 1;
		return *this;
	}

	// ����++
	Date operator++(int) 
	{
		Date tmp = *this;
		*this += 1;
		return tmp;
	}

	// ����--
	Date operator--(int)
	{
		Date tmp = *this;
		*this -= 1;
		return tmp;
	}

	// ǰ��--
	Date& operator--() 
	{
		*this -= 1;
		return *this;
	}

	// >���������
	bool operator>(const Date& d) {
		if (_year > d._year) 
		{
			return true;
		}
		else if (_year == d._year && _month > d._month)
		{
			return true;
		}
		else if (_year == d._year && _month == d._month && _day > d._day)
		{
			return true;
		}
		else {
			return false;
		}
	}

	// ==���������
	bool operator==(const Date& d) {
		return _year == d._year && _month == d._month && _day == d._day;
	}

	// >=���������

	bool operator >= (const Date& d) {
		return *this == d || *this > d;
	}

	// <���������

	bool operator < (const Date& d) {
		return !(*this >= d);
	}

	// <=���������

	bool operator <= (const Date& d) {
		return *this < d || *this == d;
	}

	// !=���������

	bool operator != (const Date& d) {
		return !(*this == d);
	}

	// ����-���� ��������
	int operator-(const Date& d) {
		int flag = 1;
		int ans = 0;
		Date max = d;
		Date min = *this;
		if (min > max) {
			flag = -1;
			Date tmp;
			tmp = max;
			max = min;
			min = tmp;
		}
		while (min != max) {
			min++;
			ans++;
		}
		return ans * flag;
	}

private:
	int _year;
	int _month;
	int _day;
};

ostream& operator<<(ostream& out, const Date& d) 
{
	out << d._year << "/" << d._month << "/" << d._day << endl;
	return out;
}


#ifdef Test_Date

int main() {
	Date d1(2025, 3, 9);
	Date d2(1945, 9, 2);
	cout << d2 - d1 << endl;
	d1 += 10000;
	cout << d1 << endl;
	return 0;
}

#endif 