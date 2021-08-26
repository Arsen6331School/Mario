#include <stdio.h>

int get_valid_height();
int ask_for_height();
void print_padded_pound(int);
void print_n(char, int);
void print_row(int, int);
void print_pyramid(int);

int main()
{
    // Get valid height (>= 1 && <= 8)
    int height = get_valid_height();
    // Print pyramid of specified height
    print_pyramid(height);
}

// get_valid_height keeps asking for a height on stdin
// until a valid one (>= 1 && <= 8) is provided.
int get_valid_height()
{
    int height;
    // Ask for height until greater than one and less than 8
    do
    {
        height = ask_for_height();
    }
    while (height < 1 || height > 8);
    return height;
}

// ask_for_height prints the height prompt and gets
// the input from stdin as an integer
int ask_for_height()
{
    // Print prompt
    printf("Height: ");
    char input[100];
    // Get input string
    fgets(input, 100, stdin);
    int height;
    // Scan input string for integer
    sscanf(input, "%i", &height);
    return height;
}

// print_pyramid prints a pyramid of specified height
void print_pyramid(int height)
{
    for (int i = 1; i <= height; i++)
    {
        print_row(height, i);
        printf("\n");
    }
}

// print_row prints one row of the pyramid. it takes
// the total height of the pyramid and the current row.
void print_row(int height, int row_num)
{
    // Get amount of padding spaces needed
    int amount_spaces = height - row_num;
    print_n(' ', amount_spaces);
    print_n('#', row_num);
    printf("  ");
    print_n('#', row_num);
}

// print_n prints the given character the given
// amount of times
void print_n(char character, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%c", character);
    }
}