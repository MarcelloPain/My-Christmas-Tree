#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
void tree(int argc){
    int space=3;
    int add=3;
    for (int i = 2; i<=argc;i++){
        space+=add;
        int q = i%2;
        if (q==1)
            add--;
        add++;
    }
    
    int star = 1;
    int lines = (argc+1)*(argc+1) - ((argc-1)*(argc-2))/2;
    int dp = space;
    int indent = 4;
    int progress = 1;
    int dec = 0;
    for(int i = 0; i < lines; i++){
        for(int j = 0; j < dp; j++){
            printf(" ");
        }
        for(int k = 0; k < star; k++){
            printf("*");
        }
        if(i == indent-1 && argc > 1){
            star = star - 2 - (2*(dec/2));
            dp = dp + (1+(dec/2));
            dec++;
            indent = indent + 4 + progress;
            progress++;
            printf("\n");
            continue;
        }
        star += 2;
        dp--;
        printf("\n");
    }
    
    int fpace = 3;
    int at = 3;
    for (int i = 2; i<=argc;i++){
        fpace+=at;
        if (i%2 == 0)
            at--;
        at++;
    }
    
    for(int i = 0; i < argc; i++){
        for(int j = 0; j < fpace; j++){
            printf(" ");
        }
        for(int k = 0; k < argc; k++){
            printf("|");
        }
        printf("\n");
    }
}

int main(int argc, char **av){
    if (av == NULL || atoi(av[1])==0)
        return 0;
    tree(atoi(av[1]));
    return 0;
}