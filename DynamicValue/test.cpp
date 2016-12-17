#include "dynamic_value.h"
#include <iostream>
#include <string>

using namespace dynamic_value;
using namespace std;

template <typename T>
bool test_value(const T& value)
{
	try {
		DynamicValue d(value);
		if (!d.is_type_of<T>()) {
			cout << "Error: expected type " << typeid(T).name() << " but got " << d.type().name() << endl;
			return false;
		}
		if (value != d.get<T>()) {
			cout << "Error: expected value " << value << " but got " << d.get<T>() << endl;
		}
	} catch(std::exception e) {
		cout << "Exception: " << e.what() << endl;
	}
}

int main(int argc, char** argv)
{
	bool success = true;
	success = success && test_value<int>(123456);
	success = success && test_value<short>(123);
	success = success && test_value<char>('b');
	success = success && test_value<char*>("bobby bob");
	success = success && test_value<float>(12.8f);
	success = success && test_value<double>(123456789.0);

	cout << "Tests " << (success ? "passed" : "failed") << endl;

	return 0;
}