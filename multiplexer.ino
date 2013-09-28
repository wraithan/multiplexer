class Multiplexer {
    char S0, S1, S2, S3, data;
  public:
    Multiplexer(char s0, char s1, char s2, char s3, char dpin) {
      S0 = s0;
      S1 = s1;
      S2 = s2;
      S3 = s3;
      data = dpin;
    }
    void setup() {
      pinMode(S0, OUTPUT);
      pinMode(S1, OUTPUT);
      pinMode(S2, OUTPUT);
      pinMode(S3, OUTPUT);
      pinMode(data, OUTPUT);
    }
    void write(char pin, char value) {
      digitalWrite(S0, (pin & 1) ? HIGH : LOW);
      digitalWrite(S1, (pin & 2) ? HIGH : LOW);
      digitalWrite(S2, (pin & 4) ? HIGH : LOW);
      digitalWrite(S3, (pin & 8) ? HIGH : LOW);
      digitalWrite(data, value);
    }
};

Multiplexer multi1(5, 6, 7, 8, 4);
Multiplexer multi2(15, 16, 17, 18, 14);

void setup() {
  multi1.setup();
  multi2.setup();
}

char count = 0;
void loop() {
  count++;
  if (count < 10) {
    multi1.write(count, HIGH);
    multi2.write(0, LOW);
  } else if (count < 20) {
    multi1.write(0, LOW);
    multi2.write(count-10, HIGH);
  } else {
    count = 0;
    multi1.write(count, HIGH);
    multi2.write(0, LOW);
  }
  delay(100);
}


