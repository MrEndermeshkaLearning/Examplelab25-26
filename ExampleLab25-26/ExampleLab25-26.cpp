#include <stdio.h>
#include <cstring>
#include <windows.h>
#include <locale.h>
//10

struct product {
	char name[30], timesafty[11], sort[30], timeofgettingout[11], timetobuy[11], cost[50], null[2];
};
product* products = (product*)malloc(sizeof(product));
void set(product &P);
void search(int n);
void get(product P);
void Delete(int i, int n);
void Sort(int n);
boolean String_Test(char* one, char* two);

int main()
{
	setlocale(LC_ALL, "RUS");
	int test;
	int n = 1, index;
	printf("Проверка роботы хотите?\nесли да любая цыфра кроме 0\n0, если не хотите\n");
	scanf_s("%d", &test);
	while (test != 0)
	{
		if (test != 0)
		{
			set(products[0]);


			printf("функции:\n------------------\n1 - добавить запись\n2 - ввывести структуру\n3 - поиск структуры по параметру\n4 - удалить из масива (если записей более одной)\n5 - Сортировать по параметру\n6  - Выход\n");
			switch (test)
			{
			case 1:
			{
				n++;
				products = (product*)realloc(products, n * sizeof(product));
				set(products[n - 1]);
				break;
			}
			case 2:
			{
				printf("\n| найменувание | стоимость | срок хранения | сорт | дата изготовления | Срок Годности |\n");
				for (int i = 0; i < n; i++) {
					get(products[i]);
				}
				break;
			}
			case 3:
			{

				printf("\n| найменувание | стоимость | срок хранения | сорт | дата изготовления | Срок Годности |\n");
				search(n);
				break;
			}
			case 4: {
				printf("Введите номер удаления записи о товаре в масиве:\n");
				scanf_s("%d", &index);
				if (index <= n && n > 1 && index > 0) {
					Delete(index - 1, n);
					n--;
				}
				else {
					printf("Такой записи не найдено\n");
				}
				break;
			}
			case 5:
			{
				Sort(n);
				break;
			}
			case 6:
			{
				printf("До побачення!\n");
				break;
			}
			default: {
				printf("Введіть число від 1 до 5 або 0");
				break;
			}
			}
		}
	}
}





void set(product &P) {
	gets_s(P.null);
	printf("Введите наименование товара\n");
	gets_s(P.name);
	printf("Введите стоимость товара\n");
	gets_s(P.cost);
	printf("Введите время хранения\n");
	gets_s(P.timesafty);
	printf("Введите сорт\n");
	gets_s(P.sort);
	printf("Введите дату выпуска\n");
	gets_s(P.timeofgettingout);
	printf("Введите срок годности\n");
	gets_s(P.timetobuy);
}
void get(product P)
{
	printf("| %s | %s | %s | %s | %s | %s | \n", P.name, P.cost, P.timesafty, P.sort, P.timeofgettingout, P.timetobuy);
}

void search(int n)
{
	int a;
	char tmp_str[100];
	printf(" Выберите параметр по которому ищем\n 1-название \n 2-стоимость \n 3-время хранения \n 4-сорт \n 5-Дата изготовления \n 6-срок годности\n");
	printf("другое-вийти\n");
	scanf_s("%d", &a);
	switch (a)
	{
	case 1:
	{
		printf("введите наименование товара\n");
		gets_s(tmp_str);
		for (int i = 0; i < n; i++) {
			if (!(strcmp(products[i].name, tmp_str))) {
				get(products[i]);
			}
		}
		break;
	}
	case 2:
	{
		printf("введите стоимость товара\n");
		gets_s(tmp_str);
		for (int i = 0; i < n; i++) {
			if (!(strcmp(products[i].cost, tmp_str))) {
				get(products[i]);
			}
		}
		break;
	}
	case 3:
	{
		printf("введите срок хранения\n");
		gets_s(tmp_str);
		for (int i = 0; i < n; i++) {
			if (!(strcmp(products[i].timesafty, tmp_str))) {
				get(products[i]);
			}
		}
		break;
	}
	case 4:
	{
		printf("введите сорт хранения\n");
		gets_s(tmp_str);
		for (int i = 0; i < n; i++) {
			if (!(strcmp(products[i].sort, tmp_str))) {
				get(products[i]);
			}
		}
		break;
	}
	case 5:
	{
		printf("введите дату выпуска\n");
		gets_s(tmp_str);
		for (int i = 0; i < n; i++) {
			if (!(strcmp(products[i].timeofgettingout, tmp_str))) {
				get(products[i]);
			}
		}
		break;
	}
	case 6:
	{
		printf("введите дату выпуска\n");
		gets_s(tmp_str);
		for (int i = 0; i < n; i++) {
			if (!(strcmp(products[i].timetobuy, tmp_str))) {
				get(products[i]);
			}
		}
		break;
	}
	default:
		break;
	}
}
void Delete(int i, int n) {
	for (; i < n - 1; i++) {
		products[i] = products[i + 1];
	}
	products = (product*)realloc(products, --n * sizeof(product));
}
boolean String_Test(char* one, char* two) {
	int n = strlen(one);
	if (strlen(two) < n) {
		n = strlen(two);
	}
	for (int i = 0; i <= n; i++) {
		if (one[i] > two[i]) {
			return true;
		}
	}
	return false;
}

void Sort(int n) {
	int a;
	printf(" Выберите параметр по которому ищем\n 1-название \n 2-стоимость \n 3-время хранения \n 4-сорт \n 5-Дата изготовления \n 6-срок годности\n");
	printf("другое-вийти\n");
	product tmp;
	scanf_s("%d", &a);
	switch (a)
	{
	case 1: {
		for (int i = 0; i < n; i++) {
			tmp = products[i];
			for (int j = i - 1; j >= 0 && String_Test(products[j].name, tmp.name); j--) {
				products[j + 1] = products[j];
				products[j] = tmp;
			}
		}
		break;
	}
	case 2: {
		for (int i = 0; i < n; i++) {
			tmp = products[i];
			for (int j = i - 1; j >= 0 && String_Test(products[j].cost, tmp.cost); j--) {
				products[j + 1] = products[j];
				products[j] = tmp;
			}
		}
		break;
	}
	case 3: {
		for (int i = 0; i < n; i++) {
			tmp = products[i];
			for (int j = i - 1; j >= 0 && String_Test(products[j].timesafty, tmp.timesafty); j--) {
				products[j + 1] = products[j];
				products[j] = tmp;
			}
		}
		break;
	}
	case 4: {
		for (int i = 0; i < n; i++) {
			tmp = products[i];
			for (int j = i - 1; j >= 0 && String_Test(products[j].sort, tmp.sort); j--) {
				products[j + 1] = products[j];
				products[j] = tmp;
			}
		}
		break;
	}
	case 5: {
		for (int i = 0; i < n; i++) {
			tmp = products[i];
			for (int j = i - 1; j >= 0 && String_Test(products[j].timeofgettingout, tmp.timeofgettingout); j--) {
				products[j + 1] = products[j];
				products[j] = tmp;
			}
		}
		break;
	}
	case 6: {
		for (int i = 0; i < n; i++) {
			tmp = products[i];
			for (int j = i - 1; j >= 0 && String_Test(products[j].timetobuy, tmp.timetobuy); j--) {
				products[j + 1] = products[j];
				products[j] = tmp;
			}
		}
		break;
	}
	default:
		break;
	}
	printf("\nВідсортовано\n");
}
