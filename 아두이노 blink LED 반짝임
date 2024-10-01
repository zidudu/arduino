// LED 변수 설정
const int RLED = 2;
const int GLED = 3;
const int BLED = 8;
// 버튼 변수 설정
const int BUTTON = 1;

boolean lastButton = LOW;
// 버튼의 현재 상태 저장
boolean currentButton = LOW;
// LED의 현재 상태(on/off)
boolean ledOn = false;

void setup() {
  // LED 출력
  pinMode(RLED, OUTPUT);
  pinMode(GLED, OUTPUT);
  pinMode(BLED, OUTPUT);
  // 버튼 입력
  pinMode(BUTTON, INPUT);
}

// 디바운싱 함수
// 버튼의 이전 상태를 매개변수로 전달하면 디바운싱된 버튼의
// 현재 상태를 얻을 수 있음
boolean debounce(boolean last) {
  boolean current = digitalRead(BUTTON);
  if (last != current) {
    // 5ms 대기
    delay(5);
    // 버튼 상태 다시 읽기
    current = digitalRead(BUTTON);
  }
  return current;
}

void loop() {
  // 만약 ledOn이 참이라면 신호등 시작, 거짓이면 종료
  if (ledOn == true) {
    BLINK();
  } else {
    // 신호등이 꺼질 때 모든 LED 끔
    digitalWrite(RLED, LOW);
    digitalWrite(GLED, LOW);
    digitalWrite(BLED, LOW);
  }

  // 디바운싱 처리
  //debouncing();
  debouncing();

}

boolean debouncing() {
  // 디바운싱이 된 버튼 상태를 읽어옴
  currentButton = debounce(lastButton);
  
  // 버튼을 누르게 되면 LED 상태가 바뀜
  if (lastButton == LOW && currentButton == HIGH) {
    // LED 상태값 반전
    ledOn = !ledOn;
    return true;  // 버튼이 눌렸음을 반환
  }

  // 이전 버튼 상태를 현재 버튼 상태로 변경
  lastButton = currentButton;
  return false;  // 버튼이 눌리지 않음
}

void BLINK() {
  // 빨강 먼저
  digitalWrite(RLED, HIGH);
  digitalWrite(GLED, LOW);
  digitalWrite(BLED, LOW);
  for (int i = 0; i < 500; i++) {  // 500ms 동안 버튼 확인
    delay(1);
    if (debouncing()) {
      return;  // 버튼이 눌리면 즉시 함수 종료
    }
  }

  // 초록
  digitalWrite(RLED, LOW);
  digitalWrite(GLED, HIGH);
  digitalWrite(BLED, LOW);
  for (int i = 0; i < 500; i++) {  // 500ms 동안 버튼 확인
    delay(1);
    if (debouncing()) {
      return;  // 버튼이 눌리면 즉시 함수 종료
    }
  }

  // 파랑
  digitalWrite(RLED, LOW);
  digitalWrite(GLED, LOW);
  digitalWrite(BLED, HIGH);
  for (int i = 0; i < 500; i++) {  // 500ms 동안 버튼 확인
    delay(1);
    if (debouncing()) {
      return;  // 버튼이 눌리면 즉시 함수 종료
    }
  }

}

