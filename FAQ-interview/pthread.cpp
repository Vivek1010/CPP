#include <stdio.h>
#include <pthread.h>
#include <time.h>
#include <assert.h>
#include <stdlib.h>

#define SZ 1000

typedef struct
{
  int *arr;
  int arr_size;
} parallel_sum_task_arg_t;

int serial_sum(int arr[], int arr_size)
{
  int i, sum = 0;
  for (i = 0; i < arr_size; i++)
  {
    sum += arr[i];
  }
  return sum;
}
void *parallel_sum_task(void *arg)
{
  parallel_sum_task_arg_t *task_arg = (parallel_sum_task_arg_t *)arg;
  int sum = serial_sum(task_arg->arr, task_arg->arr_size);
  // printf(" returning task_sum %d \n", sum);
  //  return &partial_sum;
  return ((void *)(sum));
}

int parallel_sum(int arr[], int arr_size, int num_threads)
{
  int i, sum = 0;

  for (i = 0; i < num_threads; i++)
  {
    pthread_t thread;
    parallel_sum_task_arg_t task_arg = {arr, arr_size};
    // int *task_sum = NULL;
    int task_sum = 0;
    // assert(pthread_create(&thread, NULL, (void*) parallel_sum_task, &task_arg) == 0);
    assert(pthread_create(&thread, NULL, parallel_sum_task, &task_arg) == 0);
    pthread_join(thread, (void **)&task_sum);
    // printf(" task_sum %d \n", task_sum);
    sum += task_sum;
  }

  return sum;
}

int main()
{
  int arr[SZ], i;
  int arr_size, num_threads;

  scanf("%d %d", &arr_size, &num_threads);
  assert(arr_size < SZ);

  srand(time(NULL));
  for (i = 0; i < arr_size; i++)
  {
    arr[i] = rand() % 1000;
  }
  printf(" serial sum = %d \n", serial_sum(arr, arr_size));
  printf(" parallel sum  = %d \n", parallel_sum(arr, arr_size, num_threads));
  // assert(serial_sum(arr, arr_size) == parallel_sum(arr, arr_size, num_threads));
  return 0;
}
