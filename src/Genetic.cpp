#include "Genetic.h"

void init(){
    srand(time(NULL));
}

//mutate a true array of bits into memory
//tab is a tab of byte
//mutate to either 0 or 1 every bit of the byte chain
void mutate_bits(unsigned char* tab, int tab_size, int mute_rate){
    for(int i = 0; i < tab_size; i++){
        for(int j = 0; j < sizeof(unsigned char)*CHAR_BIT; j++){
            if(rand()%100 < mute_rate){
                tab[i] = tab[i] | j;
            }else if(rand()%100 < mute_rate){
                tab[i] = tab[i] & ~j;
            }
        }
    }
}

//mutate takes an "binary" char array. Every char in the array is either 1 or 0
//if muteRate makes a mutation occur, the value replaced will be either 0 or 1
void mutate_bytes(unsigned char* tab, int tab_size, int mute_rate){
    for(int i = 0; i < tab_size; i++){
        if(rand()%100 < mute_rate){
            tab[i] = (tab[i] == 0)?1:0;
        }
    }
}

//mutate takes a "binary" short array, with values being either 0 or 1.
//if value is not 0 or 1, it is set to 0
unsigned short* mutate_bits_int(unsigned short* tab, int tab_size, int mute_rate){
    unsigned short* tab2 = new unsigned short[tab_size];
    for(int i = 0; i < tab_size; i++){
        tab2[i] = tab[i];
        if(rand()%100 < mute_rate){
            tab2[i] = (tab2[i] == 0)?1:0;
        }
    }
    return tab2;
}

//make a cross over genetic mutation
//between tab1 and tab2, if mutation rate trigger the two branchs will switched
//branches can be switched cross_count times
//returns a "binary" short array with values either 0 or 1
unsigned short* crossover_int(unsigned short* tab1, unsigned short* tab2, int tab_size, int mute_rate, int cross_count){
    unsigned short* tab3 = new unsigned short[tab_size];
    unsigned short* current_branch = (rand()%2 == 0)?tab1:tab2;
    int cross_count_local = 0;
    for(int i = 0; i < tab_size; i++){
        tab3[i] = current_branch[i];
        if(cross_count_local < cross_count && rand()%100 < mute_rate){
            current_branch = (current_branch == tab1)?tab2:tab1;
            cross_count_local++;
        }
    }
    return tab3;
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
