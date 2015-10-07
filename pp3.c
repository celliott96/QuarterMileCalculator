#include <stdio.h>
#include <math.h>

void calcTime(double*, int*, int*);
int carRating(double);

int main() 
{
	int horsePower;
	int carWeight;
	int carRate = 0;
	double expectedTime = 0;
	
		printf("\nThis program will calculate the rough estimated quarter mile time of any given car.\n");
		printf("\nPlease enter the horsepower of the car:\n");
		scanf("%d", &horsePower);
		if (horsePower > 10000)
		{
			printf("\nThat's too much horsepower, be real!\n");
		}
		else
		{
			printf("\nNow enter the weight of the car in lbs:\n");
			scanf("%d", &carWeight);
			if (carWeight > 8000)
			{
				printf("\nThat car weights too much, don't even bother racing it!\n");
			}
			else if (carWeight < 100)
			{
				printf("\nThat doesn't weigh enough, I don't think it is a real car.\n");
			}
			else
			{
				//expectedTime = calcTime(horsePower, carWeight, maxSpeed);
				calcTime(&expectedTime, &horsePower, &carWeight);
				printf("\nThe expected quarter mile time of this car is: %lf\n", expectedTime);
				//carRate = carRating(expectedTime);
				carRate = carRating(expectedTime);
				if (carRate == 1)
					{
						printf("\nYour car is a speed demon! Take it to the tracks.\n");
					}
				else if (carRate == 0)
					{
						printf("\nWow, your car is a dog. Why even bother.\n");
					}
				printf("\nDisclaimer: This is just a rough calculation. There are many other factors to take into account.\n");
			}
		}
		
return 0;
}

void calcTime(double *eT, int *hP, int *cW)
{
	*eT = (6.9446 * (pow ((*cW / *hP), 0.295)));
}

int carRating(double estTime)
{
	if (estTime <= 12.0)
	{
		return 1;
	}
	else if (estTime >= 18.0)
	{
		return 0;
	}
}

//Test: 2015 Corvette Z06: 650 HP, 3524 LBS.
//formula: 6.9446 * (LBS/HP)^.2841
//Functions of program: scan in HP, LBS, MPH. Calc 1/4 mile time, print expected time, print statment if time is certain amnt.