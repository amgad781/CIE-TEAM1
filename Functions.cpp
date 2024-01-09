//#include <iostream>
//#include <chrono>
//#include <thread>
//#include "gameConfig.h"
//#include "CMUgraphicsLib/CMUgraphics.h"
//#include "CMUgraphicsLib/auxil.h"
//#include "Functions.h"
//using namespace std;
//using namespace chrono;
//
//void Timer(window* pWind, char cKeyData, keytype kType)
//{
//	while (kType != ESCAPE)
//	{
//		pWind->SetPen(BLACK);
//		pWind->SetFont(40, BOLD, BY_NAME, "Arial");
//		kType = pWind->GetKeyPress(cKeyData);
//		int seconds = 01;
//		int minutes = 0;
//
//		pWind->DrawInteger(config.timerUprLftX, config.timerUprLftY, minutes);
//		pWind->DrawInteger(config.timerUprLftX + 35, config.timerUprLftY, seconds);
//		pWind->DrawString(config.timerUprLftX + 25, config.timerUprLftY, ":  ");
//		
//
//		 //Simulate some work
//		this_thread::sleep_for(chrono::seconds(1));
//
//		 //Get the current time point again
//		auto end = high_resolution_clock::now();
//
//		 //Calculate the duration between start and end
//		auto duration = chrono::duration_cast<chrono::seconds>(end - start);
//
//		 //Check if one second has passed
//		if (duration.count() >= 1)
//			seconds++;
//
//		if (seconds == 59)
//		{
//			seconds = 0;
//			minutes++;
//		}
//
//		pWind->DrawRectangle(config.timerUprLftX, config.timerUprLftY, config.windWidth, config.toolBarHeight);
//		pWind->UpdateBuffer();
//	}
//}
//
//void Lives(window* pWind)
//{
//
//}
