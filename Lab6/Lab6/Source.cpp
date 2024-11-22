#include<iostream>
#include<windows.h>

using namespace std;

template <class T>
void replaceElement(T arr[], int size, int index, T newElement)
{
	for (int i = 0; i < size; i++)
		if (i == index)
			arr[i] = newElement;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int intArr[] = { 1, 3, 5, 7, 12, 45, 46, 6, 34, 66, -4 };
	int size = sizeof(intArr) / sizeof(intArr[0]);

	cout << "Масив до змін: ";
	for (int i = 0; i < size; i++)
		cout << " " << intArr[i];

	replaceElement(intArr, size, 5, -76);
	replaceElement(intArr, size, 6, 343);
	replaceElement(intArr, size, 7, 99);
	cout << "\nМасив після змін: ";
	for (int i = 0; i < size; i++)
		cout << " " << intArr[i];

	string strArr[] = { "apple", "banana", "apricot", "cherry", "blackberry"};
	cout << "\n\nМасив до змін: ";
	size = sizeof(strArr) / sizeof(strArr[0]);
	for (int i = 0; i < size; i++)
		cout << " " << strArr[i];
	replaceElement(strArr, size, 1, string("kiwi"));
	replaceElement(strArr, size, 2, string("grapefruit"));
	cout << "\nМасив після змін: ";
	for (int i = 0; i < size; i++)
		cout << " " << strArr[i];

	return 0;
}