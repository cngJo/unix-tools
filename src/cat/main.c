#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/// Read the file with the given path
char* read_file(char* file_path)
{
    // 1. determine the length of the file
    // 2. allocate a buffer, with the size of the file
    // 3. read the file
    // 4. return the content of the file

    FILE* file = fopen(file_path, "r");

    // 1. determine the length of the file
    fseek(file, 0, SEEK_END);
    long size = ftell(file) + 1; // add space for the null terminator
    rewind(file);

    // 2. Allicate a buffer, with the size of the file
    char* buffer = malloc(size);

    // read the file contents into the buffer
    fread(buffer, 1, size, file);

    // Close the file
    fclose(file);

    return buffer;
}

int main(int argc, char** argv)
{
    // Check if we got any arguments
    // if we pass nothing to read_file, it will cause an segmentation fault
    if (argc <= 1) {
        printf("No arguments found!\n");
        return 0;
    }

    // Print the content of the file at the path, given in the first argument
    // (at index 0, we get the name of outself)
    printf("%s", read_file(argv[1]));

    return 0;
}