#include <stdio.h>
#include <stdlib.h>
#include "include/config.h"

int main()
{
	getConfig();
	printf("Config file is as follows:\n");
	printf("maxTemp: \t%5.2f\n", config.maxTemp);
	printf("warnTemp: \t%5.2f\n", config.warnTemp);
	printf("maxVoltage: \t%5.2f\n", config.maxVoltage);
	printf("maxCurrent: \t%5.2f\n", config.maxCurrent);
}