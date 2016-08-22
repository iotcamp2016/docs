
// cc - by Johannes Heberlein 2014
// v 1.01
// thingiverse.com/joo   wiki.fablab-nuernberg.de

// units: mm; microseconds; radians
// origin: bottom left of drawing surface

// time library see http://playground.arduino.cc/Code/time 

// delete or mark the next line as comment when done with calibration  
//#define CALIBRATION

// When in calibration mode, adjust the following factor until the servos move exactly 90 degrees
#define SERVOFAKTOR 650

// Zero-position of left and right servo
// When in calibration mode, adjust the NULL-values so that the servo arms are at all times parallel
// either to the X or Y axis
#define SERVOLEFTNULL 1950
#define SERVORIGHTNULL 1200

#define SERVOPINLIFT  6
#define SERVOPINLEFT  5
#define SERVOPINRIGHT 3

// lift positions of lifting servo
#define LIFT0 1710 // on drawing surface 1280
#define LIFT1 1125  // between numbers
#define LIFT2 725  // going towards sweeper

// speed of liftimg arm, higher is slower
#define LIFTSPEED 1500

// length of arms
#define L1 35
#define L2 55
#define L3 13.2
#define L4 45


// origin points of left and right servo 
#define O1X 22
#define O1Y -25
#define O2X 47
#define O2Y -25



//#include <Time.h> // see http://playground.arduino.cc/Code/time 
#include <Servo.h>

double move_speed = 5;
const int ledPin =  13; 
const int buttonPin = 2;
int servoLift = 1500;
int buttonState = 0;
int i = 0;
Servo servo1;  // 
Servo servo2;  // 
Servo servo3;  // 

volatile double lastX = 75;
volatile double lastY = 47.5;

int last_min = 0;

void setup() 
{ 
  // Set current time only the first to values, hh,mm are needed
//  setTime(19,38,0,0,0,0); 
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);

  servo1.attach(SERVOPINLIFT);  //  lifting servo
  servo2.attach(SERVOPINLEFT);  //  left servo
  servo3.attach(SERVOPINRIGHT);  //  right servo
//  drawTo(75.2, 47);
  lift(1);  
  delay(1000);

} 

void loop() 
{ 

#ifdef CALIBRATION

  // Servohorns will have 90° between movements, parallel to x and y axis
  drawTo(-3, 28);
  delay(1000);
  lift(0);
 // drawTo(74.1, 28);
  delay(1000);


#else 

  buttonState = digitalRead(buttonPin);

//  number(3, 3, 111, 1);
//  delay(10000);
//  if (buttonState == HIGH) {
  if (i == 0) {
    // turn LED on:
    digitalWrite(ledPin, HIGH);
//  }  
//  if (last_min != 7) {
//  i++;
    if (!servo1.attached()) servo1.attach(SERVOPINLIFT);
    if (!servo2.attached()) servo2.attach(SERVOPINLEFT);
    if (!servo3.attached()) servo3.attach(SERVOPINRIGHT);

      lift(1);
      delay(1000);
       //number(15, 20, 13, 0.9);
       
      // number(5, 15, 15, 1.2);
    //  number(15, 20, 18, 0.9);
    //  number(15, 15, 17, 0.9);//Facebook!
      number(10, 15, 16, 1.3);//Twitter!
    //move_speed = 0.85;
    
   //number(5, 30, 2, 0.9); //2016!
    // number(20, 30, 0, 0.9);
    // number(25, 30, 1, 0.9);
   // number(43, 30, 6, 0.9);
      drawTo(10, 26);
      i = 1;

    
    servo1.detach();
    servo2.detach();
    servo3.detach();
//  }
}
#endif

} 

