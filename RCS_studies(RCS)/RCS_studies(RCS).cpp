#include <iostream>
#include <Windows.h>

#define k 1.5

using namespace std;

int GetTime(float rpm) {
   return (( 60 / rpm) * 1000);
}

int main()
{
    long recoil[31][2] = { {0,0},{-1,30},{0,36},{4,51},{9,56},{15,58},{14,50},
                            {0,37},{1,1},{-23,21},{-41,11},{-34,9},{-22,7},{-21,5},{-15,4},{8,4},
                            {33,9},{42,10},{47,8},{41,1},{29,-5},{7,-1},{-2,4},{-3,10},{3,9},{7,4},
                            {-3,3},{-27,-2},{-50,-9},{-59,-17},{-56,-14} };

    int len = (sizeof(recoil) / sizeof(DWORD)) / 2;

    int index = 0;

    int delay = GetTime(600);

    cout << delay;

    while (true) {
        while (GetAsyncKeyState(VK_LBUTTON) && index != len) { //Enquanto clicar no botão, vai fazer o movimento para a coordenada
            mouse_event(MOUSEEVENTF_MOVE, long(recoil[index][0] * k), long(recoil[index][1] * k), 0, 0); //Manipula o input mouse
            index++;
            Sleep(delay);
        }

        if (index == len) {
            cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n";
        }

        index = 0; //Tempo de disparo de cada arma
    }

    return 0;
}
