#include "header.h"

static void init_stack(t_stack **st, t_App *app, int i, int j);
static void push_in_stack(t_stack *st, int elem);
static int pop_from_stack(t_stack *st);
static int get_from_stack(t_stack *st);
static void restore_path_Helper(t_App *app, t_stack *st);
static void restore_allpaths_from_to(t_App *app, int i, int j);
static bool is_next(t_App *app, t_stack *st, int next);

void restore_all_paths(t_App *app) {
    for (int i = 0; i < app->SIZE; i++) {
        for (int j = i + 1; j < app->SIZE; j++)
            restore_allpaths_from_to(app, i, j);
    }
}

void make_allpaths_and_print(t_App *app) {
    make_cost_matrix(app);
    restore_all_paths(app);
}

static void init_stack(t_stack **st, t_App *app, int i, int j) {
    *st = malloc(sizeof(t_stack)); // i, j, v2, v3, ..., vn, i
    if ((*st) == NULL) exit(1);

    (*st)->max_size = app->SIZE;
    (*st)->path = malloc((*st)->max_size * sizeof(int) + 1);
    (*st)->path[0] = i;
    (*st)->path[1] = j;
    (*st)->size = 1;
}

static void push_in_stack(t_stack *st, int elem) {
    if (st->size < st->max_size) {
        st->size++;
        st->path[st->size] = elem;
    }
}

static int pop_from_stack(t_stack *st) {
    if (st->size > 1) {
        st->size--;
        return st->path[st->size + 1];
    }
    return st->path[1]; // всегда первый элемент не можно убрать.
}

static int get_from_stack(t_stack *st) {
    return st->path[st->size];
}

static bool is_next(t_App *app, t_stack *st, int next) {
    // is cur is matches short path
    int j = get_from_stack(st);
    int i = st->path[0];
    int *AM = app->AM;
    int *DM = app->dist_M;
    int size = app->SIZE;

    if (j != next) {
        if (DM[i * size + j] - AM[j * size + next] == DM[i * size + next]) {
            return true;
        }
    }
    return false;
}

static void restore_path_Helper(t_App *app, t_stack *st) {
    // base case
    if (get_from_stack(st) == st->path[0]) { //TODO: HERE IS WRONG CHECK should be some thing like:
        print_path_info(app, st);             // if (DM[i * size + j] - AM[j * size + k] == DM[i * size + k])
        return;
    }
    else { // recursive case
        // for all adjecency virtecies to j
        for (int next = 0; next < app->SIZE; next++) {
            if (is_next(app, st, next)) {
                // choose
                push_in_stack(st, next);
                // explore
                restore_path_Helper(app, st);
                // un-choose
                pop_from_stack(st);
            }
        }
    }
}

static void restore_allpaths_from_to(t_App *app, int i, int j) {
    t_stack *st = NULL;
    init_stack(&st, app, i, j);

    restore_path_Helper(app, st);

    free(st->path);
    free(st);
}


