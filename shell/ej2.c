#include <xinu.h>
void produce (void), consume (void);
int32 num = 0;	/*Global variables are shared by all processes*/
/*---------------------------------------------------------------------
*	main - Example of unsynchronized producer and consumer processes
*---------------------------------------------------------------------
*/
void mainX(void){
	resume( create(consume, 4096, 20, "cons", 0)); 
	resume( create(produce, 4096, 20, "prod", 0));
}
/*---------------------------------------------------------------------
*	produce - Increment n 2000 times and exit
*---------------------------------------------------------------------
*/
void produce (void){
	int32 i;
	for(i=1;i<=2000; i++)
		num++;
}
/*---------------------------------------------------------------------
*	consume - Print n 2000 times and exit
*---------------------------------------------------------------------
*/
void consume (void){
	int32 i;
	for(i=1;i<=2000; i++)
		printf("The value of n is %d \n", num);
}
