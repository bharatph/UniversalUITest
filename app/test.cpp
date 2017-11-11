#include<iostream>
#include <UniversalUI.hpp>
#ifdef FLTK_UI
#include<FLTKUI.hpp>
#elif CHARACTER_UI
#include<CharacterUI.hpp>
#endif

using namespace std;
using namespace uui;
void func_test(UI *ui, void *obj)
{
	ui->error("testing dialog");
}

void func_help(UI *ui, void *obj)
{
	ui->alert("you are about to be helped");
}

void func_connect(UI *ui, void *obj)
{
	char *port = (char *)obj;	
	ui->error("cannot connect to the host");
}

int main(int argc, char *argv[]){
#ifdef FLTK_UI
	UI *ui = new FLTKUI();
#else
	UI *ui = new CharacterUI();
#endif
	ui->set("test", func_test);
	ui->set("help", func_help);
	ui->set("connect", func_connect);

	ui->run("connect");
}
