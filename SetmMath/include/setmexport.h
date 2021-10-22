#if defined(_WIN32) || defined(_WIN64)
#if defined(SETM_EXPORTING)
#define SETM_API __declspec(dllexport)
#else
#define SETM_API __declspec(dllimport)
#endif
#else
#define SETM_API
#endif
