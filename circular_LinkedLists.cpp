#include <iostream>
#include "circular_LinkedLists.h"

int main() {
	LinkList<int> first;
	first.Push_front(11);
	first.Push_front(10);
	first.Push_front(9);
	first.Push_back(12);
	first.Push_back(13);
	first.Push_back(14);
	first.Delete(13);
	first.Reverse();
	first.PrintList();
	
	LinkList<char> first1;
	first1.Push_front('C');
	first1.Push_front('B');
	first1.Push_front('A');
	first1.Push_back('D');
	first1.Push_back('E');
	first1.Push_back('F');
	first1.Delete('D');
	first1.Reverse();
	first1.PrintList();

	system("pause");
	return 0;
}
