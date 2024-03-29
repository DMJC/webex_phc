#include "token.h"

int main(void){
	string username;
	string password;
	cout << "Enter Username:" << endl;
	cin >> username;
	cout << "Enter Password:" << endl;
	cin >> password;
	string auth_token = token(username, password);
	cout << auth_token << endl;
	return 0;
}
