// friend.cpp
// ������������� �������
#include <iostream>
using namespace std;
///////////////////////////////////////////////////////////
class beta; // ����� ��� ���������� frifunc
class alpha
{
private:
	int data;
public:
	alpha() : data(3) { } // ����������� ���
	// ����������
	friend int frifunc(alpha, beta); // �������� (1) ������������� �������, �������� ����������� ������ 
};
///////////////////////////////////////////////////////////
class beta
{
private:
	int data;
public:
	beta() : data(7) { } // ����������� ���
	// ����������
	friend int frifunc(alpha, beta);  // �������� (2) ������������� �������, �������� ����������� ������ 
};
///////////////////////////////////////////////////////////

int frifunc(alpha a, beta b) // ����������� ������� 
{
	return (a.data + b.data);
}
//---------------------------------------------------------
int main()
{
	alpha aa;
	beta bb;
	cout << frifunc(aa, bb) << endl; // ����� �������
	return 0;
}