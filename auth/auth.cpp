#include "auth.h"

string auth(void){
CURL *curl;
CURLcode res;
curl_global_init(CURL_GLOBAL_ALL);
curl = curl_easy_init();
string username;
string password;

cout << "Enter a Username" << endl;
cin >> username;
cout << "Enter a Password" << endl;
cin >> password;

if (curl){
curl_easy_setopt(curl, CURLOPT_URL, "https://webexapis.com/v1/authorize");
struct curl_slist *list = NULL;
list = curl_slist_append(list,"Content-Type: application/json");
list = curl_slist_append(list,"Authorization: Bearer YzM2OTAzNjItYjE1NS00ZWU4LTg2MGUtOWYyYzk0MTFiMGEyMDgzOGVmNDQtYjdk_PF84_43f0f16a-8814-4d73-905f-ef9df603ef61");
curl_easy_setopt(curl, CURLOPT_HTTPHEADER, list);
curl_easy_setopt(curl, CURLOPT_POSTFIELDS, "{\"destination\": \"0400278993\"}");
res = curl_easy_perform(curl);
    if(res != CURLE_OK)
      fprintf(stderr, "curl_easy_perform() failed: %s\n",
              curl_easy_strerror(res));
 
    /* always cleanup */
    curl_easy_cleanup(curl);
  }
  curl_global_cleanup();
string bearer_token = "YzM2OTAzNjItYjE1NS00ZWU4LTg2MGUtOWYyYzk0MTFiMGEyMDgzOGVmNDQtYjdk_PF84_43f0f16a-8814-4d73-905f-ef9df603ef61";
return bearer_token;
}
