
#define FORWARD 1
#define BACKWARD 2
#define BRAKE 3
#define RELEASE 4

#define th 250
int sll, sl, sc, sr, srr ;
char st = 'c';

void setup()
{ Serial.begin(9600);

}
void loop()
{
  sll = digitalRead(4);
  sl = digitalRead(35);
  sc = digitalRead(34);
  sr = digitalRead(36);
  srr = digitalRead(39);
  if (!sc) {
    st = 'c'; //center
  } else   if (!sl) {
    st = 'l'; //center
  } else  if (!sr) {
    st = 'r'; //center
  } else  if (!sll) {
    st = 'L'; //center
  } else  if (!srr) {
    st = 'R'; //center
  }
  if (st == 'R') {
    r(255);
  } else if (st == 'L') {
    l(255);
  } else if (st == 'r') {
    f(0, 255);
  } else if (st == 'l') {
    f(255, 0);
  } else if (st == 'c') {
    f(255, 255);
  } else {
    s();
  }


  delay(5);
}
void f(int sp1, int sp2) {
  motor(3, FORWARD, sp1);
  motor(4, FORWARD, sp2);
}
void r(int sp) {
  motor(3, FORWARD, sp);
  motor(4, BACKWARD, sp);
}
void l(int sp) {
  motor(3, BACKWARD, sp);
  motor(4, FORWARD, sp);
}
void b(int sp) {
  motor(3, BACKWARD, sp);
  motor(4, BACKWARD, sp);
}
void s() {
  motor(3, RELEASE, 0);
  motor(4, RELEASE, 0);
}
