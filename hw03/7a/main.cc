//
//  main.cc
//  7a (Program that increments by 1)
//
//  Created by Daniel Nilo on 9/12/18.
//  Copyright © 2018 Daniel Nilo. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    // Opens and reads file
    FILE* fp = fopen ("number.txt","r");
    
    // Declare variable a as int and set it to 0
    int a=0;
    
    // Return file pointer as first argument
    while (fscanf (fp,"%d",&a)!=EOF) {
        ++a;
        // Code to print out value of a
        printf("%d\n", a);
    }
    
    // Writes file
    fp = fopen ("number.txt", "w");
    // Prints file pointer as first argument
    fprintf(fp, "%d", a);
    
    // Closes file
    fclose(fp);
    return 0;
}
