#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>
#include <7188\7188xb.h>
#include <7188\X304.h>


#define cport			2
#define commandport		1
#define ARLEN			10
#define	TRUE			1
#define	FALSE			0

int Control();

unsigned int ModRTU(char* , int );

int Receive_MODData(int ,unsigned char* ,char);

unsigned int Modbus(void);

unsigned int Modbus2(void);

unsigned int Modbus3(void);

unsigned int Modbus4(void);

int calibrate();

float integrate(int);


