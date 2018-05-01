#ifndef DECART_TREE_H_INCLUDED
#define DECART_TREE_H_INCLUDED

// Decart Tree with implicit key

#pragma once

#include<cstdio>
#include<iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

using std::vector;

// ���� ����������� ������ �� �������� �����. ������� ������� - �� ������ �� ������
// ���� � ����� ����, ������ ����� �� ������ ������ ������ ��������� � ������
// � ������ ����. ������ � ��������� ������ ����� �������������� �� ������������
// "������" �������, ������� � ����������� ������ ��� ������ (�-�-�) ������.
struct Node
{
	int y;   // ��� � ������, "���������" �������
	int size;  // �������� ������ ���������

	int value; // �������� �������� � ����.

	Node* l;
	Node* r; // ��������� �� ������ � ������� ������
};

// �������� ������ ����. ����� �� ������ ���������������� ��� ���� ����, � ��� ����
// �� ������ ������ ���������� ������� ���, ��� �����. 
Node* NewNode(int value);

// ��������� ������� ���������. ������� �����������, ��� � ���������� �� ������� � ������
// ���� ��� �������� �� ������� ������.
int GetSize(Node* t);

// �������� ������� ���������. ��� �������� ���� ��������� ������ ���, ����� � ������� ����������
// �����-���� ��������� (�� ���� � ����� split � merge) ��� ����������� ������������ ������ ��������
// ��� �������.
// ������ ������� ������������, ��� ������� �������� ����� �������� �����������. ��� ��������������
// � ��������� split � merge �� ���� �� ������������ ������� (������� ����� ��������������� �� �������
// � ������ ����� ������ ���������)
void UpdSize(Node* t);

// ��� �������� ������� (merge) ������� ����� ����� ��, ��� � ��� ����������� ������ �� ������ �����:
// ��� �� ����� ������ ������� ������� (y), �� �� ������ ������������� ����������� �������� ������ �
// ����� � ������ �����������, ��, ��������� � ��� ������ ����� ���, � ��� "�������������" ���������
// ������ ������
Node* Merge(Node* t_1, Node* t_2);

// ��������� ������ �� ��� ��������� - ���� � ��������� � ����������� �������� [0..x), ������ - [x..t->sz)
// ����� ������� ������ ��������� ���������: ��������, ��������� ����� ��� ���, ���� ����� ��� ���������, ����
// ������� ������� ���������.
void Split(Node* t, int x, Node *&t1, Node *&t2);

// ���������� � �������� ��������� �� ������ - ����� �� ������������������ split/merge, ��� � � ���������� ������
// � ��� ���� ��������, ��� ������ �� ����� ���������, ��������, �������, ���� ���� �������� ����� �������
Node* Add(Node* t, int pos, int value);

Node* Remove(Node* t, int pos);

// �������� ������ �� ������� - ������ ������� �������� ������ � ������ ���������, ������������� ��
// ��������� ��������� �������.
Node* FromVector(const vector<int>& v);

// ��������� k-�� ��������, �� ����, ���������� ��������� k-� ���������� ���������� �
// ���������� ������ �� ������ �����
int GetValue(Node* t, int pos);

// ��������� ����� ������� [l..r] � ������ ������� (��� ������ ��������, ������������ ��� "��������", ������������ �
// ���������� ������)
Node* ToFront(Node* t, int left, int right);

// ������ ����� ������. ������ ������� ���� ������ ��� ������� �������� ������ ������,
// ������ ����, ����� ������ ��� ������������ get_value.
void PrintTreap(Node* t);

void RemoveTreap(Node* t);

#endif // DECART_TREE_H_INCLUDED
