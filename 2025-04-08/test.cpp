//#include<iostream>
//#include<queue>
//
//using namespace std;



//void test_Stack() {
//	tr::stack<int> st;
//	st.push(1);
//	st.push(2);
//	st.push(3);
//	st.push(4);
//	st.push(5);
//	while (!st.empty())
//	{
//		cout << st.top() << endl;
//		st.pop();
//	}
//
//	cout << st.empty() << st.size() << endl;
//}



//void test_Queue() {
//	tr::queue<int> ls;
//	ls.push(1);
//	ls.push(2);
//	ls.push(3);
//	ls.push(4);
//	ls.push(5);
//	while (!ls.empty())
//	{
//		cout << ls.front() << endl;
//		ls.pop();
//	}
//
//	cout << "empty: " << ls.empty() << endl << "size: " << ls.size() << endl;
//}


#include"priority_queue.h"
int main() {
	tr::priority_queue<int, vector<int>, Greater<int>> pq; // 传入的不是less，而是Less<int>，类模板传的是类型，函数模板传才是参数
	pq.push(3);
	pq.push(2);
	pq.push(6);
	pq.push(1);
	pq.push(8);
	while (!pq.empty())
	{
		cout << pq.top();
		pq.pop();
	}
	cout << endl;
	return 0;
}

