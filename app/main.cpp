#include <iostream>
#include <map>
#include <vector>

extern "C" {
#include <clog/clog.h>
}
#include <Node/Node.hpp>

using namespace std;

class UI
{
  public:
	template <typename... T>
	using callback = int (*)(UI *, T... t);

	UI()
	{
		cout << "UI Object Created" << endl;
	}

	template <typename... T>
	void set(std::string, callback<T...>, std::vector<std::string> *);

	template <typename... T>
	void run(std::string, T...);
};

template <typename... T>
void UI::set(std::string name, UI::callback<T...> cb, std::vector<std::string> *input_info)
{
}

template <typename... T>
void UI::run(std::string name, T... t){};

class FLTKUI : public UI
{
  public:
	FLTKUI();
	template <typename... T>
	void set(std::string, callback<T...>, std::vector<std::string> *);
	template <typename... T>
	void run(std::string, T...);
};

FLTKUI::FLTKUI()
{
}

template <typename... T>
std::map<std::string, UI::callback<T...>> commands;

template <typename... T>
void FLTKUI::set(std::string name, UI::callback<T...> cb, std::vector<std::string> *input_info)
{
	commands<T...>.insert(std::make_pair(name, cb));
	for (const std::string &s : *input_info)
	{
		//
	}
}

template <typename... T>
void FLTKUI::run(std::string name, T... t)
{
	std::cout << "Launching Predefined function" << endl;
	UI::callback<T...> cb = commands<T...>[name];
	if (cb == nullptr)
	{
		log_fat("TAG", "Empty callback");
	}
	cb(new UI(), t...);
}

int real_function(UI *ui, std::string hostname, int port)
{
	node::Node *node = new node::Node();
	if (node->connect(hostname.c_str(), port) == 0)
	{
		node->writeln("OKokOKokayy...");
		cout << node->readln() << endl;
	}
	return 0;
}

class Range
{
  public:
	Range()
	{
	}
};

class UserInterface
{
  protected:
	UserInterface()
	{
	}
};

class FLTKGraphicalUserInterface : UserInterface
{
  private:
	static FLTKGraphicalUserInterface *instance;
	FLTKGraphicalUserInterface()
	{
	}

  public:
	FLTKGraphicalUserInterface getInstance()
	{
		return instance;
	}
};

FLTKGraphicalUserInterface *instance = nullptr;

int main(int argc, char *argv[])
{
	UI *ui = new FLTKGraphicalUserInterface::getInstance();
	cout << "Program Start" << endl;
	ui->set("test", new std::vector<std::string>{"Hostname", "Port"}, real_function);
	ui->run("test", "localhost", 22);
}
