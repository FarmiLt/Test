#pragma once
#include <list>
#include <vector>


/****************************
*	�f���Q�[�g��ՃN���X
****************************/
class IC_BaseDelegate{
public:
	IC_BaseDelegate(){}				// �R���X�g���N�^
	virtual ~IC_BaseDelegate(){}	// �f�X�g���N�^
	
	// ���Z�q�̃I�[�o���[�h
	virtual void operator()(void) = 0;

};


/****************************
*	�f���Q�[�g�N���X
****************************/
template<class T>
class C_Delegate : public IC_BaseDelegate{
public:
	// �֐��|�C���^�錾
	typedef void (T::*Func)();


	// set�A�N�Z�T
	static IC_BaseDelegate* CreateDelegator( T* pObject, Func function );


	// ���Z�q�̃I�[�o���[�h
	void operator()( void ) override;


private:
	void SetData( T* pObject, Func function );


	// �����o�ϐ�
	T*		m_pObject;
	Func	Function;
};


/*�ˁˁˁˁˁˁˁˁˁˁˁˁˁˁˁˁˁˁˁˁˁˁˁˁ� set�A�N�Z�T �ˁˁˁˁˁˁˁˁˁˁˁˁˁˁˁˁˁˁˁˁˁˁˁˁˁˁ�*/


template<class T>
IC_BaseDelegate* C_Delegate<T>::CreateDelegator( T* pObject, Func function ){
	C_Delegate* pDelegator = new C_Delegate;
	pDelegator->SetData( pObject, function );

	return pDelegator;
}


/*�ˁˁˁˁˁˁˁˁˁˁˁˁˁˁˁˁˁˁˁˁˁˁˁˁ� ���\�b�h �ˁˁˁˁˁˁˁˁˁˁˁˁˁˁˁˁˁˁˁˁˁˁˁˁˁˁ�*/


template<class T>
void C_Delegate<T>::operator()( void ){
	// �C�x���g���s
	(m_pObject->*Function)();
}



template<class T>
void C_Delegate<T>::SetData( T* pObject, Func function ){
	m_pObject = pObject;
	Function = function;
}