// Writing numeral with bx by being the bottom left originpoint. Scale 1 equals a 20 mm high font.
// The structure follows this principle: move to first startpoint of the numeral, lift down, draw numeral, lift up
void number(float bx, float by, int num, float scale) {

  
    double ms = move_speed;
  switch (num) {

  case 0:
     drawTo(bx + 0 * scale, by + 20 * scale);
    lift(0);
    drawTo(bx + 10 * scale, by + 20 * scale);
    drawTo(bx + 10 * scale, by + -3 * scale);
    drawTo(bx + 0 * scale, by + -3 * scale);
    drawTo(bx + 0 * scale, by + 20 * scale);
    lift(1);
    break;
  case 1:
    drawTo(bx + 10 * scale, by + 20 * scale);
    lift(0);
    drawTo(bx + 10 * scale, by + 0 * scale);
    lift(1);
//    drawTo(bx + 3 * scale, by + 15 * scale);
  //  drawTo(bx + 3 * scale, by + 20 * scale);
   // lift(0);
//    drawTo(bx + 10 * scale, by + 20 * scale);
 //   drawTo(bx + 10 * scale, by + 0 * scale);
 //   lift(1);
    break;
  case 2:
    drawTo(bx + 0 * scale, by + 20 * scale);
    lift(0);
    drawTo(bx + 10 * scale, by + 20 * scale);
    drawTo(bx + 10 * scale, by + 6 * scale);
    drawTo(bx + 0 * scale, by + 6 * scale);
    drawTo(bx + 0 * scale, by + 0 * scale);
    drawTo(bx + 10 * scale, by + 4 * scale);
    lift(1);
    break;
  case 3:
    drawTo(bx + 2 * scale, by + 17 * scale);
    lift(0);
    bogenUZS(bx + 5 * scale, by + 15 * scale, 5 * scale, 3, -2, 1);
    bogenUZS(bx + 5 * scale, by + 5 * scale, 5 * scale, 1.57, -3, 1);
    lift(1);
    break;
  case 4:
    drawTo(bx + 10 * scale, by + 0 * scale);
    lift(0);
    drawTo(bx + 10 * scale, by + 20 * scale);
    drawTo(bx + 2 * scale, by + 6 * scale);
    drawTo(bx + 12 * scale, by + 6 * scale);
    lift(1);
    break;
  case 5:
    drawTo(bx + 2 * scale, by + 5 * scale);
    lift(0);
    bogenGZS(bx + 5 * scale, by + 6 * scale, 6 * scale, -2.5, 2, 1);
    drawTo(bx + 5 * scale, by + 20 * scale);
    drawTo(bx + 12 * scale, by + 20 * scale);
    lift(1);
    break;
  case 6:
    drawTo(bx + 10 * scale, by + 20 * scale);
    lift(0);
    drawTo(bx + 0 * scale, by + 20 * scale);
    drawTo(bx + -3 * scale, by + 0 * scale);
    drawTo(bx + 10 * scale, by + 0 * scale);
    drawTo(bx + 10 * scale, by + 15 * scale);
    drawTo(bx + 0 * scale, by + 15 * scale);
    lift(1);
    break;
  case 7:
    drawTo(bx + 2 * scale, by + 20 * scale);
    lift(0);
    drawTo(bx + 12 * scale, by + 20 * scale);
    drawTo(bx + 2 * scale, by + 0);
    lift(1);
    break;
  case 8:
    drawTo(bx + 5 * scale, by + 10 * scale);
    lift(0);
    bogenUZS(bx + 5 * scale, by + 15 * scale, 5 * scale, 4.7, -1.6, 1);
    bogenGZS(bx + 5 * scale, by + 5 * scale, 5 * scale, -4.7, 2, 1);
    lift(1);
    break;

  case 9:
    drawTo(bx + 9 * scale, by + 11 * scale);
    lift(0);
    bogenUZS(bx + 7 * scale, by + 15 * scale, 5 * scale, 4, -0.5, 1);
    drawTo(bx + 5 * scale, by + 0);
    lift(1);
    break;

  case 13:
    move_speed = 0.5;
    drawTo(bx + 22 * scale, by + 30 * scale);
    lift(0);
    drawTo(bx + 12 * scale, by + 30 * scale);
    lift(1);
    
    drawTo(bx + 20 * scale, by + 25 * scale);
    lift(0);
    drawTo(bx + 10 * scale, by + 25 * scale);
    lift(1);
    
    drawTo(bx + 17 * scale, by + 20 * scale);
    lift(0);
    drawTo(bx + 7 * scale, by + 21 * scale);
    lift(1);

    drawTo(bx + 30 * scale, by + 32 * scale);
    lift(0);
    drawTo(bx + 20 * scale, by + 10 * scale);
    
    delay(100);
    drawTo(bx + 40 * scale, by + 12 * scale);
    
    delay(100);
    drawTo(bx + 52 * scale, by + 30 * scale);
    
    delay(200);
    //move_speed = 3;
    drawTo(bx + 30 * scale, by + 32 * scale);
    delay(200);
    //move_speed = 5;
    drawTo(bx + 33 * scale, by + 20 * scale);
    delay(200);
    drawTo(bx + 52 * scale, by + 30 * scale);
    lift(1);
    move_speed = ms;
    break;

  case 14:
    for(int i = 0; i <= 40; i+=7)
    {
        lift(1);
        drawTo(bx+15,by+i);
        lift(0);
        drawTo(bx+70,by+i);
        
        lift(1);
      
    }
    break;

  case 15:
    move_speed = 1;
    
    //Top of the umbrella
    drawTo(bx + 35 * scale, by + 18 * scale);
    lift(0);
    drawTo(bx + 35 * scale, by + 29 * scale);
    drawTo(bx + 25 * scale, by + 30 * scale);
    
    delay(200);
    drawTo(bx + 15 * scale, by + 29 * scale);
    drawTo(bx + 13 * scale, by + 17 * scale);    
    //Bottom of the umbrella
    move_speed = 0.75;  
    delay(500);
    drawTo(bx + 16 * scale, by + 25 * scale);
    drawTo(bx + 19 * scale, by + 18 * scale);
    delay(300);
    drawTo(bx + 22 * scale, by + 24 * scale);
    drawTo(bx + 25 * scale, by + 16 * scale);
    delay(300);
    drawTo(bx + 28 * scale, by + 23 * scale);
    drawTo(bx + 30 * scale, by + 16 * scale);
    delay(300);
    drawTo(bx + 33 * scale, by + 23 * scale);
    drawTo(bx + 35 * scale, by + 18 * scale);
    delay(300);
    
    
    //drawTo(bx + 37 * scale, by + 20 * scale);
    
    lift(1);
    
    
   
    //Handle
    drawTo(bx + 26 * scale, by + 33 * scale);
    delay(200);
    move_speed = 0.5;
    lift(0);
    
    drawTo(bx + 26 * scale, by + 30 * scale);
    delay(300);
    lift(1);
    drawTo(bx + 25 * scale, by + 17 * scale);
    lift(0);
    delay(300);
    drawTo(bx + 25 * scale, by + 5 * scale);
    delay(300);
    drawTo(bx + 27 * scale, by + 4 * scale);
    drawTo(bx + 29 * scale, by + 9 * scale);
    lift(1);
    
    move_speed = ms;
    break;
    
 case 16:
    move_speed = 0.75;
    
    //Top of the umbrella
    drawTo(bx + 0 * scale, by + 8 * scale);
    lift(0);
    drawTo(bx + 12 * scale, by + -6 * scale);
    drawTo(bx + 24 * scale, by + 12 * scale);
    drawTo(bx + 30 * scale, by + 18 * scale);
    drawTo(bx + 30 * scale, by + 30 * scale);
    drawTo(bx + 24 * scale, by + 36 * scale);
    delay(300);
    drawTo(bx + 18 * scale, by + 30 * scale);
    delay(300);
    drawTo(bx + 16 * scale, by + 20 * scale);
    delay(50);
    drawTo(bx + 12 * scale, by + 24 * scale);
    drawTo(bx + 6 * scale, by + 26 * scale);
    drawTo(bx + 0 * scale, by + 34 * scale);
    delay(300);
    drawTo(bx + 0 * scale, by + 24 * scale);
    drawTo(bx + 10 * scale, by + 10 * scale);
    delay(300);
    drawTo(bx + 0 * scale, by + 8 * scale);
    lift(1);
    
    drawTo(bx + 30 * scale, by + 22 * scale);
    delay(300);
    lift(0);
    drawTo(bx + 34 * scale, by + 24 * scale);
    delay(300);
    drawTo(bx + 30 * scale, by + 26 * scale);
    delay(300);
    drawTo(bx + 36 * scale, by + 30 * scale);
    delay(300);
    drawTo(bx + 30 * scale, by + 30 * scale);
    delay(300);
    lift(1);
    
    move_speed = ms;
    break;   
   
case 17:
    
    move_speed = 0.75;
    drawTo(bx + 16 * scale, by + 9 * scale);
    lift(0);
    drawTo(bx + 18 * scale, by + 23 * scale);
    delay(70);
    drawTo(bx + 18 * scale, by + 34 * scale);
    delay(50);
    drawTo(bx + 26 * scale, by + 36 * scale);
    delay(300);
    lift(1);
    
    move_speed = 0.75;
    drawTo(bx + 13 * scale, by + 17 * scale);
    delay(300);
    lift(0);
    drawTo(bx + 23 * scale, by + 17 * scale);
    delay(300);
    lift(1);
    
    drawTo(bx + 8 * scale, by + 3 * scale);
    lift(0);
    delay(300);
    drawTo(bx + 26 * scale, by + 3 * scale);
    delay(300);
    drawTo(bx + 27 * scale, by + 40 * scale);
    delay(300);
    drawTo(bx + 6 * scale, by + 40 * scale);
    delay(300);
    drawTo(bx + 8 * scale, by + 0 * scale);
    delay(300);
    
    lift(1);
    move_speed = ms;
    break; 

case 18:
    
    move_speed = 1;
    
    drawTo(bx + 10 * scale, by + 35 * scale);
    delay(300);
    lift(0);
    drawTo(bx + 10 * scale, by + 20 * scale);
    delay(300);
    lift(1);
    
    drawTo(bx + 20 * scale, by + 35 * scale);
    delay(300);
    lift(0);
    drawTo(bx + 17 * scale, by + 20 * scale);
    delay(300);
    lift(1);
    
    
    move_speed = 0.5;
    drawTo(bx + 5 * scale, by + 15 * scale);
    delay(300);
    lift(0);
    drawTo(bx + 12 * scale, by + 5 * scale);
    delay(50);
    drawTo(bx + 18 * scale, by + 5 * scale);
    delay(50);
    drawTo(bx + 25 * scale, by + 15 * scale);
    delay(300);
    lift(1);
    drawTo(bx + 12 * scale, by + 12 * scale);
    lift(0);
    delay(150);
    drawTo(bx + 15 * scale, by + 5 * scale);
    delay(150);
    drawTo(bx + 18 * scale, by + 15 * scale);
    delay(150);
    lift(1);
    move_speed = ms;
    break; 


  case 111:

    lift(0);
    drawTo(70, 46);
    drawTo(65, 43);

    drawTo(65, 49);
    drawTo(5, 49);
    drawTo(5, 45);
    drawTo(65, 45);
    drawTo(65, 40);

    drawTo(5, 40);
    drawTo(5, 35);
    drawTo(65, 35);
    drawTo(65, 30);

    drawTo(5, 30);
    drawTo(5, 25);
    drawTo(65, 25);
    drawTo(65, 20);

    drawTo(5, 20);
    drawTo(60, 44);

    drawTo(75.2, 47);
    lift(2);

    break;

  case 11:
    drawTo(bx + 5 * scale, by + 15 * scale);
    lift(0);
    bogenGZS(bx + 5 * scale, by + 15 * scale, 0.1 * scale, 1, -1, 1);
    lift(1);
    drawTo(bx + 5 * scale, by + 5 * scale);
    lift(0);
    bogenGZS(bx + 5 * scale, by + 5 * scale, 0.1 * scale, 1, -1, 1);
    lift(1);
    break;

  }
}



