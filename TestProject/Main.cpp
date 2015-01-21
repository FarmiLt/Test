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

	// オブジェクト
	Sato くそ野郎;
	Shinmiya ちんこ野郎;

	// イベントハンドラの作成
	IC_BaseDelegate* pDelegateSato = C_Delegate<Sato>::CreateDelegator( &くそ野郎, &Sato::Kill );
	IC_BaseDelegate* pDelegateShinmiya = C_Delegate<Shinmiya>::CreateDelegator(&ちんこ野郎, &Shinmiya::Call );

	// イベントハンドラを持たせるオブジェクト
	C_Entity classroom56;
	classroom56.SetEventHandler( pDelegateSato );
	classroom56.SetEventHandler( pDelegateShinmiya );

	// 実行
	classroom56.Execute();

}
