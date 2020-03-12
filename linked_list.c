#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SORTING 1

// 구조체 정의 
typedef struct _student {
	char name[64];
	int age;
	struct _student *next;
} student;

// 전역변수 
student *head=NULL;

/*********
노드 추가
*********/ 
void add_student(char *name, int age) {
	student *p=head, *cur;
	
	cur = (student *)malloc(sizeof(student));
	strcpy(cur->name, name);
	cur->age = age;
	cur->next = NULL;
	
#if SORTING==0
	for(p=head; p->next!=NULL; p=p->next);
	p->next = cur;
#else
	for(p=head; p->next!=NULL && age>=p->next->age; p=p->next);
	
	if(p->next==NULL) {
		p->next = cur;
	} else {
		cur->next = p->next;
		p->next = cur;
	}
#endif
}

/*********
노드 출력 
*********/ 
void print_student() {
	student *p=head;
	
	while(p->next!=NULL) {
		p = p->next;
		printf("%s, %d\n", p->name, p->age);
	}
}

/*********
노드 삭제 
*********/ 
void free_student() {
	student *p=head, *tmp;
	
	while(p->next!=NULL) {
		tmp=p->next;
		free(p);
		p=tmp;
	}
	free(p);
}

/*********
메인 루틴 
*********/ 
main() {
	head = (student *)malloc(sizeof(student));
	memset(head, 0, sizeof(student));
	
	add_student("khh", 51);
	add_student("ksj", 21);
	add_student("abc", 31);
	add_student("kkk", 31);
	add_student("a", 1);
	add_student("b", 61);
	add_student("c", 41);
	add_student("c", 30);
	
	print_student();
	free_student();
}
