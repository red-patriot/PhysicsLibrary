#ifndef Physics_Export_h_INCLUDED
#define Physics_Export_h_INCLUDED

#ifdef PHYSICSLIBRARY_EXPORTS
#   define PHYSICSLIBRARY_API __declspec(dllexport)
#else
#   define PHYSICSLIBRARY_API __declspec(dllimport)
#endif

#endif
