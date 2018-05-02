#include<vld.h>
#include"DecartTree.h"

// ����� ��������� ����� ���������� ������� 

int const M = 30;

inline void PrintLine(void)
{
	for (int i = 0; i < M; i++)
		cout << "-";
	cout << endl;
}

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
	PrintLine();
	// ������ ���� ��-�� ������ �������� ������.
	cout << "Treap: ";
	PrintTreap(treap);
	cout << endl;
	PrintLine();

	// ���������� �� ��� ������
	Node* treap2;
	Node* treap3;	
	Split(treap, 4, treap2, treap3);

	cout << "Split example: " << endl;

	PrintTreap(treap2);
	cout << endl;

	PrintTreap(treap3);
	cout << endl;
	PrintLine();
	// ������� ������� � ���� ������

	cout << "Merge from the same treaps: " << endl;
	treap = Merge(treap2, treap3);

	PrintTreap(treap);
	cout << endl;
	RemoveTreap(treap);
	PrintLine();
	// -------------------------------
	treap = FromVector(array);
	// �������� � ������� ���������
	cout << "Remove last and 1st el-ts: " << endl;

	PrintTreap(treap);
	cout << endl;

	Remove(treap, 14);
	Remove(treap,0);

	PrintTreap(treap);
	cout << endl;
	PrintLine();
	cout << "Insert last and 1st el-ts: " << endl;

	treap = Add(treap, 0, 1);
	treap = Add(treap, 14, 2);

	PrintTreap(treap);
	cout << endl;

	PrintLine();
	cout << "insert new 5 el-ts in the end: " << endl;
	for (int i = 15; i < 20; ++i)
		treap = Add(treap, i, i - 14);
	
	PrintTreap(treap);
	cout << endl;

	// -------------------------------

	PrintLine();
	cout << "insert new el-ts in 2 and 9 positions: " << endl;

	treap = Add(treap, 2, 1000);
	treap = Add(treap, 9, 1010);

	PrintTreap(treap);
	cout << endl;

	RemoveTreap(treap);
	return 0;
}