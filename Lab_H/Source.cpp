#include<vld.h>
#include"DecartTree.h"

// Здесь приведены тесты написанных функций 

int main(void)
{
	const int N = 15;
	vector<int> array;

	// Заполнение массива из 15 элементов и печать их 
	cout << "Array: ";
	for (int i = 0; i < N; ++i)
	{
		array.push_back(rand() % 100);
		cout << array[i] << " ";
	}
	cout << endl;

	// Заполнение дерева
	Node *treap = FromVector(array);
	

	// Печать всех эл-ов дерева с реализацией доступа к элементу по позиции
	cout << "Treap: ";
	for (int i = 0; i < GetSize(treap); ++i)
		cout << GetValue(treap, i) << " ";
	cout << endl;
	// Печать всех эл-ов дереве функцией печати.
	cout << "Treap: ";
	PrintTreap(treap);
	cout << endl;

	// Разделение на два дерева
	Node* treap2;
	Node* treap3;	
	Split(treap, 4, treap2, treap3);

	PrintTreap(treap2);
	cout << endl;

	PrintTreap(treap3);
	cout << endl;
	
	// Слияние обратно в одно дерево
	treap = Merge(treap2, treap3);

	PrintTreap(treap);
	cout << endl;
	RemoveTreap(treap);
	
	// -------------------------------
	treap = FromVector(array);

	PrintTreap(treap);
	cout << endl;

	RemoveTreap(treap);

	return 0;
}