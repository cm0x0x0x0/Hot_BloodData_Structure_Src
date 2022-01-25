#include <stdio.h>
#include <string.h>
#include "PriorityQueue.h"

int StringPriorityComp(char * str1, char * str2)
{
	return strlen(str2) - strlen(str1);
}

int main(void)
{
	PQueue pq;
	PQueueInit(&pq, StringPriorityComp);

	PEnqueue(&pq, "abcd");
	PEnqueue(&pq, "abcde");
	PEnqueue(&pq, "123456");
	PEnqueue(&pq, "1a2a3a4");
	PEnqueue(&pq, "I am so happy");

	while(!PQIsEmpty(&pq))
		printf("%s \n", PDequeue(&pq));

	return 0;
}
