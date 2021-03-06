#pragma once
#include <list>
#include <vector>


/****************************
*	fQ[gîÕNX
****************************/
class IC_BaseDelegate{
public:
	IC_BaseDelegate(){}				// RXgN^
	virtual ~IC_BaseDelegate(){}	// fXgN^
	
	// ZqÌI[o[h
	virtual void operator()(void) = 0;

};


/****************************
*	fQ[gNX
****************************/
template<class T>
class C_Delegate : public IC_BaseDelegate{
public:
	// Ö|C^é¾
	typedef void (T::*Func)();


	// setANZT
	static IC_BaseDelegate* CreateDelegator( T* pObject, Func function );


	// ZqÌI[o[h
	void operator()( void ) override;


private:
	void SetData( T* pObject, Func function );


	// oÏ
	T*		m_pObject;
	Func	Function;
};


/*ËËËËËËËËËËËËËËËËËËËËËËËËË setANZT ËËËËËËËËËËËËËËËËËËËËËËËËËËË*/


template<class T>
IC_BaseDelegate* C_Delegate<T>::CreateDelegator( T* pObject, Func function ){
	C_Delegate* pDelegator = new C_Delegate;
	pDelegator->SetData( pObject, function );

	return pDelegator;
}


/*ËËËËËËËËËËËËËËËËËËËËËËËËË \bh ËËËËËËËËËËËËËËËËËËËËËËËËËËË*/


template<class T>
void C_Delegate<T>::operator()( void ){
	// CxgÀs
	(m_pObject->*Function)();
}



template<class T>
void C_Delegate<T>::SetData( T* pObject, Func function ){
	m_pObject = pObject;
	Function = function;
}