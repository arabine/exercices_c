#include <string.h>
#include <ctype.h>

#include "morse.h"

typedef struct {
    const char *glyph;
    char letter;
} morse_char_t;


static const morse_char_t alphabet[] = {
    {
        "- ---",
        'a'
    },
    {
        "--- - - -",
        'b'
    }
};

static const morse_char_t chiffres[] = {
    {
        "- --- --- --- ---",
        '1'
    }
};

static const char *espace_mot       = "       ";
static const char *espace_lettre    = "   ";


bool can_append(const char *text_to_insert, const char *output_buffer)
{
    bool yes_you_can = false;
    
    if ((strlen(output_buffer) + strlen(text_to_insert)) < MAX_OUTPUT_STRING)
    {
        yes_you_can = true;
    }
    
    return yes_you_can;
}

bool encode(const char *input, char *output)
{
    int len = strlen(input);
    bool success = true;
    
    output[0] = 0; // précaution avant de concaténer des chaînes
    
    for (int i = 0; (i < len) && success; i++)
    {
        // On traite les cas particuliers avant
        if (input[i] == ' ')
        {
            // on vérifie que l'on a encore la place dans le buffer de sortie
            if (can_append(espace_mot, output))
            {
                output = strcat(output, espace_mot);
            }
            else
            {
                success = false;
            }
            continue;
        }
        
        char l = tolower(input[i]);
        
        if (isalpha(l))
        {
            int offset = l - 'a';
            if (can_append(alphabet[offset].glyph, output))
            {
                strcat(output, alphabet[offset].glyph);
            }
            else
            {
                success = false;
            }
        }
        else if (isdigit(l))
        {
            int offset = l - '0';
            
            if (can_append(chiffres[offset].glyph, output))
            {
                strcat(output, chiffres[offset].glyph);
            }
            else
            {
                success = false;
            }
        }
    }
    
    return success;
}

