#include<sys/types.h>
#include<stdio.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
int main(int argc,char* argv[]){
	if(argc<2 || argc>2){
		perror("Too many arguments");
	}
	char line[1025];
	int fp=open(argv[1],O_RDONLY,0);
	if(fp==-1){
		perror("Not able to open file");
		return 1;
	}
	int bytesRead,i=0,j=0;
	while((bytesRead=read(fp,line,1024))!=0){//read till EOF
		//this will read 1024 characters even if they are
		//in different lines
		char reversed[bytesRead];
		j=0;
		while(j<bytesRead){
			int k=0;
			while(j<bytesRead && line[j]!='\n'){
				reversed[k++]=line[j++];
			}
			if(j<bytesRead){
				reversed[k]=line[j];
				k++;j++;
			}
			char temp[k];//to store the reversed string
			int l=k-1,i=0;
			if(reversed[l]=='\n'){
				l--;
			}
			for(;l>=0;l--){
				temp[i++]=reversed[l];
			}
			if(reversed[k-1]=='\n'){
				temp[i]='\n';
			}
			write(1,temp,k);
		}
	}

}