#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Player
{
    int jNo;
    char name[20];
    int runs;
    int wickets;
    int matches_played;

} Player;

void addPlayer(Player parr[], int *playerCount, int *capacity);
void displayPlayer(Player parr[], int playerCount, int index);
void removePlayer(Player parr[], int *playerCount);
void searchPlayer(Player parr[], int playerCount);
void updatePlayer(Player parr[], int playerCount);
void displayTopPlayers(Player parr[], int playerCount);

int main()
{
    int capacity = 11; // Initial capacity
    Player *parr = (Player *)malloc(capacity * sizeof(Player)); 

    if (parr == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }

    parr[0] = (Player){18, "Virat Kohli", 12471, 150, 275};
    parr[1] = (Player){7, "MS Dhoni", 10773, 180, 350};
    parr[2] = (Player){45, "Rohit Sharma", 9825, 135, 243};
    parr[3] = (Player){12, "Yuvraj Singh", 8701, 111, 304};
    parr[4] = (Player){3, "Sourav Ganguly", 11363, 100, 311};
    parr[5] = (Player){10, "Sachin Tendulkar", 18426, 154, 463};
    parr[6] = (Player){99, "Jasprit Bumrah", 19, 130, 145};
    parr[7] = (Player){33, "Ravindra Jadeja", 2447, 125, 174};
    parr[8] = (Player){5, "KL Rahul", 1986, 50, 57};
    parr[9] = (Player){25, "Hardik Pandya", 1518, 63, 87};

    int playerCount = 10;
   
    int choice;
    do
    {
        printf("\n");
        printf("******* Player Management System *******\n");
        printf("1. Add Player\n");
        printf("2. Remove Player\n");
        printf("3. Search Player\n");
        printf("4. Update Player\n");
        printf("5. Display Sorted Players\n");
        printf("6. Display All Players\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addPlayer(parr, &playerCount, &capacity);
            break;
        case 2:
            removePlayer(parr, &playerCount);
            break;
        case 3:
            searchPlayer(parr, playerCount);
            break;
        case 4:
            updatePlayer(parr, playerCount);
            break;
        case 5:
            displayTopPlayers(parr, playerCount);
            break;
        case 6:
            displayPlayer(parr, playerCount, -1);
            break;
        case 0:
            printf("\nExiting the system, Thank You. \n");
            break;
        default:
            printf("Invalid choice! Please try again.\n\n");
        }
    } while (choice != 0);

    free(parr);
    return 0;
}

void addPlayer(Player parr[], int *playerCount, int *capacity)
{
    if (*playerCount >= *capacity)
    {
        *capacity *= 2; // Double the capacity
        parr = realloc(parr, *capacity * sizeof(Player)); 
        if (parr == NULL)
        {
            printf("Memory allocation failed!\n");
            return;
        }
    }
    {
        printf("\nEnter details for Player:\n");

        printf("Enter Jersey Number: ");
        scanf("%d", &parr[*playerCount].jNo);
        getchar();

        printf("Enter Player Name: ");
        fgets(parr[*playerCount].name, sizeof(parr[*playerCount].name), stdin);
        parr[*playerCount].name[strcspn(parr[*playerCount].name, "\n")] = 0;

        printf("Enter Total runs: ");
        scanf("%d", &parr[*playerCount].runs);

        printf("Enter total Wickets taken: ");
        scanf("%d", &parr[*playerCount].wickets);

        printf("Enter total matches Played: ");
        scanf("%d", &parr[*playerCount].matches_played);

        (*playerCount)++;
        printf("Player added successfully!\n\n");
    }
}

void displayPlayer(Player parr[], int playerCount, int index)
{
    if (playerCount == 0)
    {
        printf("No Player in the database!\n");
        return;
    }

    if (index != -1)   // for single player
    {
        printf("\n%-5s %-20s %-10s %-10s %-10s\n", "JNo", "Name", "Runs", "Wickets", "Matches");
        printf("------------------------------------------------------------\n");
        printf("%-5d %-20s %-10d %-10d %-10d\n",
               parr[index].jNo, parr[index].name, parr[index].runs, parr[index].wickets, parr[index].matches_played);
    }
    else  // for all player
    {
        printf("\n%-5s %-20s %-10s %-10s %-10s\n", "JNo", "Name", "Runs", "Wickets", "Matches");
        printf("------------------------------------------------------------\n");

        for (int i = 0; i < playerCount; i++)
        {
            printf("%-5d %-20s %-10d %-10d %-10d\n",
                   parr[i].jNo, parr[i].name, parr[i].runs, parr[i].wickets, parr[i].matches_played);
        }
    }
}


