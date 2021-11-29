/*
clockwise from 12 to 6-> 0 to 180
clockwise from 6 to 12-> 180 to 360

consider 12-1, 1-2, 2-3....11-12 as individual partitions
=> angle of each partition for hour hand = 360/12= 30 degrees => 30/60 = 0.5 degree per minute
=>angle of each partition for minute hand = 360/60= 6 degrees

each pair of numbers on the clock that is seperated by 180 degrees can be thought of as a complement of each other on the clock. For example : (3,9)-> 3=12-9 or 9=12-3

I thought recognizing this is important as they share the same angle w.r.t to "12" on the clock, but in opposite directions. (I might not need to use this in my program but just making notes)

9: 270 degrees clockwise
 : 90 degrees anticlockwise
3: 90 degrees clockwise
 : 270 degrees anticlockwise

input: 9 00 

hour hand = 9*30 + 0.5*0 = 270+ 0= 0
minute hand= 0*6= 0

270-0= 270
360-270= 90

O/P = 90.00

input: 3 30 

hour hand = 3*30 + 0.5*30 = 90 + 15= 105
minute hand= 30*6= 180

180-105=75
360-75= 285

O/P= 75.00
*/


#include<stdio.h>
#include<stdlib.h>

int min(float a,float b)
{
	return (a<b)?a:b;
}

int main(int argc, char *argv[])
{
	int hour,minute;
	float hDegree, mDegree,diff;
	char choice;
	hour= atoi(argv[1]);
	while(hour>12)
	{
		printf("hours have to be <=12 and >=00");
		printf("retry(r) or quit?(q)\n-->");
		scanf("%c",&choice);
		switch(choice)
		{
			case 'r': 	printf("enter hour:");
					scanf("%d",&hour);
					if(hour<=12)
						break;
					else
						continue;
			case 'q': 	printf("\n\nQuitting");
					return 0; 
		}
	}
	minute= atoi(argv[2]);
	while(minute>60)
	{
		printf("minutes have to be <=60 and >=00");
		printf("retry(r) or quit?(q)\n-->");
		scanf("%c",&choice);
		switch(choice)
		{
			case 'r': 	printf("enter minutes:");
					scanf("%d",&hour);
					if(minute<60)
						break;
					else
						continue;
			case 'q': 	printf("\n\nQuitting");
					return 0; 
		}
	}
	
	hDegree= hour*30.00 + 0.50*minute;
	mDegree= 6.00*minute;
	diff= abs(hDegree-mDegree);
	diff= min(diff, (360.00-diff) );
	printf("angle between hour hand and minute hand = %0.2f",diff);
	return 0;
}
