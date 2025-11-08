#include <stdio.h>
#include <stdlib.h>
#include <sys/random.h>

// This is default recommended password length based on the latest recommendations
const int DEFAULT_LENGTH = 16;

// Character keycode indexing
const int LOWERCASE_CHAR_START = (int)'a';
const int LOWERCASE_CHAR_END = (int)'z';
const int UPPERCASE_CHAR_START = (int)'A';
const int UPPERCASE_CHAR_END = (int)'Z';
const int SPECIAL_CHAR_START = (int)'!';
const int SPECIAL_CHAR_END = (int)'@';

const bool DEBUG = false;

int main(int argc, char *argv[])
{
  printf("Generating random password:\n");
  
  const int numOfLowerCaseChars = LOWERCASE_CHAR_END - LOWERCASE_CHAR_START;
  const int numOfUpperCaseChars = UPPERCASE_CHAR_END - UPPERCASE_CHAR_START;
  const int numOfSpecialChars = SPECIAL_CHAR_END - SPECIAL_CHAR_START;

  char characters[numOfLowerCaseChars + numOfUpperCaseChars + numOfSpecialChars];
  int count = 0;

  for(int i = LOWERCASE_CHAR_START; i <= LOWERCASE_CHAR_END; i++) characters[count++] = (char)i;
  for(int i = UPPERCASE_CHAR_START; i <= UPPERCASE_CHAR_END; i++) characters[count++] = (char)i;
  for(int i = SPECIAL_CHAR_START; i <= SPECIAL_CHAR_END; i++) characters[count++] = (char)i;

  char password[DEFAULT_LENGTH + 1];

  if (DEBUG)
  {
    printf("numOfLowerCaseChars: %i\n", numOfLowerCaseChars);
    printf("numOfUpperCaseChars: %i\n", numOfUpperCaseChars);
    printf("numOfSpecialChars: %i\n", numOfSpecialChars);
    printf("Generated characters collection:\n");

    for(int i = 0; i < sizeof characters; i++)
    {
      printf("Character: %c\n", characters[i]);
    }
  }

  // Generate the requested password
  for(int i = 0; i < DEFAULT_LENGTH; i++) 
  {
    unsigned int idx;
    getrandom(&idx, sizeof i, 0);
    idx %= sizeof characters;
    password[i] = characters[idx];
  }

  password[DEFAULT_LENGTH] = '\0';
 
  printf(password);
  
  return 0;
}