void removePlayer(Player parr[], int *playerCount)
{
    if (*playerCount == 0)
    {
        printf("No player to remove!\n");
        return;
    }

    int jersyNo;
    printf("Enter the jersey number of the player to remove: ");
    scanf("%d", &jersyNo);

    int index = -1;
    for (int i = 0; i < (*playerCount); i++)
    {
        if (parr[i].jNo == jersyNo)
        {
            index = i;
            break;
        }
    }

    if (index == -1)
    {
        printf("Player with jersey number %d not found!\n", jersyNo);
        return;
    }

    for (int i = index; i < (*playerCount) - 1; i++)
    {
        parr[i] = parr[i + 1];
    }

    (*playerCount)--;
    printf("Player with jersey number %d removed successfully!\n\n", jersyNo);
}


void searchPlayer(Player parr[], int playerCount)
{
    int searchChoice;
    int found = 0;  

    printf("Search by: \n1. Jersey Number\n2. Name\nEnter your choice: ");
    scanf("%d", &searchChoice);
    getchar();  // clear buffer

    switch (searchChoice) {
        case 1: {
            int jersyNo;
            printf("Enter the jersey number of the player to search: ");
            scanf("%d", &jersyNo);

            for (int i = 0; i < playerCount; i++) {
                if (parr[i].jNo == jersyNo) {
                    found = 1;
                    displayPlayer(parr, playerCount, i);  // Display the found player
                    break;
                }
            }
            if (!found) {
                printf("Player with Jersey Number %d not found.\n\n", jersyNo);
            }
            break;
        }

        case 2: {
            char playerName[20];
            printf("Enter the name of the player to search: ");
            fgets(playerName, sizeof(playerName), stdin);
            playerName[strcspn(playerName, "\n")] = 0;  

            for (int i = 0; i < playerCount; i++) {
                char cpy[20];
                strcpy(cpy , (parr[i].name));
                if (strstr(strlwr(cpy), strlwr(playerName)) != NULL) {
                    found = 1;
                    displayPlayer(parr, playerCount, i);  // Display the found player
                    break;
                }
            }
            if (!found) {
                printf("Player with name %s not found.\n\n", playerName);
            }
            break;
        }

        default:
            printf("Invalid choice! Please select a valid search option.\n\n");
    }
}

void updatePlayer(Player parr[], int playerCount)
{
    if (playerCount == 0)
    {
        printf("No players available to update.\n");
        return;
    }

    int jersyNo;
    printf("Enter the jersey number of the player to update: ");
    scanf("%d", &jersyNo);

    int index = -1;
    for (int i = 0; i < playerCount; i++)
    {
        if (parr[i].jNo == jersyNo)
        {
            index = i;
            break;
        }
    }
    if (index == -1)
    {
        printf("Player with jersey number %d not found.\n", jersyNo);
        return;
    }

    int choice;
    do
    {
        printf("\nUpdating details for player: %s\n", parr[index].name);
        printf("What do you want to update?\n");
        printf("1. Runs\n");
        printf("2. Wickets\n");
        printf("3. Matches Played\n");
        printf("0. Exit Update Menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter new total runs (current: %d)", parr[index].runs);
            scanf("%d", &parr[index].runs);
            printf("Runs updated succesfully!\n");
            break;

        case 2:
            printf("Enter new total wickets (current: %d)", parr[index].wickets);
            scanf("%d", &parr[index].wickets);
            printf("Wickets updated succesfully!\n");
            break;

        case 3:
            printf("Enter new total matches played (current: %d)", parr[index].matches_played);
            scanf("%d", &parr[index].matches_played);
            printf("Matches played updated successfully!\n");
            break;

        case 0:
            printf("Exiting update menu.\n");
            break;

        default:
            printf("Invalid choice! Please try again.\n");
            break;
        }

    } while (choice != 0);

    printf("player record updated succesfully!\n\n");
}

void displayTopPlayers(Player parr[], int playerCount)
{
    if (playerCount == 0)
    {
        printf("No players in the database.\n");
        return;
    }

    // Sort players by runs
    for (int i = 0; i < playerCount - 1; i++)
    {
        for (int j = i + 1; j < playerCount; j++)
        {
            if (parr[i].runs < parr[j].runs)
            {
                Player temp = parr[i];
                parr[i] = parr[j];
                parr[j] = temp;
            }
        }
    }

    printf("\nTop 3 Players by Runs:\n");
    for (int i = 0; i < playerCount && i < 3; i++)
    {
        printf("%d. %s - Runs: %d\n", i + 1, parr[i].name, parr[i].runs);
        printf("\n");
    }

    // Sort players by wickets in descending order
    for (int i = 0; i < playerCount - 1; i++)
    {
        for (int j = i + 1; j < playerCount; j++)
        {
            if (parr[i].wickets < parr[j].wickets)
            {
                Player temp = parr[i];
                parr[i] = parr[j];
                parr[j] = temp;
            }
        }
    }

    printf("\nTop 3 Players by Wickets:\n");
    for (int i = 0; i < (playerCount < 3 ? playerCount : 3); i++)
    {
        printf("%d. %s - Wickets: %d\n", i + 1, parr[i].name, parr[i].wickets);
        printf("\n");
    }
}
