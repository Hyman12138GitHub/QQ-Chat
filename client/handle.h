#ifndef __HANDLE__
#define __HANDLE__

void Wait_Dian();
void My_Fgets(char *buf, int bufsize, FILE *stream);
void Check_Screen();
void Handle_See_Board();
void Reg(int sockfd, struct chat *temp);
void Log(int sockfd, struct chat *temp);
void Chat_One(int sockfd, struct chat *temp);
void Chat_All(int sockfd, struct chat *temp);
void See(int sockfd, struct chat *temp);
void Data(int sockfd, struct chat *temp);
void Face(int sockfd, struct chat *temp);
void Hi(int sockfd, struct chat *temp);
void Change(int sockfd, struct chat *temp);
void Password(int sockfd, struct chat *temp);
void Trans(int sockfd, struct chat *temp);
void Kick(int sockfd, struct chat *temp);
void Shut(int sockfd, struct chat *temp);
void Remove(int sockfd, struct chat *temp);
void Cancel(int sockfd, struct chat *temp);
void Exit_Tell(int sockfd, struct chat *temp);
void Exit_Tell_Kick(int sockfd, struct chat *temp);

#endif
