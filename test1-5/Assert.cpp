#include <iostream>
#include <string>
#include <vector>
using namespace std;

namespace AssertSpace {
	static vector<int> passArray;
	static vector<string> desc;
	static int TotalUse = 0;
	static string tagValue;

	template<class T, class V>
	class Assert {
	private:
		Assert() {}
		Assert(const Assert& ast) {}

		static int AssertCount;
		static int AssertPassed;

		static Assert* pAssert;
	public:
		static Assert* init();
		static Assert* describe(string desc, string tag = "all");
		static Assert* SameTypeValidate(string msg, T sameTypeInput, T sameTypeExpect);
		static Assert* MixTypeValidate(string msg, T input, V expect);
		static Assert* summary();
		static void destroy();
		~Assert() { }
	};

	template<typename T, typename V>
	int Assert<T, V>::AssertCount = 0;

	template<typename T, typename V>
	int Assert<T, V>::AssertPassed = 0;

	template<typename T, typename V>
	Assert<T, V>* Assert<T, V>::pAssert = new Assert();

	template<typename T, typename V>
	Assert<T, V>* Assert<T, V>::init() {
		AssertCount = 0;
		AssertPassed = 0;
		passArray.clear();
		desc.clear();
		return pAssert;
	}

	template<typename T, typename V>
	Assert<T, V>* Assert<T, V>::describe(string msg,string tag) {
		tagValue = tag;
		TotalUse++;
		cout << endl << "============ test begin ============" << endl << endl;

		if (tagValue == "all")
			cout << "第\"" << TotalUse << "\"次、 " << msg << endl << endl;
		else 
			cout << "第\"" << TotalUse <<"\"次、 测试" << endl << endl;
		return pAssert;
	}

	template<typename T, typename V>
	Assert<T, V>* Assert<T, V>::MixTypeValidate(string msg, T input, V expect) {
		desc.push_back(msg);
		AssertCount++;

		if(tagValue=="all")
		cout << "test" << AssertCount << ". input: \"" << input << "\" expect: \"" << expect << "\"" << endl;
		
		if (input == expect) {
			AssertPassed++;
			passArray.push_back(1);

			if (tagValue == "all")
			cout << "result: √ pass, test success. " << endl << endl;
		}
		else {
			passArray.push_back(0);

			if (tagValue == "all")
			cout << "result: × test error expect \"" << expect << "\", but get \"" << input << "\"" << endl << endl;
		}
		return pAssert;
	}

	template<typename T, typename V>
	Assert<T, V>* Assert<T, V>::SameTypeValidate(string msg, T sameTypeInput, T sameTypeExpect) {
		desc.push_back(msg);
		AssertCount++;

		if (tagValue == "all")
		cout << "test" << AssertCount << ". input: \"" << sameTypeInput << "\" expect: \"" << sameTypeExpect << "\"" << endl;
		
		if (sameTypeInput == sameTypeExpect) {
			AssertPassed++;
			passArray.push_back(1);

			if (tagValue == "all")
			cout << "result: √ pass, test success. " << endl << endl;
		}
		else {
			passArray.push_back(0);

			if (tagValue == "all")
			cout << "result: × test error expect \"" << sameTypeExpect << "\", but get \"" << sameTypeInput << "\"" << endl << endl;
		}
		return pAssert;
	}

	inline string judge(int num) {
		if (num)
			return " 通过√ ";
		else
			return " 未通过× ";
	}

	template<typename T, typename V>
	Assert<T, V>* Assert<T, V>::summary() {
		int j = 1;
		if (tagValue == "all")
		cout << "-------------- summary --------------" << endl << endl;
		
		for (vector<int>::iterator i = passArray.begin(); i != passArray.end(); ++i) {
			string str = judge(*i);
			cout << j << "." << str << desc.at(j - 1) << endl;
			++j;
		}

		cout << endl << "======== total: " << AssertCount << ", passed: " << AssertPassed << " ========" << endl << endl << endl;

		init();
		return pAssert;
	}

	template<typename T, typename V>
	void Assert<T, V>::destroy() {
		delete pAssert;
		pAssert = NULL;
		init();
	}
}