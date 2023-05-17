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
// ����Ʈ �ʱ�ȭ �Լ�
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
		error("��ġ ����");
	return L->array[pos];
}
// ����Ʈ ���
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
	printf("�̵�Ƚ��:%d \n", count);
}

element delete(ArrayListType* L, int pos)
{
	element item;
	int count = 0;
	if (pos < 0 || pos >= L->size)
		error("��ġ ����");
	item = L->array[pos];
	for (int i = pos; i < (L->size - 1); i++){
		L->array[i] = L->array[i + 1];
		count++;
	}
	printf("\n������ ����: %d\n", item);
	printf("�̵�Ƚ��:%d\n", count);
	L->size--;
	return item;
}

int main(void) {
	ArrayListType list;
	init(&list);
	while (1)
	{
		int n;
		printf("=========�޴�=========\n");
		printf("1.����Ʈ�� �߰��ϴ� ���ڿ� ��ġ�� �Է� �޾Ƽ� ����Ʈ�� ����\n");
		printf("2.����Ʈ���� ������ ��ġ�� �Է� �޾Ƽ� ����\n");
		printf("3.����Ʈ�� ���ʷ� ���\n");
		printf("0.����\n");
		printf("��ȣ�� �����ϼ���: ");
		scanf_s("%d", &n);
		switch (n)
		{
		case 1:
			if (is_full(&list)) {
				printf("��ȭ�����Դϴ�.\n\n");
			}
			else {
				int a, b = 0;
				printf("\n������ ���ڿ� ��ġ�� �Է��ϼ���: ");
				scanf_s("%d %d", &a, &b);
			    insert(&list, b, a);
		
			}
			break;
		case 2:
			if (is_empty(&list)) {
				printf("��������Դϴ�.\n\n");
			}
			else {
				int a= 0;
				printf("������ ��ġ�� �Է��ϼ���: ");
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
			printf("�߸��� �Է��Դϴ�.\n\n");
			break;
		}
	}
	return 0;
}
 