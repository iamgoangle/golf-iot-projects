// relay :: in1
int relay1 = 8;

// relay :: in2
int relay2 = 13;

int ledPin = 13;


void setup() {    
  Serial.begin(9600);            
  pinMode(relay1, OUTPUT); 
//  pinMode(relay2, OUTPUT);    
  digitalWrite(ledPin, HIGH);
}

void loop() {
  // relay1 open
  Serial.println("relay1: open");
  digitalWrite(relay1, 0);

   // relay2 open   
  Serial.println("relay2: open");
//  digitalWrite(relay2, 0); 

  delay(3000);           

  // relay1 close
  Serial.println("relay1: close");
  digitalWrite(relay1, 1); 
  
  
  // relay2 close
  Serial.println("relay2: close");
//  digitalWrite(relay2, 1); 
  
  delay(3000); 
}
