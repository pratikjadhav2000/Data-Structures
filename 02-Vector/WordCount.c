#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define SUCCESS 1
#define FAILURE 0

struct word_info
{
    char *word;
    unsigned long long lineno;
    unsigned long long wordno;
};

struct vector_of_word_info
{
    struct word_info **word_detail;
    unsigned long long int size;
    unsigned long long int wordcount;
};

struct vector_of_vector_of_word_info
{
    struct vector_of_word_info *file_detail;
    unsigned long long int size;
};

void readFile(char *filename, struct vector_of_word_info *pv);
int compare_word(char *word1, char *word2);

struct vector_of_word_info *create_vector_word_info();
void append_vector_word_info(struct vector_of_word_info *pv, struct word_info *new_word);
void display_vector_word_info(struct vector_of_word_info *pv, const char *msg);
void destroy_vector_word_info(struct vector_of_word_info **ppv);

struct vector_of_vector_of_word_info *create_vector_of_vector_word_info();
void append_vector_of_vector_of_word_info(struct vector_of_vector_of_word_info *pv, struct vector_of_word_info new_file);
void display_vector_of_vector_of_word_info(struct vector_of_vector_of_word_info *pv, const char *msg);
void destroy_vector_of_vector_of_word_info(struct vector_of_vector_of_word_info **ppv);

int main(int argc, char *argv[])
{

    if (argc < 2)
        exit(1);

    struct vector_of_vector_of_word_info *pvv = NULL;
    pvv = create_vector_of_vector_word_info();

    // read files and store information into vector of files
    for (int i = 1; i < argc; ++i)
    {
        struct vector_of_word_info *pv = NULL;
        pv = create_vector_word_info();
        readFile(argv[i], pv);

        append_vector_of_vector_of_word_info(pvv, *pv);
        // display_vector_word_info(pv, "Words in file");
    }

    // input word to search
    char *word;
    word = NULL;
    word = (char *)malloc(50 * sizeof(char));
    while (1)
    {
        unsigned long long totalcount = 0;

        printf("Enter word to be searched.Press 0 to exit \n");
        scanf("%s", word);

        if (word[0] == '0' && word[1] == '\0')
            break;

        // search word in vector of files
        for (int i = 0; i < pvv->size; ++i)
        {
            unsigned long long count = 0;
            for (int j = 0; j < pvv->file_detail[i].size; ++j)
            {
                if (compare_word(pvv->file_detail[i].word_detail[j]->word, word))
                {
                    printf("In file %s ", argv[i + 1]);
                    printf("Line number %d - ", pvv->file_detail[i].word_detail[j]->lineno);
                    printf("Word number %d \n", pvv->file_detail[i].word_detail[j]->wordno);
                    ++count;
                }
            }
            printf("----------------------------------------------- \n");
            printf("Total word count in file %s is %d\n\n", argv[i + 1], count);

            pvv->file_detail[i].wordcount = count;
            totalcount += count;
        }

        printf("-------------------------------------------------------------------------\n");
        printf("Total word count in All Files is %d\n\n", totalcount);
    }

    free(word);
    word = NULL;
    // display vector of files

    // free vector
    destroy_vector_of_vector_of_word_info(&pvv);

    return 0;
}

int compare_word(char *word1, char *word2)
{
    int i = 0;
    while (word1[i] == word2[i])
    {
        if (word1[i] == '\0')
            return SUCCESS;

        ++i;
    }

    return FAILURE;
}

