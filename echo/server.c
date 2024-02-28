#include "csapp.h"

void	echo(int connfd);
void	sig_handler(int sig);

int main(int ac, char **av) {
	int						listenfd, connfd;
	socklen_t				c_len;
	struct sockaddr_storage	c_addr;
	char					c_hostname[MAXLINE], c_port[MAXLINE];

	if (ac != 2) {
		fprintf(stderr, "usage: %s <port>\n", av[0]);
		exit(0);
	}

	signal(SIGTSTP, sig_handler);

	listenfd = Open_listenfd(av[1]);
	while(1) {
		c_len = sizeof(struct sockaddr_storage);
		connfd = Accept(listenfd, (SA *)&c_addr, &c_len);
		Getnameinfo((SA *)&c_addr, c_len, c_hostname, MAXLINE, c_port, MAXLINE, 0);
		printf("Connected to (%s, %s)\n", c_hostname, c_port);
		echo(connfd);
		Close(connfd);
	}
	exit(0);
}

void echo(int connfd) {
	size_t	n;
	char	buf[MAXLINE];
	rio_t	rio;

	Rio_readinitb(&rio, connfd);
	while ((n = Rio_readlineb(&rio, buf, MAXLINE)) != 0) {
		printf("server received %d bytes\n", (int)n);
		Rio_writen(connfd, buf, n);
	}
}

void sig_handler(int sig) {
	if (sig == SIGTSTP)
		exit(146);
}
