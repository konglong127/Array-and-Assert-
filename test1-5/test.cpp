#include <iostream>
#include <string>
#include "Array.cpp"
#include "Assert.cpp"
using namespace std;

class Person {
private:
	Person() { }
	Person(const Person& person) { }
	static Person* p1;
public:
	static int count;
	static Person* create() {
		count++;
		return p1;
	}
};

int Person::count = 0;
Person* Person::p1 = new Person;

void test() {
	Person* p1 = Person::create();
	Person* p2 = Person::create();
	Person* p3 = Person::create();
	Person* p4 = Person::create();
	cout<<Person::count << endl;
}

class People {
public:
	int id;
	string name;
};

void test1() {
	using namespace AssertSpace;
	Array<int>* arr = new Array<int>(1);
	(*arr)
		.push(1).push(2).push(3)
		.unshift(4).unshift(5).unshift(6)
		.shift().pop().splice(3).insert(1,8);

	Array<int>* arr1 = new Array<int>(1);
	(*arr1)
		.push(1).push(2).push(3)
		.unshift(4).unshift(5).unshift(6)
		.shift().pop().splice(3).insert(1, 8);

	Assert<int,int>* ast = Assert<int,int>::init();

	ast->describe("数组测试","result")
		->SameTypeValidate("数组已用长度", (*arr).Length(), 4)
		->SameTypeValidate("数组总长度", (*arr).Size(), 101)
		->SameTypeValidate("数组容量",(*arr).Capacity(),404)
		->summary();

	int testArray[4] = { 5,8,4,1 };
	for (int i = 0; i < (*arr).Length();++i) {
		ast->describe("数组测试","result")
			->SameTypeValidate("数组测试", (*arr)[i],testArray[i])
			->summary();
	}

	Assert<bool, bool>* ast1 = Assert<bool, bool>::init();
	
	
	ast1->describe("数组比较", "result")
		->SameTypeValidate("arr==arr1", ((*arr) == (*arr1)), true)
		->SameTypeValidate("arr!=arr1", ((*arr) != (*arr1)), false)
		->SameTypeValidate("arr>=arr1", ((*arr) >= (*arr1)), true)
		->SameTypeValidate("arr<=arr1", ((*arr) <= (*arr1)), true)
		->SameTypeValidate("arr>arr1", ((*arr) > (*arr1)), false)
		->SameTypeValidate("arr<arr1", ((*arr) < (*arr1)), false)
		->summary();

	
	(*arr1).push(7).push(8).push(9);
	Array<int>* arr3 = new Array<int>(arr1);
	ast1->describe("数组比较", "result")
		->SameTypeValidate("arr3==arr1", ((*arr3) == (*arr1)), true)
		->summary();
	ast->describe("数组测试", "result")
		->SameTypeValidate("数组已用长度", (*arr3).Length(), 7)
		->SameTypeValidate("数组总长度", (*arr3).Size(), 101)
		->SameTypeValidate("数组容量", (*arr3).Capacity(), 404)
		->summary();

	(* arr3)[0] = 78;
	ast1->describe("数组比较", "all")
		->SameTypeValidate("arr[0]==arr1[0]", ((*arr3)[0] == (*arr1)[0]), false)
		->summary()->destroy();

	(*arr) = (*arr1);
	ast1->describe("数组比较", "result")
		->SameTypeValidate("arr==arr1", ((*arr) == (*arr1)), true)
		->summary();
	ast->describe("数组测试", "result")
		->SameTypeValidate("数组已用长度", (*arr).Length(), 7)
		->SameTypeValidate("数组总长度", (*arr).Size(), 101)
		->SameTypeValidate("数组容量", (*arr).Capacity(), 404)
		->summary();

	(*arr)[0] = 99;
	ast1->describe("数组比较", "all")
		->SameTypeValidate("arr[0]==arr1[0]", ((*arr)[0] == (*arr1)[0]), false)
		->summary()->destroy();
}

int main() {
	test();
	test1();
	system("pause");
	return EXIT_SUCCESS;
}