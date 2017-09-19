#define LED_ONE 8
#define LED_TWO 6

#define SWITCH_INPUT 4

//Keep track of all the possible program states that I am using for the demonstrations
enum ProgramStates {SOLID, ONE_BLINK, BOTH_BLINK, SWITCH_RESPONSE};

//Set the default state as both LEDs being on 
ProgramStates states = ProgramStates.SOLID;

void setup()
{
	//Setup the first LED
	pinMode(LED_ONE, OUTPUT);
	
	//Setup the second LED
	pinMode(LED_TWO, OUTPUT);
}

void loop()
{
	//Use this boolean to determine if a blinking LED should be high or low.
	bool blinkTracker = true;
	
	//IF the program state is to turn both LEDs on...
	if(states == ProgramStates.SOLID)
	{
		//Set both LED pins to HIGH
		digitalWrite(LED_ONE, HIGH);
		digitalWrite(LED_TWO, HIGH);
	}
	//If the state is that only one LED blinks...
	else if(states == ProgramStates.ONE_BLINK)
	{
		//Set LED_TWO to be off.
		digitalWrite(LED_TWO, LOW);
		
		//Set LED_ONE to either on or off, depending on the blink sequence
		digitalWrite(LED_ONE, blinkTracker);
		
		//Invert blinkTracker in order to invert the LED output next time
		blinkTracker = !blinkTracker;
		
		//Wait a bit so we can actually see the LED blink
		delay(750);
	}
	else if(states == ProgramStates.BOTH_BLINK)
	{
		//Set LED_ONE to either on or off, depending on the blink sequence
		digitalWrite(LED_ONE, blinkTracker);
		
		///Set LED_TWO to either on or off, depending on the blink sequence
		digitalWrite(LED_TWO, blinkTracker);
		
		//Invert blinkTracker in order to invert the LED output next time
		blinkTracker = !blinkTracker;
		
		//Wait a bit so we can actually see the LED blink
		delay(750);
	}
}