void lift(char lift) {
  switch (lift) {
    // room to optimize  !

  case 0: //850

      if (servoLift >= LIFT0) {
      while (servoLift >= LIFT0) 
      {
        servoLift--;
        servo1.writeMicroseconds(servoLift);        
        delayMicroseconds(LIFTSPEED);
      }
    } 
    else {
      while (servoLift <= LIFT0) {
        servoLift++;
        servo1.writeMicroseconds(servoLift);
        delayMicroseconds(LIFTSPEED);

      }

    }

    break;

  case 1: //150

    if (servoLift >= LIFT1) {
      while (servoLift >= LIFT1) {
        servoLift--;
        servo1.writeMicroseconds(servoLift);
        delayMicroseconds(LIFTSPEED);

      }
    } 
    else {
      while (servoLift <= LIFT1) {
        servoLift++;
        servo1.writeMicroseconds(servoLift);
        delayMicroseconds(LIFTSPEED);
      }

    }

    break;

  case 2:

    if (servoLift >= LIFT2) {
      while (servoLift >= LIFT2) {
        servoLift--;
        servo1.writeMicroseconds(servoLift);
        delayMicroseconds(LIFTSPEED);
      }
    } 
    else {
      while (servoLift <= LIFT2) {
        servoLift++;
        servo1.writeMicroseconds(servoLift);        
        delayMicroseconds(LIFTSPEED);
      }
    }
    break;
  }
}


