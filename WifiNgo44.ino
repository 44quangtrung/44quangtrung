#include <ESP8266WiFi.h>
#include <lwip/napt.h>
#include <lwip/dns.h>
#include <dhcpserver.h>

#define NAPT 1000
#define NAPT_PORT 10

#if HAVE_NETDUMP
#include <NetDump.h>
void dump(int netif_idx, const char* data, size_t len, int out, int success) {
  (void)success;
  {
    netDump(Serial, data, len);
  }
}
#endif

void setup() {

   WiFi.begin("FPT1", "vannhucu");
   while ( WiFi.status() != WL_CONNECTED) {
   delay(500);
   }

  // give DNS servers to AP side
  dhcps_set_dns(0, WiFi.dnsIP(0));
  dhcps_set_dns(1, WiFi.dnsIP(1));

  WiFi.softAPConfig(  // enable AP, with android-compatible google domain
    IPAddress(172, 217, 28, 254),
    IPAddress(172, 217, 28, 254),
    IPAddress(255, 255, 255, 0));

  WiFi.softAP("http://44quangtrung.cf", "");
 
  err_t ret = ip_napt_init(NAPT, NAPT_PORT);
  if (ret == ERR_OK) {
    ret = ip_napt_enable_no(SOFTAP_IF, 1);
  }
     ESP.getFreeHeap();
     

}

void loop() {
  

}
