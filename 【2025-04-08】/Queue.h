#pragma once
#include<list>

namespace tr
{
	template<typename T>
	class queue
	{
	public:
		queue() {}
		void push(const T& x) { _a.push_back(x); }
		const T& front() const { return _a.front(); }
		T& front() { return _a.front(); }
		void pop() { _a.pop_front(); } // ͷɾ
		size_t size() { return _a.size(); }
		bool empty() { return _a.empty(); }

	private:
		std::list<T> _a;
	};


}