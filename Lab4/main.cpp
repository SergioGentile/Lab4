#include "Looper.h"
#include "Message.h"
int main() {
	
	Looper<Message> l;
	Message m;
	
	try {
		m.setMessage("ciao");
		l.postMessage(m);
		m.setMessage("sono");
		l.postMessage(m);
		m.setMessage("Sergio");
		l.postMessage(m);
		l.quit();
		l.postMessage(m);
	}
	catch(std::exception& e){
		std::cout << e.what() << std::endl;
	}
	
	while (1);
	return 0;
}