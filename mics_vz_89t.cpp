#include <stdio.h>
#include <wiringPi.h>
#include <wiringPiI2C.h>

int main(void)
{
	int WRITE1, WRITE2, WRITE3, WRITE4, WRITE5, WRITE6;
	int READ[7];
	int CO2, VOC;
	int VZ89;

	VZ89=wiringPiI2CSetup(0x70);
	while(1)
	{
		WRITE1=wiringPiI2CWrite(VZ89, 0x0C);
		WRITE2=wiringPiI2CWrite(VZ89, 0x00);
		WRITE3=wiringPiI2CWrite(VZ89, 0x00);
		WRITE4=wiringPiI2CWrite(VZ89, 0x00);
		WRITE5=wiringPiI2CWrite(VZ89, 0x00);
		WRITE6=wiringPiI2CWrite(VZ89, 0xF3);

		delay(1000);

		for(int i=0; i<7; i++)
		{
			READ[i]=wiringPiI2CRead(VZ89);
		}

		//CO2=(READ[1]-13)*(1600/229)+400;
		VOC=(READ[0]-13)*(1000/229);

		//printf("VOC:%d,	CO2:%d \n %02x,	%02x,	%02x \n %02x	%02x	%02x \n", VOC, CO2, READ[0], READ[1], READ[2], READ[3], READ[4], READ[5]);
		printf("VOC:%d \n", VOC);
	}
}
