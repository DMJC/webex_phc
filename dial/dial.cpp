#include "dial.h"

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

string dial(string auth_token, string number){
CURL *curl;
string readBuffer;
CURLcode res;
curl_global_init(CURL_GLOBAL_ALL);
curl = curl_easy_init();
if (curl){
curl_easy_setopt(curl, CURLOPT_URL, "https://webexapis.com/v1/telephony/calls/dial");
struct curl_slist *list = NULL;
list = curl_slist_append(list,"Content-Type: application/json");
auth_token = "Authorization: Bearer " + auth_token;
cout << auth_token << endl;
list = curl_slist_append(list, auth_token.c_str());
curl_easy_setopt(curl, CURLOPT_HTTPHEADER, list);
number = "{\"destination\": \"" + number + "\"}";
cout << number << endl;
curl_easy_setopt(curl, CURLOPT_POSTFIELDS, number.c_str());
curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
res = curl_easy_perform(curl);
    if(res != CURLE_OK)
      fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
    curl_easy_cleanup(curl);
  }
  curl_global_cleanup();
    string delimiter = "\",";
    string caller_id = readBuffer.substr(0, readBuffer.find(delimiter));
    delimiter = ":\"";
    caller_id = caller_id.erase(0, caller_id.find(delimiter));
    caller_id = caller_id.erase(0, 2);
    cout << caller_id << endl;
return caller_id;
}
