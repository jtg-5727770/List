#include <stdio.h>
#include <stdlib.h>

#define MAX_LIST_SIZE 100 

typedef int element; 
typedef struct {
	element array[MAX_LIST_SIZE]; 
	int size; 
} ArrayListType;

void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}
// 리스트 초기화 함수
void init(ArrayListType* L)
{
	L->size = 0;
}

int is_empty(ArrayListType* L)
{
	return L->size == 0;
}

int is_full(ArrayListType* L)
{
	return L->size == MAX_LIST_SIZE;
}

element get_entry(ArrayListType* L, int pos)
{
	if (pos < 0 || pos >= L->size)
		error("위치 오류");
	return L->array[pos];
}
// 리스트 출력
void print_list(ArrayListType* L)
{
	int i;
	for (i = 0; i < L->size; i++)
		printf("%d->", L->array[i]);
	printf("\n");
}

void insert(ArrayListType* L, int pos, element item)
{
	int count = 0;
	if (!is_full(L) && (pos >= 0) && (pos <= L->size)) {
		for (int i = (L->size - 1); i >= pos; i--) {
			L->array[i + 1] = L->array[i];
			count++;
		}
		L->array[pos] = item;
		L->size++;
	}
	printf("이동횟수:%d \n", count);
}

element delete(ArrayListType* L, int pos)
{
	element item;
	int count = 0;
	if (pos < 0 || pos >= L->size)
		error("위치 오류");
	item = L->array[pos];
	for (int i = pos; i < (L->size - 1); i++){
		L->array[i] = L->array[i + 1];
		count++;
	}
	printf("\n삭제한 숫자: %d\n", item);
	printf("이동횟수:%d\n", count);
	L->size--;
	return item;
}

int main(void) {
	ArrayListType list;
	init(&list);
	while (1)
	{
		int n;
		printf("=========메뉴=========\n");
		printf("1.리스트에 추가하는 숫자와 위치를 입력 받아서 리스트에 삽입\n");
		printf("2.리스트에서 삭제할 위치를 입력 받아서 삭제\n");
		printf("3.리스트를 차례로 출력\n");
		printf("0.종료\n");
		printf("번호를 선택하세요: ");
		scanf_s("%d", &n);
		switch (n)
		{
		case 1:
			if (is_full(&list)) {
				printf("포화상태입니다.\n\n");
			}
			else {
				int a, b = 0;
				printf("\n삽입할 숫자와 위치를 입력하세요: ");
				scanf_s("%d %d", &a, &b);
			    insert(&list, b, a);
		
			}
			break;
		case 2:
			if (is_empty(&list)) {
				printf("공백상태입니다.\n\n");
			}
			else {
				int a= 0;
				printf("삭제할 위치를 입력하세요: ");
				scanf_s("%d", &a);
				delete(&list, a);
			}
			break;
		case 3:
			print_list(&list);
			printf("\n");
			break;
		case 0:
			return 0;
		default:
			printf("잘못된 입력입니다.\n\n");
			break;
		}
	}
	return 0;
}
 