
#include <iostream>
#include <iomanip>
#include "clsLoginScreen.h"
#include "clsLoginUserScreen.h"
using namespace std;




int main()
{
	while (true)
	{
		if (!clsLoginScreen::ShowLoginScreen())
		{
			break;
		}
		
	}
	
	return 0;
}

