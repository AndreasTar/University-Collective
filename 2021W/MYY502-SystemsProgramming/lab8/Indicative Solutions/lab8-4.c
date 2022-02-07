// Endeiktiki Lysi tis Askisis 8.4 

#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>

int pfd[2];   /* Pipe: child will write, parent will read */


void parent(int N)
{
	int i, sum = 0, childres;

	close(pfd[1]);

	for (i = 1; i <= N/2; i++)   /* Sum first half */
		sum += i;

	read(pfd[0], &childres, sizeof(int));   /* Read result from child */
	close(pfd[0]);
	waitpid(-1, NULL, 0);   /* Wait for my child */

	/* To double-check, remember that 1+2+...+N = N(N+1)/2 */
	printf("Sum from 1 to %d = %d\n", N, sum+childres);
}


void child(int N)
{
	int i, sum = 0;

	close(pfd[0]);
	for (i = N/2+1; i <= N; i++)   /* Sum second half */
		sum += i;

	write(pfd[1], &sum, sizeof(int));   /* Send to father */
	close(pfd[1]);
}


int main(void)
{
	int N;

	if (pipe(pfd) < 0)   /* Create pipe */
	{
		perror("pipe(pfd)");
		exit(1);
	}

	do
	{
		printf("Give positive integer >= 2: ");
		scanf("%d", &N);
	}
	while (N < 2);

	if (fork() != 0)   /* Fork */
		parent(N);
	else
		child(N);
	return 0;
}