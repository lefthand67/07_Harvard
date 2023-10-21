#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct person
{
    struct person *parents[2];
    char alleles[2];
}
person;

int main(void)
{
	person *p = malloc(sizeof(person));
	p->parents[0] = NULL;
	p->parents[1] = NULL;
	p->alleles[0] = 'a';

    char allele = p->alleles[0];
	printf("hello: %c\n", allele);


	person *s = malloc(sizeof(person));
	s->parents[0] = p;
	printf("again: %c\n", s->parents[0]->alleles[0]);
}
