#include <stdio.h>
typedef char brd[3][3];
void display(brd b);
int checkwin(brd b);
int main() {
	int player=0;
	int winner=0;
	int choice=0;
	int i,r,c;
	brd b={{'1','2','3'}, {'4','5','6'}, {'7','8','9'}};
	for (i=0; i<9 && winner==0; i++) {
		display(b);
		player=i%2+1;
		do {
			printf("Player %d ""hod: %c ", player, (player==1?'x':'o'));
			scanf("%d", &choice);
			r=--choice/3;
			c=choice%3;
		} while (choice<0 || choice>9 || b[r][c]>'9');
			b[r][c]=(player==1)?'x':'o';
		if (checkwin(b)) {
			winner=player;
			break;
			}
	}
	display(b);
	if (winner)
		printf("\nPlayer %d win\n",winner);
	else
		printf("\n it is draw\n");
	return 0;
}
void display(brd b) {
	int r,c;
	printf("\n");
	for (r=0; r<3; ++r) {
		if (r!=0)
			printf("---+---+---\n");
		for (c=0; c<3; ++c) {
                	if (c!=0)
                		printf("|");
			printf(" %c ", b[r][c]);
		}
	printf("\n");
	}
}

int checkwin(brd b) {
	char c, ch[3], cv[3]; // ch-гориз, cv-верт
	int row, col, k;
	c=b[0][0];
	if (c==b[1][1] && c==b[2][2])
		return 1;
	c=b[0][2];
	if (c==b[1][1] && c==b[2][0])
		return 1;
	for (k=0; k<3; ++k) {
		ch[k]=b[k][0];
		cv[k]=b[0][k];
	}
	for (row=0; row<3; ++row) {
		int t=1;
		for (col=0; col<3; ++col)
			t=t && (ch[row]==b[row][col]);
		if (t)
			return 1;
	}
        for (col=0; col<3; ++col) {
                int t=1;
                for (row=0; row<3; ++row)
                        t=t && (cv[col]==b[row][col]);
                if (t)
                        return 1;
        }
	return 0;
}

/*
	Правило 1: если игрок может немедленно выиграть, он это делает!
	Правило 2: если игрок не может немедленно выиграть, то нужно защититься!
*/

//////////компьютер//////////////////////////////////////////////////////////////
/*	for (i=0; i<9 && winner==0; i++) {
		display(b);
		player=i%2+1;
		switch (player) {
			case 1: choice=compmove(b,i);
				break;
			case 2: choice=compmove(b,i);
				break;
		}
		row=--choice/3;
		col=choice%3;
		b[row][col]=(player==1)?'x':'o';
		if (checkwin(b))
			winner=player;
}
int usermove(brd b, int m) {
	do {
		t=ch-1;
		r=t/3;
		c=t%3;
	} while(t<0 || t>8 || b[r][c]>'9');
	return ch;
}
int compmove(brd a, int m) {
	static int st=0;
	static const int pos[9]={5,1,3,5,7,9,2,4,6,8};
	brd b;
	char ch;
	int i,j,k,f=0;
	if (m==0)
		return 5;
        for (i=0; i<3; ++i)
                for (j=0; j<3; ++j)
			b[i][j]=a[i][j];
//rule1:
	for (i=0; i<3; ++i)
	        for (j=0; j<3; ++j)
			if (b[i][j]<='9') {
				ch=b[i][j];
				b[i][j]='x';
				f=checkwin(b);
				if (f)
					return i*3+j+1;
				else
					b[i][j]=ch;
			}
//rule2:
        for (i=0; i<3; ++i)
                for (j=0; j<3; ++j)
                        if (b[i][j]<='9') {
                                ch=b[i][j];
                                b[i][j]='o';
                                f=checkwin(b);
                                if (f)
                                        return i*3+j+1;
                                else
                                        b[i][j]=ch;
                        }
	if (m==2) {
        	for (i=0; i<3; ++i)
	                for (j=0; j<3; ++j)
				if (b[i][j]=='o') {
					if ((i+j)%2==1) {
						st=3*i+j;
						if ((i==0 && j==1) || (i==1 && j==0))
							return 1;
						if ((i==1 && j==2) || (i==2 && j==1))
                                                        return 9;
                                         }
				}
	}
	if (m==4 && st) {
		switch (st) {
			case 1: return 4;
			case 3: return 2;
			case 5: return 8;
			case 7: return 6;
		}
	}
	for (k=0; k<9; ++k) {
		int l=pos[k], t=l-1;
		i=t/3;
		j=t%3;
		if (b[i][j]<='9')
			return l;
	}
*/
