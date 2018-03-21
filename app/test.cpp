#include <iostream>
#include <vector>
#include <map>
#include <clog/clog.h>
#include <Node/Node.hpp>
#include <UniversalUI.hpp>
#if defined(FLTK_UI)
#include <FLTKUI.hpp>
#elif defined(CHARACTER_UI)
#include <CharacterUI.hpp>
#endif

using namespace std;
using namespace uui;

typedef struct
{
	std::string hostname;
	int port;
} host_data;

int lol_test(uui::UI *ui, void *obj)
{
	std::string lol = "something is lolly";
	ui->error(lol);
	ui->alert("hello");
}

int test_connection(uui::UI *ui, void *obj)
{
	std::string hostname = ((host_data *)obj)->hostname;
	int port = ((host_data *)obj)->port;
	node::Node *n = new node::Node();
	if (n->connect(hostname.c_str(), port) != 0)
	{
		ui->error("Cannot connect to the service");
		return 0;
	}
	log_inf("TEST", "All are working fine");
	n->writeln("OkokOkokayyOkay...");
	ui->alert(n->readln());
	return 0;
}

void *make_args(std::string s, int i)
{
	return nullptr;
}

int main(int argc, char *argv[])
{
#ifdef FLTK_UI
	UI *ui = new FLTKUI();
#else
	UI *ui = CharacterUI::getInstance();
#endif
	ui->error("Why?");
	ui->alert("I am going to walk you through, are you ready?");
	ui->alert("Be sure to install the dependencies before you continue");
	ui->set("connect", new vector<std::string>{"Hostname", "Port"}, test_connection);
	ui->set("lol", new vector<std::string>{"LOL", "another lOl"}, lol_test);
	ui->run("connect", new host_data{"localhost", 22});
	ui->run("lol", nullptr);
	return 0;
}
