/*

*/

#include "cryonet.h"


#define ZERO 			7156
#define SLOPE        0.0039
float TankPer=0;
float Meterdisplay_out;

extern float ER,ModeVar, ER_FreqAddToPhase;
extern float a[ARLEN];

/*
Input parameter: None
Return Value:
*/

int Control()
{
unsigned long int FreqCountNext,FreqCountPrev,FreqC;
unsigned long int ADCCounts;
long int ADCCountTank1Pr, ADCCountTank1Lev, ADCCountTank2Pr, ADCCountTank2Lev;
float f2v,integral,i1,i2,p1,p2,p1ini, p2ini, i1ini, i2ini, thp,thn,offsetP,offsetN;
int LockWindow,LockCount,calmode,error, AvDelCnt;
float OP, TrapezF, IntegErr, FreqAv, Th_Unlock,ERLast,der;
int unlockDelay,derc;
int count,i, pi_set,g,PhaseSignValue,integconst,start,iRet;


//calmode=calibrate();
//unlockDelay = 200;

  //	if(calmode==1)
		{
      Print("control  before LED!\r\n");
		X304_Init();
      Print("control after x304 init!\r\n");
		//SetDoLow();
       Print("control  before com install!\r\n");
        //	DelayMs(1000);
		InstallCom(cport,9600L,8,0,1);
	  //	InstallCom(commandport,115200L,8,0,1);
      Print("control  after comm install!\r\n");
		X304_Write_One_DO(0, 0);

		p1 = (ReadNVRAM(0))/100;

		i1=(ReadNVRAM(1))/100;

		Th_Unlock = ReadNVRAM(2)/10;

		derc= ReadNVRAM(3)/1000;

		offsetN=(ReadNVRAM(4))/100;

		offsetP=(ReadNVRAM(5))/100;

		integconst=(ReadNVRAM(6));

		LockWindow=(ReadNVRAM(7));

		while(1)
			{
         TankPer=0;
         	Print("control  before LED!\r\n");
				LedOn();
				DelayMs(200);
				LedOff();
            Print("control  after  LED!\r\n");
            ADCCountTank1Lev 	= Modbus();
            Print("control  after  modbus!\r\n");
            //ADCCountTank1Lev 	= Modbus2();
            //ADCCountTank2Pr 	= Modbus3();
           // ADCCountTank2Lev 	= Modbus4();
            TankPer =(ADCCountTank1Lev-ZERO)*SLOPE;
            if ((ADCCountTank1Lev-ZERO)<0)
                    TankPer=0;
             else
                     TankPer=TankPer;
            Meterdisplay_out= TankPer*0.01;

           // printCom(1,"ADC Value is=%u %u %u %u\n\r",ADCCountTank1Pr, ADCCountTank1Lev, ADCCountTank2Pr, ADCCountTank2Lev);

        	  //	OP = 10 * ADCCountTank1Lev / 65536;
            				  	X304_AnalogOut(0, Meterdisplay_out);

                           Print("ADCCountTank1Lev= %d\n",ADCCountTank1Lev);
                           Print("TankPer= %f\n",TankPer);

		}
}
}
