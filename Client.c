#include <stdio.h>
#include <sys/socket.h>
#include <linux/if_packet.h>
#include <net/ethernet.h>
#include <unistd.h>
#include <netinet/in.h>

#define SIZE 10
unsigned char buf[SIZE]= "123\n";

int main() {
        int s = socket(AF_INET, SOCK_DGRAM, 0);

        // Привязка сокета к интерфейсу
        struct sockaddr_in addr;
        addr.sin_family = AF_INET;
        addr.sin_port = 217;
        bind(s, &addr, sizeof(addr));
        int c = 0;
        while(c < 2) {
                size_t ret = sendto(s, &buf, 10, 0, NULL, 0);
                printf("ret = %lu\n", ret);
                c++;
        }

        close(s);
        return 0;
}

