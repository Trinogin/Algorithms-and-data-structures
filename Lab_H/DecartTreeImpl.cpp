#include"DecartTree.h"

Node* NewNode(int value)
{
	Node* result = new Node;
	result->y = rand();
	result->size = 1;     // �� ����, ����� ���� ����� ��� ��������� ������ �� ������ ����,
						  // � ������ ������ ������ ����� ����� 1.
	result->value = value;
	result->l = nullptr;
	result->r = nullptr;
	return result;
}

int GetSize(Node* t)
{
	if (t == nullptr)
		return 0;   // �������� ������ ������� ������ ������ ����.
	return t->size; // �������, ��� ������ ��������� �������������� ���������
}

void UpdSize(Node* t)
{
	if (t == nullptr)
		return;
	t->size = 1 + GetSize(t->l) + GetSize(t->r);
}

Node* Merge(Node* t_1, Node* t_2)
{
	if (t_1 == nullptr)
		return t_2;
	if (t_2 == nullptr)
		return t_1;
	if (t_1->y > t_2->y)
	{
		t_1->r = Merge(t_1->r, t_2);
		UpdSize(t_1);
		return t_1;
	}
	else
	{
		t_2->l = Merge(t_1, t_2->l);
		UpdSize(t_2);
		return t_2;
	}
}

void Split(Node* t, int x, Node *&t1, Node *&t2)
{
	if (t == nullptr)
	{
		t1 = nullptr;
		t2 = nullptr;
		return;
	}
	// �������, ��� ���������� ����� ������� ������� � ������ ������ ����� ������� � ������ ���������.
	// (�������������, ���� � ������ ������ �� ������ ������� ������ ���� ����� �����, ������ ��� �������
	// � �����). �������������, ���� ������ �������� ������ ��������� ������, ��� ������ ���������, ��
	// ��� ������� ���������� � ������ ������, � ��������� ��� ���� ����� ������ ���������.
	if (GetSize(t->l) < x)
	{
		// ������ � �� ����� ��������� ������ ����������� � ������ ������-���������, � ������ ��������� ����
		// ���������� ���������. ��� ������ ������ ��������� ����� ��� ������: ������ � ����� ��������� ��������
		// GetSize(t->l) + 1 ����, � ������ ��������� ���� ��������� ��� ������ ���������.
		Split(t->r, x - GetSize(t->l) - 1, t->r, t2);
		t1 = t;
	}
	else
	{
		// ������� ������� ��������� ������ ������� ���������, �������������, ��� ������ ����������� ��
		// ������ ������. ��� ���� ������ ��������� ������� �� �����.
		Split(t->l, x, t1, t->l);
		t2 = t;
	}
	UpdSize(t);
}

Node* Add(Node* t, int pos, int value)
{
	Node* t_1;
	Node* t_2;
	Split(t, pos, t_1, t_2);
	Node* new_tree = NewNode(value);
	return Merge(Merge(t_1, new_tree), t_2);
}

Node* Remove(Node* t, int pos)
{
	Node* t_1;
	Node* t_2;
	Node* t_3;
	Node* t_4;
	Split(t, pos, t_1, t_2);
	Split(t_2, pos + 1, t_3, t_4);
	t = Merge(t_1, t_4);
	delete t_3;
	t_3 = nullptr;
	return t;
}

Node* FromVector(const vector<int>& v)
{
	Node* result = nullptr;

	for (unsigned int i = 0; i < v.size(); ++i)
		result = Merge(result, NewNode(v[i]));

	return result;
}

int GetValue(Node* t, int pos)
{
	int my_idx = GetSize(t->l);
	if (pos < my_idx)
		return GetValue(t->l, pos);
	else if (pos == my_idx)
		return t->value;
	else
		return GetValue(t->r, pos - my_idx - 1);
}

Node* ToFront(Node* t, int left, int right)
{
	Node* t_1;
	Node* t_2;
	Node* t_3;
	Node* t_4;
	// ���� �� ������ ��� ���, ��� ��������������� ������� ��� ����������,
	// ������� "�������" �� ������ �������, ����� - �� �����.
	Split(t, right + 1, t_1, t_2);
	Split(t_1, left, t_3, t_4);
	// ������ "����������" ����� ��������� � ������ t4, ��, ��� ���� ����� - � t3,
	// ��� ������ - � t2.
	return Merge(Merge(t_4, t_3), t_2);
}

void PrintTreap(Node* t)
{
	if (t == nullptr)
		return;
	PrintTreap(t->l);
	cout << t->value << " ";
	PrintTreap(t->r);
}

void RemoveTreap(Node* t)
{
	while (GetSize(t))
		t = Remove(t, 0);
	t = nullptr;
}