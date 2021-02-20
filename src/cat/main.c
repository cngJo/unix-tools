#include <stdio.h>
#include <stdlib.h>

char* read_file(char* filename) {
    char* buffer;
    size_t result;
    long size;

    // Open the file
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fputs("File Error", stderr);
        exit(1);
    }

    // determine the length of the file
    fseek(file, 0, SEEK_END);
    size = ftell(file);
    rewind(file);
    buffer = malloc(size);

    // read the file
    result = fread(buffer, 1, size, file);
    if (result != size) {
        fputs("Reading error 2", stderr);
        exit(3);
    }

    // close the file
    fclose(file);

    return buffer;
}

int main(int argc, char** argv) {
    // the filename we want to print lives in the second argument we get
    char* filename = argv[1];

    char* file_content = read_file(filename);

    printf("%s\n", file_content);

    return 0;
}