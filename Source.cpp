//Name: Theodor Giles
//Programming Assignment: 7- Templated List Enhancements
#include "LinkedList.h"

int basicintsort(const int& L, const int& R);
int basicstringsort(const char* const& L, const char* const& R);
void staticSum(int& x);
void ModulusDataBy(int& data1, int& data2);
void DivideDataBy(int& data1, int& data2);
template<class T>
void AddChar(T& data1, char& data2);
int main() {
	LinkedList<int> intlist = LinkedList<int>();
	intlist.PushBack(3);
	intlist.PushBack(386);
	intlist.PushBack(12);
	intlist.PushBack(40);
	intlist.PushBack(3547);
	intlist.PushBack(7000);
	intlist.PushBack(7);
	intlist.PushBack(124);
	intlist.Display();
	intlist.Reverse();
	intlist.Display();
	intlist.forEach(staticSum);
	intlist.Display();
	intlist.Sort(basicintsort);

	LinkedList<int> intlist2 = LinkedList<int>(6969);
	intlist2.PushBack(4356);
	intlist2.PushBack(6843);
	intlist2.PushBack(5640);
	intlist2.Display();
	int mod = 3;
	intlist2.forEach(ModulusDataBy, mod);
	intlist2.Display();

	LinkedList<const char*> charlist = LinkedList<const char*>();
	charlist.PushBack("all your base are belong to us");
	charlist.PushBack("you must construct additional pylons");
	charlist.PushBack("fortnite");
	charlist.PushBack("mister chef");
	charlist.Display();
	charlist.Sort(basicstringsort);
	charlist.Display();
	char add = 'f';
	charlist.forEach(AddChar, add);
	charlist.Display();

	LinkedList<const int> constintlist = LinkedList<const int>();
	constintlist.PushBack(40);
	constintlist.PushBack(2);
	constintlist.PushBack(1);
	constintlist.PushBack(87);
	constintlist.PushBack(27);

	return 0;
}
template<class T>
void AddChar(T& data1, char& data2) {
	cout << data1 << data2 << endl;
}
int basicintsort(const int& L, const int& R) {
	return (L - R);
}
int basicstringsort(const char* const& L, const char* const& R) {
	int i;
	for (i = 0; L[i] != '\0'; i++) {}
	int j;
	for (j = 0; R[j] != '\0'; j++) {}
	return (i - j);
}
void staticSum(int& x)
{
	static int sum = 0;
	sum += x;
	cout << sum << endl;
}
void ModulusDataBy(int& data1, int& data2) {
	data1 %= data2;
}
void DivideDataBy(int& data1, int& data2) {
	data1 /= data2;
}