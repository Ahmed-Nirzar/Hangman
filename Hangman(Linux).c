/* A simple game of Hangman */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(void)
{
    char word[][80][80] = {
        {"best","huge","here","hair","race"},
        {"brand","catch","crime","cause","cross"},
        {"appear","detect","device","border","budget"},
        {"airport","alcohol","brother","chamber","channel"},
        {"addition","business","contrast","capacity","calendar"}
        };
    char temp[][80] = {"----","-----","------","-------","--------"};
    char ch,ch1,ch2;
    char num[5] = {0,1,2,3,4};
    char h[][80] = {"----","-----","------","-------","--------"};
    int count,i,j,k,l,m,r,point=0;
	srand(time(NULL));

    printf("\n\n\n\t\t\t\t\t\033[42m\033[3;90mHangman\033[0m\033[0m\n\t\t\t\t\t \033[1;92m(1.0)\033[0m\n");
    printf("\n\n\t\t\t\t    \033[1;93mPress \033[1;92mENTER\033[0m\033[1;93m to start\033[0m\n");
    ch1 = getchar();
    if(ch1 != '\n') {
        exit(1);
    }

    printf("\n\n\n\t\t\t\t\t\033[43m\033[1;90mDescription\033[0m\033[0m\n\n\t\t\t\033[1;93m[1]: There are total 5 levels.\n\t\t\t[2]: Each level has 5 stages.\n\t\t\t[3]: Number of letters and hyphen(-) are eqaual.\033[0m");
    printf("\n\t\t\t\033[1;93m[4]: Each time you can maximum use 15 guesses.\n\t\t\t[5]: Point = (left over guesses) multiply by 10\033[0m\n");
    printf("\n\n\t\t\t\t    \033[1;93mPress \033[1;92mENTER\033[0m\033[1;93m to continue\033[0m\n");

    ch2 = getchar();

    if(ch2 != '\n') {
        exit(1);
    }

    for(l=0;l<5;l++)
    {
        printf("\n\n\n\t\t\t\t\t\033[4;94mLevel %d\033[0m\n",l+1);

        for(i=0;i<5;i++)
        {
            j = (rand()%4)+1;
            k = num[i];
            num[i] = num[j];
            num[j] = k;
        }

        for(m=1;m<4;m++)
        {
            count = 0; // count number of guesses
            r = num[m];
            printf("\n\t\t\t\t\t\033[4;91mStage %d\033[0m\n",m);

            do 
            {
                printf("\n\n\t\t\t\033[1;92m%s\033[0m\n", temp[l]);
                printf("\n\t\t\t\033[3;95mEnter your guess: \033[0m");
        
                scanf(" %c",&ch);
                printf("\n");

                // see if letter matches any in word
                for(i=0; i<strlen(word[l][r]); i++)
                if(ch==word[l][r][i]) temp[l][i] = ch;
                count++;

                if(count>15)
                {
                    printf("\n\n\n\t\t\t\t\t\033[41m{ You Loose }\033[0m\n\n\n\n");
                    exit(1);
                }
            } while(strcmp(temp[l], word[l][r]));

            printf("\n\t\t\t\033[1;90m[%s]\033[0m\n", temp[l]);
            printf("\n\t\t\t\033[1;93mYou guessed the word and used \033[0m\033[42m%d\033[0m\033[1;93m guesses\033[0m\n", count);
            point = point + (15 - count)*10;
            printf("\n\t\t\t\033[1;93mScore = \033[42m[%d]\033[0m\033[0m",point);
            strcpy(temp[l],h[l]);
        }
    }

    printf("\n\n\n\t\t\t\t\t\033[42m{ You Win }\033[0m\n\n\n");
    printf("\t\t\t\t\t\033[1;93m( Score )\033[0m \033[42m%d\033[0m\033[0m\n\n\n",point);

    return 0;

}
