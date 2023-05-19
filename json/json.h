#ifndef JSON_H
#define JSON_H

#define MAX_JSON_SIZE 4096

typedef struct {
    char key[128];
    char value[128];
} jsonPair;

typedef struct {
    jsonPair pairs[MAX_JSON_SIZE];
    int count;
} jsonObject;

void json_add_pair(jsonObject *json, const char *key, const char *value);
char* json_to_string(const jsonObject *json);

#endif /* JSON_H */
