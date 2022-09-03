// Advanced_tutorial.cpp : Defines the entry point for the application.
//

#include "Advanced_tutorial.h"



void myVector() {
	vector< string >  strings;

	strings.push_back("one");
	strings.push_back("two");
	strings.push_back("three");

	strings.reserve(1000);
	double capacity = strings.capacity();

	cout << capacity << endl;
	vector< vector<int> > grid(3, vector <int>(4, 3));
	for (vector< string >::iterator it = strings.begin(); it != strings.end(); it++)
	{
		cout << *it << endl;
	}

	grid[0].push_back(8);

	for (int r = 0; r < grid.size(); r++) {
		for (int c = 0; c < grid[r].size(); c++) {
			cout << grid[r][c] << flush;

		}
		cout << endl;
	}
}

void myList()
{
	list<int> num;
	num.push_back(10);
	num.push_back(9);
	num.push_back(8);
	num.push_front(1);

	list<int>::iterator it = num.begin();
	it++;
	num.insert(it, 3);
	
	for (list<int>::iterator it = num.begin(); it != num.end(); it++) {
		cout << *it << endl;
	}
	cout << "before erase" << endl;
	it++;
	num.erase(it);
	


	for (list<int>::iterator it = num.begin(); it != num.end(); it++) {


		if (*it == 8)
		{
			list<int>::iterator newit = num.insert(it, 345);
			cout << *newit << endl;
		}
		
		//cout << *it << endl;

	}


	cout << "printing all  " << endl;

	for (list<int>::iterator it = num.begin(); it != num.end(); it++) {
		cout << *it << endl;
	}


}

void myMap()
{
	map<string, string> address;
	address["naren"] = "peter";
	address["rishab"] = "vogil";
	address["kamal"] = "peter";
	address["sourab"] = "westentor";

	address.insert(pair<string,string> ("rahul","gjb"));

	for (map<string, string>::iterator it = address.begin(); it != address.end(); it++)
	{
		cout << it->first << ":" << it->second << endl;

	}

	cout << "multimap---" << endl;
	multimap<int, string> lookup;
	lookup.insert(make_pair(30, "Naren"));
	lookup.insert(make_pair(30, "Kamal"));
	lookup.insert(make_pair(30, "sourabh"));
	lookup.insert(make_pair(28, "Piu"));
	lookup.insert(make_pair(27, "Rishab"));

	pair<multimap<int, string>::iterator, multimap<int, string>::iterator> its = lookup.equal_range(30);
	for (multimap<int, string>::iterator it = its.first; it!=its.second; it++)
	{
		cout << it->first << ":" << it->second << endl;

	}



}

void myMap2()
{
	class Person {
	private:
		int age;
		string name;

	public:
		Person():name(""),age(0){}

		Person(string name, int age): name(name), age(age) {}

		void print() {
			cout << name << ":" << age << endl;
		}

		bool operator<(const Person& other) const {

			return name < other.name;
		}
	};

	map<int, Person> people;
	people[20] = Person("Naren", 30);
	people[30] = Person("kamak", 32);
	people[10] = Person("rishab", 27);
	bool i = people[30] < people[20];

	cout << "map with class ---" << endl;
	 cout << "people compare " << i << endl;
	for (map<int, Person>::iterator it = people.begin(); it != people.end(); it++)
	{
		cout << it->first << ":" << flush;
		it->second.print();
		

	}

}

void mySet()
{
	class Test {
	private:
		int id;
		string name;
	public:
		Test() : id(0), name("") {

		}

		Test(int id, string name) : id(id), name(name) {
		}

		void print () const
		{
			cout << id << ":" << name << endl;
		}

		// no copy just referenc the object thats why &, second const is for internal variables
		bool operator<(const Test &other) const {
			return id < other.id;
		}

	};


	set<Test> tests;
	tests.insert(Test(10, "Naren"));
	tests.insert(Test(20, "Piu"));
	tests.insert(Test(30, "Rishab"));
	tests.insert(Test(10, "Kamal"));
	tests.insert(Test(40, "Rishab"));

	for (set<Test>::iterator it = tests.begin(); it != tests.end(); it++)
	{
		it->print();
	}

}

