#include <stdio.h>
#include <sys/time.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char **argv)
{

	FILE *fp;
	int zero_byte_read;
	char buffer[256];
	double total_time = 0;
	double ave_time;
	double temp;
	struct timeval start;
	struct timeval end;
	
	/*
	I have tried to use iterations with 100, 1000, 10000 and 100000 respectively.
	When I run my program with iterations of 100000 multiple times, the results always
		have the form of 0.03xxxx.
	Most of the time, the result is in [0.030000, 0.039999].
	Thus, with the iterations of 100000, the average run-time is accurate and precise.
	*/
	int iterations = 100000;

	for (int i = 1; i < iterations; i++)
	{
		//open the file which has 1 string "Hello!" (quotation marks are excluded)
		fp = fopen("test.txt", "r"); 
		
		gettimeofday(&start, NULL); //start-time
		
		/*
		This function fread()
			- reads 1 item of data which is 0-byte long, from the stream pointed to by fp.
			- stores this item at the location given by buffer.
		*/
		zero_byte_read = fread(buffer, 0, 1, fp);
		
		gettimeofday(&end, NULL); //end-time
		
		//measure the run-time in seconds
		temp = (end.tv_sec * 1000000 + end.tv_usec) - (start.tv_sec * 1000000 + start.tv_usec);
		
		total_time += temp; //calculate the total run-time
		
		fclose(fp); //close the file
	}
	
	//average run-time of 100000 iterations
	ave_time = total_time / iterations;

	printf("%f seconds. \n", ave_time);
	
	return 0;
}
