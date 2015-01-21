#pragma once
#include <list>
#include <vector>


/****************************
*	デリゲート基盤クラス
****************************/
class IC_BaseDelegate{
public:
	IC_BaseDelegate(){}				// コンストラクタ
	virtual ~IC_BaseDelegate(){}	// デストラクタ
	
	// 演算子のオーバロード
	virtual void operator()(void) = 0;

};


/****************************
*	デリゲートクラス
****************************/
template<class T>
class C_Delegate : public IC_BaseDelegate{
public:
	// 関数ポインタ宣言
	typedef void (T::*Func)();


	// setアクセサ
	static IC_BaseDelegate* CreateDelegator( T* pObject, Func function );


	// 演算子のオーバロード
	void operator()( void ) override;


private:
	void SetData( T* pObject, Func function );


	// メンバ変数
	T*		m_pObject;
	Func	Function;
};


/*⇒⇒⇒⇒⇒⇒⇒⇒⇒⇒⇒⇒⇒⇒⇒⇒⇒⇒⇒⇒⇒⇒⇒⇒⇒ setアクセサ ⇒⇒⇒⇒⇒⇒⇒⇒⇒⇒⇒⇒⇒⇒⇒⇒⇒⇒⇒⇒⇒⇒⇒⇒⇒⇒⇒*/


template<class T>
IC_BaseDelegate* C_Delegate<T>::CreateDelegator( T* pObject, Func function ){
	C_Delegate* pDelegator = new C_Delegate;
	pDelegator->SetData( pObject, function );

	return pDelegator;
}


/*⇒⇒⇒⇒⇒⇒⇒⇒⇒⇒⇒⇒⇒⇒⇒⇒⇒⇒⇒⇒⇒⇒⇒⇒⇒ メソッド ⇒⇒⇒⇒⇒⇒⇒⇒⇒⇒⇒⇒⇒⇒⇒⇒⇒⇒⇒⇒⇒⇒⇒⇒⇒⇒⇒*/


template<class T>
void C_Delegate<T>::operator()( void ){
	// イベント実行
	(m_pObject->*Function)();
}



template<class T>
void C_Delegate<T>::SetData( T* pObject, Func function ){
	m_pObject = pObject;
	Function = function;
}