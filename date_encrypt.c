#include <stdio.h>
#include <string.h>


int l=0;//global variable to keep track of shift value


void encrypt(char *message, int date[], int n) {
	int i=0;
	for(i=0;i<n;i++) {
		char c = message[i];
		int shift = date[l%6];//wrap around 0-5 when i is greater than 6
		//change characters only if it is a alphabet
		if (c>='a' && c<='z'){
			c = (char)((int)(c+ shift - 'a')%26 +'a');//take modulo with 26
			l++;// l is to keep track of the alphabets so we we take the next digit only when we encounter an alphabet
			
		}
		else if (c<='Z' && c>='A') { // c is uppercase alphabet
			c = (char)((int)(c+ shift - 'A')%26 +'A');
			l++;
		}
		message[i] = c;
	}
}


int main(int argc, char* argv[]) {
	char fileName[102];//2 extra char for null terminator and enter key press
	char outputFileName[105];//4 extra  chars for .ecp
	char message[10001];
	int i=0;


	printf("Enter the file name: ");
	fgets(fileName,101,stdin);//get the fileName
		
	//The issue with fgets is that it gets the enter key press as well so we have to remove it
	for(i=0;i<102;i++) {
		if(fileName[i]=='\n') {
			fileName[i]='\0';
		}
	}
	int date[] = {1,2,1,8,4,6};
	printf("Enter date in the format of 6 digit: ");
	for(i=0;i<6;i++) {
		scanf("%1d",&date[i]);
	}


	int n = strlen(fileName);
	for(i=0;i<n;i++){
		outputFileName[i] = fileName[i];
	}


	// append .ecp at end of output file name
	outputFileName[n] = '.';
	outputFileName[n+1] = 'e';
	outputFileName[n+2] = 'c';
	outputFileName[n+3] = 'p';
	outputFileName[n+4] = '\0';
	printf("Output file name: %s\n", outputFileName);

	FILE* fp = fopen(fileName, "r");//open the file for reading
	
	if(fp == NULL){// if file couldnot be opened
		printf("Error");
		return -1;
	}
	
	FILE* output = fopen(outputFileName, "w");//open file for writing


	while(!feof(fp)) { //scan until end of file
		//get words till file ends
		fgets(message, 10000, fp);
		encrypt(message, date, strlen(message));
		fprintf(output, "%s",message);
	}
}