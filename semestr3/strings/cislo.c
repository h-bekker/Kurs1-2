#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	int n, k, i, t, ans, len=0;
	char* str=NULL;
	scanf("%d",&n);
	k=n;
	while (k!=0) {
		k=k / 10;
		len++;
		}
	if (!(str=(char*) calloc (len+1,sizeof(char)))) {
		printf("Error\n");		
		return 0; 
		}
	str[len]='\0';
	k=n;
	i=1;
	while (k!=0) {
		t=k % 10;
		str[len-i]=t+'0';
		k=k / 10;
		i++;
		}
	i=0;
	ans=0;
	while (i<len) {
		if ((str[i]!='0') && (str[i]!='5'))
			ans=ans*10+(str[i]-'0');
		i++;
		}
	printf("%d\n",ans);
	}
