#include <stdio.h>
#include <string.h>

char str[100];
int dig[100];

int main(void) {
	int i, n, p=0, q=1, k=1;
	if (scanf("%99s",str)==1) {
		scanf("%d",&n);
		for (i=0; i<strlen(str); i++) {
			if ((str[i]<'0') || (str[i]>'9')) {
				printf("String with not digit\n");
				k=0;
				break;
				}
			}
		if (k==1) {
			for (i=0; i<strlen(str); i++)
				if ((str[i]-'0')>n) {
					printf("%d\n",str[i]-'0');
					dig[strlen(str)-q]=str[i]-'0';
					q++;
					}
				else {
					dig[p]=str[i]-'0';
					p++;
					}
			for (i=0; i<strlen(str); i++)
				printf("%d ",dig[i]);
			printf("\n");
			}
		}
	else
		printf("Error!\n");
	return 0;
	}
