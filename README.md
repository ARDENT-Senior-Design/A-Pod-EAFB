# A-Pod-EAFB
The purpose of this repository is to setup the Lynxmotion A-pod in collaboration with edwards air force base

Make sure the Arduino Libraries "Pixy" and "PS2X_lib" are both added to your Arduino libraries.

For simplicity, the Lynxmotion GP_Player function was disabled in place of an autonomous ball follower functionality

if the robot is frozen, its most likely because the Pixy Camera has reset to its default parameters. You can fix this by opening "PixyMon" program, setting
the interface method to "I2C" and pressing "Apply"

