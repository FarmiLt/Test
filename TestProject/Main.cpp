#include <iostream>
#include "Entity.h"
#include "Delegater.h"
#include "Utility.h"
using namespace std;

void main()
{

	int a = 2;
	int b = 7;

	cout << Add(a, b) << endl;

	cout << Clamp(6, 3, a);
	cout << Clamp(6, 3, b);

	getchar();

	// �I�u�W�F�N�g
	Sato ������Y;
	Shinmiya ���񂱖�Y;

	// �C�x���g�n���h���̍쐬
	IC_BaseDelegate* pDelegateSato = C_Delegate<Sato>::CreateDelegator( &������Y, &Sato::Kill );
	IC_BaseDelegate* pDelegateShinmiya = C_Delegate<Shinmiya>::CreateDelegator(&���񂱖�Y, &Shinmiya::Call );

	// �C�x���g�n���h������������I�u�W�F�N�g
	C_Entity classroom56;
	classroom56.SetEventHandler( pDelegateSato );
	classroom56.SetEventHandler( pDelegateShinmiya );

	// ���s
	classroom56.Execute();

}
