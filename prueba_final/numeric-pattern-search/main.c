#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    if (argc != 3){
        printf("Usage: %s <file> <value>\n", argv[0]);
        return 1;
    }

    int n = 0;
    int *numbers = NULL;
    int target = atoi(argv[2]);
    int count = 0;

    FILE *file = fopen(argv[1], "r");
    if(file == NULL){
        printf("Error: Could not open file\n");
        return 1;
    }

    if(fscanf(file, "%d", &n) != 1 || n <= 0){
        printf("Error: invalid record count\n");
        fclose(file);
        return 1;
    }

    numbers = malloc(n * sizeof(int));
    if(numbers == NULL){
        printf("Error: Memory allocation failed\n");
        fclose(file);
        return 1;
    }

    for(int i=0; i < n; i++) {
        if(fscanf(file, "%d", &numbers[i]) != 1){
            printf("Error: file does not contain the expected records\n");
            free(numbers);
            fclose(file);
            return 1;
        }
    }

    fclose(file);

    for(int i=0; i < n; i++) {
        if (numbers[i] == target) count++;
    }

    printf("=== Number Counter ===\n");
    printf("File: %s\n", argv[1]);
    printf("Numbers loaded: %d\n", n);
    printf("Looking for: %d\n", target);
    printf("Occurrences: %d\n", count);

    free(numbers);

    return 0;
}
