#include "cryonet.h"



float ER,ModeVar, ER_FreqAddToPhase;
float a[ARLEN];


unsigned int ModRTU(char* buf, int len)
{
  unsigned int crc = 0xFFFF;
  int pos,i;
  for (pos = 0; pos < len; pos++) {
    crc ^= (unsigned int)buf[pos];          // XOR byte into least sig. byte of crc

    for (i = 8; i != 0; i--) {    // Loop over each bit
      if ((crc & 0x0001) != 0) {      // If the LSB is set
        crc >>= 1;                    // Shift right and XOR 0xA001
        crc ^= 0xA001;
      }
      else                            // Else LSB is not set
        crc >>= 1;                    // Just shift right
    }
  }
  // Note, this number has low and high bytes swapped, so use it accordingly (or swap bytes)
  return crc;
}


//------Supporting function to read the response of counter module from COM 2------
int Receive_MODData(int iPort,unsigned char* cInBuf,char cTerminator)
{
    /*
    Uses COM port to receive data with a terminative char.

    iPort:    COM port number to receive data.
              0:COM0, 1:COM1, 2:COM2  .....
    *cInBuf:  Input buffer to receive data(7 bytes).
    cTerminator: what is the last byte ?

    return: >0 :length of received data
             0 :doen't receive any data
    */
    unsigned char cChar;
    int iIndex=0;

    if(IsCom(iPort))
    {
            while(IsCom(iPort)) //check COM port
            {
                cChar=ReadCom(iPort);
                if(cChar==cTerminator) /* the terminal char is 0x0D */
                {
                    cInBuf[iIndex]=0;  /* Add the zero end to the data. */
                    return iIndex;     /* return data length                */
                                       /* (doesn't include the cTerminator) */
                }
                else	cInBuf[iIndex++]=cChar;
            }
            cInBuf[iIndex]=0; /* Add the zero end to the data. */
            return iIndex;  /* receive data timeout */
    }
    else	return 0;
}

//----------The Receive function for counter response ends here------------


//---------Primary Function to send a message(encoded with MODBUS protocol) to 7080 & receive response--------

unsigned int Modbus(void)
{
	int iLength;
	unsigned char response[10];
	unsigned char cmd[8];
	unsigned char check1[5];
	unsigned char check2[2];
   unsigned int check3;
	cmd[0]=0x11;       //adress
	cmd[1]=0x04;       //command
	cmd[2]=0x00;
	cmd[3]=0x00;
	cmd[4]=0x00;
	cmd[5]=0x01;
	cmd[6]=0x33;   //crc
	cmd[7]=0x5A;   //crc
	while(1)
	{
		ToComBufn(cport,cmd,8);
		while(1)
		{
			if(IsCom(cport))
			{
				iLength=Receive_MODData(cport,response,0x0D);
				/*
				check1[0]=response[0];
				check1[1]=response[1];
				check1[2]=response[2];
				check1[3]=response[3];
				check1[4]=response[4];
				check2[0]=response[5];
				check2[1]=response[6];
				check3=ModRTU(check1, iLength-2);
				if((unsigned int)check2[0]==(unsigned int)(check3%256) && (unsigned int)check2[1]==(unsigned int)(check3/256))
				{
					*/
					//Print("\n\r%c" , response[5]);
					return ((unsigned int)((unsigned char) response[3]*256 + (unsigned char) response[4]));
				//}
				//else break;
			}
		}
	}
}

unsigned int Modbus2(void)
{
	int iLength;
	unsigned char response[10];
	unsigned char cmd[8];
	unsigned char check1[5];
	unsigned char check2[2];
		unsigned int check3;
	cmd[0]=0x02;
	cmd[1]=0x04;
	cmd[2]=0x00;
	cmd[3]=0x01;
	cmd[4]=0x00;
	cmd[5]=0x01;
	cmd[6]=0x60;
	cmd[7]=0x39;
	while(1)
	{
		ToComBufn(cport,cmd,8);
		while(1)
		{
			if(IsCom(cport))
			{
				iLength=Receive_MODData(cport,response,0x0D);
				/*
				check1[0]=response[0];
				check1[1]=response[1];
				check1[2]=response[2];
				check1[3]=response[3];
				check1[4]=response[4];
				check2[0]=response[5];
				check2[1]=response[6];
				check3=ModRTU(check1, iLength-2);
				if((unsigned int)check2[0]==(unsigned int)(check3%256) && (unsigned int)check2[1]==(unsigned int)(check3/256))
				{
					*/
					//Print("\n\r%c" , response[5]);
					return ((unsigned int)((unsigned char) response[3]*256 + (unsigned char) response[4]));
				//}
				//else break;
			}
		}
	}
}

