#include<vld.h>
#include"DecartTree.h"

// ����� ��������� ����� ���������� ������� 

int main(void)
{
	const int N = 15;
	vector<int> array;

	// ���������� ������� �� 15 ��������� � ������ �� 
	cout << "Array: ";
	for (int i = 0; i < N; ++i)
	{
		array.push_back(rand() % 100);
		cout << array[i] << " ";
	}
	cout << endl;

	// ���������� ������
	Node *treap = FromVector(array);
	

	// ������ ���� ��-�� ������ � ����������� ������� � �������� �� �������
	cout << "Treap: ";
	for (int i = 0; i < GetSize(treap); ++i)
		cout << GetValue(treap, i) << " ";
	cout << endl;
	// ������ ���� ��-�� ������ �������� ������.
	cout << "Treap: ";
	PrintTreap(treap);
	cout << endl;

	// ���������� �� ��� ������
	Node* treap2;
	Node* treap3;	
	Split(treap, 4, treap2, treap3);

	PrintTreap(treap2);
	cout << endl;

	PrintTreap(treap3);
	cout << endl;
	
	// ������� ������� � ���� ������
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