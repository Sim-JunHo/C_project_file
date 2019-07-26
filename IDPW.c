#include <stdio.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
#define cls system("cls")
#define pause system("pause>nul")

void Delete() {
	int i;
	for(i = 5; i > 0; i--) {
		printf("%d초 후에 사라집니다.", i);
		Sleep(1000);
		printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
	}
	cls;
}

void encrypt() {
	int i, j, key, keysize = 0;
	char password[30], temp;
	FILE *keyvalue;
	
	cls;
	keyvalue = fopen("key.txt", "w+");
	
	srand(time(NULL));
	printf("비밀번호를 입력하세요 : ");
	scanf(" %s", password);
	
	/*for(i = 0; kbhit(); i++) {
		password[i] = getche();
	}
	pause;
	pause;
	*/
	
	cls;
	for(i = 0; i < strlen(password); i++) {
		key = rand() % 127;
		temp = password[i];
		password[i] += key;
		if(password[i] > 122) {
			password[i] -= 122;
			key -= 122;
		}
		if(password[i] < 33) {
			password[i] += 33;
			key += 33;
		}
		
		fprintf(keyvalue, "%4d", key);
		
		if((password[i] != 33 && password[i] < 42) || (password[i] != 42 && password[i] < 48) || (password[i] < 64 && password[i] >= 58) || (password[i] < 97 && password[i] > 90)) {
				/*keysize = 0;
				while(key > 0) {
					key/=10;
					keysize++;
				}
				for(j = 0; j < 3; j++) {
					fprintf(keyvalue, "\b");
				}*/
				fseek(keyvalue, -4, SEEK_CUR);
				password[i] = temp;
				i--;
		}
	}
	printf("새 비밀번호 : ");
	puts(password);
	fclose(keyvalue);
	Delete();
}

void decrypt() {
	int i, j, key[30];
	char pw[30];
	FILE *keyvalue;
	
	cls;
	keyvalue = fopen("key.txt", "r");
	printf("복호화할 암호를 입력하세요 : ");
	scanf(" %s", pw);
	
	/*for(i = 0; i < 30; i++) {
		fseek(keyvalue, 4*i, SEEK_SET);
		fscanf(keyvalue, "3d", &key[i]);
	}*/
	for(i = 0; i < strlen(pw); i++) {
	//	fgets(&key, 4, keyvalue);
		fscanf(keyvalue, "%4d ", &key[i]);
		pw[i] -= (int)key[i];
	}
	puts("");
	puts(pw);
	fclose(keyvalue);
	Delete();
}

int main() {
	int chk = 1;
	
	while(chk) {
		printf("1. 암호화\n2. 복호화\n0. 종료\n\n어떤 작업을 행하시겠습니까 : ");
		scanf("%d", &chk);
		switch(chk) {
			case 1 : encrypt(); break;
			case 2 : decrypt(); break;
		}
	}
	
	
	return 0;
}
