// Woooooooooo
//OH GOD THIS IS A MISTAKE
const int f1 = 3; // pin values for fan
const int f2 = 5;

int sen1 = 0; // store sensor readings
int sen2 = 0;

long f1reset = 0; // time since fan 1 has reset
long f2reset = 0; 
long f1BeganInflate = 0; // time since fan 1 has started inflating
long f2BeganInflate; 

boolean f1started = false; // has fan 1 started inflating?
boolean f2started = false; 
boolean f1beenhit = false; // has fan 1 been hit?
boolean f2beenhit = false; 

int f1target = random(2000,10000); // time to wait until f1 inflates
int f2target = random(2000,10000); 

void setup() {
  Serial.begin(9600);
  pinMode(f1, OUTPUT);
  pinMode(f2, OUTPUT);
  digitalWrite(f1, HIGH);
  digitalWrite(f2, HIGH);
  delay(100);
}

void loop() {
  if (millis() - f1reset >= f1target && f1started == false) { // if time since last reset exceeds target time:
    digitalWrite(f1, LOW); // turn on fan
    f1BeganInflate = millis(); // record time that fan began inflating
    f1started = true; // report that fan has started
  }

  if ((millis() > (f1BeganInflate + 3000)) && f1started == true) { // if it's been more than 3 seconds than the start of inflation:
    sen1 = analogRead(A0); // store both sensor readings
    sen2 = analogRead(A1);
    Serial.print("Sensor 1: ");
    Serial.println(sen1);
    if (sen1 > 200) {
      digitalWrite(f1, HIGH); // turn off fan
      f1reset = millis(); // record the current moment as the time the fan was reset
      f1started = false; // report that fan has stopped
      f1target = random(2000,10000); // assign new target time
    }  
  }
}



