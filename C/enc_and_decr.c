// 8 klas

// encrypts and decrypts text, writes and reads from file
// to test: type in the command line "yourfilename.c -t randomkeyboardsmashdoesntmatterreally"

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN (1024*4)

int encrypting(char*);
int decrypting(char*);
int load_file(char*, unsigned char*, unsigned int);
unsigned char enc_function(unsigned char, unsigned char, unsigned char);
unsigned char dec_function(unsigned char, unsigned char, unsigned char);
int save_file_enc(unsigned char[], char*, unsigned int);
int save_file_dec(unsigned char[], char*, unsigned int);
int test();

int main(int argc, char* argv[])
{
    char arrray[1204];
    char* input_name;

    if (argc != 3) {
        printf("Error\n");
        return 0;
    }

    input_name = argv[2];

    if (strcmp(argv[1], "-e") == 0) {
        encrypting(input_name);
    }
    if (strcmp(argv[1], "-d") == 0) {
        decrypting(input_name);
    }
    if (strcmp(argv[1], "-t") == 0) {
        test();
    }

    return 0;
}


int load_file(char* input_name, unsigned char* data, unsigned int max_size)
{
    FILE* fp;
    int bytes;

    memset(data, 0, max_size);

    fp = fopen(input_name, "r");

    if (fp == NULL) {
        printf("there is no file / it can't be open\n");
        return 0;
    }

    bytes = fread(data, 1, max_size, fp);

    fclose(fp);

    return bytes;
}


int encrypting(char* input_name)
{
    unsigned char data[MAX_LEN + 1];
    unsigned char data_output[MAX_LEN + 1];
    unsigned char data_buffer_str[MAX_LEN + 1];
    unsigned char x, y;
    unsigned int i, j, size_str;

    memset(data_output, 0, sizeof(data_output));

    if (load_file(input_name, data, MAX_LEN) == 0) {
        printf("Error\n");
        return 0;
    }

    size_str = load_file(input_name, data, MAX_LEN);

    x = data[(size_str / 2) - 1];
    y = data[(size_str / 2)];

    for (i = 0; i < size_str; i++) {
        data_output[i] = enc_function(data[i], x, y);
    }

    for (j = 0; j <= ((size_str / 2) - 1); j++) {
        data_buffer_str[j] = data_output[j];
    }

    data_buffer_str[(size_str / 2)] = x;
    data_buffer_str[(size_str / 2) + 1] = y;

    j = j + 2;

    for (; j < (size_str + 2); j++) {
        data_buffer_str[j] = data_output[j - 2];
    }

    save_file_enc(data_buffer_str, input_name, size_str);

    return 1;
}


unsigned char enc_function(unsigned char c, unsigned char x, unsigned char y)
{
    return (unsigned char)(c + 127 + x * x - y * y * y);
}


int save_file_enc(unsigned char data_output[], char* input_name, unsigned int size_str)
{
    int i;
    FILE* fp;
    char new_name[1024];

    printf("in save file\n");

    memset(new_name, 0, sizeof(new_name));

    snprintf(new_name, sizeof(new_name) - 1, "%s.encr", input_name);

    printf("new name = %s", new_name);

    fp = fopen(new_name, "w");

    if (fp == NULL) {
        printf("there is no file / it can't be open /some other error\n");
        return 0;
    }

    for (i = 0; i < (size_str + 2); i++) {
        fputc(data_output[i], fp);
    }

    fclose(fp);
}


int decrypting(char* input_name)
{
    unsigned char data[MAX_LEN + 1];
    unsigned char data_output[MAX_LEN + 1];
    unsigned char data_buffer_str[MAX_LEN + 1];
    unsigned char x, y;
    unsigned int i, j, size_str;

    memset(data_output, 0, sizeof(data_output));

    if (load_file(input_name, data, MAX_LEN) == 0) {
        printf("Error\n");
        return 0;
    }

    size_str = load_file(input_name, data, MAX_LEN);

    x = data[(size_str / 2) - 1];
    y = data[(size_str / 2)];

    for (i = 0; i < size_str; i++) {
        data_output[i] = dec_function(data[i], x, y);
    }

    for (j = 0; j < (size_str / 2); j++) {
        data_buffer_str[j] = data_output[j];
    }

    i = j - 1;
    j = j + 1;

    while (j < size_str) {
        data_buffer_str[i] = data_output[j];
        j++;
        i++;
    }

    save_file_dec(data_buffer_str, input_name, size_str);

    return 1;
}


unsigned char dec_function(unsigned char c, unsigned char x, unsigned char y)
{
    return (unsigned char)(c - 127 - x * x + y * y * y);
}


int save_file_dec(unsigned char data_output[], char* input_name, unsigned int size_str)
{
    int i;
    FILE* fp;
    char new_name[1024];

    printf("in save file\n");

    memset(new_name, 0, sizeof(new_name));

    snprintf(new_name, sizeof(new_name) - 1, "%s.decr", input_name);

    printf("new name = %s", new_name);

    fp = fopen(new_name, "w");

    if (fp == NULL) {
        printf("there is no file / it can't be open /some other error\n");
        return 0;
    }

    for (i = 0; i < (size_str - 2); i++) {
        fputc(data_output[i], fp);
    }

    fclose(fp);
}


int test()
{
    unsigned char e_data[4] = { 't', 'e', 's', 't' };
    unsigned char e_data_output[4];
    unsigned char e_data_buffer_str[6];
    unsigned char e_x, e_y;
    unsigned int i, j, e_size_str = 4;

    unsigned char d_data[6];
    unsigned char d_data_output[6];
    unsigned char d_data_buffer_str[4];
    unsigned char d_x, d_y;
    unsigned int d_size_str = 6;

    printf("given text = ");
    for (int i = 0; i < 4; i++) printf("%c", e_data[i]);
    printf("\n");
  
    memset(e_data_output, 0, sizeof(e_data_output));
    memset(e_data_buffer_str, 0, sizeof(e_data_buffer_str));

    e_x = e_data[(e_size_str / 2) - 1];
    e_y = e_data[(e_size_str / 2)];

    for (i = 0; i < e_size_str; i++) {
        e_data_output[i] = enc_function(e_data[i], e_x, e_y);
    }

    for (j = 0; j <= ((e_size_str / 2) - 1); j++) {
        e_data_buffer_str[j] = e_data_output[j];
    }

    e_data_buffer_str[(e_size_str / 2)] = e_x;
    e_data_buffer_str[(e_size_str / 2) + 1] = e_y;

    j = j + 2;

    for (; j < (e_size_str + 2); j++) {
        e_data_buffer_str[j] = e_data_output[j - 2];
    }

    // encrypted

    printf("enc text = ");
    for (int i = 0; i < 6; i++) printf("%c", e_data_buffer_str[i]);
    printf("\n");


    for (i = 0; i < 6; i++) {
        d_data[i] = e_data_buffer_str[i];
    }

    memset(d_data_output, 0, sizeof(d_data_output));

    d_x = d_data[(d_size_str / 2) - 1];
    d_y = d_data[(d_size_str / 2)];

    for (i = 0; i < d_size_str; i++) {
        d_data_output[i] = dec_function(d_data[i], d_x, d_y);
    }

    for (j = 0; j < (d_size_str / 2); j++) {
        d_data_buffer_str[j] = d_data_output[j];
    }

    i = j - 1;
    j = j + 1;

    while (j < d_size_str) {
        d_data_buffer_str[i] = d_data_output[j];
        j++;
        i++;
    }

    printf("decr text = ");
    for (int i = 0; i < 4; i++) printf("%c", d_data_buffer_str[i]);
    printf("\n");
}
