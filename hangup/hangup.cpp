#include "hangup.h"

void hangup(string auth_token, string callid){
CURL *curl;
CURLcode res;
curl_global_init(CURL_GLOBAL_ALL);
curl = curl_easy_init();
if (curl){
curl_easy_setopt(curl, CURLOPT_URL, "https://webexapis.com/v1/telephony/calls/hangup");
struct curl_slist *list = NULL;
list = curl_slist_append(list,"Content-Type: application/json");
string auth = "Authorization: Bearer ";
auth = auth + auth_token;
cout << auth << endl;
const char * auth_c = auth.c_str();
list = curl_slist_append(list, auth_c);
curl_easy_setopt(curl, CURLOPT_HTTPHEADER, list);
string call_com = "{\"callId\": \"";
call_com = call_com + callid + "\"}";
cout << call_com << endl;
curl_easy_setopt(curl, CURLOPT_POSTFIELDS, call_com.c_str());
res = curl_easy_perform(curl);
    if(res != CURLE_OK)
      fprintf(stderr, "curl_easy_perform() failed: %s\n",
              curl_easy_strerror(res));

    /* always cleanup */
    curl_easy_cleanup(curl);
  }
  curl_global_cleanup();
}
