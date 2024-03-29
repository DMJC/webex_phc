#include "dial/dial.h"
#include "answer/answer.h"
using namespace std;
int main(void){
	cout << "enter a bearer token" << endl;
	string bearer_token;
	cin >> bearer_token;
	string number_to_dial;
	cout << "Enter a Number to Dial" << endl;
	cin >> number_to_dial;
	string call_id = dial(bearer_token, number_to_dial);
	answer(bearer_token, call_id);
return 0;
}
