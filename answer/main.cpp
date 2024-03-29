#include "answer.h"
using namespace std;
int main(void){
	cout << "enter a bearer token" << endl;
	string bearer_token;
	cin >> bearer_token;
	cout << "enter a caller ID" << endl;
	string caller_id;
	cin >> caller_id;
	answer(bearer_token, caller_id);
return 0;
}
