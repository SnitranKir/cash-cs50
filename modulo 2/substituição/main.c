#include <cs50.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

bool check(string key);

int main(int argc, string argv[])
{

    setlocale(LC_ALL, "portuguese");

    if(argc != 2)
    {
        printf("Use: ./main.c chave de substituição");

        return 1;
    }
    else if(!check(argv[1]))
    {
        printf("É necessário 26 caracteres...");
    
        return 1;
    }

    string resposta = get_string("\n\nSe voce for codificar um texto digite S, caso vc queira decodificar um texto, digite N\n");
    
    if(strcmp(resposta, "S") == 0)
    {

        char texto[] = {argv[1][0], argv[1][1], argv[1][2], argv[1][3], argv[1][4], argv[1][5], argv[1][6], argv[1][7], argv[1][8], argv[1][9], argv[1][10], argv[1][11], argv[1][12], argv[1][13], argv[1][14], argv[1][15], argv[1][16], argv[1][17], argv[1][18], argv[1][19], argv[1][20], argv[1][21], argv[1][22], argv[1][23], argv[1][24], argv[1][25]};

        string frase_simples = get_string("Insira o texto que sera codificado: ");

        for(int i = 0; i < strlen(frase_simples); i++)
        {
            if(isalpha(frase_simples[i]) && isupper(frase_simples[i]))
            {
                int endereco = frase_simples[i] - 65;

                printf("%c", toupper(texto[endereco]));
            }
            else if(isalpha(frase_simples[i]) && islower(frase_simples[i]))
            {
                int endereco = frase_simples[i] - 97;

                printf("%c", texto[endereco]);
            }  
            else
            {
                printf("%c",frase_simples[i]);
            }  
        }
    }
    else if(strcmp(resposta, "N") == 0)
    {

        char texto[] = {argv[1][0], argv[1][1], argv[1][2], argv[1][3], argv[1][4], argv[1][5], argv[1][6], argv[1][7], argv[1][8], argv[1][9], argv[1][10], argv[1][11], argv[1][12], argv[1][13], argv[1][14], argv[1][15], argv[1][16], argv[1][17], argv[1][18], argv[1][19], argv[1][20], argv[1][21], argv[1][22], argv[1][23], argv[1][24], argv[1][25]};

        string frase_simples = get_string("Insira o texto que sera decodificado: ");

        for(int j = 0; j < strlen(frase_simples); j++)
        {
            for(int i = 0; i < 26; i++)
            {
                if(isalpha(frase_simples[j]) && isupper(frase_simples[j]) && frase_simples[j] == toupper(texto[i]))
                {
                    printf("%c", 65 + i);
                }
                else if(isalpha(frase_simples[j]) && islower(frase_simples[j]) && frase_simples[j] == texto[i])
                {
                    printf("%c", 97 + i);
                }
                else if(!isalpha(frase_simples[j]))
                {
                    printf("%c", frase_simples[j]);

                    break;
                }
            } 
        
        }
        
    }
    else
    {
        printf("Insira somente \" S \" ou \" N \" ");
    }
}

bool check(string key)
{
    int tamanho;

    tamanho = strlen(key);

    if(tamanho < 26)
    {
        return false;
    }
    for(int i = 0; i < tamanho; i++)
    {
        if(!isalpha(key[i]))
        {
            return false;
        }
        for(int j = i + 1; j < tamanho; j++)
        {
            if(toupper(key[i]) == toupper(key[j]))
            {
                return false;
            }
        }
    }
    
    return true;
}