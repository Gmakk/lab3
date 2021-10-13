#include "Plate.h"

Plate::Plate(int x, int y, int type) :size(1) {//конструктор, создающий только 1 контакт на плате
	if (type != 0 && type != 1)
		throw std::exception("Incorrect type\n");
	arr[0].type = type;
	arr[0].x = x;
	arr[0].y = y;
	arr[0].number = INT_MAX;
};

Plate::Plate(int size, Contact arr[Size]) {//переденный массив помещается в поле класса
	if (size < 0 || size >= Size)
		throw std::exception("Incorrect size\n");
	this->size = size;
	Contact* ptr_arr1 = arr;
	Contact* ptr_arr2 = this->arr;
	Contact* arr_end = ptr_arr1 + size;
	for (; ptr_arr1 != arr_end; ++ptr_arr1, ++ptr_arr2)
		*ptr_arr2 = *ptr_arr1;
}

int Plate::addContact(int x, int y, int type) {
	if (size == Size || !(type == 1 || type == 0))
		return -1;
	//в конец добавляется новый элемент
	arr[size].x = x;
	arr[size].y = y;
	arr[size].type = type;
	arr[size].number = INT_MAX;
	//увеличивается количество занятых в массиве элементов
	size++;
	return 1;
}

int Plate::deleteContact() {
	if (size == 0)
		return -1;
	size--;
	return 1;
}

void Plate::showInfo() const {
	if (size == 0)
		std::cout << "Plate is empty" << std::endl;
	for (int i = 0; i < size; i++) {
		std::cout << "Number: " << i << "	Type: ";
		if (arr[i].type == 1)
			std::cout << "entrance";
		else
			std::cout << "output";
		std::cout << "	(x,y): " << '(' << arr[i].x << ',' << arr[i].y << ')';
		if (arr[i].number != INT_MAX) {
			std::cout << std::endl;
			if (arr[i].type == 1)
				std::cout << "Related output element: " << arr[i].number;
			else
				std::cout << "Related input element: " << arr[i].number;
		}
		std::cout << std::endl;
	}
}

int Plate::correctness(int number) const {
	//если такого контакта не существует
	if (number >= size)
		return 3;
	//нет связи
	if (arr[number].number == INT_MAX)
		return 2;
	//если номер связанного элемента соответсвует указанному с структуре
	if (arr[number].number != INT_MAX && arr[number].type != arr[arr[number].number].type)
		return 1;
	//некорректная связь
	return -1;

}

int Plate::addLink(int number1, int number2) {//с проверкой корректности
	//проверка на существование контаков
	if (number1 >= size) {
		std::cout << "Incorrect first contact number" << std::endl;
		return -1;
	}
	if (number2 >= size) {
		std::cout << "Incorrect second contact number" << std::endl;
		return -1;
	}
	//проверка на наличие уже имеющейся связи
	if (arr[number1].number != INT_MAX) {
		std::cout << "The first element already has a connection" << std::endl;
		return -1;
	}
	if (arr[number2].number != INT_MAX) {
		std::cout << "The second element already has a connection" << std::endl;
		return -1;
	}
	//проверка на соответствие типов
	if (arr[number1].type == 1) {
		std::cout << "The type of the first element is not suitable" << std::endl;
		return -1;
	}
	if (arr[number2].type == 0) {
		std::cout << "The type of the second element is not suitable" << std::endl;
		return -1;
	}
	arr[number1].number = number2;
	arr[number2].number = number1;
	return 1;
}

void Plate::showGroup(int type) const {
	for (int i = 0; i < size; i++) {
		if (arr[i].type == type) {
			std::cout << "Number: " << i << "	Type: ";
			if (arr[i].type == 1)
				std::cout << "entrance";
			else
				std::cout << "output";
			std::cout << "	(x,y): " << '(' << arr[i].x << ',' << arr[i].y << ')';
			std::cout << std::endl;
		}
	}
}

double Plate::pathLength(int number1, int number2) const {//с проверкой корректности
	//проверка на существование контаков
	if (number1 >= size) {
		std::cout << "Incorrect first contact number" << std::endl;
		return -1;
	}
	if (number2 >= size) {
		std::cout << "Incorrect second contact number" << std::endl;
		return -1;
	}
	//проверка на существование связи
	if (arr[number1].number == INT_MAX) {
		std::cout << "The first element is not connected to anything" << std::endl;
		return -1;
	}
	if (arr[number2].number == INT_MAX) {
		std::cout << "The second element is not connected to anything" << std::endl;
		return -1;
	}
	//проверка на наличие связи между двумя этими элементами
	if (arr[number1].number != number2 || arr[number2].number != number1) {
		std::cout << "There is no such connection" << std::endl;
		return -1;
	}
	return sqrt(pow(arr[number1].x - arr[number2].x, 2) + pow(arr[number1].y - arr[number2].y, 2));
}