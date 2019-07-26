#include <stdio.h>

int main () {
	int yyyy, mm, dd, jumin, jumin2, xy, aa;
	char gender;
	
	scanf("%d-%d", &jumin, &jumin2);
	yyyy = jumin/10000;				//030410 => 03
	mm = (jumin%10000)/100;			//030410 % 10000 = 0410, 0410 / 100 = 04
	dd = (jumin%10000)%100;			//0410 % 100 = 100
	xy = jumin2/1000000;
	
	if(xy == 1) {
		yyyy = yyyy + 1900;
		gender = 'M';
	} else if(xy == 2) {
		yyyy = yyyy + 1900;
		gender = 'F';
	} else if(xy == 3) {
		yyyy = yyyy + 2000;
		gender = 'M';
	} else if(xy == 4) {
		yyyy = yyyy + 2000;
		gender = 'F';
	}
	
	printf("%.4d/%.2d/%.2d %c", yyyy, mm, dd, gender);
	
	return 0;
}
