# libft: Function Descriptions

This file explains every function in libft: what it does and how to use it.

All functions start with `ft_` and are declared in `libft.h`. Compile your program with:

```bash
cc -Wall -Wextra -Werror main.c -L. -lft -o program
```

## Contents

1. [Memory functions](#1-memory-functions)
2. [Character functions](#2-character-functions)
3. [String functions](#3-string-functions)
4. [Conversion and allocation](#4-conversion-and-allocation)
5. [String functions that allocate memory](#5-string-functions-that-allocate-memory)
6. [File descriptor output](#6-file-descriptor-output)
7. [Linked list functions](#7-linked-list-functions)

---

## 1. Memory functions

### ft_memset

```c
void *ft_memset(void *s, int c, size_t n);
```

Fills the first `n` bytes of the memory area `s` with the byte `c`. Returns `s`.

```c
char buf[5];
ft_memset(buf, 'A', 5);   // buf = "AAAAA" (no '\0')
```

### ft_bzero

```c
void ft_bzero(void *s, size_t n);
```

Sets the first `n` bytes of `s` to zero. Returns nothing.

```c
char buf[5] = "abcd";
ft_bzero(buf, 5);         // all 5 bytes are now 0
```

### ft_memcpy

```c
void *ft_memcpy(void *dst, const void *src, size_t n);
```

Copies `n` bytes from `src` to `dst`. The two areas must **not overlap**. Returns `dst`.

```c
char src[] = "hello";
char dst[6];
ft_memcpy(dst, src, 6);   // dst = "hello"
```

### ft_memmove

```c
void *ft_memmove(void *dst, const void *src, size_t len);
```

Copies `len` bytes from `src` to `dst`, like `ft_memcpy`, but it is safe when the two areas **overlap**. Returns `dst`.

```c
char str[] = "abcdef";
ft_memmove(str + 2, str, 4);   // str = "ababcd"
```

### ft_memchr

```c
void *ft_memchr(const void *s, int c, size_t n);
```

Looks for the first occurrence of the byte `c` in the first `n` bytes of `s`. Returns a pointer to the byte, or `NULL` if not found.

```c
char *p = ft_memchr("hello", 'l', 5);   // p points to "llo"
```

### ft_memcmp

```c
int ft_memcmp(const void *s1, const void *s2, size_t n);
```

Compares the first `n` bytes of `s1` and `s2`. Returns `0` if they are equal, otherwise the difference between the first two bytes that differ (as `unsigned char`).

```c
ft_memcmp("abc", "abd", 3);   // negative number
ft_memcmp("abc", "abc", 3);   // 0
```

---

## 2. Character functions

All of these take an `int` and return an `int`.

### ft_isalpha

```c
int ft_isalpha(int c);
```

Returns non-zero if `c` is a letter (`a-z` or `A-Z`), otherwise `0`.

### ft_isdigit

```c
int ft_isdigit(int c);
```

Returns non-zero if `c` is a digit (`0-9`), otherwise `0`.

### ft_isalnum

```c
int ft_isalnum(int c);
```

Returns non-zero if `c` is a letter or a digit, otherwise `0`.

### ft_isascii

```c
int ft_isascii(int c);
```

Returns non-zero if `c` is in the ASCII table (`0` to `127`), otherwise `0`.

### ft_isprint

```c
int ft_isprint(int c);
```

Returns non-zero if `c` is printable (`32` to `126`), otherwise `0`.

```c
ft_isalpha('a');   // non-zero
ft_isdigit('a');   // 0
ft_isprint('\n');  // 0
```

### ft_toupper

```c
int ft_toupper(int c);
```

Converts a lowercase letter to uppercase. Any other character is returned unchanged.

### ft_tolower

```c
int ft_tolower(int c);
```

Converts an uppercase letter to lowercase. Any other character is returned unchanged.

```c
ft_toupper('a');   // 'A'
ft_tolower('Z');   // 'z'
ft_toupper('5');   // '5'
```

---

## 3. String functions

### ft_strlen

```c
size_t ft_strlen(const char *s);
```

Returns the number of characters in `s`, not counting the final `'\0'`.

```c
ft_strlen("hello");   // 5
```

### ft_strchr

```c
char *ft_strchr(const char *s, int c);
```

Returns a pointer to the **first** occurrence of `c` in `s`, or `NULL` if not found. Searching for `'\0'` returns a pointer to the end of the string.

```c
char *p = ft_strchr("hello", 'l');   // p points to "llo"
```

### ft_strrchr

```c
char *ft_strrchr(const char *s, int c);
```

Returns a pointer to the **last** occurrence of `c` in `s`, or `NULL` if not found.

```c
char *p = ft_strrchr("hello", 'l');   // p points to "lo"
```

### ft_strncmp

```c
int ft_strncmp(const char *s1, const char *s2, size_t n);
```

Compares at most `n` characters of `s1` and `s2`. Stops at the first difference or at `'\0'`. Returns `0` if equal, otherwise the difference between the two differing characters.

```c
ft_strncmp("abc", "abd", 2);   // 0 (only 'ab' is compared)
ft_strncmp("abc", "abd", 3);   // negative number
```

### ft_strlcpy

```c
size_t ft_strlcpy(char *dst, const char *src, size_t dstsize);
```

Copies `src` into `dst`, writing at most `dstsize - 1` characters and always adding `'\0'` (if `dstsize > 0`). Returns the length of `src`. If the return value is `>= dstsize`, the string was truncated.

```c
char dst[4];
ft_strlcpy(dst, "hello", 4);   // dst = "hel", returns 5
```

### ft_strlcat

```c
size_t ft_strlcat(char *dst, const char *src, size_t dstsize);
```

Appends `src` to the end of `dst`, so the total size never goes over `dstsize` (including `'\0'`). Returns the length it tried to create: the length of `src` plus the initial length of `dst` (or `dstsize` if `dst` is longer). If the return value is `>= dstsize`, the string was truncated.

```c
char dst[8] = "abc";
ft_strlcat(dst, "def", 8);   // dst = "abcdef", returns 6
```

### ft_strnstr

```c
char *ft_strnstr(const char *haystack, const char *needle, size_t len);
```

Looks for the string `needle` inside `haystack`, searching at most `len` characters. Returns a pointer to the start of the match, `haystack` if `needle` is empty, or `NULL` if not found.

```c
char *p = ft_strnstr("hello world", "world", 11);   // p points to "world"
char *q = ft_strnstr("hello world", "world", 5);    // NULL
```

---

## 4. Conversion and allocation

### ft_atoi

```c
int ft_atoi(const char *nptr);
```

Converts the beginning of a string to an `int`. It skips leading whitespace, accepts one optional `+` or `-`, then reads digits until a non-digit.

```c
ft_atoi("  -42abc");   // -42
ft_atoi("abc");        // 0
```

### ft_calloc

```c
void *ft_calloc(size_t nmemb, size_t size);
```

Allocates memory for `nmemb` elements of `size` bytes each and sets all bytes to zero. Returns a pointer to the memory, or `NULL` if the allocation fails. Free the result with `free`.

```c
int *arr = ft_calloc(5, sizeof(int));   // 5 ints, all 0
free(arr);
```

### ft_strdup

```c
char *ft_strdup(const char *s1);
```

Returns a new copy of `s1` in freshly allocated memory, or `NULL` if the allocation fails. Free the result with `free`.

```c
char *copy = ft_strdup("hello");
free(copy);
```

---

## 5. String functions that allocate memory

All of these return a new string (or array) in allocated memory, or `NULL` if the allocation fails. **You must free the result.**

### ft_substr

```c
char *ft_substr(char const *s, unsigned int start, size_t len);
```

Returns a new string taken from `s`, starting at index `start`, with at most `len` characters. If `start` is past the end of `s`, it returns an empty string.

```c
char *sub = ft_substr("hello world", 6, 5);   // "world"
free(sub);
```

### ft_strjoin

```c
char *ft_strjoin(char const *s1, char const *s2);
```

Returns a new string that is `s1` followed by `s2`.

```c
char *res = ft_strjoin("hello ", "world");   // "hello world"
free(res);
```

### ft_strtrim

```c
char *ft_strtrim(char const *s1, char const *set);
```

Returns a copy of `s1` with all characters from `set` removed from the **start and the end** (not from the middle).

```c
char *res = ft_strtrim("xxhelloxx", "x");   // "hello"
free(res);
```

### ft_split

```c
char **ft_split(char const *s, char c);
```

Splits `s` into words using the character `c` as the separator. Returns an array of strings ending with a `NULL` pointer. Empty parts (like `"a,,b"`) are skipped. You must free each string, then the array.

```c
char **words = ft_split("hello world 42", ' ');
// words[0] = "hello", words[1] = "world", words[2] = "42", words[3] = NULL

int i = 0;
while (words[i])
    free(words[i++]);
free(words);
```

### ft_itoa

```c
char *ft_itoa(int n);
```

Converts the integer `n` to a string. It handles negative numbers and `INT_MIN`.

```c
char *str = ft_itoa(-123);   // "-123"
free(str);
```

### ft_strmapi

```c
char *ft_strmapi(char const *s, char (*f)(unsigned int, char));
```

Applies the function `f` to each character of `s` (`f` receives the index and the character) and returns a new string made of the results.

```c
char to_upper_even(unsigned int i, char c)
{
    if (i % 2 == 0)
        return (ft_toupper(c));
    return (c);
}

char *res = ft_strmapi("hello", to_upper_even);   // "HeLlO"
free(res);
```

### ft_striteri

```c
void ft_striteri(char *s, void (*f)(unsigned int, char *));
```

Applies `f` to each character of `s` (`f` receives the index and a pointer to the character). It changes `s` **in place** and returns nothing.

```c
void to_upper_even(unsigned int i, char *c)
{
    if (i % 2 == 0)
        *c = ft_toupper(*c);
}

char str[] = "hello";
ft_striteri(str, to_upper_even);   // str = "HeLlO"
```

---

## 6. File descriptor output

These functions write to the file descriptor `fd` using `write`. Use `1` for standard output and `2` for standard error.

### ft_putchar_fd

```c
void ft_putchar_fd(char c, int fd);
```

Writes the character `c` to `fd`.

### ft_putstr_fd

```c
void ft_putstr_fd(char *s, int fd);
```

Writes the string `s` to `fd`.

### ft_putendl_fd

```c
void ft_putendl_fd(char *s, int fd);
```

Writes the string `s` to `fd`, followed by a newline.

### ft_putnbr_fd

```c
void ft_putnbr_fd(int n, int fd);
```

Writes the integer `n` to `fd`. It handles negative numbers and `INT_MIN`.

```c
ft_putchar_fd('A', 1);        // A
ft_putstr_fd("hello", 1);     // hello
ft_putendl_fd("hello", 1);    // hello\n
ft_putnbr_fd(-42, 1);         // -42
ft_putendl_fd("error", 2);    // prints to standard error
```

---

## 7. Linked list functions

These functions use this structure, defined in `libft.h`:

```c
typedef struct s_list
{
    void            *content;
    struct s_list   *next;
}   t_list;
```

### ft_lstnew

```c
t_list *ft_lstnew(void *content);
```

Creates a new node with `content` and `next` set to `NULL`. Returns the node, or `NULL` if the allocation fails.

```c
t_list *node = ft_lstnew(ft_strdup("hello"));
```

### ft_lstadd_front

```c
void ft_lstadd_front(t_list **lst, t_list *new);
```

Adds the node `new` at the **beginning** of the list. `lst` is a pointer to the first node pointer, because the head changes.

```c
t_list *list = NULL;
ft_lstadd_front(&list, ft_lstnew("b"));
ft_lstadd_front(&list, ft_lstnew("a"));   // list: a -> b
```

### ft_lstsize

```c
int ft_lstsize(t_list *lst);
```

Returns the number of nodes in the list.

```c
ft_lstsize(list);   // 2
```

### ft_lstlast

```c
t_list *ft_lstlast(t_list *lst);
```

Returns the last node of the list, or `NULL` if the list is empty.

### ft_lstadd_back

```c
void ft_lstadd_back(t_list **lst, t_list *new);
```

Adds the node `new` at the **end** of the list. If the list is empty, `new` becomes the first node.

```c
ft_lstadd_back(&list, ft_lstnew("c"));   // list: a -> b -> c
```

### ft_lstdelone

```c
void ft_lstdelone(t_list *lst, void (*del)(void *));
```

Deletes one node: calls `del` on its content, then frees the node itself. It does **not** fix the pointer of the previous node.

```c
ft_lstdelone(node, free);
```

### ft_lstclear

```c
void ft_lstclear(t_list **lst, void (*del)(void *));
```

Deletes and frees the node and all the nodes after it (using `del` and `free`), then sets the list pointer to `NULL`.

```c
ft_lstclear(&list, free);   // list is now NULL
```

### ft_lstiter

```c
void ft_lstiter(t_list *lst, void (*f)(void *));
```

Calls the function `f` on the content of every node.

```c
void print_content(void *content)
{
    ft_putendl_fd((char *)content, 1);
}

ft_lstiter(list, print_content);
```

### ft_lstmap

```c
t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
```

Creates a **new list** by applying `f` to the content of each node. If an allocation fails, it clears the new list with `del` and returns `NULL`. The original list is not changed.

```c
void *to_upper_str(void *content)
{
    char *copy = ft_strdup((char *)content);
    int i = 0;

    while (copy && copy[i])
    {
        copy[i] = ft_toupper(copy[i]);
        i++;
    }
    return (copy);
}

t_list *new_list = ft_lstmap(list, to_upper_str, free);
```
