#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "config.h"

#define MAXLEN 100
struct Config config;

void getConfig()
{
	FILE *fp;

	//Set all values to default to start with
	config.maxTemp=60;
	config.warnTemp=45;
	config.maxVoltage=240;
	config.maxCurrent=150;

	// Open a file in read mode
	fp = fopen("config.cfg", "r");

	// Use default values if config file is not located or is missing
	if (NULL == fp) {
        printf("WARNING: config file not found\n");
		printf("Using default values for config\n");
		return;
    }
	 
	char line[MAXLEN];
    char key[MAXLEN];
	char value[MAXLEN];
	
	while (fgets(line, MAXLEN, fp) != NULL)
	{
		sscanf(line, "%[^=]=%s", key, value);
		if (strcmp(key, "maxTemp") == 0) {
			config.maxTemp=atof(value);
		}
		else if (strcmp(key, "warnTemp") == 0) {
			config.warnTemp=atof(value);
		}
		else if (strcmp(key, "maxVoltage") == 0) {
			config.maxVoltage=atof(value);
		}
		else if (strcmp(key, "maxCurrent") == 0) {
			config.maxCurrent=atof(value);
		}
	}

	fclose(fp);
	return;
}