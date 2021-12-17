#include "../include/shared/TestClass.h"
#include<iostream>

TestClass::TestClass() {
	age = 5;
}

TestClass::TestClass(int i) {
	age = i;
}

void TestClass::ShowAge() {
	std::cout << age << std::endl;
}
