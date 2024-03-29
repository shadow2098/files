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



void user_filtration_by_height(User *arr, int lenght) {
    for (int i = 0; i < lenght; ++i) {
        if (arr[i].height > 180) {
            printf("User id: %d ||| User age: %d ||| User birth year: %d\n",
            i, arr[i].age, arr[i].birth_year
            );
        }
    }
}

int user_deletion(User *arr, int lenght) {

   for (int i = 0; i < lenght;) {

        if (arr[i].birth_year >= 2000) {
            for (int j = i; j < lenght - 1; ++j) {
                arr[j] = arr[j + 1];
            }
            --lenght;
        } else {
            ++i;
        }
    }

    return lenght;
}


int main() {

    time_t cur_time = time(NULL);
    struct tm *gm_time = gmtime(&cur_time);
    int cur_year = gm_time->tm_year;

    User user_arr[100];
    int arr_length = 100;

    srand(time(NULL));
    for (int i = 0; i < 100; ++i) {
        User user;

        user.age = 10 + rand() % 40;
        user.weight = 60 + rand() % 40;
        user.height = 120 + rand() % 80;
        user.birth_year = 1900 + cur_year - user.age;
        user.balance = rand() % 10000;

        user_arr[i] = user;
    }

    // user_filtration_by_height(user_arr, arr_length);

    int user_count = user_deletion(user_arr, arr_length);


    for (int i = 0; i < user_count; ++i) {
        printf("%d\n", user_arr[i].birth_year);
    }

    return 0;
}