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
			printf("정답입니다.\n");
			total_score++;
			break;
		}
		printf("오답입니다.");
	}
}

int minus(n1, n2) {
	while(1) {
		if(n1 >= n2) {
			printf("%d - %d = ", n1, n2);
			scanf("%d", &inp);
			if(inp == n1 - n2) {
				printf("정답입니다.\n");
				total_score++;
				return 0;
			}
			printf("오답입니다.\n");
		}
		else {
			printf("%d - %d = ", n2, n1);
			scanf("%d", &inp);
			if(inp == n2 - n1) {
				printf("정답입니다.\n");
				total_score++;
				return 0;
			}
			printf("오답입니다.\n");
		}
	}
	
}

int mul(n1, n2) {
	while(1) {
		printf("%d × %d = ", n1, n2);
		scanf("%d", inp);
		if(inp == n1 * n2) {
			printf("정답입니다.\n");
			total_score++;
			return 0;
		}
			printf("오답입니다.\n");
	}
	
}


int main() {
	int ch = 0;
	while(ch != 5) {
		printf("단순 사칙연산 문제입니다. 문제를 선택해주세요\n");
		printf("1. 덧셈\n2. 뺄셈\n3. 곱셈\n4. 나눗셈\n5. 종료.\n");
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
	
	printf("맞은 문제 갯수는 %d개 입니다.", total_score);
	return 0;
} 