void readFile(char *filename, struct vector_of_word_info *pv)
{
    FILE *fp;
    fp = fopen(filename, "r");
    char filechar;
    int linenumber = 1;
    int wordnumber = 0;
    int isword = 0;

    // read file
    char readword[50] = "";
    int i = 0;
    if (fp == NULL)
    {
        printf("File cannot be read \n");
    }

    while (filechar = fgetc(fp))
    {

        if (filechar == ' ' || filechar == ',' || filechar == '.' || filechar == '\n' || filechar == EOF)
        {
            if (isword)
            {
                int j;
                char *word;
                word = NULL;
                word = (char *)malloc(50 * sizeof(char));
                // printf("read word : ");
                for (j = 0; j < i; ++j)
                {
                    // printf("%c", readword[j]);
                    word[j] = readword[j];
                }
                word[j] = '\0';
                // printf("\n");

                //  printf("In file %s : Line number %d - Word number %d - Word : %s \n", filename, linenumber, wordnumber, word);
                // add word to vector

                struct word_info *temp = NULL;
                temp = (struct word_info *)malloc(sizeof(struct word_info));
                assert(temp != NULL);
                temp->word = word;
                temp->lineno = linenumber;
                temp->wordno = wordnumber;
                append_vector_word_info(pv, temp);
                temp = NULL;

                // end adding to vector
            }
            isword = 0;

            i = -1;

            if (filechar == '\n')
            {
                ++linenumber;
                wordnumber = 0;
            }
        }
        else if (isword == 0)
        {
            isword = 1;
            ++wordnumber;
        }

        if (isword)
        {
            readword[i] = filechar;
        }
        ++i;

        if (filechar == EOF)
            break;
    }
    fclose(fp);
}

// vector of word_info functions

struct vector_of_word_info *create_vector_word_info()
{
    struct vector_of_word_info *pv = NULL;
    pv = (struct vector_of_word_info *)malloc(sizeof(struct vector_of_word_info));
    assert(pv != NULL);

    pv->word_detail = NULL;
    pv->size = 0;
    pv->wordcount = 0;
    return pv;
}

void append_vector_word_info(struct vector_of_word_info *pv, struct word_info *new_word)
{

    pv->word_detail = (struct word_info **)realloc(pv->word_detail, (pv->size + 1) * sizeof(struct word_info *));
    pv->word_detail[pv->size] = new_word;
    pv->size += 1;
    pv->wordcount = 0;
}

void display_vector_word_info(struct vector_of_word_info *pv, const char *msg)
{

    if (msg != NULL)
        puts(msg);

    for (int i = 0; i < pv->size; ++i)
    {
        printf("%s ", pv->word_detail[i]->word);
        printf("%d ", pv->word_detail[i]->lineno);
        printf("%d\n", pv->word_detail[i]->wordno);
    }
}

void destroy_vector_word_info(struct vector_of_word_info **ppv)
{

    struct vector_of_word_info *pvector = *ppv;
    for (int i = 0; i < pvector->size; ++i)
    {
        free(pvector->word_detail[i]->word);
        pvector->word_detail[i]->word = NULL;
    }
    free(pvector->word_detail);
    pvector->word_detail = NULL;
    free(pvector);
    *ppv = NULL;
}

// vector of vector of word_info functions

struct vector_of_vector_of_word_info *create_vector_of_vector_word_info()
{
    struct vector_of_vector_of_word_info *pv = NULL;
    pv = (struct vector_of_vector_of_word_info *)malloc(sizeof(struct vector_of_vector_of_word_info));
    assert(pv != NULL);
    pv->file_detail = NULL;
    pv->size = 0;
    return pv;
}

void append_vector_of_vector_of_word_info(struct vector_of_vector_of_word_info *pv, struct vector_of_word_info new_file)
{

    pv->file_detail = (struct vector_of_word_info *)realloc(pv->file_detail, (pv->size + 1) * sizeof(struct vector_of_word_info));
    pv->file_detail[pv->size] = new_file;
    pv->size += 1;
}

void display_vector_of_vector_of_word_info(struct vector_of_vector_of_word_info *pv, const char *msg)
{

    if (msg != NULL)
        puts(msg);

    for (int i = 0; i < pv->size; ++i)
    {
        printf("%s \n", (pv->file_detail->wordcount));
    }
}

void destroy_vector_of_vector_of_word_info(struct vector_of_vector_of_word_info **ppv)
{

    struct vector_of_vector_of_word_info *pvector = *ppv;
    destroy_vector_word_info(&pvector->file_detail);
    free(pvector);
    *ppv = NULL;
}
