#define BOOL int

unsigned char* __crossmemcpy(const unsigned char* pSrc2, const unsigned char* pSrc1, int nSize);
unsigned char* __randmem(int nSize);
BOOL __scanmem(unsigned char* pMem, int nSize);
