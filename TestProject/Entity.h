#pragma once
#include "Delegater.h"
#include <iostream>
#include <string>


namespace Dispose{
	template<typename T>
	static const void SAFE_DELETE( T*& p ){
		delete p;
		p = nullptr;
	}
}


class C_Entity{
public:
	// 型省略
	using list = std::list<IC_BaseDelegate*>;

	C_Entity(){}	// コンストラクタ
	~C_Entity(){
		//Dispose();
	}


	// 実行処理
	void Execute(){
		auto iter = m_delegatorList.begin();

		while( iter != m_delegatorList.end() ){
			(*(*iter))();
			++ iter;
		}
	}


	// setアクセサ
	void SetEventHandler( IC_BaseDelegate* pDelegator ){
		m_delegatorList.push_back( pDelegator );
	}


private:
	//void Dispose(){
	//	auto iter = m_delegatorList.begin();

	//	while( iter != m_delegatorList.end() ){
	//		Dispose::SAFE_DELETE( *iter );
	//		iter = m_delegatorList.erase( iter );
	//	}
	//}


	// メンバ変数
	list	m_delegatorList;

};




class Sato{
public:
	void Kill(){
		std::cout << "コロス" << std::endl;
	}
};



class Shinmiya{
public:
	void Call(){
		std::cout << "ちんこ" << std::endl;
	}
};