#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

#define ACCESS_ONCE(x) ( *(volatile typeof(x)*)&(x))

#define container_of(ptr, type, member) ( { \
	const typeof( ((type*)0)->member ) *__mptr = (ptr);  \
	(type*)( (char *)__mptr - offsetof(type, member) );} )
	
struct llist_node;

struct llist_head {
	struct llist_node *first;
};

struct llist_node {
	struct llist_node *next;
};

#define LLIST_HEAD_INIT(name) { NULL }
#define LLIST_HEAD(name) \
	struct llist_head name = LLIST_HEAD_INIT(name)

/**
 * init_llist_head - initialize lock-less list head
 * @head: the head of your lock-less list
 */
static inline void init_llist_head(struct llist_head *list)
{
	list->first = NULL;
}

/**
 * llist_entry - get the struct of this entry
 * @ptr:   the &struct llist_node pointer
 * @type:  the type of the struct this is embedded in
 * @name:  the name of the llist_node within the struct
 */
#define llist_entry(ptr, type, name) 	\
	container_of(ptr, type, name)
	
/**
 * llist_for_each - iterate over some
 */
#define llist_for_each(pos, node) 	\
	for ((pos) = node; pos; (pos) = (pos)->next)

#define llist_for_each_entry(pos, node, member) 	\
	for ( (pos) = llist_entry((node), typeof(*(pos)), member);  \
			&(pos)->member != NULL; 	\
			(pos) = llist_entry((pos)->member.next, typeof(*pos), member) )

static inline bool llist_empty(const struct llist_head *head)
{
	return ACCESS_ONCE(head->first) == NULL;
}

static inline struct llist_node *llist_next(struct llist_node *node)
{
	return node->next;
}

static inline bool llist_add(struct llist_node *new, struct llist_head *head)
{
	struct llist_node *entry;
	entry = head->first;
	for(;;) {
		if (!entry) {
			new->next = entry;
			entry = new;
		}
		entry = entry->next;
	}
}



















