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
}
