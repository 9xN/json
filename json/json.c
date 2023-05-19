#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "json.h"

void json_add_pair(jsonObject *json, const char *key, const char *value) {
    if (json->count >= MAX_JSON_SIZE) {
        printf("JSON limit reached\n");
        return;
    }

    strncpy(json->pairs[json->count].key, key, sizeof(json->pairs[json->count].key) - 1);
    strncpy(json->pairs[json->count].value, value, sizeof(json->pairs[json->count].value) - 1);
    json->count++;
}

char* json_to_string(const jsonObject *json) {
    char *result = (char *)malloc(MAX_JSON_SIZE * sizeof(char));
    if (result == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }

    snprintf(result, MAX_JSON_SIZE, "{");
    for (int i = 0; i < json->count; i++) {
        snprintf(result + strlen(result), MAX_JSON_SIZE - strlen(result), "\"%s\": \"%s\"", json->pairs[i].key, json->pairs[i].value);
        if (i != json->count - 1) {
            snprintf(result + strlen(result), MAX_JSON_SIZE - strlen(result), ", ");
        }
    }
    snprintf(result + strlen(result), MAX_JSON_SIZE - strlen(result), "}");

    return result;
}
