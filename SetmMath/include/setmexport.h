#pragma once

#if defined(SETM_EXPORTING)
#    define SETM_API __declspec(dllexport)
#else
#    define SETM_API __declspec(dllimport)
#endif

