#define togglePin 3
#define sensorPin 2

int time = 0;
int timeDifference = 0;
int previousTime = 0;

boolean val = 0;
boolean newVal = 0;
boolean currentState = 0;

void setup()
{
  pinMode(sensorPin, INPUT);
  pinMode(togglePin, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  newVal = digitalRead(sensorPin);

  // the value has changed
  if (val != newVal)
  {
    val = newVal;

    // this can trigger four times in a span of 6 milliseconds
    if (val == 1)
    {

      time = millis();
      timeDifference = time - previousTime;
      if (timeDifference > 10)
      {

        // Serial.println("Flick");
        // Serial.println(millis());

        // the time delay will be between 100 and 800 milliseconds
        if (timeDifference > 100 && timeDifference < 800)
        {
          Serial.println("Activated");
          currentState = digitalRead(togglePin);
          digitalWrite(togglePin, !currentState);
        }
      }

      previousTime = time;
    }
  }
}