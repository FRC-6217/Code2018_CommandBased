/*
 * WeekZero.cpp
 *
 *  Created on: Feb 12, 2018
 *      Author: HarpsterT
 */

#include <WeekZero.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define		GAMEDATA_IP  "10.0.100.44"
#define		GAMEDATA_PORT	5555


char* WeekZero::getGameSpecificMessage(){
	static char gamedata_msg[16];
	int sock;
	struct sockaddr_in serv_addr;

	gamedata_msg[0] = '\0';
	if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
		printf("Error creating socket\n");
		return gamedata_msg;
	}
	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(GAMEDATA_PORT);

	if (inet_pton(AF_INET, GAMEDATA_IP, &serv_addr.sin_addr) <= 0) {
		printf("Invalid game data server IP address\n");
		return gamedata_msg;
	}
	if (connect(sock, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
		printf("Error connecting to game data server\n");
		return gamedata_msg;
	}
	if (read(sock, gamedata_msg, sizeof(gamedata_msg)) <= 0) {
		printf("Error reading game data\n");
		return gamedata_msg;
	}
	close(sock);
	printf("returning week zero game data [%s]", gamedata_msg);
	return gamedata_msg;

}
