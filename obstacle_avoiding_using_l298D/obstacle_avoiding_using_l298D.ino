
//initializing pinss
int in1 = 3;
int in2 = 4;
int in3 = 10;
int in4 = 9;

int en1 = 5;
int en2 = 6;

int trig = 7;
int echo = 8;

long duration;
int dist;

int speedValue = 200;  // 0 to 255

void setup()
{

  //selecting or selecting pin and mode
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  pinMode(en1, OUTPUT);
  pinMode(en2, OUTPUT);

  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);

  Serial.begin(9600);
}

void loop()
{
  
  dist = getdistance();

  if (dist > 28)
  {
    forward();
  }
  else
  {
    stopMotor();
    delay(500);

    backward();
    delay(800);

    right();
    delay(800);
  }
}

void forward()
{
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(en1, speedValue);

  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(en2, speedValue);
}

void backward()
{
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(en1, speedValue);

  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(en2, speedValue);
}

void right()
{
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(en1, speedValue);

  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(en2, speedValue);
}

void left()
{
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(en1, speedValue);

  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(en2, speedValue);
}

void stopMotor()
{
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  analogWrite(en1, 0);

  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  analogWrite(en2, 0);
}

int getdistance()
{
  digitalWrite(trig, LOW);
  delayMicroseconds(5);

  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  duration = pulseIn(echo, HIGH);

  int distance = duration * 0.0343 / 2;

  Serial.print("Distance: ");
  Serial.println(distance);

  return distance;
}