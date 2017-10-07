#include <iostream>

using namespace std;

int* removeDuplicates(int *a, int length) {
	if (NULL == a)
		return NULL;
	int valid = 0, next = 0;
	for (int i = 1; i < length; i++){
		if (*(a + i) != *(a + valid)) {
			valid++;
			*(a + valid) = *(a + i);
		}
	}

	for (int i = valid + 1; i < length; i++)
		*(a + i) = 0;

	return a;
}

void print(int *a, int length) {
	for (int i = 0; i < length; i++)
		cout << *(a + i) << " ";
	cout << endl;
}

int main()
{
	int a[5] = {1,1, 2, 4, 4};

	int *b = removeDuplicates(a, 5);

	print(b, 5);

	system("pause");
	return 0;
}