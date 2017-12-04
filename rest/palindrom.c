#include <stdio.h>
#include <string.h>	
#include <stdlib.h>
			
int palindrom(char* str) {
	int k,i;
	k=strlen(str);
	for (i=0; i<k/2; i++)
		if (*(str+i)!=(*(str+k-1-i)))
			return 0;
	printf("%s\n",str);
	return 1;
	}

int main() {
	int i,ans=0;
	char* str=NULL;
	if (!(str=(char*) calloc (4,sizeof(char)))) {
		printf("Error\n");
		return 0; 
		}
	for (i=11; i<=999; i++) {
		if (sprintf(str,"%d",i)==-1) {
			printf("Error\n");
			exit(1);
			}
		ans+=palindrom(str);
		}
	printf("%d\n",ans);
	return 0;
	}