unsigned int Modbus3(void)
{
	int iLength;
	unsigned char response[10];
	unsigned char cmd[8];
	unsigned char check1[5];
	unsigned char check2[2];
		unsigned int check3;
	cmd[0]=0x02;
	cmd[1]=0x04;
	cmd[2]=0x00;
	cmd[3]=0x02;
	cmd[4]=0x00;
	cmd[5]=0x01;
	cmd[6]=0x90;
	cmd[7]=0x39;
	while(1)
	{
		ToComBufn(cport,cmd,8);
		while(1)
		{
			if(IsCom(cport))
			{
				iLength=Receive_MODData(cport,response,0x0D);
				/*
				check1[0]=response[0];
				check1[1]=response[1];
				check1[2]=response[2];
				check1[3]=response[3];
				check1[4]=response[4];
				check2[0]=response[5];
				check2[1]=response[6];
				check3=ModRTU(check1, iLength-2);
				if((unsigned int)check2[0]==(unsigned int)(check3%256) && (unsigned int)check2[1]==(unsigned int)(check3/256))
				{
					*/
					//Print("\n\r%c" , response[5]);
					return ((unsigned int)((unsigned char) response[3]*256 + (unsigned char) response[4]));
				//}
				//else break;
			}
		}
	}
}

unsigned int Modbus4(void)
{
	int iLength;
	unsigned char response[10];
	unsigned char cmd[8];
	unsigned char check1[5];
	unsigned char check2[2];
		unsigned int check3;
	cmd[0]=0x02;
	cmd[1]=0x04;
	cmd[2]=0x00;
	cmd[3]=0x03;
	cmd[4]=0x00;
	cmd[5]=0x01;
	cmd[6]=0xC1;
	cmd[7]=0xF9;
	while(1)
	{
		ToComBufn(cport,cmd,8);
		while(1)
		{
			if(IsCom(cport))
			{
				iLength=Receive_MODData(cport,response,0x0D);
				/*
				check1[0]=response[0];
				check1[1]=response[1];
				check1[2]=response[2];
				check1[3]=response[3];
				check1[4]=response[4];
				check2[0]=response[5];
				check2[1]=response[6];
				check3=ModRTU(check1, iLength-2);
				if((unsigned int)check2[0]==(unsigned int)(check3%256) && (unsigned int)check2[1]==(unsigned int)(check3/256))
				{
					*/
					//Print("\n\r%c" , response[5]);
					return ((unsigned int)((unsigned char) response[3]*256 + (unsigned char) response[4]));
				//}
				//else break;
			}
		}
	}
}


unsigned int ModReadMulti(void)
{
	int iLength;
	unsigned char response[10];
	unsigned char cmd[8];
	unsigned char check1[5];
	unsigned char check2[2];
	unsigned int check3;
	cmd[0]=0x02;
	cmd[1]=0x04;
	cmd[2]=0x00;
	cmd[3]=0x00;
	cmd[4]=0x00;
	cmd[5]=0x01;
	cmd[6]=0x31;
	cmd[7]=0xF9;
	while(1)
	{
		ToComBufn(cport,cmd,8);
		while(1)
		{
			if(IsCom(cport))
			{
				iLength=Receive_MODData(cport,response,0x0D);
				/*
				check1[0]=response[0];
				check1[1]=response[1];
				check1[2]=response[2];
				check1[3]=response[3];
				check1[4]=response[4];
				check2[0]=response[5];
				check2[1]=response[6];
				check3=ModRTU(check1, iLength-2);
				if((unsigned int)check2[0]==(unsigned int)(check3%256) && (unsigned int)check2[1]==(unsigned int)(check3/256))
				{
					*/
					//Print("\n\r%c" , response[5]);
					return ((unsigned int)((unsigned char) response[3]*256 + (unsigned char) response[4]));
				//}
				//else break;
			}
		}
	}
}


void ModbusW(float value)
{
	int iLength,valuecount;
	unsigned char cmd[8];
	unsigned int crccode;
	iLength=8;
	cmd[0]=0x03;
	cmd[1]=0x06;
	cmd[2]=0x00;
	cmd[3]=0x02;
	valuecount=(value*819.2);
	cmd[5]=(valuecount%256);
	cmd[4]=(valuecount/256);
	crccode=ModRTU(cmd,iLength-2);
	cmd[7]=(unsigned char)(crccode/256);
	cmd[6]=(unsigned char)(crccode%256);
	ToComBufn(cport,cmd,8);
}

