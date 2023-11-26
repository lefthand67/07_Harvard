#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int count_letters(char *text);
int count_words(char *text);
int count_sentences(char *text);

int main(void) 
{
	char *text = get_string("Text: ");
	// printf("%s\n", text);

	int letters = count_letters(text);
	int words = count_words(text);
	int sentences = count_sentences(text);

	double L = (double)letters / (double)words * 100;
	double S = (double)sentences / (double)words * 100;
    double index = 0.0588*L - 0.296*S - 15.8;

	int grade = (int)round(index); 

//	printf("%i letters\n", letters);
//	printf("%i words\n", words);
//	printf("%i sentences\n", sentences);

	if (grade < 1)
	{
		printf("Before Grade 1\n");
	}
	else if (grade > 15)
	{
		printf("Grade 16+\n");
	}
	else
	{
		printf("Grade %i\n", grade);
	}
	return 0;
}

int count_letters(char *text)
{
	int letters_sum = 0;

	for (int i = 0; i < strlen(text); i++)
	{
		char letter = text[i];
		if (islower(letter) || isupper(letter))
		{
			letters_sum++;
		}
	}
	
	return letters_sum;
}

int count_words(char *text)
{
	int words = 1;

	for (int i = 0; i < strlen(text); i++)
	{
		if (isspace(text[i]))
		{
			words++;
		}
	}

	return words;
}


int count_sentences(char *text)
{
	int sentences = 0;
	int p = (int)'.';

	for (int i = 0; i < strlen(text); i++)
	{
		char s = text[i];

		if (s == p && text[i+1] == p && text[i+2] == p)
		{
			sentences++;
			i += 2;
		}
		else if (s == p || s == (int)'!' || s == (int)'?')
		{
			sentences++;
		}
	}

	return sentences;
}