void myStackQueue()
{
	class Test {
	private:
		string name;
	public:
		Test() : name("") {

		}

		~Test() {

		}

		Test(string name) :  name(name) {
		}

		void print() const
		{
			cout << name << endl;
		}

		// no copy just referenc the object thats why &, second const is for internal variables
		bool operator<(const Test& other) const {
			return name < other.name;
		}

	};

	stack<Test> testStack;

	testStack.push(Test("Naren"));
	testStack.push(Test("Piu"));
	testStack.push(Test("Yamini"));

	cout << "STACK VALUES" << endl;
	while (testStack.size() > 0) {
		Test& test = testStack.top();
		test.print();
		testStack.pop();
	}



}

void mySTL()
{
	map<string, vector<int>> scores;

	scores["Naren"].push_back(10);
	scores["Naren"].push_back(20);
	scores["Kamal"].push_back(20);
	scores["Piu"].push_back(30);

	for (map<string, vector<int>>::iterator it = scores.begin(); it != scores.end(); it++)
	{
		string name = it->first;
		vector<int> scoreList = it->second;
		cout << name << ":" << flush;

		for (int i = 0; i < scoreList.size(); i++)
		{
			cout << scoreList[i] << " " << flush;
		}
		cout << endl;

	}
}

void myOperatorOverloading()
{
	class Test {
	private:
		int id;
		string name;
	public:
		Test() :id(), name("") {

		}

		Test(const Test& other) {
			cout << "copy constructore running" << endl;
			id = other.id;
			name = other.name;

		}

		~Test() {

		}

		Test(int id, string name) :id(id), name(name) {
		}

		void print() const
		{
			cout << id << ":" << name << endl;
		}

		// no copy just referenc the object thats why &, second const is for internal variables
		bool operator<(const Test& other) const {
			return id < other.id;
		}

		const Test& operator=(const Test& other) {
			cout << "assignment running" << endl;
			id = other.id;
			name = other.name;
			return *this;
		}

		//shuld be in sepreate cpp file
		//friend ostream &operator<<(ostream &out, const Test &test) {
		//	out << test.id << ":" << test.name;
		//}

	};

	Test test1(10, "Naren");
	Test test2;

	test2 = test1;

	test2.print();

	Test test4 = test1;
	test4.print();

	cout << "cout overloading " << endl;
	//cout << test1 << endl;

}



void myTemplate()
{
	
	TestTemp<string,int> test1("template class",10);
	test1.print();
	printany<string,int>("template function ",5);

	printany("hello",5);
	show<double>();

}
void test() {
	cout << "pointer function" << endl;
}

void myFuctionPointer()
{
	
	void (*ptest)();
	ptest = test;
	(*ptest)();
	ptest();
}

void myObjectSlicing() {
	class Parent {
	public:
		Parent() {
		}

		Parent(const Parent& other) {
			cout << "copy parent" << endl;
		}
		virtual void print() {
			cout << "parent" << endl;
		}
	};

	class Child :public Parent {
	public:
		void print() {
			cout << "child" << endl;
		}
	};

	Child c1;
	c1.print();
	Parent& p1 = c1;
	p1.print();

	Parent p2 = Child();
	p2.print();

}

void myAbstractClasss()
{

	class Animal {
	public:
		virtual void speak() = 0;
		virtual void run() = 0;
	};

	// dog and no run so it is also an abstract class
	class Dog : public Animal {
	public:
		virtual void speak() {
			cout << "woof" << endl;
		}
	};

	class Labrador : public Dog {
	public:
		virtual void run() {
			cout << "Labradoor running" << endl;
		}
	};


	//Dog dog;
	//dog.speak();

	Labrador lab;
	lab.speak();
	lab.run();

}
void check(string text) {

}

void myFuntor()
{
	struct MatchTest {
		bool operator()(string &text) {
			return text == "lion";
		}
	};

	MatchTest pred;

	string value = "lion";

	cout << pred(value) << endl;
}

int main()
{
	cout << "vector----------------------" << endl;
	myVector();

	cout << "list----------------------" << endl;

	myList();

	cout << "map----------------------" << endl;
	myMap();

	myMap2();

	cout << "set----------------------" << endl;
	mySet();

	cout << "stack and queue----------------------" << endl;
	myStackQueue();

	cout << "mix stl----------------------" << endl;
	mySTL();

	cout << "operator overloading----------------------" << endl;
	myOperatorOverloading();

	cout << "template class----------------------" << endl;
	myTemplate();

	cout << "function pointer----------------------" << endl;
	myFuctionPointer();

	cout << "object slicing and polimorphism---------" << endl;
	myObjectSlicing();

	cout << "abstract class and pure virtual function---------" << endl;
	myAbstractClasss();

	cout << "Funtor-----------------------" << endl;
	myFuntor();
	return 0;
}
