#include <stdio.h>
#include <string.h>
#include "md5.h"


// soleil  ==> 23206deb7eba65b3fbc80a2ffbc53c28
// baaaaa  ==> 46399f97b09b5ca519a524a3dfc68419
const char *hash_to_find = "23206deb7eba65b3fbc80a2ffbc53c28";

int main()
{
    unsigned char buff[16];
    unsigned char tofindbuff[16];
    md5 ("soleil", 6, buff);

    // On va transformer le hash fourni en décimal

    int j = 0;
    for (int i = 0; i < 32; i+= 2)
    {
        char digit[3] = { hash_to_find[i], hash_to_find[i+1], 0 };
        tofindbuff[j++] = strtoul(digit, NULL, 16);
    }

    char input[7] = {'a', 'a', 'a', 'a', 'a', 'a', 0};
    int col = 1;

   //
    for (input[0] = 'a'; input[0] <= 'z'; input[0]++)
        for (input[1] = 'a'; input[1] <= 'z'; input[1]++)
            for (input[2] = 'a'; input[2] <= 'z'; input[2]++)
                for (input[3] = 'a'; input[3] <= 'z'; input[3]++)
                    for (input[4] = 'a'; input[4] <= 'z'; input[4]++)
                        for (input[5] = 'a'; input[5] <= 'z'; input[5]++) {
                            printf("\rTesting: %s\n", input);
                            fflush(stdout);
                            md5(input, 6, buff);

                            // Compare !
                            int equal = 0;
                            for (int i = 0; i < 16; i++) {
                                if (buff[i] == tofindbuff[i]) {
                                    equal++;
                                }
                            }

                            if (equal == 16) {
                                printf("Found password !\n");
                                return 0;
                            }
                        }

    printf("Digest not found :(\n");
    return 0;
}
