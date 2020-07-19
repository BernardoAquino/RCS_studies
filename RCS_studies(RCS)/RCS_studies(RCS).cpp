#include <iostream>
#include <Windows.h>

using namespace std;

float GetK(float dpi, float sensitivity) { //Calcula constante de multiplicação
    return 1140 / (dpi * sensitivity); 
}

float GetTime(float rpm) { //Calcula tempo do disparo
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

    float K = GetK(800, 2.60); //Calcula a constante através da sensibilidade do CS e DPI do mouse

    cout << K << "\n";

    while (true) {
        while (GetAsyncKeyState(VK_LBUTTON) && index != len) { //Enquanto clicar no botão, vai fazer o movimento para a coordenada
            mouse_event(MOUSEEVENTF_MOVE, long(recoil[index][0] * K), long(recoil[index][1] * K), 0, 0); //Manipula o input mouse
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
