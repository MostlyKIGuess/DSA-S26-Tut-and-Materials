#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_LEN 100

typedef struct {
    char key[MAX_LEN];
    char **words;
    int count;
    int capacity;
} AnagramGroup;

int compareChars(const void *a, const void *b) {
    return (*(char *)a - *(char *)b);
}

void sortString(char *s) {
    int len = strlen(s);
    qsort(s, len, sizeof(char), compareChars);
}

unsigned long hashFunction(const char *str) {
    // http://www.cse.yorku.ca/~oz/hash.html
    unsigned long hash = 5381;
    int c;
    while ((c = *str++))
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    return hash;
}

AnagramGroup *findGroup(AnagramGroup *groups, int *groupCount, const char *key) {
    unsigned long hash = hashFunction(key) % MAX_WORDS;
    for (int i = 0; i < *groupCount; i++) {
        if (strcmp(groups[i].key, key) == 0)
            return &groups[i];
    }
    return NULL;
}

void addToGroup(AnagramGroup *group, const char *word) {
    if (group->count >= group->capacity) {
        group->capacity *= 2;
        group->words = realloc(group->words, group->capacity * sizeof(char *));
    }
    group->words[group->count] = strdup(word);
    group->count++;
}

int main() {
    char *words[] = {"eat", "tea", "tan", "ate", "nat", "bat"};
    int n = sizeof(words) / sizeof(words[0]);

    AnagramGroup groups[MAX_WORDS];
    int groupCount = 0;

    for (int i = 0; i < n; i++) {
        char sortedKey[MAX_LEN];
        strcpy(sortedKey, words[i]);
        sortString(sortedKey);

        AnagramGroup *group = findGroup(groups, &groupCount, sortedKey);

        if (group == NULL) {
            strcpy(groups[groupCount].key, sortedKey);
            groups[groupCount].capacity = 4;
            groups[groupCount].words = malloc(4 * sizeof(char *));
            groups[groupCount].count = 0;
            group = &groups[groupCount];
            groupCount++;
        }

        addToGroup(group, words[i]);
    }

    printf("Grouped Anagrams:\n");
    for (int i = 0; i < groupCount; i++) {
        printf("[");
        for (int j = 0; j < groups[i].count; j++) {
            printf("\"%s\"%s", groups[i].words[j],
                   j < groups[i].count - 1 ? ", " : "");
        }
        printf("]\n");
    }

    for (int i = 0; i < groupCount; i++) {
        for (int j = 0; j < groups[i].count; j++)
            free(groups[i].words[j]);
        free(groups[i].words);
    }

    return 0;
}
