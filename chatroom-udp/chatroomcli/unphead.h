#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <signal.h>
#include <sys/select.h>
#include <sys/time.h>
#include <sys/wait.h>

#define _INT_NAME (64)

#define _INT_TEXT (512)


#define CERR(fmt, ...) \
    fprintf(stderr,"[%s:%s:%d][error %d:%s]" fmt "\r\n",__FILE__, __func__, __LINE__, errno, strerror(errno),##__VA_ARGS__)

#define CERR_EXIT(fmt, ...) \
    CERR(fmt,##__VA_ARGS__),exit(EXIT_FAILURE)

#define IF_CHECK(code) \
    if((code) < 0) \
		CERR_EXIT(#code)



struct umessage
{
    char type;         		//1		2	3	      
	char name[_INT_NAME];  
	char text[_INT_TEXT]; 
};

/*
typedef struct ucNode
{
    struct sockaddr_in addr;
	struct ucNode* next;
} *ucNode_t ;

static inline ucNode_t _new_ucNode(struct sockaddr_in* pa)
{
	ucNode_t node = calloc(sizeof(struct ucNode), 1);    
	if(NULL == node)
		CERR_EXIT("calloc sizeof struct ucNode is error. ");
	node->addr = *pa;
	return node;
}

static inline void _insert_ucNode(ucNode_t head, struct sockaddr_in* pa)
{
    ucNode_t node = _new_ucNode(pa);
	node->next = head->next;
	head->next = node;    
}

static void _login_ucNode(ucNode_t head, int sd, struct sockaddr_in* pa, struct umessage* msg)
{
    _insert_ucNode(head, pa);
	head = head->next;
	while(head->next)
	{
		head = head->next;
		IF_CHECK(sendto(sd, msg, sizeof(*msg), 0, (struct sockaddr*)&head->addr, sizeof(struct sockaddr_in)));
	}
}


static void _broadcast_ucNode(ucNode_t head, int sd, struct sockaddr_in* pa, struct umessage* msg)
{
    int flag = 0;
	while(head->next)
	{
		head = head->next;
		if((flag) || !(flag=memcmp(pa, &head->addr, sizeof(struct sockaddr_in))==0))
		{
			IF_CHECK(sendto(sd, msg, sizeof(*msg), 0, (struct sockaddr*)&head->addr, sizeof(struct sockaddr_in)));
		}
	}
}

static void _quit_ucNode(ucNode_t head, int sd, struct sockaddr_in* pa, struct umessage* msg)
{
    int flag = 0;
	while(head->next)
	{
		if((flag) || !(flag = memcmp(pa, &head->next->addr, sizeof(struct sockaddr_in))==0))
		{
			IF_CHECK(sendto(sd, msg, sizeof(*msg), 0, (struct sockaddr*)&head->next->addr, sizeof(struct sockaddr_in)));
			head = head->next;
		}        
		else
		{ 
			ucNode_t tmp = head->next;
			head->next = tmp->next;
			free(tmp);
		}
	}        
}

static void _destroy_ucNode(ucNode_t* phead)
{
    ucNode_t head;
	if((!phead) || !(head=*phead)) return;    
	while(head)
	{
		ucNode_t tmp = head->next;
		free(head);
		head = tmp;
	}    
	*phead = NULL;
}

*/
