/* File: palindrome.c 
   Author: Olivia Davis
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> //allows to use "bool" as a boolean type
#include <ctype.h>
#include <string.h>

/*Optional functions, uncomment the next two lines
 * if you want to create these functions after main: */
//bool readLine(char** line, size_t* size, size_t* length);

/* 
  * NOTE that I used char** for the line above... this is a pointer to
  * a char pointer.  I used this because of the availability of
  * a newer function getline which takes 3 arguments (you should look it
  * up) and the first argument is a char**.  You can create a char*, say
  * called var, and to make it a char** just use &var when calling this
  * function.  If this is too confusing, you can use fgets instead.  Feel
  * free to change the function prototypes as you need them.
  * Also, note the use of size_t as a type.  You can look this up, but
  * essentially, this is just a special type of int to track sizes of
  * things like strings...
*/

bool isPalindrome(const char* line, size_t len){
  int start = 0;
  int end = len;

  while(start < end){
    if(line[start] != line[end])
      return false;
    start++;
    end--;
  }
  return true;
}

int main(int argc, char *argv[]){
  char word[1000];
  char new_word[1000];
  do{
    printf("word> ");
    fgets(word, sizeof(word), stdin);
    int len = strcspn(word, "\n");
    word[len] = '\0';

    int i = 0;
    int characters = 0;
    while (i < len){
      if(isalpha(word[i])){
        new_word[characters] = tolower(word[i]);
        characters++;
      }
      i++;
    }
    new_word[characters] = '\0';

    bool is_palindrome = isPalindrome(new_word,characters-1);

    if (is_palindrome){
       printf("\"%s\" is a palindrome\n", word);
    }else{
       printf("\"%s\" is not a palindrome\n", word);
    }

  }while(strcmp(word,"."));
}
