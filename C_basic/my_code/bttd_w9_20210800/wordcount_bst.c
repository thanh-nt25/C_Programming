/*
  Ho va ten: Nguyen Tuan Thanh
  MSSV: 20210800
  Ma lop: 135307
  Ngay viet chuong trinh: 12/1/2023
  Muc dich chuong trinh: Đếm số từ trong file văn bản
  Ghi chu: trong thu muc di kem
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <ctype.h>

#define WORDCHUNK 9
#define MAXLEN 100

struct WordTree {
  struct WordTree *below, 
                  *above;
  char *word;
  unsigned long used;
};

// ham lay cac ki tu chu va so trong file input
char *GetWord(FILE *input)
{
  char *temp = NULL;
  int byte,
      count,      
      wordsize;        

  for (byte = fgetc(input); !isalnum(byte); byte = fgetc(input))
  {
    if (byte == EOF)
      return NULL;
  }

  if ((temp = malloc(wordsize = WORDCHUNK)) == NULL)
    return NULL;

  for (count = 0; isalnum(byte); byte = fgetc(input))
  {
    if (count == wordsize-1)
    {
      char *temp2;

      if ((temp2 = realloc(temp,wordsize+=WORDCHUNK)) == NULL)
        return NULL;
      else
        temp = temp2;
    }
    *(temp+count++) = byte;
  }

  *(temp+count) = 0;

  ungetc(byte,input);

  return temp;
}

// ham them cac tu vao BST va duyet cay de ghi len file output
int AddWord(char *text, struct WordTree **base)
{
  struct WordTree *temp;
  int direction;

  if ((temp = malloc(sizeof *temp)) == NULL)
    return 0;

  temp->below = temp->above = NULL;
  temp->word = text;
  temp->used = 1;

  if (*base == NULL)	
    *base = temp;	
  else
  {
    struct WordTree *prev = NULL,
                    *this = *base;
    int direction;

    while (this != NULL)
    {
      prev = this;

      if ((direction = strcmp(this->word, temp->word)) == 0)
      {
        this->used += 1;
        free(temp);
        return 0;
      }
      else
        if (direction < 0)
          this = this->above;
        else			
          this = this->below;
    }

    if (direction < 0)
      prev->above = temp;
    else
      prev->below = temp;
  }
  return 1;
}


void DelWord(struct WordTree *root, int trace, FILE *output)
{
  char word[MAXLEN];
  if (root == NULL) return;

  DelWord(root->below,trace, output);
  if (trace) {
    for (int i=0; i< sizeof(root->word)/sizeof(char); ++i){
      word[i] = toupper(root->word[i]);
    }
    fprintf(output, "%s %lu\n", word, (root->used));
  }
  DelWord(root->above,trace, output);
  free(root->word); free(root);
}

void AllWords(FILE *input, int trace, FILE *output)
{
  struct WordTree *root = NULL;
  char *a_word;
  unsigned long wordcount = 0;

  while ((a_word = GetWord(input)) != NULL)
    wordcount += AddWord(a_word, &root);

  DelWord(root,trace,output);
}

// ham check loi cu phap dau vao
int usage(char *name, char *text)
{
  fprintf(stderr,"%s needs 2 parameters: input and output file\n",name);
  if (text != NULL) fprintf(stderr,"%s\n",text);

  return EXIT_FAILURE;
}


int main(int argc, char *argv[])
{
  FILE *input;
  FILE *output;
  unsigned trace = 0;		/* terse */

  // ham thong bao loi
  if (argc == 3){
        trace  = 1;
        if ((input  = fopen(argv[1], "r")) == NULL)
          return usage(argv[0], "Input file not found");
        output = fopen(argv[2], "w+");
        AllWords(input,trace,output);
        printf("Wordcount Successfully to Output file\n");
  }
  else
      return usage(argv[0],NULL);

  fclose(input);
  fclose(output);

  return EXIT_SUCCESS;
}


