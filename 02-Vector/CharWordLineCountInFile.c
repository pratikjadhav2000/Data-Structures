#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void getCharWordLinesInFile(char *filename, int *arr);

int main(int argc, char *argv[])
{

    int *arr = NULL;
    arr = (int *)malloc(3 * sizeof(int));
    assert(arr != NULL);

    if (argc < 2)
        exit(1);

    int totallines = 0;
    int totalwords = 0;
    int totalchars = 0;
    printf("Lines Words Chars   Filename \n");
    for (int i = 1; i < argc; ++i)
    {

        *(arr + 0) = 0;
        *(arr + 1) = 0;
        *(arr + 2) = 0;

        getCharWordLinesInFile(argv[i], arr);
        int no_of_lines = *(arr + 0);
        int no_of_words = *(arr + 1);
        int no_of_chars = *(arr + 2);

        printf(" %d     %d    %d    %s \n", no_of_lines, no_of_words, no_of_chars, argv[i]);
        totallines += no_of_lines;
        totalwords += no_of_words;
        totalchars += no_of_chars;
    }
    printf("------------------------------------------\n");
    printf(" %d     %d   %d         TOTAL \n", totallines, totalwords, totalchars);

    free(arr);
    arr = NULL;

    return 0;
}

void getCharWordLinesInFile(char *filename, int *arr)
{
    FILE *fp;
    fp = fopen(filename, "r");
    char filechar;
    char previous;
    int no_of_lines = 0;
    int no_of_words = 0;
    int no_of_chars = 0;

    // read file
    if (fp == NULL)
    {
        printf("File cannot be read \n");
    }

    while (filechar = fgetc(fp))
    {

        if (filechar == ' ' || filechar == '\n' || filechar == EOF)
        {

            if (filechar != ' ')
                ++no_of_lines;

            if (filechar == EOF && previous == '\n')
                break;

            ++no_of_words;
        }

        if (filechar != EOF && filechar != ' ' && filechar != '\n')
            ++no_of_chars;

        previous = filechar;

        if (filechar == EOF)
            break;
    }

    *(arr + 0) = no_of_lines;
    *(arr + 1) = no_of_words;
    *(arr + 2) = no_of_chars;

    fclose(fp);
}
