#include <stdio.h>
#include <string.h>

char wr[100],pr[100];	

int strlen1(char *str) {
	char *d=str;
	int s=0;
	while(*str++)
		s++;
	return s;
	}	

int strspn1(char *str1, char *str2) {
	char *p, *q=str1;
	int k=0, i=0, ans=strlen1(str1)-1;
	while ((*(q)!='\0') && (k==0)) {
		p=str2;
		while ((*(p)!='\0') && (k==0))
			if (*(q)==*(p)) {
				ans=i;
				k=1;
				}
			else
				*p++;
		*q++;
		i++;
		}
	return ans;
	}

int main(void) {
	int ans;
	if (scanf("%99s%99s",wr,pr)==2) {
			ans=strspn1(wr,pr);
			printf("%d\n",ans);
			}
	else
		printf("Error!\n");
	return 0;
	}
