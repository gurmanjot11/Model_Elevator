# Model_Elevator
I built a model elevator project to learn how to incorporate hardware systems with a sofware controller. 

Using C, I outlined the logic that determines which direction the elevator will move depending on whichever button is pressed by the user. 

This is done by reading the upward distance between an ultrasonic sensor at the base of the machine and the elevator cab, and comparing it to the target height depending on whichever button is pressed. 

Once this is computed, the machine is able to determine which way to rotate the mounted servo to translate the cab up or down. The ultrasonic sensor takes height readings simultaneously to determine when the transfer is done. 

All of the steps are serialized onto an LCD to offer clear readability and ease of use for the user. 

An example demonstration can be found here: https://www.youtube.com/watch?v=AneynTFfyFE&t=969s 
* Note its made in a longer informational style because I used this to teach classmates how to combine the readings of sensors with the behaviour of a control system.
