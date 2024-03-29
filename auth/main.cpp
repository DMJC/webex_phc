#include "auth.h"

int main(){
	string auth_token = auth();
	cout << "authorisation token = " << auth_token << endl;
	return 0;
}
