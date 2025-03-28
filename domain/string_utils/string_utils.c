#include "string_utils.h"


char** split_string(const char* input_str, const char* delimiters, int* out_token_count) {

    char* input_copy = strdup(input_str);
    if (input_copy == NULL) {
        *out_token_count = 0;
        return NULL;
    }

    int count = 0;
    char* current_token = strtok(input_copy, delimiters);
    while (current_token != NULL) {
        count++;
        current_token = strtok(NULL, delimiters);
    }

    char** result_tokens = (char**)malloc(count * sizeof(char*));
    if (result_tokens == NULL) {
        free(input_copy);
        *out_token_count = 0;
        return NULL;
    }

    strcpy(input_copy, input_str);
    current_token = strtok(input_copy, delimiters);
    for (int i = 0; i < count; i++) {
        result_tokens[i] = strdup(current_token);
        if (result_tokens[i] == NULL) {
            for (int j = 0; j < i; j++) {
                free(result_tokens[j]);
            }
            free(result_tokens);
            free(input_copy);
            *out_token_count = 0;
            return NULL;
        }
        current_token = strtok(NULL, delimiters);
    }

    free(input_copy);
    *out_token_count = count;
    return result_tokens;
}

void free_string_array(char** string_array, int count) {
    for (int i = 0; i < count; i++) {
        free(string_array[i]);
    }
    free(string_array);
}