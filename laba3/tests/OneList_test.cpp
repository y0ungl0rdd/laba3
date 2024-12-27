#define CATCH_CONFIG_MAIN
#include "OneList.cpp"
#include "catch.hpp"



TEST_CASE("Check Constructor") {
	OneList<int> test;
	REQUIRE(test.back() == nullptr);
	REQUIRE(test.front() == nullptr);
}

TEST_CASE("Check CopyConstr") {
	OneList<int> test;
	OneList<int> test2 = test;
	REQUIRE(test.front() == test2.front());
	REQUIRE(test.back() == test2.back());
}

TEST_CASE("push front") {
	OneList<int> test;
	test.push_front(2);
	REQUIRE(test.front()->element == 2);
	REQUIRE(test.front()->NextEl == nullptr);
	test.push_front(3);
	REQUIRE(test.front()->element == 3);
	REQUIRE(test.front()->NextEl->element == 2);
}

TEST_CASE("push back") {
	OneList<int> test;
	test.push_back(2);
	REQUIRE(test.back()->element == 2);
	REQUIRE(test.back()->NextEl == nullptr);
	test.push_back(3);
	REQUIRE(test.back()->element == 3);
	REQUIRE(test.front()->element == 2);
}

TEST_CASE("insert") {
	OneList<int> test;
	test.insert(0, 2);
	REQUIRE(test.front()->element == 2);
	test.insert(test.size(), 4);
	REQUIRE(test.back()->element == 4);
	test.insert(1, 5);
	REQUIRE(test[1] == 5);
}

TEST_CASE("front") {
	OneList<int> test;
	REQUIRE(test.front() == nullptr);
	test.push_front(2);
	REQUIRE(test.front()->element == 2);
}

TEST_CASE("back") {
	OneList<int> test;
	REQUIRE(test.back() == nullptr);
	test.push_back(2);
	REQUIRE(test.back()->element == 2);
}

TEST_CASE("size") {
	OneList<int> test;
	REQUIRE(test.size() == 0);
	test.push_back(3);
	test.push_back(2);
	test.push_back(4);
	REQUIRE(test.size() == 3);
}

TEST_CASE("[]") {
	OneList<int> test;
	test.push_back(3);
	test.push_back(2);
	test.push_back(4);
	REQUIRE(test[1] == 2);
}

TEST_CASE("empty") {
	OneList<int> test;
	REQUIRE(test.empty() == 1);
	test.push_back(2);
	REQUIRE(test.empty() == 0);
}

TEST_CASE("pop front") {
	OneList<int> test;
	test.push_front(2);
	test.push_front(3);
	test.pop_front();
	REQUIRE(test.front()->element == 2);
}

TEST_CASE("pop back") {
	OneList<int> test;
	test.push_back(2);
	test.push_back(3);
	test.pop_back();
	REQUIRE(test.back()->element == 2);
}

TEST_CASE("remove") {
	OneList<int> test;
	test.push_back(2);
	test.push_back(3);
	test.push_back(4);
	test.remove(2);
	REQUIRE(test.front()->element == 3);
	test.remove(4);
	REQUIRE(test.back()->element == 3);
	test.push_front(2);
	test.push_back(3);
	test.push_back(4);
	test.remove(3);
	REQUIRE(test.front()->NextEl->element == 4);

}