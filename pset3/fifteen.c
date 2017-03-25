/**
 * fifteen.c
 *
 * Implements Game of Fifteen (generalized to d x d).
 *
 * Usage: fifteen d
 *
 * whereby the board's dimensions are to be d x d,
 * where d must be in [DIM_MIN,DIM_MAX]
 *
 * Note that usleep is obsolete, but it offers more granularity than
 * sleep and is simpler to use than nanosleep; `man usleep` for more.
 */
 
#define _XOPEN_SOURCE 500

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// constants
#define DIM_MIN 3
#define DIM_MAX 9

// board
int board[DIM_MAX][DIM_MAX];

// dimensions
int d;

// prototypes
void clear(void);
void greet(void);
void init(void);
void draw(void);
bool move(int tile);
bool won(void);
void swap(int tile_row, int tile_column, int blank_row, int blank_column, int tile);

int main(int argc, string argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        printf("Usage: fifteen d\n");
        return 1;
    }

    // ensure valid dimensions
    d = atoi(argv[1]);
    if (d < DIM_MIN || d > DIM_MAX)
    {
        printf("Board must be between %i x %i and %i x %i, inclusive.\n",
            DIM_MIN, DIM_MIN, DIM_MAX, DIM_MAX);
        return 2;
    }

    // open log
    FILE *file = fopen("log.txt", "w");
    if (file == NULL)
    {
        return 3;
    }

    // greet user with instructions
    greet();

    // initialize the board
    init();

    // accept moves until game is won
    while (true)
    {
        // clear the screen
        clear();

        // draw the current state of the board
        draw();

        // log the current state of the board (for testing)
        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < d; j++)
            {
                fprintf(file, "%i", board[i][j]);
                if (j < d - 1)
                {
                    fprintf(file, "|");
                }
            }
            fprintf(file, "\n");
        }
        fflush(file);

        // check for win
        if (won())
        {
            printf("ftw!\n");
            break;
        }

        // prompt for move
        printf("Tile to move: ");
        int tile = get_int();
        
        // quit if user inputs 0 (for testing)
        if (tile == 0)
        {
            break;
        }

        // log move (for testing)
        fprintf(file, "%i\n", tile);
        fflush(file);

        // move if possible, else report illegality
        if (!move(tile))
        {
            printf("\nIllegal move.\n");
            usleep(500000);
        }

        // sleep thread for animation's sake
        usleep(500000);
    }
    
    // close log
    fclose(file);

    // success
    return 0;
}

/**
 * Clears screen using ANSI escape sequences.
 */
void clear(void)
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}

/**
 * Greets player.
 */
void greet(void)
{
    clear();
    printf("WELCOME TO GAME OF FIFTEEN\n");
    usleep(2000000);
}

/**
 * Initializes the game's board with tiles numbered 1 through d*d - 1
 * (i.e., fills 2D array with values but does not actually print them).  
 */
void init(void)
{
    for(int row = 0, subtracter = 1; row < d; row++) {
        for(int column = 0; column < d; column++, subtracter++) {
            board[row][column] = d*d-subtracter;
        }
    }
}

/**
 * Prints the board in its current state.
 */
void draw(void)
{
    for(int row = 0; row < d; row++) {
        for(int column = 0; column < d; column++) {
            if(board[row][column] != 0)
                printf("%2i ", board[row][column]);
            else
                printf(" _");
        }
        printf("\n");
    }
}

/**
 * If tile borders empty space, moves tile and returns true, else
 * returns false. 
 */
bool move(int tile)
{
    if(tile > d*d)
        return false;
    int location_blank[2];
    int location_tile[2];
    for(int row = 0; row < d; row++) {
        for(int column = 0; column < d; column++) {
            if(board[row][column] == 0) {
                location_blank[0] = row;
                location_blank[1] = column;
            } else if(board[row][column] == tile) {
                location_tile[0] = row;
                location_tile[1] = column;
            }
        }
    }
    if(location_tile[0] == location_blank[0]-1) {
        if(location_tile[1] == location_blank[1]) {
            swap(location_tile[0], location_tile[1], location_blank[0], location_blank[1], tile);
            return true;
        }
    } else if(location_tile[0] == location_blank[0]+1) {
        if(location_tile[1] == location_blank[1]) {
            swap(location_tile[0], location_tile[1], location_blank[0], location_blank[1], tile);
            return true;
        }
    } else if(location_tile[1] == location_blank[1]-1) {
        if(location_tile[0] == location_blank[0]) {
            swap(location_tile[0], location_tile[1], location_blank[0], location_blank[1], tile);
            return true;
        }
    } else if(location_tile[1] == location_blank[1]+1) {
        if(location_tile[0] == location_blank[0]) {
            swap(location_tile[0], location_tile[1], location_blank[0], location_blank[1], tile);
            return true;
        }
    }
    return false;
}

void swap(int tile_row, int tile_column, int blank_row, int blank_column, int tile) {
    board[blank_row][blank_column] = tile;
    board[tile_row][tile_column] = 0;
}

/**
 * Returns true if game is won (i.e., board is in winning configuration), 
 * else false.
 */
bool won(void)
{
    for(int row = 0, checker = 1; row < d; row++, checker++) {
        for(int column = 0; column < d; column++) {
            if(board[row][column] != checker) {
                return false;
            }
        }
    }   
    return true;
}
