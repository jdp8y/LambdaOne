# LambdaOne
This is repository for code to run on a Arduino robot. The robot has an undecided amount of (DC or AC) motors, four brakes, two line sensors, four ultrasonic sensors, and two servo's. All connections are clearly listed as global variables in the code.

## Code Flow
Each part of the code is seperated into functions that are called by the control() function that simply calls to the most
appropriate direction to go in and then calls the ultrasonic() function that in turn goes to the control() function that 
starts the loop all over.

### Copyright
The LambdaOne sofware is protected by the ["Attribution-NonCommercial-NoDerivs 3.0"](http://tinyurl.com/LambdaOneCode). The LambdaOne hardware is protected by the ["Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License"](http://tinyurl.com/nrek8ac)

### Credits
All credits go to Josh Perry and Collin Rodes.

