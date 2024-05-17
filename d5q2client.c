#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
// client
#define SERV_PORT	2809
#define SERV_IP		"127.0.0.1"
int main() {
	int cli_fd, ret;
	struct sockaddr_in serv_addr;
	int arr[3];
	cli_fd = socket(AF_INET, SOCK_STREAM, 0);
	if(cli_fd < 0) {
		perror("socket() failed");
		_exit(1);
	}

	serv_addr.sin_family = AF_UNIX;
	serv_addr.sin_port ="/tmp/desd1";
	
	ret = connect(cli_fd, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
	if(ret < 0) {
		perror("connect() failed");
		_exit(2);
	}

	do {
		printf("enter the numbers ");

		scanf("%d",&arr);
		write(cli_fd, arr, strlen(arr)+1);

		read(cli_fd, arr, sizeof(arr));
		printf("server: %s\n", arr);
	}while((arr=-1);

	close(cli_fd);
	return 0;
}
