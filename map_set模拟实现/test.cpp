#include"mymap.h"
#include"myset.h"
#include<string>

void testmap()
{
	tr::map<int, int> dict;
	dict.insert({ 5,5 });
	dict.insert({ 4,4 });
	dict.insert({ 3,3 });
	dict.insert({ 1,1 });
	
	tr::map<int, int>::iterator it = dict.begin();
	while (it != dict.end())
	{

		it->second += 1; // ��ȡ�쳣

		cout << it->first << ":" << it->second << endl;
		++it;
	}

	cout << endl;

	for (auto& kv : dict)
	{
		cout << kv.first << ":" << kv.second << endl;
	}
	if (dict.find(5) != dict.end())
	{
		cout << "�ҵ���" << endl;
	}

}

void testset()
{
	tr::set<int> s;
	s.insert(5);
	s.insert(4);
	s.insert(3);
	s.insert(2);
	s.insert(1);

	tr::set<int>::iterator sit = s.end(); // end()�õ�����nullptr�ĵ�����
	while (sit != s.begin())
	{
		--sit; // ��--end()���õ����������һ��Ԫ�صĵ�������Ȼ���ٲ���
		cout << *sit << " ";

	}
	cout << endl;

	for (auto& e : s)
	{
		cout << e << " ";
	}
	cout << endl;

}

int main()
{
	testmap();
	testset();
	return 0;
}
