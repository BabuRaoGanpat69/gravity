# gravity

## A basic gravity simulator created using raylib

## INSTALLATION

 paste these commands to install in your desired location

 ```
 git clone https://github.com/BabuRaoGanpat69/gravity
 cd gravity
 mkdir build && cd build
 cmake .. -DCMAKE_BUILD_TYPE=Debug 
 make -j4
./main 

```
***The steps upto make -j4 should be done only once if you are not changing the code,
after completing you just need to do ./main to play again and again.***

### FEATURES/how to use

 1.create as many bodies as you want and watch the chaoes      
 2.the radius is directional proportional to mass so more radius means more mass   
 3.left click for creating new bodies  
 4.hold the left click for increasing its radius  
 5.Right click for starting sim  
 6.You can add bodies during the the simulation also  
 7.you can change the time step using w and s   
 8.w for increasing and s for decreasing   
 9.there is a vector that shows the force vector(direction only)  
 10.on the top left corner you can see the the stats of the bodies   

 
