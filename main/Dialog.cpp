#include "Dialog.h"

int dialog(const char* msgs[], int N) {
	int rc;
	int i, n;
	do {
		for (i = 0; i < N; ++i)
			puts(msgs[i]);
		puts("Make your choice:");
		n = getValue(rc);
		if (n == 0)
			rc = 0;
	} while (rc < 0 || rc >= N);
	return rc;
}

int D_AddContact(Plate* plate) {
	int x, y, type;
	std::cout << "Enter the contact coordinates: " << std::endl;
	getValue(x);
	getValue(y); 
	std::cout << "Enter the contact type: " << std::endl;
	do {//ожидание корректного ввода типа
		getValue(type);
	} while (type != 0 && type != 1);
	if (plate->addContact(x, y, type) == -1) {
		std::cout << "There is no possibility to add a contact: " << std::endl;
		return -1;
	}
	return 1;
}
int D_Info(Plate* plate) {
	plate->showInfo();
	return 1;
}
int D_Correct(Plate* plate) {
	int number;
	std::cout << "Enter number of the contact: " << std::endl;
	getPositive(number);
	switch (plate->correctness(number))
	{
	case -1:
		std::cout << "The connection between the contacts is incorrect " << std::endl;
		break;
	case 1:
		std::cout << "The connection between the contacts is correct " << std::endl;
		break;
	case 2:   
		std::cout << "The contact is not connected " << std::endl;
		break;
	}
	return 1;
}
int D_AddLink(Plate* plate) {
	int number1, number2;
	std::cout << "Enter number of the first contact: " << std::endl;
	getPositive(number1);
	std::cout << "Enter number of the second contact: " << std::endl;
	getPositive(number2);
	return plate->addLink(number1, number2);
}
int D_Group(Plate* plate) {
	short number;
	std::cout << "Enter 0 for output, 1 for entrance, another number to exit: " << std::endl;
	getValue(number);
	if(number == 1 || number == 0)
		plate->showGroup(number);
	return 1;
}
int D_Length(Plate* plate) {
	int number1, number2;
	double result;
	std::cout << "Enter number of the first contact: " << std::endl;
	getPositive(number1);
	std::cout << "Enter number of the second contact: " << std::endl;
	getPositive(number2);
	result = plate->pathLength(number1, number2);
	if(result != -1)
		std::cout << "Distance between contacts is: " << result << std::endl;
	return 1;
}