#include "Plate.h"

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

void Plate::showInfo() {
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
			if(arr[i].type == 1)
				std::cout << "Related output element: "<< arr[i].number;
			else
				std::cout << "Related input element: "<< arr[i].number;
		}
		std::cout << std::endl;
	}
}

int Plate::correctness(int number) {
	//если номер связанного элемента не соответсвует указанному с структуре
	if (arr[number].number != INT_MAX && arr[number].type != arr[arr[number].number].type)
		return 1;
	//корректная связь
	if(arr[number].number != INT_MAX)
		return -1;
	//нет связи
	if (arr[number].number == INT_MAX)
		return 2;
}

int Plate::addLink(int number1, int number2) {//с проверкой корректности
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
	arr[number1].type = 0;
	arr[number2].type = 1;
	return 1;
}

void Plate::showGroup(int type) {
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

double Plate::pathLength(int number1, int number2) {//с проверкой корректности
	int check = 0;
	if (arr[number1].number == INT_MAX) {
		std::cout << "The first element is not connected to anything" << std::endl;
		check = 1;
	}
	if (arr[number2].number == INT_MAX) {
		std::cout << "The second element is not connected to anything" << std::endl;
		check = 1;
	}
	if (arr[number1].number != number2 || arr[number2].number != number1) {
		std::cout << "There is no such connection" << std::endl;
		check = 1;
	}
	if (check == 1)
		return -1;
	return sqrt(pow(arr[number1].x - arr[number2].x, 2) + pow(arr[number1].y - arr[number2].y, 2));
}