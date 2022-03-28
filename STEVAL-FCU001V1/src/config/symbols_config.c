
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
#define SYMBOLS_IGNORE_STR 1
#define SYMBOLS_IGNORE_SEM 1
#define SYMBOLS_IGNORE_MQ 1
#define SYMBOLS_IGNORE_TIME 1
#define SYMBOLS_IGNORE_RAND 1
#define SYMBOLS_IGNORE_ENV 1
#define SYMBOLS_USE_IPRINTF 1

#define fgetwc 0
#define fgetws 0
#define fputwc 0
#define fputws 0
#define fwide 0
#define fwprintf 0
#define fwscanf 0
#define swprintf 0
#define swscanf 0
#define ungetwc 0
#define vfwprintf 0
#define vfwscanf 0
#define vswprintf 0
#define vswscanf 0
#define vwprintf 0
#define vwscanf 0
#define wprintf 0
#define wscanf 0
#define wcstod 0
#define wcstof 0
#define wcstol 0
#define wcstold 0
#define wcstoll 0
#define wcstoul 0
#define wcstoull 0
#define btowc 0
#define mbrlen 0
#define mbrtowc 0
#define mbsinit 0
#define mbsrtowcs 0
#define wcrtomb 0
#define wctob 0
#define wcsrtombs 0
#define wcscat 0
#define wcschr 0
#define wcscmp 0
#define wcscoll 0
#define wcscpy 0
#define wcscspn 0
#define wcslen 0
#define wcsncat 0
#define wcsncpy 0
#define wcspbrk 0
#define wcsrchr 0
#define wcsspn 0
#define wcsstr 0
#define wcstok 0
#define wcsxfrm 0
#define wmemchr 0
#define wmemcmp 0
#define wmemcpy 0
#define wmemmove 0
#define wmemset 0
#define wcsftime 0
#define _ctype_ 0
#define __locale_mb_cur_max 0

#define signal 0
#define sigaction 0
#define pthread_sigmask 0
#define sigprocmask 0
#define sigpending 0
#define sigsuspend 0
#define pthread_kill 0
#define sigqueue 0
#define sigwait 0
#define sigtimedwait 0
#define sigwaitinfo 0
#define raise 0

#include <sos/symbols/table.h>
