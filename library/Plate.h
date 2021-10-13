#pragma once
#include <iostream>
#include <cmath>

#define Size 10

typedef struct Contact {
	bool type;//1-entrance / 0-output
	int x, y, number;//number-number of the associated contact / ==INT_MAX - no connection
}Contact;

class Plate
{
	int size;
	Contact arr[Size];//�������� ����������� � �����
public:
	Plate() : size(0), arr{0}{};
	Plate(Plate& origin);//������� ������� ����������� ��������
	Plate(int x, int y, int type);//�����������, ��������� ������ 1 ������� �� �����
	Plate(int size, Contact arr[Size]);//���������� ������ ���������� � ���� ������
	~Plate() = default;
	//������
	inline Contact* getArr() { return arr; }//���������� ������
	int addContact(int x, int y, int type);//���������� ��������
	int deleteContact();//������� ��������� �������, ���� ����� ����
	void showInfo() const;//����� ���� ���������
	int correctness(int number) const;//�������� ������������ �����
	int addLink(int number1, int number2);//���������� ����� � ��������� ������������
	void showGroup(bool type) const;//����� ������������� ���� ���������
	double pathLength(int number1, int number2) const;//���������� ����� ���� � ��������� ������������
	//�������
	friend Plate& operator++(Plate& plate);//���������� ��������� ���������� ������ � ����������� ����������(0,0,0)
	friend Plate operator++(Plate& plate, int i);//����������� ��������� ���������� �����������, �� ��������� ������ ������
	friend Plate& operator--(Plate& plate);//���������� ��������� ������� �������
	friend Plate operator--(Plate& plate, int i);//����������� ��������� ���������� �����������, �� ��������� ������ ������
	//��������
	friend Plate& operator+=(Plate& left, const int right);//��������� N ��������� (0,0,0)
	friend Plate& operator-=(Plate& left, const int right);//������� N  ��������� ���������, ���� ����� ����
	friend Plate* operator+(Plate& left, Plate& right);//������� ����� ������� � ���������� ���������
	friend bool operator!=(const Plate& left, const Plate& right);//
	friend bool operator==(const Plate& left, const Plate& right);//
	friend bool operator<(const Plate& left, const Plate& right);//
	friend bool operator<=(const Plate& left, const Plate& right);//	���������� ���������� ��������� �� ������
	friend bool operator>(const Plate& left, const Plate& right);//
	friend bool operator>=(const Plate& left, const Plate& right);//
	friend bool operator==(const Contact& left, const Contact& right);//��������� ������������ ����� ����� ����������
	//���� �����
	friend std::ostream& operator<<(std::ostream& out, const Plate& plate);//����� ���� ��������� ������
	friend std::istream& operator>>(std::istream& in, Plate& plate);//���������� ���� � ���������� ������ ��������

	Plate& operator=(Plate& right) {//����� ����� ������������� ������ � ������ ��������� ������
		if (this == &right) {//�������� �� ����������������
			return *this;
		}
		size = right.size;
		Contact* ptr_arr1 = right.arr;
		Contact* ptr_arr2 = this->arr;
		Contact* arr_end = ptr_arr1 + size;
		for (; ptr_arr1 != arr_end; ++ptr_arr1, ++ptr_arr2)
			*ptr_arr2 = *ptr_arr1;
		return *this;
	}
	Contact& operator[] (int index) {//���������� ������� �������
		return arr[index];
	}
};