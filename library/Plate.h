#pragma once
#include <iostream>
#include <cmath>

#define Size 10

typedef struct Contact {
	bool type;//1-entrance / 0-output
	int x, y, number;//number-number of the associated contact / ==INT_MAX - no connection
	Contact() = default;
}Contact;

class Plate
{
	int size = 0;
	Contact arr[Size];//элементы добавляются в конец
public:
	Plate() = default;
	Plate(int size, Contact arr[Size]) {//переденный массив помещается в поле класса
		this->size = size;
		Contact* ptr_arr1 = arr;
		Contact* ptr_arr2 = this->arr;
		Contact* arr_end = ptr_arr1 + size;
		for (; ptr_arr1 != arr_end; ++ptr_arr1, ++ptr_arr2)
			*ptr_arr2 = *ptr_arr1;
	}
	~Plate() = default;

	int addContact(int x, int y, int type);//добавление контакта
	void showInfo();//вывод всех элементов
	int correctness(int number);//проверка корректности связи
	int addLink(int number1, int number2);//добавление связи с проверкой корректности
	void showGroup(int type);//вывод определенного типа контактов
	double pathLength(int number1, int number2);//нахождение длины пути с проверкой корректности
};