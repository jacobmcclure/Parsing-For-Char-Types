//-----------------------------------------------------------------------------
//   Jacob McClure (jatmcclu@ucsc.edu)
//   
//   charType.c
//   Reads all characters from an input file and checks for the number of
//   alphabetica, numerical, punctuation, and whitespace characters, separates
//   them, then prints the results in an output file in order the order of:
//   (1) line number; (2) alphebetical characters on that line; (3) numerical
//   characters on that line; (4) punctuation characters on that line;
//   (5) whitespace characters on that line.
//-----------------------------------------------------------------------------

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<assert.h>
#include<string.h>

#define MAX_STRING_LENGTH 100
// function prototype 

void extract_chars(char* s, char* a, char* d, char* p, char* w);

// function main which takes command line arguments
int main(int argc, char* argv[]){
   FILE* in;            // handle for input file           
   FILE* out;           // handle for output file      
   char* line;          // string holding input line 
   char* alpha_num;     // string holding all alpha-numeric chars
   char* dig;       // string holding all digits
   char* wsp;       // sring holding all white spaces
   char* punc;      // string holding all punctuations 

   // check command line for correct number of arguments
   if( argc != 3 ){
      printf("Usage: %s input-file output-file\n", argv[0]);
      exit(EXIT_FAILURE);
   }
   // open input file for reading
   if( (in=fopen(argv[1], "r"))==NULL ){
      printf("Unable to read from file %s\n", argv[1]);
      exit(EXIT_FAILURE);
   }
   // open output file for writing
   if( (out=fopen(argv[2], "w"))==NULL ){
      printf("Unable to write to file %s\n", argv[2]);
      exit(EXIT_FAILURE);
   }

   // allocate strings line and alpha_num on the heap
   line = calloc(MAX_STRING_LENGTH+1, sizeof(char) );
   alpha_num = calloc(MAX_STRING_LENGTH+1, sizeof(char) );
   dig = calloc(MAX_STRING_LENGTH+1, sizeof(char) );
   wsp = calloc(MAX_STRING_LENGTH+1, sizeof(char) );
   punc = calloc(MAX_STRING_LENGTH+1, sizeof(char) );
   assert( line!=NULL && alpha_num!=NULL );

   // read each line in input file, extract alpha-numeric characters
   while( fgets(line, MAX_STRING_LENGTH, in) != NULL ){
      extract_chars(line, alpha_num, dig, punc, wsp); 
      int linenum;
      linenum++;
      fprintf(out, "line %d contains:\n", linenum);
      if (strlen(alpha_num) == 1) {
         fprintf(out, "%ld alphabetic character: %s\n", strlen(alpha_num), alpha_num);
      }
      if (strlen(alpha_num) != 1) {
         fprintf(out, "%ld alphabetic characters: %s\n", strlen(alpha_num), alpha_num);
      }
      if (strlen(dig) == 1) {
         fprintf(out, "%ld numeric character: %s\n", strlen(dig), dig);
      }
      if (strlen(dig) != 1) {
         fprintf(out, "%ld numeric characters: %s\n", strlen(dig), dig);
      }
      if (strlen(punc) == 1) {
         fprintf(out, "%ld punctuation character: %s\n", strlen(punc), punc);
      }
      if (strlen(punc) != 1) {
         fprintf(out, "%ld punctuation characters: %s\n", strlen(punc), punc);
      }
      if (strlen(wsp) == 1) {
         fprintf(out, "%ld whitespace character: %s\n", strlen(wsp), wsp);
      }
      if (strlen(wsp) != 1) {
         fprintf(out, "%ld whitespace characters: %s\n", strlen(wsp), wsp);
      }

   }

   // free heap memory
   free(line);
   free(alpha_num);
   free(dig);
   free(wsp);
   free(punc);

   // close input and output files
   fclose(in);
   fclose(out);

   return EXIT_SUCCESS;
}

// function definition 
void extract_chars(char* s, char* a, char* d, char* p, char* w){
   int i=0, j=0, k=0, n=0, m=0;

   while(s[i]!='\0' && i<MAX_STRING_LENGTH){
      if(isalpha( (int) s[i]) ) {
         a[j++] = s[i];

      }
      if(isdigit( (int) s[i]) ) {
         d[k++] = s[i];

      }
      if(ispunct( (int) s[i]) ) {
         p[n++] = s[i];

      }
      if(isspace( (int) s[i]) ) {
         w[m++] = s[i];

      }
      i++;
   }
   a[j] = '\0';
   d[k] = '\0';
   p[n] = '\0';
   w[m] = '\0';
}             
