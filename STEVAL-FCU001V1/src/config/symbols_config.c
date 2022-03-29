
#include <sos/symbols.h>

//you can exclude functions groups from the build
#define SYMBOLS_IGNORE_DCOMPLEX 1
#define SYMBOLS_IGNORE_POSIX_TRACE 1 // Always ignore -- deprecated
#define SYMBOLS_IGNORE_SOCKET 1
#define SYMBOLS_IGNORE_LWIP 1

// other ignore switches
#define SYMBOLS_IGNORE_MATH_F 1
#define SYMBOLS_IGNORE_DOUBLE 1
#define SYMBOLS_IGNORE_SCANF 1
#define SYMBOLS_IGNORE_STDIO_FILE 1
#define SYMBOLS_IGNORE_PTHREAD_MUTEX 1
#define SYMBOLS_IGNORE_PTHREAD_COND 1
#define SYMBOLS_IGNORE_AIO 1
#define SYMBOLS_IGNORE_WCTYPE 1
#define SYMBOLS_IGNORE_WCHAR 1
#define SYMBOLS_IGNORE_STR 1
#define SYMBOLS_IGNORE_SEM 1
#define SYMBOLS_IGNORE_MQ 1
#define SYMBOLS_IGNORE_TIME 1
#define SYMBOLS_IGNORE_RAND 1
#define SYMBOLS_IGNORE_ENV 1
#define SYMBOLS_USE_IPRINTF 1
#define SYMBOLS_IGNORE_SIGNAL 1


#include <sos/symbols/table.h>
