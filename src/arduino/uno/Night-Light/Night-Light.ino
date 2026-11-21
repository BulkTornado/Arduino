const int POWER = 7;

void setup() {
	//code to be run once
	pinMode(3, OUTPUT);
	pinMode(5, OUTPUT);
	pinMode(9, OUTPUT);
}

void loop() {
	//code to be looped all the time
	analogWrite(3, POWER);
	analogWrite(5, POWER);
	analogWrite(9, POWER);
}
