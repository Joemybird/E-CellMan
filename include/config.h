struct Config {
	float maxTemp;
	float warnTemp;
	float maxVoltage;
	float maxCurrent;
};

// Global configuration settings
extern struct Config config;

// Function to read configuration file
extern void getConfig();