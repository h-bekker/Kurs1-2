#include <stdio.h>
#include <string.h>

int a[100],b[100];

void transp(int *mas, int *ans, int k) {
	int j;
	int p=0, q=k;//q=strlen(mas);
	for (j=0; j<strlen(mas); j++)
		if (mas[j]>k) {
			ans[q]=mas[j];
			q--;
			}
		else {
			ans[p]=mas[j];
			p++;
			}
	ans[strlen(mas)]=0;
	}

int main(void) {
	int i,n;
	for (i=0; ; i++) {
		if (scanf("%d",&n)==1)
			a[i]=n;
		else {
			printf("Error!\n");
			break;
			}
		}
	scanf("%d",&n);
	transp(a,b,n);
	for (i=0; i<strlen(b); i++)
		printf("%d ",b[i]);
	printf("\n");
	return 0;
	}

	
