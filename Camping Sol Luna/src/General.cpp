#include <iostream>

using namespace std;

int main(){
     int opc;


    while(true){
        system("cls");
        cout<<"-------MENU PRINCIPAL -------"<<endl;
        cout<<"1.   "<<endl;
        cout<<"2.   "<<endl;
        cout<<"3.   "<<endl;
        cout<<"0.   SALIR"<<endl;
        cout<<"-----------------------------"<<endl<<endl;
        cout<<"OPCION: ";
        cin>>opc;
        system("cls");
        switch(opc){
            case 1:
                    break;
            case 2:
                    break;
            case 3:
                    break;

            case 0:
                    return 0;

                    break;

        }
        system("pause");

    }

	cout<<endl;
	system("pause");
	return 0;

}#include "General.h"

General::General()
{
    //ctor
}

General::~General()
{
    //dtor
}
