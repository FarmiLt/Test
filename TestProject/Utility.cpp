#include "Utility.h"


template<typename _T>
_T Max( const _T& a, const _T& b ){
	return a > b ? a : b;
}


template<typename _T>
_T Min(const _T& a, const _T& b){
	return a <= b ? a : b;
}


template<typename _T>
_T Clamp(const _T& max, const _T& min, const _T& aho){
	return Min( Max( min, aho ), max );
}


template<typename _T>
_T Add(const _T &a, const _T &b)
{
	return a + b;
}