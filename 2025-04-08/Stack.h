#include<vector>

namespace tr
{
	template<typename T>
	class stack
	{
	public:
		stack(){}
		void push(const T& x) { _a.push_back(x); }
		void pop() { _a.pop_back(); }
		const T& top() const { return _a.back(); }
		T& top() { return _a.back(); }
		size_t size() { return _a.size(); }
		bool empty() { return _a.empty(); }

	private:
		std::vector<T> _a; // 栈的底层用数组
	};
}
