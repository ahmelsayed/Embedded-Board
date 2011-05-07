#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef ROBOTFUNCTIONS_H
#define ROBOTFUNCTIONS_H
void rPlaySong();
void rMoveForward();
void rMoveBackward();
void rStop();
void rMoveRight90();
void rMoveLeft90();
void rAction(char* recv_data);
void rSendCommand(unsigned char data[], int n);
#endif
