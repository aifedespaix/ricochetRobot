#include <stdio.h>

#include "ask_Multi.h"

#include "work_Environnement.h"

// Users bet on the number of anticipated travel to reach the goal.
int askBet(void)
{
    int i;
	int j;
	int size;
	int bet;
	int multiple;
	int bad;
		do{
			bad = 0;
		    bet = 0;
		    size = 0;
	        char a[3]; // a = bet in char
	        for(i=0; i<3; i++){ // init char array
	            a[i] = '\0';
	        }
	        scanf("%s", a); //Scanf the the bet in char

            //Calc size of bet array
            i = 0;
            while(i++<3 && a[i] != '\0') size++;

            // Verify entry
	        for(i=0; i<=size; i++){
	        	if(
	        		a[i] != '0'
	        		&& a[i] != '1'
	        		&& a[i] != '2'
	        		&& a[i] != '3'
	        		&& a[i] != '4'
	        		&& a[i] != '5'
	        		&& a[i] != '6'
	        		&& a[i] != '7'
	        		&& a[i] != '8'
	        		&& a[i] != '9'
	        		){
	        		bad = 1;
	        		break;
	        	}
	        }
			if(a[0] == 'q'){
	            bet = -1;
	        }
	        else if(bad){
	        	bet = -2;
	    	} else{
	            // Convert to int
	            i = 0;
	            while(a[i] != '\0' && i<3){
	                multiple = 1;
	                for(j=size; j>i; j--){
	                    multiple *= 10;
	                }
	                bet = bet + multiple*(((int)a[i])-48);
	                i++;
	            }
	        }
		}while(bet < -1 || bet > 999 );

    return bet;
}
