#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

int getpath(int argc, char **argv) {
    char *path = getenv("PATH");
    char *dir = strtok(path, ":");
    int found = 0;
	int i;
	struct stat st;

	if (argc < 2) {
        printf("Usage: %s filename ...\n", argv[0]);
        return 0;
    }
    while (dir != NULL) {
        for (i = 1; i < argc; i++) {
            char *filepath = (char *)malloc(strlen(dir) + strlen(argv[i]) + 2);
            sprintf(filepath, "%s/%s", dir, argv[i]);

            if (stat(filepath, &st) == 0) {
                printf("%s\n", filepath);
                found = 1;
            }

            free(filepath);
        }
        dir = strtok(NULL, ":");
    }

    if (!found) {
        printf("No files found in PATH.\n");
    }

    return 0;
}
