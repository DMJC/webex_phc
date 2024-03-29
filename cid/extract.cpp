#include <string>
#include <iostream>

using namespace std;
int main(void){
	string call_string = "{\"callId\":\"Y2lzY29zcGFyazovL3VzL0NBTEwvY2FsbGhhbGYtNzUyNDkwODUzOjA\",\"callSessionId\":\"MjVjNmEwNWYtYWQyOS00YWRmLWI4YzMtZTU5MWY1ZjYzNzY0\"}";
	string delimiter = "\",";
	string caller_id = call_string.substr(0, call_string.find(delimiter));
	delimiter = ":\"";
	caller_id = caller_id.erase(0, caller_id.find(delimiter));
	caller_id = caller_id.erase(0, 2);
	cout << caller_id << endl;
return 0;
}
