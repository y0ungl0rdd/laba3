
#include "DoubleList.cpp"
#include "catch.hpp"



TEST_CASE("Check_Constructor") {
	DoubleList<int> test;
	REQUIRE(test.back() == nullptr);
	REQUIRE(test.front() == nullptr);
}

TEST_CASE("Check_CopyConstr") {
	DoubleList<int> test;
	DoubleList<int> test2 = test;
	REQUIRE(test.front() == test2.front());
	REQUIRE(test.back() == test2.back());
}

TEST_CASE("push_front") {
	DoubleList<int> test;
	test.push_front(2);
	REQUIRE(test.front()->element == 2);
	REQUIRE(test.front()->NextEl == nullptr);
	test.push_front(3);
	REQUIRE(test.front()->element == 3);
	REQUIRE(test.front()->NextEl->element == 2);
}

TEST_CASE("push_back") {
	DoubleList<int> test;
	test.push_back(2);
	REQUIRE(test.back()->element == 2);
	REQUIRE(test.back()->NextEl == nullptr);
	test.push_back(3);
	REQUIRE(test.back()->element == 3);
	REQUIRE(test.front()->element == 2);
}

TEST_CASE("insert_") {
	DoubleList<int> test;
	test.insert(0, 2);
	REQUIRE(test.front()->element == 2);
	test.insert(test.size(), 4);
	REQUIRE(test.back()->element == 4);
	test.insert(1, 5);
	REQUIRE(test[1] == 5);
}

TEST_CASE("front_") {
	DoubleList<int> test;
	REQUIRE(test.front() == nullptr);
	test.push_front(2);
	REQUIRE(test.front()->element == 2);
}

TEST_CASE("back_") {
	DoubleList<int> test;
	REQUIRE(test.back() == nullptr);
	test.push_back(2);
	REQUIRE(test.back()->element == 2);
}

TEST_CASE("size_") {
	DoubleList<int> test;
	REQUIRE(test.size() == 0);
	test.push_back(3);
	test.push_back(2);
	test.push_back(4);
	REQUIRE(test.size() == 3);
}

TEST_CASE("[]_") {
	DoubleList<int> test;
	test.push_back(3);
	test.push_back(2);
	test.push_back(4);
	REQUIRE(test[1] == 2);
}

TEST_CASE("empty_") {
	DoubleList<int> test;
	REQUIRE(test.empty() == 1);
	test.push_back(2);
	REQUIRE(test.empty() == 0);
}

TEST_CASE("pop_front") {
	DoubleList<int> test;
	test.push_front(2);
	test.push_front(3);
	test.pop_front();
	REQUIRE(test.front()->element == 2);
}

TEST_CASE("pop_back") {
	DoubleList<int> test;
	test.push_back(2);
	test.push_back(3);
	test.pop_back();
	REQUIRE(test.back()->element == 2);
}

TEST_CASE("remove_") {
	DoubleList<int> test;
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