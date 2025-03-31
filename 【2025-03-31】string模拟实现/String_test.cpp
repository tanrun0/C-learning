#define _CRT_SECURE_NO_WARNINGS
#include"string.h"

void testConstructors() {
    tr::string s1;
    assert(s1.size() == 0);

    tr::string s2("hello");
    assert(s2.size() == 5);
    assert(strcmp(s2.c_str(), "hello") == 0);

    tr::string s3(s2);
    assert(s3.size() == 5);
    assert(strcmp(s3.c_str(), "hello") == 0);
}

void testAssignmentOperator() {
    tr::string s1("hello");
    tr::string s2("world");
    s2 = s1;
    assert(s2.size() == 5);
    assert(strcmp(s2.c_str(), "hello") == 0);
}

void testModifyFunctions() {
    tr::string s("hello");
    s.push_back('!');
    assert(s.size() == 6);
    assert(strcmp(s.c_str(), "hello!") == 0);

    s += ' ';
    assert(s.size() == 7);
    assert(strcmp(s.c_str(), "hello! ") == 0);

    s.append("world");
    assert(s.size() == 12);
    assert(strcmp(s.c_str(), "hello! world") == 0);

    s += "!!";
    assert(s.size() == 14);
    assert(strcmp(s.c_str(), "hello! world!!") == 0);

    s.clear();
    assert(s.size() == 0);
    assert(strcmp(s.c_str(), "") == 0);
}

void testCapacityFunctions() {
    tr::string s;
    assert(s.empty());

    s.resize(10, 'a');
    assert(s.size() == 10);
    assert(strcmp(s.c_str(), "aaaaaaaaaa") == 0);

    s.reserve(20);
    assert(s.capacity() >= 20);
}

void testAccessFunctions() {
    tr::string s("hello");
    assert(s[0] == 'h');
    s[0] = 'H';
    assert(strcmp(s.c_str(), "Hello") == 0);
}

void testRelationalOperators() {
    tr::string s1("hello");
    tr::string s2("world");
    assert(s1 < s2);
    assert(s1 <= s2);
    assert(s2 > s1);
    assert(s2 >= s1);
    assert(s1 != s2);

    tr::string s3("hello");
    assert(s1 == s3);
}

void testFindFunctions() {
    tr::string s("hello world");
    size_t pos = s.find('o');
    assert(pos == 4);

    pos = s.find("world");
    assert(pos == 6);
}

void testInsertFunctions() {
    tr::string s("hello");
    s.insert(2, 'l');
    assert(strcmp(s.c_str(), "helllo") == 0);

    s.insert(3, "oo");
    assert(strcmp(s.c_str(), "heloollo") == 0);
}

void testEraseFunctions() {
    tr::string s("hello world");
    s.erase(6, 5);
    assert(strcmp(s.c_str(), "hello ") == 0);
}

int main() {
    testConstructors();
    testAssignmentOperator();
    testModifyFunctions();
    testCapacityFunctions();
    testAccessFunctions();
    testRelationalOperators();
    testFindFunctions();
    testInsertFunctions();
    testEraseFunctions();

    std::cout << "All tests passed!" << std::endl;
    return 0;
}