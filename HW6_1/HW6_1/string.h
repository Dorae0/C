int __strlen(char* pStr);
void __strcpy(char* pDst, const char* pSrc);
char* __strcpyEx(char* pDst, const char* pSrc);
char* __strcat(char* pDst, const char* pSrc);
char* __strrot(char* pStr, int n);
// 이 이후의 함수는 과제 이외의 범위입니다.
char* __strchr(const char* s, int c);
char* __strrchr(const char* s, int c);
int __strcmp(const char* s1, const char* s2);
int __stricmp(const char* s1, const char* s2);
int __strncmp(const char* s1, const char* s2, int n);
int __strnicmp(const char* s1, const char* s2, int n);
size_t __strcspn(const char* c1, const char* c2);
char* __strlwr(char* s);
char* __strncat(char* pDst, const char* pSrc, size_t maxlen);
char* __strncpy(char* pDst, const char* pSrc, size_t maxlen);