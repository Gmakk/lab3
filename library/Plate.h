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
	Contact arr[Size];//элементы добавляются в конец
public:
	Plate() : size(0), arr{0}{};
	Plate(Plate& origin);//создает дублика переданного элемента
	Plate(int x, int y, int type);//конструктор, создающий только 1 контакт на плате
	Plate(int size, Contact arr[Size]);//переденный массив помещается в поле класса
	~Plate() = default;
	//методы
	inline Contact* getArr() { return arr; }//возвращает массив
	int addContact(int x, int y, int type);//добавление контакта
	int deleteContact();//удаляет последний контакт, если такой есть
	void showInfo() const;//вывод всех элементов
	int correctness(int number) const;//проверка корректности связи
	int addLink(int number1, int number2);//добавление связи с проверкой корректности
	void showGroup(bool type) const;//вывод определенного типа контактов
	double pathLength(int number1, int number2) const;//нахождение длины пути с проверкой корректности
	//унарные
	friend Plate& operator++(Plate& plate);//префиксный инкремент возвращает объект с добавленным контакатом(0,0,0)
	friend Plate operator++(Plate& plate, int i);//постфиксный инкремент аналогичен префиксному, но вовращает старую версию
	friend Plate& operator--(Plate& plate);//префиксный декремент удаляет элемент
	friend Plate operator--(Plate& plate, int i);//постфиксный декремент аналогичен префиксному, но вовращает старую версию
	//бинарные
	friend Plate& operator+=(Plate& left, const int right);//добавляет N контактов (0,0,0)
	friend Plate& operator-=(Plate& left, const int right);//удаляет N  последних контактов, если такие есть
	friend Plate* operator+(Plate& left, Plate& right);//создает новый элемент с контактами слагаемых
	friend bool operator!=(const Plate& left, const Plate& right);//
	friend bool operator==(const Plate& left, const Plate& right);//
	friend bool operator<(const Plate& left, const Plate& right);//
	friend bool operator<=(const Plate& left, const Plate& right);//	сравнивают количество контактов на платах
	friend bool operator>(const Plate& left, const Plate& right);//
	friend bool operator>=(const Plate& left, const Plate& right);//
	friend bool operator==(const Contact& left, const Contact& right);//проверяет корректность связи между контактами
	//ввод вывод
	friend std::ostream& operator<<(std::ostream& out, const Plate& plate);//вывод всех контактов класса
	friend std::istream& operator>>(std::istream& in, Plate& plate);//происходит ввод и добавление нового контакта

	Plate& operator=(Plate& right) {//левой плате присваивается размер и массив контактов правой
		if (this == &right) {//проверка на самоприсваивание
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
	Contact& operator[] (int index) {//возвращает элемент массива
		return arr[index];
	}
};