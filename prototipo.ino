
#include <Wire.h>
#define uchar unsigned char
uchar t;
//void send_data(short a1,short b1,short c1,short d1,short e1,short f1);
uchar data[16];

uchar i3l = data[0];
uchar i2l = data[2];
uchar i1l = data[4];
uchar i0l = data[6];
uchar d0l = data[8];
uchar d1l = data[10];
uchar d2l = data[12];
uchar d3l = data[14];

int IN1 = 2;
int IN2 = 3;
int IN3 = 4;
int IN4 = 5;

int ENA = 9;
int ENB = 10;

void setup() {
  // put your setup code here, to run once:
  Wire.begin();        // join i2c bus (address optional for master)
  Serial.begin(9600);  // start serial for output
  t = 0;

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  datosLinea();
  if (superficieNegra(i0l) || superficieNegra(d0l)) {
    avanzar();
  } else if(superficieNegra(i1l)) { 
    // girar a la derecha intensidad baja
      avanzar();
  } else if(superficieNegra(d1l)) {
    // girar a la derecha intensidad media
      avanzar();
  } else if(superficieNegra(i2l)) { 
    // girar a la derecha intensidad baja
      girarDerecha(100);
  } else if(superficieNegra(d2l)) {
    // girar a la derecha intensidad media
      girarIzquierda(100);
  }else if(superficieNegra(i3l)) { 
    // girar a la derecha intensidad baja
      girarDerecha(100);
  } else if(superficieNegra(d3l)) {
    // girar a la derecha intensidad media
      girarIzquierda(100);
  }
}
