#include <stdio.h>
#include <string.h>
#include <stdlib.h>

main() {
	float data[150][4] = {0, };
	char name[150][32];
	
	FILE *fp;
	char buf[256], *p;
	int row=0, col=0;
	
	fp = fopen("iris.csv", "r");
	fgets(buf,255,fp);
	
	while(1) {
		if(fgets(buf, 255, fp)==NULL) break;
		if(buf[strlen(buf)-1]=='\n') buf[strlen(buf)-1]=0;
		
		p = strtok(buf, ",");
		data[row][0] = atof(p);
		p = strtok(NULL, ",");
		data[row][1] = atof(p);
		p = strtok(NULL, ",");
		data[row][2] = atof(p);
		p = strtok(NULL, ",");
		data[row][3] = atof(p);
		p = strtok(NULL, ",");
		strcpy(name[row], p);
		
		row++;
	}
	
	fclose(fp);
	
	// print data
	for(row=0;row<150;row++) {
		printf("%03d> %.1f %.1f %.1f %.1f %s\n",
			row+1, data[row][0], data[row][1], data[row][2], data[row][3], name[row]);
	}
	
	
	/*****************************************
	첫번째 꽃과 나머지 꽃들간의 거리를 측정 
	*****************************************/
	int i, flower;
	float distance[150] = {0,};
	
	for(flower=0; flower<150; flower++) {
		for(i=0;i<4;i++)
			distance[flower] += pow(data[0][i] - data[flower][i], 2);
		distance[flower] = sqrt(distance[flower]);
	}
	
	for(flower=0; flower<150; flower++)
		printf("%03d 번째 꽃과의 거리는 %.2f 입니다\n", flower+1, distance[flower]);
}
