#include "RobotFunctions.h"
/*
Code 128 starts the serial control

Using with 128 132 puts the Create Robot in Full Mode
Full mode was used in all the functions because the robot we have has a faulty cliff senor, hence is unusable in Safe Mode
if your cliff sensor is working you should cosider using safe mode instead with 128 131
*/

void rSendCommand(unsigned char data[], int n)
{
	int i;
	for (i=0; i<n; i++)
	{
		putc(data[i], stdout);
		//fflush(stdout);
	}
}

void rAction(char* recv_data)
{
	if (strcmp(recv_data, "song") == 0)
		rPlaySong();
	else if (strcmp(recv_data, "f") == 0)
		rMoveForward();
	else if (strcmp(recv_data, "b") == 0)
		rMoveBackward();
	else if (strcmp(recv_data, "s") == 0)
		rStop();
	else if (strcmp(recv_data, "r") == 0)
		rMoveRight90();
	else if (strcmp(recv_data, "l") == 0)
		rMoveLeft90();
}

void rPlaySong()
{
	unsigned char tx_data[15] = {128, 132, 140, 0, 4, 62, 12, 66, 12, 69, 12, 74, 36, 141, 0};
	rSendCommand(tx_data, 15);
}

void rMoveForward()
{
	unsigned char tx_data[7] = {128, 132, 137, 1, 244, 128, 0};
	rSendCommand(tx_data, 7);
}

void rMoveBackward()
{
	unsigned char tx_data[7] = {128, 132, 137, 255, 156, 128, 0};
	rSendCommand(tx_data, 7);
}

void rStop()
{
	unsigned char tx_data[7] = {128, 132, 137, 0, 0, 0, 0};
	rSendCommand(tx_data, 7);
}

void rMoveRight90()
{
	unsigned char tx_data[7] = {128, 132, 137, 0, 100, 255, 255};
	rSendCommand(tx_data, 7);
}

void rMoveLeft90()
{
	unsigned char tx_data[7] = {128, 132, 137, 0, 100, 0, 1};
	rSendCommand(tx_data, 7);
}
