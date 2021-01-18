#include <iostream>
#include "bin_tree.h"
#include "fucking_tree.h"

int main()
{
	/*Tree test;
	test.add_element(2);
	test.add_element(1,'l');
	auto t1 = test.get_leaf('l');
	t1.add_element(3,'l');
	test.print();
	cout << test.search(3).empty();
	cout << test.search(4).empty();
	test.delete_element('l');
	std::cout << std::endl;
	test.print();*/
	f_tree test;
	test.add_elem(2);
	test.add_leaf(3);
	test.add_leaf(4);
	test.add_leaf(5);
	auto temp  = test.search(4);
	temp.add_leaf(7);
	temp.add_leaf(10);
	test.print();
	temp.erase(temp.search(10));
	test.print();
	return 0;
}
