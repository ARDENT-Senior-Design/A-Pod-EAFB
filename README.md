## A-Pod-EAFB
The purpose of this repository is to setup the Lynxmotion A-pod in collaboration with edwards air force base

Make sure the Arduino Libraries "Pixy" and "PS2X_lib" are both added to your Arduino libraries.

For simplicity, the Lynxmotion GP_Player function was disabled in place of an autonomous ball follower functionality

## Commands

1. Start button will start the robot once both switches have been turned on. If the legs do not automatically move to a standing position, consult the debug guide below. Pressing the start button a second time will disable and lower the robot

2. The joysticks will move the robot forward, backwards, sideways, and spin. Pressing the L1/2 and R1/2 will adjust the walking gait.

3. The left thumb pad will elevate or lower the chassis, but maintain the smae locomotion.

4. The X-Button will switch the robot to "Autonomous Mode." The robot will then turn to face the object that it has been trained to follow by PixyMon. If the object is within the distance of the jaws, the mouth will automatically close to grab the object. After a few seconds teh robot will drop the ball again to prevent motor damage.

## Debugging 

### Camera Interfacing

If the robot is frozen, its most likely because the Pixy Camera has reset to its default parameters. You can fix this by opening "PixyMon" program, setting
the interface method to "I2C" and pressing "Apply"

### Controller isn't connected

The robot is not the most solid protocol for communication. If the robot is not moving and you have already checked the I2C settings of the camera, the issue is most likely a radio signal issue.

1. Double check to make sure all wires connected to the transmitter are plugged in. By pressing the "Mode" button on the controller, the controller should toggle an orange light. The orange light should be on for the controller to connect to the robot.

2. Check the serial output of the hexapod for the controller. By typing the following type of command in void loop():

  ```
  Serial.println(ps2x.ButtonPressed(<playstation button>))
  ```
  
Where the <playstation button> is one of the definitions for the playstation button you wish to press.
  
3. Replace the controller. Purchase a new transmitter and controller from the Lynxmotion website (http://www.lynxmotion.com/p-1096-ps2-robot-controller-v4.aspx). Since the hardware is cheap, breakage is fairly common.

## Additional

These were the main issues that appeared during the project. IF you are still confused, please search the RobotShop forums for "Phoenix hexapod." Additional documentation for the A-Pod, which is build based on the Phoenix Frame, is also under the hexapod forums on RobotShop.