void bogenUZS(float bx, float by, float radius, int start, int ende, float sqee) {
  float inkr = -0.05;
  float count = 0;

  do {
    drawTo(sqee * radius * cos(start + count) + bx,
    radius * sin(start + count) + by);
    count += inkr;
  } 
  while ((start + count) > ende);

}

void bogenGZS(float bx, float by, float radius, int start, int ende, float sqee) {
  float inkr = 0.05;
  float count = 0;

  do {
    drawTo(sqee * radius * cos(start + count) + bx,
    radius * sin(start + count) + by);
    count += inkr;
  } 
  while ((start + count) <= ende);
}



void drawTo(double pX, double pY) {
  double dx, dy, c;
  int i;
  double Speed =  move_speed;
  // dx dy of new point
  dx = pX - lastX;
  dy = pY - lastY;
  //path lenght in mm, times 4 equals 4 steps per mm
  c = floor(4 * sqrt(dx * dx + dy * dy));

  if (c < 1) c = 1;

  for (int j = 0; j <= c*Speed; j++) {
    // draw line point by point
    i = j/Speed;
    set_XY(lastX + (i * dx / c), lastY + (i * dy / c));

  }

  lastX = pX;
  lastY = pY;
}

double return_angle(double a, double b, double c) {
  // cosine rule for angle between c and a
  return acos((a * a + c * c - b * b) / (2 * a * c));
}

