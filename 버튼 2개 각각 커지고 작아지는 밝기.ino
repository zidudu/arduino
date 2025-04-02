const int LED = 9;
const int BUTTON1 = 2;
const int BUTTON2 = 3;
int i=0;
int current =0;

void setup() {
pinMode(LED, OUTPUT); //LED 핀을 출력으로 설정
pinMode(BUTTON1, INPUT);
pinMode(BUTTON2, INPUT);
}




void loop() {
  if(digitalRead(BUTTON1) == HIGH){
    for(i=current;digitalRead(BUTTON1) == HIGH; i++){
      current= i;
      if(current >=250) current =255;
      analogWrite(LED,current);
      delay(20);
    }
  }
  else if(digitalRead(BUTTON2) == HIGH){
    for(i=current;digitalRead(BUTTON2) == HIGH; i--){
      current= i;
       if(current <=5) current =0;
      analogWrite(LED,current);
      delay(20);
    }
  }








  // if(digitalRead(BUTTON1) ==HIGH)
  // {
  //   while(i<250){
  //     i = i+2;
  //     analogWrite(LED, i);
  //     delay(20);
  //   }
  //   i = 250;
  //   // if(i <=253) i += 2; // i가 250보다 낮다면 i는 계속 커짐
  //   // else i=255; // i가 250보다 높아진다면 255로 고정됨
    
  //   // analogWrite(LED,i);
  //   // delay(50);
    
  // }
  // if(digitalRead(BUTTON2) == HIGH){
  //   while(i>2){
  //     i = i-2;
  //     analogWrite(LED, i);
  //     delay(20);
  //   }
  //   i = 0;



  //   // if(i>=2) i-=2;
  //   // else i =0;
  //   // analogWrite(LED,i);
  //   // delay(50);
  // }

  // // if(BUTTON2 == HIGH)
  // // {
  // //  for(int i=256;i>0;i--){
  // //     analogWrite(LED,i);
  // //   }
  // // }

}
