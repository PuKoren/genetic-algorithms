#include "Genetic.h"

void init(){
    srand(time(NULL));
}

//mutate a true array of bits into memory
//tab is a tab of byte
//mutate to either 0 or 1 every bit of the byte chain
void mutate_bits(unsigned char* tab, int tabSize, int muteRate){
    for(int i = 0; i < tabSize; i++){
        for(int j = 0; j < sizeof(unsigned char)*CHAR_BIT; j++){
            if(rand()%100 < muteRate){
                tab[i] = tab[i] | j;
            }else if(rand()%100 < muteRate){
                tab[i] = tab[i] & ~j;
            }
        }
    }
}

//mutate takes an "binary" char array. Every char in the array is either 1 or 0
//if muteRate makes a mutation occur, the value replaced will be either 0 or 1
void mutate_bytes(unsigned char* tab, int tabSize, int muteRate){
    for(int i = 0; i < tabSize; i++){
        if(rand()%100 < muteRate){
            tab[i] = (tab[i] == 0)?1:0;
        }
    }
}

void int_to_bits(int value, unsigned char* tab){
    tab = new unsigned char[sizeof(int) * CHAR_BIT];
    int mask,masked_n,i =  0;
    for(i; i < sizeof(int) * CHAR_BIT; i += CHAR_BIT){
        mask = 1 << i;
        masked_n = value & mask;
        tab[i] = masked_n >> i;
    }
}
