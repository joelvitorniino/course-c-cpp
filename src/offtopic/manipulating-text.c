#include <stdio.h>

int main()
{
    FILE *file;
    char text[100];

    file = fopen("./textfile.txt", "r");

    while(!feof(file))
    {
        fscanf(file, "%s\n", &text);
        printf("%s\n", text);
    }

    fclose(file);

    return 0;
}