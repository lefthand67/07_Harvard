// Implements a dictionary's functionality

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 100000;

// Hash table
node *table[N];

// words in dictionary counter
int cntr = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
	node *dct_word = table[hash(word)];

	while (dct_word != NULL)
	{
		if(strcasecmp(word, dct_word->word) == 0)
		{
			return true;
		}
		else
		{
			dct_word = dct_word->next;
		}
	}
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
	int word_length = strlen(word);
	int hash_code = 0;
    if (word_length != 0)
	{
		for (int i = 0; i < word_length; i++)
		{
			hash_code += tolower(word[i]);
		}
	}
	return hash_code % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
	FILE *input = fopen(dictionary, "r");
	if (input == NULL)
	{
		fclose(input);
		printf("Could not open a dictionary file error.\n");
		return false;
	}
	
	char word[LENGTH+1];
	while(fscanf(input, "%s", word) != EOF)
	{
		node *n = malloc(sizeof(node));
		if (n == NULL)
		{
			fclose(input);
			printf("Could not allocate memory error.\n");
			return false;
		}
		
		strcpy(n->word, word);

		int idx = hash(word);
		n->next = table[idx];
		table[idx] = n;
		cntr++;
	}
	fclose(input);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return cntr;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
	for (int i = 0; i < N; i ++)
	{
		node *dct_word = table[i];
		while(dct_word != NULL)
		{
			node *next = dct_word->next;
			free(dct_word);
			dct_word = next;
		}
	}
    return true;
}
