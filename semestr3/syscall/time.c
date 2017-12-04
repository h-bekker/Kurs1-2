#include <time.h>  
#include <stdio.h>  
#define SIZE 256   
int main ( void ) {  
char buffer [SIZE ];  
time_t curtime ;  
struct tm *loctime ;   

/* Get the current time . */  
curtime = time(NULL);   // кол-во секунд начиная с 1970

/* Convert it to local time representation . */  
loctime = localtime (&curtime );  

/* Print out the date and time in the standard format.*/ 
fputs(asctime(loctime ), stdout ); 

/* Print it out in a nice format . */ 
strftime (buffer , SIZE, "Today is %A, %B %d.\n", loctime ); // A-день недели, a-3 буквы недели, B-месяц, b-3 буквы месяца 
fputs (buffer , stdout ); // j - день, m - месяц года. U - номер недели в году. w - день недели. W - неделя в году. x - дата. X - время
strftime (buffer , SIZE, "The time is %I:%M %p.\n", loctime ); //c - дата и время, d - день месяца. H-24, I-12 часовая школа, M-минуты в часе
fputs (buffer , stdout ); // y - год в веке. Y - год. Z - имя часового пояса.
return 0; 

}
