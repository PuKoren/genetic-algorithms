/*
 * Genetic.h
 * Contains every functions needed for genetic algorithms manipulation
 * Every functions is working only with binary values (bits)
 *
 */
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <climits>
#ifndef GENETIC_H_
#define GENETIC_H_

/*Première fonction (Mutation):
        Mutation générique, qui fait muter une chaine binaire.
    Deuxième fonction (Cross Over):
        Deux génomes donnent deux génomes mutés à partir des parents (1 point de croisement, peut être plus)
        Taille des génomes potentiellement variable*/

//first way to mutate bits, using char and modifing bits in memory
void int_to_bits(int value, unsigned char* tab);
void mutate_bits(unsigned char* tab, int tabSize, int muteRate);
void mutate_bytes(unsigned char* tab, int tabSize, int muteRate);

//second way to mutate bits, with short arrays that symbolize bit chain with 0 and 1
void mutate_bits_int(unsigned short* tab, int tabSize, int muteRate);
void crossover_int(unsigned short* tab1, unsigned short* tab2, int tabSize, int muteRate);

//initialise stuff needed to generate populations
void init();

#endif
