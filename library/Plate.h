#pragma once
#include <iostream>
#include <cmath>

typedef struct Contact {
	bool type;//1-entrance / 0-output
	int x, y, number;//number-number of the associated contact / ==INT_MAX - no connection
}Contact;

Contact* new_size(int size_old, int size_new, Contact* arr);//�������� ��������� ���������� ��� ������ ������

class Plate
{
private:
	int size;//������� ���������� ���������
	Contact* arr;//�������� ����������� � �����
public:
	Plate();
	Plate(const Plate& origin);//������� �������� ����������� ��������
	Plate(Plate&& origin);//������������ �����������
	Plate(int x, int y, int type);//�����������, ��������� ������ 1 ������� �� �����
	Plate(int size, Contact* arr);//���������� ������ ���������� � ���� ������
	~Plate();
	//������
	inline Contact* getArr() { return arr; };//���������� ������
	inline int getSize() const { return size; };//���������� ������� ������
	inline void setSize(int new_s) { size = new_s; };//������ ����� ������
	int addContact(int x, int y, int type);//���������� ��������
	int deleteContact();//������� ��������� �������, ���� ����� ����
	void showInfo(std::ostream& out) const;//����� ���� ���������
	int correctness(int number) const;//�������� ������������ �����
	int addLink(int number1, int number2);//���������� ����� � ��������� ������������
	void showGroup(bool type, std::ostream& out) const;//����� ������������� ���� ���������
	double pathLength(int number1, int number2) const;//���������� ����� ���� � ��������� ������������

	//�������
	friend Plate& operator++(Plate& plate);//���������� ��������� ���������� ������ � ����������� ����������(0,0,0)
	friend Plate operator++(Plate& plate, int i);//����������� ��������� ���������� �����������, �� ��������� ������ ������
	friend Plate& operator--(Plate& plate);//���������� ��������� ������� �������
	friend Plate operator--(Plate& plate, int i);//����������� ��������� ���������� �����������, �� ��������� ������ ������
	//��������
	friend Plate& operator+=(Plate& left, const int right);//��������� N ��������� (0,0,0)
	friend Plate& operator-=(Plate& left, const int right);//������� N  ��������� ���������, ���� ����� ����
	friend Plate* operator+(const Plate& left, const Plate& right);//������� ����� ������� � ���������� ���������
	//���� �����
	friend std::ostream& operator<<(std::ostream& out, const Plate& plate);//����� ���� ��������� ������
	friend std::istream& operator>>(std::istream& in, Plate& plate);//���������� ���� � ���������� ������ ��������

	Plate& operator=(const Plate& right);//����� ����� ������������� ������ � ������ ��������� ������
	Plate& operator=(Plate&& right);//����� ����� ������������� ������ � ������ ��������� ������
	Contact& operator[] (int index);//���������� ������� �������
	const Contact& operator[] (int index) const;
};

//���������
bool operator!=(const Plate& left, const Plate& right);//
bool operator==(const Plate& left, const Plate& right);//
bool operator<(const Plate& left, const Plate& right);//
bool operator<=(const Plate& left, const Plate& right);//	���������� ���������� ��������� �� ������
bool operator>(const Plate& left, const Plate& right);//
bool operator>=(const Plate& left, const Plate& right);//
bool operator==(const Contact& left, const Contact& right);//��������� ������������ ����� ����� ����������