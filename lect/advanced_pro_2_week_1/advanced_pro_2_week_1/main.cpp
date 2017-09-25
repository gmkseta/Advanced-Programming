#include <iostream>


namespace my_first_namespace {
	int my_variable_in_namespace = 1;

}

int main() {

	std::cout << "d" << my_first_namespace::my_variable_in_namespace << std::endl;
	return 0;

}