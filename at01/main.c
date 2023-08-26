#include <stdio.h>
#include "staticStack.h"

int main(int argc, char* argv[]) {

    //verifica se todos os parametros necessarios foram passados para o programa
    if( argc != 3 ) {
        printf("nao foram passados os parametros necessarios para o programa");
        return 1;
    }

    //capturando nome do arquivo de entrada, abrindo no modo de leitura e verificando abertura
    char* inputFileName = argv[1];
    FILE* inputFile = fopen(inputFileName, "r");
    if( inputFile == NULL  ) {
        printf("Erro ao abrir arquivo de entrada");
        return 1;
    }

    StaticStack stack;
    startStack(&stack);

    //lendo valores do arquivo de entrada até o fim do arquivo e empilhando
    int value;
    while(fscanf(inputFile,"%d", &value) != EOF ) {
        push(&stack, value);
    }

    print(&stack);

    fclose(inputFile);
    //----- processo que necessitava do arquivo de entrada foi encerrado -----

    //capturando nome do arquivo de saida, abrindo no modo de escrita e verificando abertura
    char* outputFileName = argv[2];
    FILE* outputFile = fopen(outputFileName, "w");
    if( outputFile == NULL  ) {
        printf("Erro ao abrir arquivo de saida");
        return 1;
    }

    while (!isEmpty(&stack)) {
        //capturando valor do tipo da stack
        int decimalValue = top(&stack);

        //desempilhando valor do topo
        pop(&stack );

        //vetor que vai armazenar os digitos binarios
        char binary[32];
        int index = 0;

        while (decimalValue > 0) {
            //calcula o dígito binário atual
            binary[index] = (decimalValue % 2) + '0';
            decimalValue /= 2;
            index++;
        }
        binary[index] = '\0';

        //escreve valor convertido no arquivo de saida
        fprintf(outputFile, "%s\n", binary);
    }

    fclose(outputFile);

    return 0;
}
