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



int main() {
    srand(time(NULL));

    User user_arr[100];
    int user_count = 0;

    for (int i = 0; i < 100; ++i) {
        User user;

        user.age = 10 + rand() % 40;
        user.weight = 60 + rand() % 40;
        user.height = 120 + rand() % 80;
        user.birth_year = 2023 - user.age;
        user.balance = rand() % 10000;

        user_arr[i] = user;
        user_count += 1;
    }

    for (int i = 0; i < user_count; i++) {

        if (user_arr[i].height > 180) {
            printf("User id: %d ||| User age: %d ||| User birth year: %d\n",
             i, user_arr[i].age, user_arr[i].birth_year
             );
        }

    }

    return 0;
}