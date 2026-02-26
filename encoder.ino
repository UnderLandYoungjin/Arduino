#define EN_01 3
#define IN_01 5
#define IN_02 6
#define INTR2 2


volatile int p_count = 0;

void hw_isr() {
  p_count++;
}

void setup() {
  pinMode(EN_01, OUTPUT);
  pinMode(IN_01, OUTPUT);
  pinMode(IN_02, OUTPUT);

  digitalWrite(EN_01, HIGH);
  digitalWrite(IN_01, HIGH);
  digitalWrite(IN_02, LOW);
  attachInterrupt(digitalPinToInterrupt(INTR2), hw_isr, CHANGE);
  Serial.begin(9600);
}
void loop() {
  Serial.println(p_count);
  p_count=0;
  delay(5);
}
