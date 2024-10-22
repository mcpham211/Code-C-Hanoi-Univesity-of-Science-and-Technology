#include <stdio.h>
#include <stdlib.h>

void caesarCipher(char *filename, int offset, char *outfilename) {
    FILE *fin, *fout;
    char ch;

    fin = fopen(filename, "r");
    if (fin == NULL) {
        printf("\n");
        return;
    }

    fout = fopen(outfilename, "w");
    if (fout == NULL) {
        printf("\n");
        fclose(fin);
        return;
    }

    while ((ch = fgetc(fin)) != EOF) {
        if (isalpha(ch)) {
            ch = ch + offset;
            if (isupper(ch)) {
                ch = (ch - 'A') % 26 + 'A';
            } else {
                ch = (ch - 'a') % 26 + 'a';
            }
        }
        fputc(ch, fout);
    }

    fclose(fin);
    fclose(fout);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("%s <tệp_nguồn> <độ_dịch_chuyển> <tệp_đích>\n", argv[0]);
        return 1;
    }

    char *infile = argv[1];
    int offset = atoi(argv[2]);
    char *outfile = argv[3];

    caesarCipher(infile, offset, outfile);

    return 0;
}

