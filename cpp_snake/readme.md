# Snake-Game-in-C++


This repository contains the code and explaination for the code of Snake Game in C++



The complete functioning of the code is divided into 4 parts or function namely 



    1) init()

    2) Box() 

    3) Input()

    4) Running()

    

### All variables and their meaning 



  1) gameOver = This is a boolean variable that decides whether the game should continue or should be stopped. If the value of this is false means the game will continue otherwise the game will stop 

  

  2) width and height = These constant integer variables define the dimension of the box where the game will be played 

  

  3) Snakex and Snakey = These are 2 global arrays of type integer which stores the "x" and the "y" coordinate of the tail of the snake 

  

  4) x and y = This 2 integer variable stores the "x" and "y" coordinate of the head of the snake

  

  5) lengthTail = This stores the length of the tail of snake 

  

  6) fruitX and fruitY = This stores the "x" and "y" coordinate of the Fruit 

  

  7) score = This stores the score  

  

  8) direction = This is an enum type which has the enumerated the directions i.e, LEFT, RIGHT, UP, DOWN and STOP for stopping the game

  

  

### init() 



  In this function, all the variables are initialized.

  

  As the game is started, the gameOver has assigned a value of false 

  

  Initially, only the head of snake will be there, so lengthTail = 0 

  

  Starting position of snake is the middle point of the box, that's why        x = width/2      y = height/2 

  

  The position of the fruit is chosen randomly 

  

  And the score is 0 

  







### Box() 



  Here we're starting by writing system("cls") to clear the screen. Now we are doing that, because every time the snake moves it's position changes, so we need to reflect the same changes in the Box and that's why every time we need to print a new Box and clear the previous box 

  

  Now using 2 for loops I'm printing the box. In the corner position,i.e, at the start and end of both horizontal and vertical dimension, I'm printing the box's boundary defined by "#" 

 

 Now if the given coordinate is same as the co-ordinate of Fruit , so I'm printing Fruit there denoted by "F" 

 

 If the co-ordinate is same as the co-ordinate of the head of the Snake ,I'll print the head of snake denoted by "0" 

 

 Now comes the interesting part. If nothing is there so I need to print whitespace and if any tail block of snake is there so I've to print the tail. So for that, I've used a boolean variable called space. For every iteration of the loop , if the co-ordinate matched with the co-ordinate of any of the tail block, then I'll print the tail block denoted by "o" and mark space as true otherwise I'll print whitespace

 

 ### Input() 

 

 In this function the input by the player is stored using  "_kbhit()"  [ Conio.h] and using "_getch()"  I'm checking the input. Now for this game, the standard input of "w" for up, "a" for left, "s" for the bottom and "d" for right is used and the same is determined in the code using switch statement and the given direction is stored in "dir" variable of direction enumeration. 

 

 

### Running() 



This is the most important function of the program as these changes the box, the co-ordinate of snakes, and the new location of Fruit every time according to the input given by the player.



Now in this function, the first thing I'm doing is changing the position of all tail block. For that what  I'm doing is shifting the 1st block of the tail to the position of the head , 2nd block of the tail to 1st block of the tail and so on. [All this is done only if tail exist and that's what I'm doing in the 1st if block of this function] 



Now according to the value of dir[Which stores the direction to move from the Input() function], I'm changing the coordinates "x" and "y". That is 

          

          For left = x-=1  ; 

          For right = x+=1 ;

          For Up = y-=1 ; 

          For bottom = y+=1 ; 

          

Now to handle the condition of what if the snake goes outside the border I'm using the reflection property,i.e,  snake going outside the border is made equivalent to snake coming inside from the same alignment opposite border. 



Now finally the condition which ends the game is coded. That is if any co-ordinate of tail matched with the co-ordinate of head, the game is finished and the boolean gameOver becomes true  



And now the scoring part is coded. That is if co-ordinate of head matched with co-ordinate of fruit , so score is incremented by 1 and the position of fruit is changed using the same random function modulo width and height 





### main() function 



In the main function, I'm calling srand(time(0)) to make sure the uniqueness in the random function and then using init() all the variables are initialized. 



And until the game is not over Box() is created, Input() is taken and the corresponding changes are done using Running(). Now as we are clearing the screen every time, so the game will blink every time, so to reduce the speed of that blink and also to make sure that the speed of snake is well maintained, I'm using Sleep() for 50 milliseconds. You may increase or decrease it as per convenience . 



And finally, when the game is finished, I'm, displaying the score. 
