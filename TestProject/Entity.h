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
	// �^�ȗ�
	using list = std::list<IC_BaseDelegate*>;

	C_Entity(){}	// �R���X�g���N�^
	~C_Entity(){
		//Dispose();
	}


	// ���s����
	void Execute(){
		auto iter = m_delegatorList.begin();

		while( iter != m_delegatorList.end() ){
			(*(*iter))();
			++ iter;
		}
	}


	// set�A�N�Z�T
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


	// �����o�ϐ�
	list	m_delegatorList;

};




class Sato{
public:
	void Kill(){
		std::cout << "�R���X" << std::endl;
	}
};



class Shinmiya{
public:
	void Call(){
		std::cout << "����" << std::endl;
	}
};