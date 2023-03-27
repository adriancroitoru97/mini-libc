// SPDX-License-Identifier: BSD-3-Clause

#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <internal/essentials.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>

void *malloc(size_t size)
{
	void* ptr = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if (ptr == MAP_FAILED) {
        return NULL;
    }
    mem_list_add(ptr, size);
    return ptr;
}

void *calloc(size_t nmemb, size_t size)
{
	size_t total_size = nmemb * size;
    void* ptr = mmap(NULL, total_size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if (ptr == MAP_FAILED) {
        return NULL;
    }
    memset(ptr, 0, total_size);
    mem_list_add(ptr, total_size);
    return ptr;
}

void free(void *ptr)
{
	if (ptr == NULL) {
        return;
    }

    struct mem_list *item = mem_list_find(ptr);
    if (item == NULL) {
        return;
    }

    int ret = munmap(ptr, item->len);
    if (ret == -1) {
        return;
    }

    mem_list_del(ptr);
}

void *realloc(void *ptr, size_t size)
{
	if (ptr == NULL) {
        return malloc(size);
    }

    if (size == 0) {
        free(ptr);
        return NULL;
    }

    struct mem_list* item = mem_list_find(ptr);
    if (item == NULL) {
        return NULL;
    }

    void* new_ptr = mremap(ptr, item->len, size, MREMAP_MAYMOVE);
    if (new_ptr == MAP_FAILED) {
        mem_list_add(ptr, item->len);
        return NULL;
    }

    item->start = new_ptr;
    item->len = size;
    mem_list_add(new_ptr, size);
    return new_ptr;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
	size_t total_size = nmemb * size;
    return realloc(ptr, total_size);
}
