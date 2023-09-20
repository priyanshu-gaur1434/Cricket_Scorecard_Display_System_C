//Cricket Score Display System

#include <stdio.h>
#include <stdlib.h>

// structure to store the details of batsman
struct batsman
{
    char name[25];    // Name of the batsman
    int runs, score, balls, toruns, tobal, ones, twos, threes, fours, sixes;
    int max_six, max_run, max_four;    // Maximum number of sixes, runs and fours scored by batsman
    float str;

} pl1[100], pl3;

//structure to store details of bowler
struct bowler
{
    char name[25];      // Name of  bowler
    int runsgv, wkttkn, overs;
    int max_w;
    float econ;     // Economy rate of bowler
} pl2[100], pl4;

// main function of the program.
int main()
{
    // Variables to store player no. and user choice
    int plno, choice;
    int i, n, m;

    // Ask user to enter details of batsmen
    printf("Enter the Batsman detail:\n");
    printf("Enter the number of Batsman:\n");
    scanf("%d", &m);
    // Loop of each batsman and ask user to enter their detail
    for (i = 0; i < m; i++)
    {
        printf("Enter name of Batsman %d:\n", i + 1);
        scanf("%s", pl1[i].name);

        printf("Enter the number of ones scored by player %d:\n ", i + 1);
        scanf("%d", &pl1[i].ones);

        printf("Enter the number of twos scored by player %d:\n ", i + 1);
        scanf("%d", &pl1[i].twos);

        printf("Enter the number of threes scored by player %d:\n ", i + 1);
        scanf("%d", &pl1[i].threes);

        printf("Enter the number of fours scored by player %d:\n ", i + 1);
        scanf("%d", &pl1[i].fours);

        printf("Enter the number of sixes scored by player %d:\n ", i + 1);
        scanf("%d", &pl1[i].sixes);

        printf("Enter the balls played by the player %d:\n", i + 1);
        scanf("%d", &pl1[i].balls);
    }

// Ask user to enter details of  bowlers
    printf("\nEnter the Bowlers details:\n");

    printf("Enter the number of Bowlers:\n");

    scanf("%d", &n);

// Loop for each bowler and ask user to enter their details
    for (i = 0; i < n; i++)
    {
        printf("\nEnter name of bowler%d:\n", i + 1);
        scanf("%s", pl2[i].name);

        printf("Enter the runs given by the bowler%d:\n ", i + 1);
        scanf("%d", &pl2[i].runsgv);

        printf("Enter the overs bowled by the bowler%d:\n", i + 1);
        scanf("%d", &pl2[i].overs);

        printf("Enter the wickets taken by the bowler%d\n", i + 1);
        scanf("%d", &pl2[i].wkttkn);
    }

    printf("Thank you all details are recorded\n");

    do
    {
        // display menu to user
        printf("Enter the choice:\n 1)Batsman detail:\n 2)Bowlers detail:\n 3)Match summary:\n 4)Record:\n 5)Exit\n ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the batsman number to see his details\n");
            scanf("%d", &plno);

           // Print the details of particular batsman
            plno--;
            printf("                       Player Detail\n");
            printf("===========================================================================\n");
            printf(" Batsman        runs           balls        fours       sixes         sr   \n");
            printf("===========================================================================\n");
            // Calculate batsman statistics
            pl1[plno].runs = (1 * pl1[plno].ones) + (2 * pl1[plno].twos) + (3 * pl1[plno].threes) + (4 * pl1[plno].fours) + (6 * pl1[plno].sixes);
            pl1[plno].str = (pl1[plno].runs * 100.00) / pl1[plno].balls;
            printf(" %-15s %-14d %-13d %-11d %-11d %-9.2f\n\n", pl1[plno].name, pl1[plno].runs, pl1[plno].balls, pl1[plno].fours, pl1[plno].sixes, pl1[plno].str);

            break;

        case 2:
    printf("Enter the bowlers number to see his details\n");
    scanf("%d", &plno);

    //Print the details of particular bowle
    plno--;
    printf("                         Player Detail\n  ");
    printf("=================================================================\n");
    printf(" Bowler        overs           runs        wicket       economy\n");
    printf("=================================================================\n");

     // Calculate bowler statistics
    pl2[plno].econ = pl2[plno].runsgv / pl2[plno].overs;
    printf(" %-15s %-14d %-13d %-11d %-11.2f\n\n", pl2[plno].name, pl2[plno].overs, pl2[plno].runsgv, pl2[plno].wkttkn, pl2[plno].econ);

    break;


        case 3:
    printf("                         Match Summary\n");
    printf("=============================================================================\n");
    printf(" Batsman        runs           balls        fours       sixes         sr   \n");
    printf("=============================================================================\n");

    for (i = 0; i < m; i++) {
        pl1[i].runs = (1 * pl1[i].ones) + (2 * pl1[i].twos) + (3 * pl1[i].threes) + (4 * pl1[i].fours) + (6 * pl1[i].sixes);
        pl1[i].str = (pl1[i].runs * 100.00) / pl1[i].balls;
        printf(" %-15s %-14d %-13d %-11d %-11d %-9.2f\n", pl1[i].name, pl1[i].runs, pl1[i].balls, pl1[i].fours, pl1[i].sixes, pl1[i].str);
    }

    printf("\n\n");

    printf("                         Match Summary\n");
    printf("=================================================================\n");
    printf(" Bowler        overs           runs        wicket       economy\n");
    printf("=================================================================\n");

    for (i = 0; i < n; i++) {
        pl2[i].econ = pl2[i].runsgv / pl2[i].overs;
        printf(" %-15s %-14d %-13d %-11d %-11.2f\n", pl2[i].name, pl2[i].overs, pl2[i].runsgv, pl2[i].wkttkn, pl2[i].econ);
    }

    break;


        case 4:
            pl3.max_run = 0, pl4.max_w = 0, pl3.max_four = 0, pl3.max_six = 0;

            for (i = 0; i < m; i++)
            {
                pl1[i].runs = (1 * pl1[i].ones) + (2 * pl1[i].twos) + (3 * pl1[i].threes) + (4 * pl1[i].fours) + (6 * pl1[i].sixes);
                if (pl3.max_run < pl1[i].runs)
                {
                    pl3.max_run = pl1[i].runs;
                }

                if (pl3.max_six < pl1[i].sixes)
                {
                    pl3.max_six = pl1[i].sixes;
                }

                if (pl3.max_four < pl1[i].fours)
                {
                    pl3.max_four = pl1[i].fours;
                }

                if (pl4.max_w < pl2[i].wkttkn)
                {
                    pl4.max_w = pl2[i].wkttkn;
                }
            }
            printf("Highest runs scored by the batsman:%d\n", pl3.max_run);

            printf("Maximum fours scored by the batsman:%d\n", pl3.max_four);

            printf("Maximum sixes scored by the batsman%d:\n", pl3.max_six);

            printf("Maximum wickets taken by the bowler:%d\n", pl4.max_w);

            break;
        //exit to the code
        case 5:
            exit(1);

        // Print error message for invalid input
        default:
            printf("Enter the correct choice\n");
            break;
        }

    } while (choice != 5);

    return 0;
}
