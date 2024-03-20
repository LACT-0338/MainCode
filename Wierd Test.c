#include <kipr/wombat.h>

#define ARM_PORT 0
#define CLAW 1

void smooth_servo(int port, int position) { // smooth servo function makes the servo movements smoother
 int current_position = get_servo_position(port);
 if(current_position < position) {
    while(current_position < position) {
        set_servo_position(port, current_position+10);
        msleep(1);
        printf("adjusted position %d \n", current_position);
        current_position = get_servo_position(port);
       
    }
 }
    else {
    while(current_position > position) {
        set_servo_position(port, current_position-10);
        msleep(10);
        printf("adjusated %d \n", current_position);
        current_position = get_servo_position(port);
    }
    }
}
//What is up youtube today im going to touch raghav

void move_to_poms() { // this function moves until the tophat sensor detects black line
    enable_servos();
    smooth_servo(ARM_PORT,1400);
    smooth_servo(CLAW,1497);
   while(analog(1)<1500) { // tophat sensor  
       
        motor(0,400);
        motor(1,400);
   }
   
   motor(0, 100); // movement towards first pom (lines 38-41)
   msleep(180);
   motor(1, 100);
   msleep(180);
} 
   // moving towards first set of poms and turning
   void turn1() { //turns 90 degrees towards first set of poms
      cmpc(0);
      cmpc(1);
   while(gmpc(0) > -950) {
      motor(1,100);
      motor(0,-100);   
   } }

	void allahuakbar() {
       motor(0,0);
       motor(1,0);
       msleep(200);
       motor(1,-100);
       motor(0,-100);
       msleep(1100);
        // opening arm
        printf("opening arm \n");
       smooth_servo(ARM_PORT,1935); //height of the claw right before gripping
        motor(0,0);  //add a wait after opening arm.
        motor(1,0);
        msleep(1000);
        motor(1,100);
       motor(0,100);
       msleep(700);
       smooth_servo(CLAW,2047);
       msleep(50);
       smooth_servo(ARM_PORT,1200);
       motor(1,0);
       motor(0,0);
       
    }

 void grippin1() {
   cmpc(0);
   cmpc(1);
   motor(0,0);
   motor(1,0);
   msleep(100);
   motor(1,100);
   motor(0,100);
   msleep(500);
   motor(1,0);
   motor(0,0);
   msleep(100);
 }
	void disengage1() {
    smooth_servo(ARM_PORT,1815);
   smooth_servo(CLAW,1087);
    printf(" \n disengaged");
       msleep(300);
       smooth_servo(ARM_PORT,2047);
       printf(" \n ready to push red poms");
       motor(0,100);
        motor(1,100);
        msleep(100);
       printf("\n returning...");
        motor(1,-100);
       motor(0,-100);
       msleep(2000);
       motor(1,0);
       motor(0,0);
       msleep(50);
       smooth_servo(ARM_PORT,1400);
        
       printf("\n turning to next pom ur compooper hab virus \n");
    }
	void turnaway(){ 
        //the string of motor commands orient the bot properly towards the airlock...
        motor(1,100);
        motor(0,100);
        msleep(500); //adjust for accuracy for turning 
        printf("\n adjusted positioning to rotate now... \n");
        motor(0,0);
        motor(1,0);
        msleep(10);
       cmpc(0);
        cmpc(1);
       while(gmpc(0)<1550) {
       motor(1,-100);
       motor(0,100);
   }
  motor(1,0);
  motor(0,0);
  msleep(100);
  //will position the claw ready to grapple
  smooth_servo(CLAW,1745);
  smooth_servo(ARM_PORT, 2024);
  msleep(1000);
   }

  void airlawk_engage() {
      // this opens the airlock.
      smooth_servo(1,1900);
      printf("\ninitiating airlock open procedure \n");
      motor(1,100); // makes bot go forward towards the airlock to grip.
      motor(0,100);
      msleep(500);
      motor(0,0);
      motor(1,0);
      msleep(2000);
      smooth_servo(1,2047); // grip it
      msleep(2000);
      //go back
      motor(1,-100);
      motor(0,-100);
      msleep(1000);
      smooth_servo(1,1500); //unengage syeervo
      motor(0,0);
      motor(1,0);
      msleep(10);
  }

int main()
{
    
    move_to_poms();
    turn1();
    allahuakbar();
    grippin1();
    disengage1();
    turnaway();
    airlawk_engage();
    return 0;
}
