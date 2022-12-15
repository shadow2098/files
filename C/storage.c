/*
Сделать в программе хранилище пользователей сайта. 
Каждый пользователь описывается числовыми данными - 
	рост, вес, год рождения и баланс. 
Все эти данные о пользователе нужно хранить в структуре (struct). 
Все пользователи будут храниться в большом массиве структур 
	(User arr[], где User - это структура)
Добавить функции для фильтрации по каждому из параметров пользователя 
(вывести всех пользователей у которых баланс больше какого-то числа, 
	у которых рост меньше какого-то числа)
*/

#include <stdio.h>

struct User_storage {
	int age;
	int weight;
	int height;
	int birth_year;
	int balance;
};
typedef struct User_storage User;






int main() {

	int num;
	for (int i = 0; i < 2; ++i) {
		printf("Please, insert data for user creation: \n");

		printf("Please insert age: ");
		scanf("%d", &num);

		printf("Please insert weight: ");
		scanf("%d", &num);

		printf("Please insert height: ");
		scanf("%d", &num);

		printf("Please insert birth_year: ");
		scanf("%d", &num);

		printf("Please insert balance: ");
		scanf("%d", &num);
	}

	return 0;
}