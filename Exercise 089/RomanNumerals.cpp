/*   Roman numerals
 
Problem 89
For a number written in Roman numerals to be considered valid there are basic rules which must be followed. Even though the rules allow some numbers to be expressed in more than one way there is always a "best" way of writing a particular number.

For example, it would appear that there are at least six ways of writing the number sixteen:

IIIIIIIIIIIIIIII
VIIIIIIIIIII
VVIIIIII
XIIIIII
VVVI
XVI

However, according to the rules only XIIIIII and XVI are valid, and the last example is considered to be the most efficient, as it uses the least number of numerals.

The 11K text file, roman.txt (right click and 'Save Link/Target As...'), contains one thousand numbers written in valid, but not necessarily minimal, Roman numerals; see About... Roman Numerals for the definitive rules for this problem.

Find the number of characters saved by writing each of these in their minimal form.

Note: You can assume that all the Roman numerals in the file contain no more than four consecutive identical units.

Pergjigje:  743   */

#define MAXLEN 40
#define N 1000

int charvalue(char ch){
        switch (ch){
                case 'I':
                        return 1;
                case 'V':
                        return 5;
                case 'X':
                        return 10;
                case 'L':
                        return 50;
                case 'C':
                        return 100;
                case 'D':
                        return 500;
                case 'M':
                        return 1000;
                default: //???
                        return 0;
        }
}

int numbervalue(char *number){
        int i, result = 0;

        for (i = 0; i < strlen(number); i++){
                switch (number[i]){
                        //Substractive pairs
                        case 'I':
                                if (i == strlen(number) - 1 ||
                                (number[i+1] != 'V' && number[i+1] != 'X'))
                                        result += 1;
                                else{
                                        result += charvalue(number[i+1]) - 1;
                                        i++;
                                }
                                break;
                        case 'X':
                                if (i == strlen(number) - 1 ||
                                (number[i+1] != 'L' && number[i+1] != 'C'))
                                        result += 10;
                                else{
                                        result += charvalue(number[i+1]) - 10;
                                        i++;
                                }
                                break;
                        case 'C':
                                if (i == strlen(number) - 1 ||
                                (number[i+1] != 'D' && number[i+1] != 'M'))
                                        result += 100;
                                else{
                                        result += charvalue(number[i+1]) - 100;
                                        i++;
                                }
                                break;
                        // Normal case
                        default:
                                result += charvalue(number[i]);
                }
        }
        return result;
}

int minimize (int number){
        int result = 0,
                aux = number;

        result += aux /1000;
        aux %= 1000;

        if (aux / 500 > 0 && aux / 100 != 9){
                result += aux /500;
                aux %= 500;
        }

        switch (aux / 100){
                case 9: // 900: CM
                case 4: // 400: CD
                        result += 2;
                        break;
                default:
                        result += aux /100;
                        break;
        }
        aux %= 100;

        if (aux / 50 > 0 && aux / 10 != 9){
                result += aux /50;
                aux %= 50;
        }
        switch (aux / 10){
                case 4: //40: XL
                case 9: //90: XC
                        result += 2;
                        break;
                default:
                        result += aux / 10;
                        break;
        }
        aux %= 10;

        if (aux / 5 > 0 && aux != 9){
                result += aux /5;
                aux %= 5;
        }

        switch (aux){
                case 4: // IV
                case 9: // IX
                        result += 2;
                        break;
                default:
                        result += aux;
                        break;
        }

        return result;
}

int main(int argc, char **argv){
        FILE *file = fopen("roman.txt", "rb");
        int i;
        unsigned charsbefore = 0, charsafter = 0;
        char line[MAXLEN];

        if (file == NULL){
                printf("File error.\n");
                return 1;
        }

        for (i = 0; i < N; i++){
                fscanf(file, "%s\n", &line);
                charsbefore += strlen(line);
                charsafter += minimize( numbervalue(line) );
        }

        fclose(file);

        printf("chars before: %u; chars after: %u; saved: %d\n",
               charsbefore, charsafter, charsbefore - charsafter);
        return 0;
}