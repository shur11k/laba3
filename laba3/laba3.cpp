#include "stdafx.h"
#include <string.h>
#include <memory.h>
#include <stdlib.h>
#include <locale.h>

struct node
{
	char inf[256];
	struct node* next; // ссылка на следующий элемент 
};

struct node* last = NULL; // указатели на последний элементы списка

void push(const char* str) {
	node* tmp = (node*)malloc(sizeof(node));
	if (last == NULL) {
		last = tmp;
		strcpy_s(last->inf, str);
		last->next = NULL;
	}
	else {
		tmp->next = last;
		strcpy_s(tmp->inf, str);
		last = tmp;
	}
}

void pop() {
	if (last == NULL) {
		printf("Стэк пустой\n\n");
		return;
	}
	else if (last->next == NULL) {
		printf("Извлечённый элемент: %s\n\n", last->inf);
		free(last);
		last = NULL;
	}
	else {
		printf("Извлечённый элемент: %s\n", last->inf);
		node* tmp = last;
		last = last->next;
		free(tmp);
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "Russian");
	char com[10], data[256];
	while (1) {
		if (last != NULL) {
			node* tmp = last;
			printf("Стэк: ");
			while (1) {
				printf("%s ", tmp->inf);
				if (tmp->next == NULL) {
					printf("\n\n");
					break;
				}
				tmp = tmp->next;
			}
		}
		printf("Введите команду push или pop для работы с очередью. Чтобы выйти введите exit: ");
		scanf("%s", &com);
		printf("\n");
		if (!strcmp(com, "push")) {
			printf("Введите данные для помещения в стэк: ");
			scanf("%s", &data);
			printf("\n");
			push(data);
		}
		else if (!strcmp(com, "pop")) {
			pop();
		}
		else if (!strcmp(com, "exit")) {
			exit(0);
		}
		else {
			printf("Вы ввели команду неверно\n\n");
		}
	}
	return 0;
}