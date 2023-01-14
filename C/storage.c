#include <stdlib.h>
#include <stdio.h>
#include <time.h>

struct User_storage {
    int age;
    int weight;
    int height;
    int birth_year;
    int balance;
};
typedef struct User_storage User;

/*
Написать функцию для удаления пользователей 
с определенным годом рождения
     (в случае со статическим массивом)
*/
int main() {

    time_t cur_time = time(NULL);
    struct tm *gm_time = gmtime(&cur_time);
    int cur_year = gm_time->tm_year;

    User user_arr[100];
    int arr_length = 100;
    // int user_count = 0;

    srand(time(NULL));
    for (int i = 0; i < 100; ++i) {
        User user;

        user.age = 10 + rand() % 40;
        user.weight = 60 + rand() % 40;
        user.height = 120 + rand() % 80;
        user.birth_year = 1900 + cur_year - user.age;
        user.balance = rand() % 10000;

        user_arr[i] = user;
        // user_count += 1;
    }
/*
    // user filtration
    for (int i = 0; i < user_count; i++) {
        if (user_arr[i].height > 180) {
            printf("User id: %d ||| User age: %d ||| User birth year: %d\n",
             i, user_arr[i].age, user_arr[i].birth_year
             );
        }

    }
*/
    for (int i = 0; i < 100; ++i) {

        printf("%d\n", user_arr[i].birth_year);
    }

    printf("\n\n\n\n\n");

    for (int i = 0; i < arr_length; ++i) {

        if (user_arr[i].birth_year >= 2000) {
            printf("%d\n", i);
            for (int j = i; j < arr_length - 1; ++j) {
                user_arr[j] = user_arr[j + 1];
                // printf("%d\n", user_arr[j].age);
                // printf("%d\n", j);
                // user_count += 1;
            }
        }
    }

    for (int i = 0; i < 100; ++i) {

        printf("%d\n", user_arr[i].birth_year);
    }


   // for (int i = 0; i < user_count; ++i) {
   //     printf("%d\n", user_arr[i].age);
   // }

    return 0;
}