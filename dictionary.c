#include <stdbool.h>
#include "dictionary.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

/**
* Returns true if word is in dictionary else false.
*/
bool check(const char* word)
{
  // TODO
  return false;
}

typedef struct node
{
  char word[LENGTH + 1];
  struct node* next;
}
node;

/**
* Loads dictionary into memory.  Returns true if successful else false.
*/
bool load(const char* dictionary)
{
  // open file
  FILE* fp = fopen(dictionary, "r");
  if (fp == NULL) return false;
  // create a hash table; 0-25
  node* hash[26];
  int value;

  while (!feof(fp))
  {
    node* new_node = malloc(sizeof(node));
    fscanf(fp, "%s", new_node -> word);
    value = new_node -> word[0]-97;
    if (hash[value] == NULL)
    {
      new_node -> next = NULL;
      hash[value] = new_node;
    }
    else {
      node* previous = NULL;
      node* current = hash[value];

      while (current != NULL && current->word > new_node->word)
      {
        node* previous = current;
        current = previous->next;
      }
      new_node -> next = current;

      if (previous == NULL)
      {
        hash[value] = new_node;
      } else {
        previous -> next = new_node;
      }
     return true;  
    }
  }
  return false;
}

/**
* Returns number of words in dictionary if loaded else 0 if not yet loaded.
*/
unsigned int size(void)
{
  // TODO
  return 0;
}

/**
* Unloads dictionary from memory.  Returns true if successful else false.
*/
bool unload(void)
{
  // TODO
  return false;
}
