#include<iostream>
#include<vector>
#include<map>
#include <UniversalUI.hpp>
#ifdef FLTK_UI
#include<FLTKUI.hpp>
#elif CHARACTER_UI
#include<CharacterUI.hpp>
#endif
#include <Node/Node.hpp>

using namespace std;
using namespace uui;


typedef struct {
	std::string hostname;
	int port;
} host_data;

int test_connection(uui::UI *ui, void *obj)
{
	std::string hostname = ((host_data *)obj)->hostname;
	int port = ((host_data *)obj)->port;
	node::Node *n = new node::Node();
	if(n->connect(hostname.c_str(), port) != 0)
	{
		ui->error("Cannot connect to the service");
		return 0;
	}
	log_inf("TEST", "All are working fine");
	n->writeln("OkokOkokayyOkay...");
	ui->alert( n->readln() );
	return 0;
}

void *make_args(std::string s, int i)
{
	return nullptr;
}


int main(int argc, char *argv[]){
#ifdef FLTK_UI
	//UI *ui = new FLTKUI();
#else
	//UI *ui = new CharacterUI();
#endif
	FLTKUI *ui = new FLTKUI();
	ui->error("Why?");
	ui->set("connect", new vector<std::string>{"Hostname", "Port"}, test_connection);
	ui->run("connect", new host_data {"localhost", 22});
	return 0;
}
