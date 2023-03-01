#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define INT_TO_CHAR(c) c + '0'

void printhelp()
{
    printf("SYNTAX: win-95-keygen [keyamount]\nGITHUB: OkiStuff/win-95-keygen\n");
}

int main(int argc, const char** argv)
{
    if (argc < 2)
    {
        printf("ERROR: Not enough arguments.\n");
        printhelp();
        return 1;
    }
    
    const int KEY_AMOUNT = (atoi(argv[1]) * 12); // XXX-XXXXXXX\n = 12 Characters
    
    char keys[KEY_AMOUNT + 1];
    keys[KEY_AMOUNT] = '\0';
    
    memset(&(keys[0]), 0, KEY_AMOUNT + 1);
    
    char starter[] = "000-";
    int iterations = 0;
    
    printf("Generating product keys... this may take a moment\n\n");
    for (int i = 0; i < KEY_AMOUNT; iterations++)
    {
        // Populate starter characters
        keys[i] = starter[0];
        keys[i + 1] = starter[1];
        keys[i + 2] = starter[2];
        keys[i + 3] = starter[3];
        
        int buffer[7];
        buffer[0] = (int)((iterations / 1000000) % 10);
        buffer[1] = (int)((iterations / 100000) % 10);
        buffer[2] = (int)((iterations / 10000) % 10);
        buffer[3] = (int)((iterations / 1000) % 10);
        buffer[4] = (int)((iterations / 100) % 10);
        buffer[5] = (int)((iterations / 10) % 10);
        buffer[6] = (int)((iterations / 1) % 10);
        
        if (buffer[6] == 0 || buffer[6] == 8 || buffer[6] == 9) continue; // Ending of 0,8,9 is blacklisted. Invalid so try next iteration
        else if ((buffer[0] + buffer[1] + buffer[2] + buffer[3] + buffer[4] + buffer[5] + buffer[6]) % 7 == 0)
        {
            int index = i + 4;
            keys[index + 0] = INT_TO_CHAR(buffer[0]);
            keys[index + 1] = INT_TO_CHAR(buffer[1]);
            keys[index + 2] = INT_TO_CHAR(buffer[2]);
            keys[index + 3] = INT_TO_CHAR(buffer[3]);
            keys[index + 4] = INT_TO_CHAR(buffer[4]);
            keys[index + 5] = INT_TO_CHAR(buffer[5]);
            keys[index + 6] = INT_TO_CHAR(buffer[6]);
            keys[index + 7] = '\n';
            
            i += 12;
            continue;
        }
    }
    
    printf("=== KEYS START ===\n%s=== KEYS END ===\n", keys);
    return 0;
}