double toremove=0;

void set_XY(double Tx, double Ty) 
{
  delay(1);
  double dx, dy, c, a1, a2, a3, a4, Hx, Hy;

  // calculate triangle between pen, servoLeft and arm joint
  // cartesian dx/dy
  dx = Tx - O2X;
  dy = Ty - O2Y;

  // polar lemgth (c) and angle (a1)
  c = sqrt(dx * dx + dy * dy); // 
  a1 = atan2(dy, dx); //
  a2 = return_angle(L1, L2, c);

  servo3.writeMicroseconds(floor(((a1 - a2) * SERVOFAKTOR) + SERVORIGHTNULL));

  // calculate joinr arm point for triangle of the right servo arm
  a3 = return_angle(L1, c, L2);
  a4 = M_PI - (a3 - (a1-a2)-return_angle(L2,L3,L4)) -  (M_PI - return_angle(L3,L2,L4));
  Hx = Tx - L3 * cos(a4); //36,5°
  Hy = Ty - L3 * sin(a4);
  // calculate triangle between pen joint, servoRight and arm joint
  dx = Hx - O1X;
  dy = Hy - O1Y;

  c = sqrt(dx * dx + dy * dy);

  a1 = atan2(dy, dx);
  a2 = return_angle(L1, L4, c);

  servo2.writeMicroseconds(floor(((a1 + a2 - M_PI) * SERVOFAKTOR) + SERVOLEFTNULL));
  //servo2.writeMicroseconds(2000);
  if(a1+a2 > 2.5 && abs(a1+a2-toremove)>0.01)
  {
    Serial.print("HEYYYYYYY");
    Serial.print("\n");
    toremove = a1+a2;
  }

}

/*void set_XY(double Tx, double Ty) 
{
  delay(1);
  double dx, dy, c, a1, a2, Hx, Hy;

  // calculate triangle between pen, servoLeft and arm joint
  // cartesian dx/dy
  dx = Tx - O1X;
  dy = Ty - O1Y;
nm
  // polar lemgth (c) and angle (a1)
  c = sqrt(dx * dx + dy * dy); // 
  a1 = atan2(dy, dx); //
  a2 = return_angle(L1, L2, c);

  servo2.writeMicroseconds(floor(((a2 + a1 - M_PI) * SERVOFAKTOR) + SERVOLEFTNULL));

  // calculate joinr arm point for triangle of the right servo arm
  a2 = return_angle(L2, L1, c);
  Hx = Tx + L3 * cos((a1 - a2 + 0.621) + M_PI); //36,5°
  Hy = Ty + L3 * sin((a1 - a2 + 0.621) + M_PI);

  // calculate triangle between pen joint, servoRight and arm joint
  dx = Hx - O2X;
  dy = Hy - O2Y;

  c = sqrt(dx * dx + dy * dy);
  a1 = atan2(dy, dx);
  a2 = return_angle(L1, (L2 - L3), c);

  servo3.writeMicroseconds(floor(((a1 - a2) * SERVOFAKTOR) + SERVORIGHTNULL));

}*/









