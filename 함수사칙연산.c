#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int total_score = 0;
int n1, n2, inp;

int plus(n1, n2) {
	while (1) {
		printf("%d + %d = ", n1, n2);
		scanf("%d", &inp);
		if(inp == n1+n2) {
			printf("�����Դϴ�.\n");
			total_score++;
			break;
		}
		printf("�����Դϴ�.");
	}
}

int minus(n1, n2) {
	while(1) {
		if(n1 >= n2) {
			printf("%d - %d = ", n1, n2);
			scanf("%d", &inp);
			if(inp == n1 - n2) {
				printf("�����Դϴ�.\n");
				total_score++;
				return 0;
			}
			printf("�����Դϴ�.\n");
		}
		else {
			printf("%d - %d = ", n2, n1);
			scanf("%d", &inp);
			if(inp == n2 - n1) {
				printf("�����Դϴ�.\n");
				total_score++;
				return 0;
			}
			printf("�����Դϴ�.\n");
		}
	}
	
}

int mul(n1, n2) {
	while(1) {
		printf("%d �� %d = ", n1, n2);
		scanf("%d", inp);
		if(inp == n1 * n2) {
			printf("�����Դϴ�.\n");
			total_score++;
			return 0;
		}
			printf("�����Դϴ�.\n");
	}
	
}


int main() {
	int ch = 0;
	while(ch != 5) {
		printf("�ܼ� ��Ģ���� �����Դϴ�. ������ �������ּ���\n");
		printf("1. ����\n2. ����\n3. ����\n4. ������\n5. ����.\n");
		scanf("%d", &ch);
		
		srand(time(NULL));
		n1 = rand() % 1000;
		n2 = rand() % 1000;
		switch (ch) {
			case 1: plus(n1, n2); break;
			case 2: minus(n1, n2); break;
			case 3: n1 = rand() % 100; n2 = rand() % 100; mul(n1, n2); break;
			case 4: n1 = rand() % 100; n2 = rand() % 100; div(n1, n2); break;
		}	
	}
	
	printf("���� ���� ������ %d�� �Դϴ�.", total_score);
	return 0;
} 
