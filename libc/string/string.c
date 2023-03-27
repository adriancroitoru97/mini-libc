// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>

char *strcpy(char *destination, const char *source)
{
	size_t i = 0;
	while (source[i] != '\0') {
		destination[i] = source[i];
		i++;
	}

	destination[i] = '\0';

	return destination;
}

char *strncpy(char *destination, const char *source, size_t len)
{
	for (size_t i = 0; i < len; i++) {
		destination[i] = 0;
	}

	size_t i = 0;
	while (source[i] != '\0' && i < len) {
		destination[i] = source[i];
		i++;
	}

	return destination;
}

char *strcat(char *destination, const char *source)
{
	size_t len_dest = strlen(destination);
	size_t len_source = strlen(source);

	for (size_t i = 0; i < len_source; i++) {
		destination[len_dest + i] = source[i];
	}

	destination[len_dest + len_source] = '\0';
	return destination;
}

char *strncat(char *destination, const char *source, size_t len)
{
	size_t tmp = strlen(destination);
	if (strlen(source) < len) {
		len = strlen(source);
	}
	for (size_t i = 0; i < len; i++) {
		destination[tmp + i] = source[i];
	}

	destination[tmp + len] = '\0';
	return destination;
}

int strcmp(const char *str1, const char *str2)
{
	if (str1[0] == '\0' && str2[0] == '\0') {
		return 0;
	}

	if (str1[0] < str2[0]) {
		return -1;
	} else if (str1[0] > str2[0]) {
		return 1;
	}

	return strcmp(str1 + 1, str2 + 1);
}

int strncmp(const char *str1, const char *str2, size_t len)
{
	if (len == 0 || (str1[0] == '\0' && str2[0] == '\0')) {
		return 0;
	}

	if (str1[0] < str2[0]) {
		return -1;
	} else if (str1[0] > str2[0]) {
		return 1;
	}

	return strncmp(str1 + 1, str2 + 1, len - 1);
}

size_t strlen(const char *str)
{
	size_t i = 0;

	for (; *str != '\0'; str++, i++)
		;

	return i;
}

char *strchr(const char *str, int c)
{
	size_t len = strlen(str);
	for (size_t i = 0; i < len; i++) {
		if (str[i] == c) {
			return (char*)str + i;
		}
	}
	return NULL;
}

char *strrchr(const char *str, int c)
{
	size_t len = strlen(str) - 1;
	for (size_t i = len; i--; ) {
		if (str[i] == c) {
			return (char*)str + i;
		}
	}
	return NULL;
}

char *strstr(const char *str1, const char *str2)
{
	size_t len1 = strlen(str1), len2 = strlen(str2);
	size_t dif = len1 - len2 + 1;
	for (size_t i = 0; i < dif; i++) {
		if (!strncmp(str1 + i, str2, len2)) {
			return (char*)str1 + i;
		}
	}

	return NULL;
}

char *strrstr(const char *str1, const char *str2)
{
	size_t len1 = strlen(str1), len2 = strlen(str2);
	size_t dif = len1 - len2;
	for (size_t i = dif; i--; ) {
		if (!strncmp(str1 + i, str2, len2)) {
			return (char*)str1 + i;
		}
	}

	return NULL;
}

void *memcpy(void *destination, const void *source, size_t num)
{
	char* dest = (char*) destination;
	const char* src = (const char*) source;

	for (size_t i = 0; i < num; i++) {
		dest[i] = src[i];
	}

	return destination;
}

void *memmove(void *destination, const void *source, size_t num)
{
	char *dest = (char *)destination;
    const char *src = (const char *)source;

    if (dest < src) {
        return memcpy(destination, source, num);
    }

	for (size_t i = num; i--; ) {
		dest[i - 1] = src[i - 1];
	}

    return destination;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	return strncmp((const char*) ptr1, (const char*)ptr2, num);
}

void *memset(void *source, int value, size_t num)
{
	char* s = (char*)source;
	for (size_t i = 0; i < num; i++) {
		s[i] = value;
	}

	return (void*)s;
}
