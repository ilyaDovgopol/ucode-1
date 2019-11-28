#include "uls.h"
#include <stdio.h>

void print_list_anonim_data(t_list *head) {
    printf("head->");
    t_list *cur = head;
    for (int i = 0; cur != NULL; cur = cur->next, i++)
        printf("[%d]->", i);
    printf("NULL\n");
}

void print_list_int_data(t_list *head) {
    printf("head->");
    t_list *cur = head;
    for (int i = 0; cur != NULL; cur = cur->next, i++)
        printf("[%d) %d]->", i, *(int *)(cur->data));
    printf("NULL\n");
}

void make_anonim_list_of(t_list **head, int size) {
    for (int i = 0; i < size; i++) {
        mx_push_back(head, NULL);
    }
}

void make_int_list_of(t_list **head, int size) {
    for (int i = 0; i < size; i++) {
        int *int_p = malloc(sizeof(int));
        *int_p = i;
        mx_push_back(head, int_p);
    }
}

void print_attr_list(void **attr_array) {
    //attr_array[attr_blocks] = &sb.st_blocks;
		printf("%lu ", (unsigned long)*((blkcnt_t *)attr_array[attr_blocks]));
    //attr_array[attr_chmod] = eleven_chars_code(sb, name); // -rw-r--r--@ 
		printf("%s ", (char *)attr_array[attr_chmod]);
    //attr_array[attr_links] = &sb.st_nlink; // 1
		printf("%d ", (unsigned short)*((nlink_t *)attr_array[attr_links]));
	//attr_array[attr_user] = get_user(sb.st_uid); // psymonov
		printf("%s ", (char *)attr_array[attr_user]);
	//attr_array[attr_group] = get_group(sb.st_gid); // 4242
		printf("%s ", (char *)attr_array[attr_group]);
    //attr_array[attr_file_size] = &sb.st_size; // 623
        printf("%lu ", *((long *)(attr_array[attr_file_size])));
    //time_for_lflag(sb, arr); // Nov 18 17:33
    //attr_array[attr_a_time] = &sb.st_atimespec;
		printf("%lu ", *((long *)attr_array[attr_a_time]));
    //attr_array[attr_m_time] = &sb.st_mtimespec;
		printf("%lu ", *((long *)attr_array[attr_m_time]));
    //attr_array[attr_c_time] = &sb.st_ctimespec;
		printf("%lu ", *((long *)attr_array[attr_c_time]));
	//attr_array[attr_file_name] = get_name(sb, name); // Makefile
		printf("%s ", (char *)attr_array[attr_file_name]);
	printf("\n");
}

