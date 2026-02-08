#define red 13
#define blue 12
#define green 4
#define yellow 3
#define red_button 7
#define blue_button 6
#define green_button 10
#define yellow_button 9
#define buzzer 11
#define red_sound 250
#define blue_sound 270
#define green_sound 320
#define yellow_sound 300
int led[] = {blue, red, yellow, green};
int sound[] = {blue_sound, red_sound, yellow_sound, green_sound};
int game_seq[100];
int user_seq[100];
int seq_num = 0;
int score = 0;

void setup() {
Serial.begin(9600);
pinMode(red, OUTPUT);
pinMode(blue, OUTPUT);
pinMode(yellow, OUTPUT);
pinMode(green, OUTPUT);

pinMode(buzzer, OUTPUT);

pinMode(red_button, INPUT_PULLUP);
pinMode(blue_button, INPUT_PULLUP);
pinMode(yellow_button, INPUT_PULLUP);
pinMode(green_button, INPUT_PULLUP);

randomSeed(analogRead(A0));
}

void new_sequence(){
  int i = random(0,4);
  game_seq[seq_num] = i;
  seq_num++;
}

void play_seq(){
  for(int i=0; i<seq_num; i++){
    digitalWrite(led[game_seq[i]], HIGH);
    tone(buzzer, sound[game_seq[i]], 300);
    delay(400);
    digitalWrite(led[game_seq[i]], LOW);
    delay(100);
  }
}

void gameOverMusic() {
  int notes[] = {300, 280, 260, 240, 220, 200, 180};
  int duration[] = {150, 150, 150, 200, 200, 250, 400};

  for (int i = 0; i < 7; i++) {
    tone(buzzer, notes[i], duration[i]);
    delay(duration[i] + 50);
  }

  noTone(buzzer);
}

void loop() {
  new_sequence();
  play_seq();
  int passed = 1;

  for(int i=0; i<seq_num; i++){

    int pressed = -1;

    while(pressed == -1){
    if(!digitalRead(blue_button)) pressed = 0;
    else if(!digitalRead(red_button)) pressed = 1;
    else if(!digitalRead(yellow_button)) pressed = 2;
    else if(!digitalRead(green_button)) pressed = 3;
    delay(10);
    }

    if(pressed==game_seq[i]){
      digitalWrite(led[pressed], HIGH);
      tone(buzzer, sound[pressed], 300);
      delay(400);
      digitalWrite(led[pressed], LOW);
    }

    else{
      Serial.println("Game Over !");
      gameOverMusic();
      seq_num = 0;
      delay(500);
      Serial.println("New Game Starts...");
      passed = 0;
      break;
    }
  }
  if(passed){
  score++;
  Serial.print("Score : ");
  Serial.println(score);
  }
  
  delay(1000);
}
