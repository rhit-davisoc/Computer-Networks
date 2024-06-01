/* File: paint.c 
   Author: Olivia Davis
   
*/
#define CAN_COVERAGE 200

#include <stdio.h>
#include <math.h>

/* If you do not use the Makefile provided and use gcc,
 * and if you continue to use the math.h library, you
 * will need to include -lm in your gcc compile statement
 * to load the math library */

/* Optional functions, uncomment the next two lines
 * if you want to create these functions after main: */
float readDimension(const char* name){
    float dimension;
    printf("%s> ",name);
    scanf("%f", &dimension);
    return dimension;
}

float calcArea(float width, float height, float depth){
    return 2*width*height + 2*width*depth + 2*height*depth;
}

int main(int argc, char *argv[]){
    float width;
    float height;
    float depth;
    float area;
    int cans_needed;

    do {
        width = readDimension("width");
    }while(width < 0);

    do {
        height = readDimension("height");
    }while(height < 0);

    do{
        depth = readDimension("depth");
    }while(depth < 0);

    area = calcArea(width,height,depth);

    cans_needed = (int)(ceil(area / 200.0));
    // Print the number the user typed
    printf("Total Area: %.3f\n", area);
    printf("Number of cans required: %d\n", cans_needed);
}
