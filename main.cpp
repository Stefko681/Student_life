#include <iostream>
#include <fstream>
#include <limits>
#include <random>

//========CONSTANTS=============
const int MAX_PARAMETER_VALUE = 100;
const int STUDENT_PARAMETERS_COUNT = 7;
const int EXAM_1_DAY = 8;
const int EXAM_2_DAY = 17;
const int EXAM_3_DAY = 26;
const int EXAM_5_DAY = 45;
const char *SAVE_FILE = "game.txt";


//=========RANDOM_GENERATOR==============
std::mt19937 randomGenerator(std::random_device{}());

int randomNumber(const int min, const int max) {
    std::uniform_int_distribution<int> range(min, max);
    return range(randomGenerator);
}


//========PARAMETERS==============
double money, energy, psychics, knowledge, successfulExams = 0, day = 1, examNumber = 1,
        exam4Day = randomNumber(27, 45), failedExams = 0;


void parameterRestrictions() {
    if (energy > MAX_PARAMETER_VALUE) {
        energy = MAX_PARAMETER_VALUE;
    }
    if (psychics > MAX_PARAMETER_VALUE) {
        psychics = MAX_PARAMETER_VALUE;
    }
    if (knowledge > MAX_PARAMETER_VALUE) {
        knowledge = MAX_PARAMETER_VALUE;
    }
}


void energyLessThanZero() {
    std::cout << "Припадна и изпускаш следващия ден, защото енергията ти е по-малка от 0" << std::endl;
    day++;
    energy = 40;
}

//======RANDOM_EVENT_FOR_EVERY_MAIN_EVENT=====
void studyRandomEvents() {
    int rand = randomNumber(1, 100);
    if (rand <= 5) {
        knowledge += 15;
        std::cout << "Изведнъж всичко ти стана ясно! Материалът е елементарен. +15 знания!" << std::endl;
    } else if (rand <= 15) {
        knowledge += 5;
        psychics += 5;
        std::cout << "Колега ти праща снимани лекциите, които ти липсват. +5 знания и +5 психика!" << std::endl;
    } else if (rand <= 27) {
        energy -= 10;
        std::cout << "Прекали с четенето, очите те болят. -10 енегрия!" << std::endl;
    } else if (rand <= 34) {
        psychics -= 15;
        std::cout << "Някой пробива с бормашина точно докато учиш. -15 психика!" << std::endl;
    }
}

void workRandomEvents() {
    int rand = randomNumber(1, 100);
    if (rand <= 10) {
        money += 15;
        std::cout << "Клиентът беше много доволен. +15 пари!" << std::endl;
    } else if (rand <= 12) {
        money += 20;
        std::cout << "Докато отиваше на работа, видя 20 лв. на тротоара. +20 пари!" << std::endl;
    } else if (rand <= 17) {
        money -= 15;
        std::cout << "Счупи нещо или сбърка поръчка. Удържат ти от заплатата. -15 пари!" << std::endl;
    } else if (rand <= 27) {
        energy -= 15;
        std::cout << "Наложи се да останеш 1 час повече. -15 енергия!" << std::endl;
    }
}

void goOutRandomEvents() {
    int rand = randomNumber(1, 100);
    if (rand <= 4) {
        money += 15;
        std::cout << "КНякой непознат плати сметката на масата. +15 пари!" << std::endl;
    } else if (rand <= 9) {
        psychics += 30;
        std::cout << "Запозна се с някой много специален/на. +30 психика!" << std::endl;
    } else if (rand <= 11) {
        money -= 40;
        std::cout << "Прибираш се и осъзнаваш, че портфейлът го няма. -40 пари!" << std::endl;
    } else if (rand <= 32) {
        energy -= 20;
        std::cout << "Беше твърде диво. На сутринта си парцал. -20 енергия!" << std::endl;
    }
}

void eatRandomEvents() {
    int rand = randomNumber(1, 100);
    if (rand <= 10) {
        psychics += 5;
        std::cout << "КПромоция в стола/дюнера. +5 психика!" << std::endl;
    } else if (rand <= 15) {
        energy -= 20;
        std::cout << "Нещо му имаше на този дюнер... -20 енергия!" << std::endl;
    }
}

void sleepRandomEvents() {
    int rand = randomNumber(1, 100);
    if (rand <= 7) {
        psychics -= 10;
        std::cout << "Сънува, че отиваш гол на изпит. -10 психика   !" << std::endl;
    } else if (rand <= 17) {
        energy -= 25;
        std::cout << "Купон в съседната стая до 3 сутринта. -25 енергия!" << std::endl;
    }
}


//======CHANGE_STATS============
void goToLessons() {
    knowledge += 20;
    energy -= 20;
    psychics -= 10;
    int randomNum = randomNumber(1, 100);
    if (energy < 40 && randomNum > 50) {
        knowledge -= 10;
        std::cout << "Енергията ти е ниска и за жалост се активира ефективност на половина от действието!" << std::endl;
    } else if (energy < 80 && randomNum > 75) {
        knowledge -= 10;
        std::cout << "Енергията ти е ниска и за жалост се активира ефективност на половина от действието!" << std::endl;
    }
    parameterRestrictions();
}

void studyHome() {
    knowledge += 20;
    energy -= 15;
    psychics -= 20;
    int randomNum = randomNumber(1, 100);
    if (energy < 40 && randomNum > 50) {
        knowledge -= 10;
        std::cout << "Енергията ти е ниска и за жалост се активира ефективност на половина от действието!" << std::endl;
    } else if (energy < 80 && randomNum > 75) {
        knowledge -= 10;
        std::cout << "Енергията ти е ниска и за жалост се активира ефективност на половина от действието!" << std::endl;
    }
    parameterRestrictions();
}

void studyWithFriends() {
    knowledge += 5;
    energy -= 10;
    psychics += 10;
    int randomNum = randomNumber(1, 100);
    if (energy < 40 && randomNum > 50) {
        knowledge -= 2.5;
        psychics -= 5;
        std::cout << "Енергията ти е ниска и за жалост се активира ефективност на половина от действието!" << std::endl;
    } else if (energy < 80 && randomNum > 75) {
        knowledge -= 2.5;
        psychics -= 5;
        std::cout << "Енергията ти е ниска и за жалост се активира ефективност на половина от действието!" << std::endl;
    }
    parameterRestrictions();
}

void eat() {
    energy += 20;
    money -= 10;
    psychics += 5;
    std::cout << "Днес избра да се нахраниш. Резултатът е +20 енергия, -10 пари и +5 психика." << std::endl;
    int randomNum = randomNumber(1, 100);
    if (energy < 40 && randomNum > 50) {
        energy -= 10;
        psychics -= 2.5;
        std::cout << "Енергията ти е ниска и за жалост се активира ефективност на половина от действието!" << std::endl;
    } else if (energy < 80 && randomNum > 75) {
        energy -= 10;
        psychics -= 2.5;
        std::cout << "Енергията ти е ниска и за жалост се активира ефективност на половина от действието!" << std::endl;
    }
    parameterRestrictions();
}

void goOut() {
    psychics += 40;
    money -= 25;
    energy -= 15;
    std::cout << "Днес избра да излезеш. Резултатът е -15 енергия, -25 парии +40 психика." << std::endl;
    int randomNum = randomNumber(1, 100);
    if (energy < 40 && randomNum > 50) {
        psychics -= 20;
        std::cout << "Енергията ти е ниска и за жалост се активира ефективност на половина от действието!" << std::endl;
    } else if (energy < 80 && randomNum > 75) {
        psychics -= 20;
        std::cout << "Енергията ти е ниска и за жалост се активира ефективност на половина от действието!" << std::endl;
    }
    parameterRestrictions();
}

void sleep() {
    energy += 50;
    psychics += 10;
    parameterRestrictions();
    std::cout << "Днес избра да се наспиш. Резултатът е +50 енергия и +10 психика." << std::endl;
}

void work() {
    money += 40;
    energy -= 20;
    psychics -= 10;
    std::cout << "Днес избра да отидеш на работа. Резултатът е -20 енергия, +40 пари и -20 психика." << std::endl;
    int randomNum = randomNumber(1, 100);
    if (energy < 40 && randomNum > 50) {
        money -= 20;
        std::cout << "Енергията ти е ниска и за жалост се активира ефективност на половина от действието!" << std::endl;
    } else if (energy < 80 && randomNum > 75) {
        money -= 20;
        std::cout << "Енергията ти е ниска и за жалост се активира ефективност на половина от действието!" << std::endl;
    }
    parameterRestrictions();
}

void goToExam() {
    energy -= 20;
    int luck = randomNumber(1, 100);
    double penalty = (examNumber - 1) * 5;
    double success = (knowledge * 0.75) + (psychics * 0.1) + (energy * 0.1) + (luck * 0.2) - penalty;
    if (success >= 75.0) {
        successfulExams++;
        psychics += 20;
        std::cout << "Поздравления, успешно си взе изпита!" << std::endl;
    } else {
        psychics -= 30;
        std::cout << "За жалост не успя да си вземеш изпита." << std::endl;
        failedExams++;
    }
    examNumber++;
    int randomNum = randomNumber(1, 100);
    if (energy < 40 && randomNum > 50) {
        psychics -= 10;
        std::cout << "Енергията ти е ниска и за жалост се активира ефективност на половина от действието!" << std::endl;
    } else if (energy < 80 && randomNum > 75) {
        psychics -= 10;
        std::cout << "Енергията ти е ниска и за жалост се активира ефективност на половина от действието!" << std::endl;
    }
    parameterRestrictions();
}


void printBeginGame() {
    std::cout << "||======================================||" << std::endl;
    std::cout << "||  🎓  ПОЗДРАВЛЕНИЯ!                   ||" << std::endl;
    std::cout << "||  [1] Започване на нова игра          ||" << std::endl;
    std::cout << "||  [2] Зареждане на игра от файл       ||" << std::endl;
    std::cout << "||======================================||" << std::endl;
}


void printDifficultyLevel() {
    std::cout << "||======================================||" << std::endl;
    std::cout << "||  Избери начално ниво                 ||" << std::endl;
    std::cout << "||  [1] Лесно                           ||" << std::endl;
    std::cout << "||  [2] Нормално                        ||" << std::endl;
    std::cout << "||  [3] Трудно                          ||" << std::endl;
    std::cout << "||======================================||" << std::endl;
}


void difficultyLevel(const int n) {
    if (n == 1) {
        knowledge = 80;
        energy = 100;
        money = 100;
        psychics = 100;
    }
    if (n == 2) {
        knowledge = 50;
        energy = 80;
        money = 80;
        psychics = 80;
    }
    if (n == 3) {
        knowledge = 35;
        money = 60;
        energy = 60;
        psychics = 40;
    }
}


void printStudentStatus() {
    std::cout << std::endl;
    std::cout << "||==========================================||" << std::endl;
    std::cout << "||  Ден: " << day << " от 45                ||" << std::endl;
    std::cout << "||  Пари: " << money << " лв                ||" << std::endl;
    std::cout << "||  Енергия: " << energy << " 🔋            ||" << std::endl;
    std::cout << "||  Психика: " << psychics << " 🧠          ||" << std::endl;
    std::cout << "||  Знания: " << knowledge << " 📔          ||" << std::endl;
    std::cout << "||  Взети изпити: " << successfulExams << " 🎓    ||" << std::endl;
    if (failedExams != 0) {
        std::cout << "||  Невзети изпити: " << failedExams << " ❌    ||" << std::endl;
    }
    std::cout << "||==========================================||" << std::endl;
}


void printMenu() {
    std::cout << "Какво искаш да направиш днес?" << std::endl;
    std::cout << "[1] Учиш" << std::endl;
    std::cout << "[2] Храниш се" << std::endl;
    std::cout << "[3] Излизаш" << std::endl;
    std::cout << "[4] Почиваш" << std::endl;
    std::cout << "[5] Работиш" << std::endl;
    std::cout << "[6] Явяваш се на изпит (ако е време)" << std::endl;
    std::cout << "[7] Излез от играта" << std::endl;
    if (failedExams != 0) {
        std::cout << "[8] Яви се на поправка: " << failedExams << " ❌    ||" << std::endl;
    }
}


void printStudyOptions() {
    std::cout << "Избери тип учене?" << std::endl;
    std::cout << "[1] Ходене на лекции" << std::endl;
    std::cout << "[2] Учене вкъщи" << std::endl;
    std::cout << "[3] Учене с приятели" << std::endl;
}


void studyOptions(const int n) {
    if (n == 1) {
        goToLessons();
    }
    if (n == 2) {
        studyHome();
    }
    if (n == 3) {
        studyWithFriends();
    }
}


void menu(const int n) {
    switch (n) {
        case 2: eat();
            break;
        case 3: goOut();
            break;
        case 4: sleep();
            break;
        case 5: work();
            break;
        case 6: if (day == EXAM_1_DAY || day == EXAM_2_DAY || day == EXAM_3_DAY || day == exam4Day || day ==
                    EXAM_5_DAY) {
                goToExam();
            }
            break;
        case 7: break;
        case 8: if (failedExams != 0) {
                goToExam();
            }
        default: return;
    }
}


void printWinGame() {
    std::cout << "||======================================||" << std::endl;
    std::cout << "||  🎓  ПОЗДРАВЛЕНИЯ!                   ||" << std::endl;
    std::cout << "||  Взе всички изпити и оцеля           ||" << std::endl;
    std::cout << "||  в сесията на живота си!             ||" << std::endl;
    std::cout << "||======================================||" << std::endl;
}


void printLostGame() {
    std::cout << "||======================================||" << std::endl;
    std::cout << "||  💥 ИГРАТА ПРИКЛЮЧИ!                 ||" << std::endl;
    std::cout << "||  Твоята психика не издържа           ||" << std::endl;
    std::cout << "||  и си напуснал университета          ||" << std::endl;
    std::cout << "||======================================||" << std::endl;
}


void printExamDays() {
    std::cout << "❗❗❗Внимание! Дните са изпити са:" << EXAM_1_DAY << "-ия, " << EXAM_2_DAY << "-ия, " << EXAM_3_DAY <<
            "-ия, " <<
            exam4Day << "-ия и " << EXAM_5_DAY << "-ия❗❗❗" << std::endl;
}

void saveGame() {
    std::ofstream out(SAVE_FILE);
    if (!out) {
        std::cout << "Играта не успя да се запази.";
        return;
    }
    double stats[] = {money, energy, psychics, knowledge, successfulExams, day, failedExams};
    for (int i = 0; i < STUDENT_PARAMETERS_COUNT; i++) {
        out << stats[i] << " ";
    }
    out << std::endl;
    out.close();
    std::cout << "Успешно запзаи играта." << std::endl;
}


bool loadGame() {
    std::ifstream in(SAVE_FILE);
    if (!in) {
        std::cout << "Файлът не успя да се отвори.";
        return false;
    }
    double stats[] = {money, energy, psychics, knowledge, successfulExams, day, failedExams};
    for (int i = 0; i < STUDENT_PARAMETERS_COUNT; i++) {
        in >> stats[i];
    }
    money = stats[0];
    energy = stats[1];
    psychics = stats[2];
    knowledge = stats[3];
    successfulExams = stats[4];
    day = stats[5];
    failedExams = stats[6];
    in.close();
    return true;
}


void beginGame(const int n) {
    if (n == 1) {
        saveGame();
    }
    if (n == 2) {
        loadGame();
    }
}


//============RANDOM_EVENT_FOR_EVERY_DAY=======
void receiveMoney() {
    int rand = randomNumber(1, 30);
    if (rand < 4) {
        money += 30;
        std::cout << "Мама и тате ти пращат пари. +30 пари!" << std::endl;
    }
    parameterRestrictions();
}

void freeCoffe() {
    int rand = randomNumber(1, 30);
    if (rand < 4) {
        psychics += 10;
        std::cout << "Приятел те черпи кафе. +10 психика!" << std::endl;
    }
    parameterRestrictions();
}

void getSick() {
    int rand = randomNumber(1, 30);
    if (rand < 4) {
        energy -= 20;
        std::cout << "Разболял си се. -20 енергия!" << std::endl;
    }
    parameterRestrictions();
}

void noElectricity() {
    int rand = randomNumber(1, 30);
    if (rand < 4) {
        day++;
        std::cout << "Няма ток в блока, пропускаш действието за деня!" << std::endl;
    }
}

void randomDayEvents() {
    receiveMoney();
    freeCoffe();
    getSick();
    noElectricity();
}


int main() {
    //==========CHOOSE_GAME_START_OPTION=======
    printBeginGame();
    int beginGameOption;
    do {
        std::cout << "Избери опция 1 или 2:";
        std::cin >> beginGameOption;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
    } while (beginGameOption != 1 && beginGameOption != 2);
    beginGame(beginGameOption);


    //=========CHOOSE_DIFFICULTY_LEVEL===========
    if (beginGameOption == 1) {
        printDifficultyLevel();
        int DifficultyLevelOption;
        do {
            std::cout << "Избери опция 1 или 2 или 3:";
            std::cin >> DifficultyLevelOption;
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }
        } while (DifficultyLevelOption != 1 && DifficultyLevelOption != 2 && DifficultyLevelOption != 3);
        difficultyLevel(DifficultyLevelOption);
    }


    //=========LOOP_TO_THE_LAST_DAY==========
    while (day <= 45) {
        //============CHOOSE_WHAT_TO_DO_TODAY============
    backFromOption6:
        if (energy < 0) {
            energyLessThanZero();
        }
        printStudentStatus();
        randomDayEvents();
        printExamDays();
        if (day == EXAM_1_DAY || day == EXAM_2_DAY || day == EXAM_3_DAY || day == exam4Day || day == EXAM_5_DAY) {
            std::cout << "Днес е ден за изпит. Отиваш автоматично!" << std::endl;
            goToExam();
            day++;
        }


        printMenu();
        int menuOption;
        int studyOption;
        do {
            std::cout << "Избери опция 1 или 2 или 3 или 4 или 5 или 6 или 7 или 8(ако имаш невзет изпит):";
            std::cin >> menuOption;
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Моля избери валидна опция." << std::endl;
                continue;
            }
        } while (menuOption != 1 && menuOption != 2 && menuOption != 3 && menuOption != 4 && menuOption != 5 &&
                 menuOption != 6 && menuOption != 7 && menuOption != 8);


        //============STUDY_OPTION_CHOOSE=======
        if (menuOption == 1) {
            printStudyOptions();
            do {
                std::cout << "Избери опция 1 или 2 или 3:";
                std::cin >> studyOption;
                if (std::cin.fail()) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    continue;
                }
            } while (studyOption != 1 && studyOption != 2 && studyOption != 3);
            studyOptions(studyOption);
        }


        //======EXIT_FROM_THE_GAME=========
        if (menuOption == 7) {
            saveGame();
            break;
        }


        menu(menuOption);


        if (menuOption == 6 && day != EXAM_1_DAY && day != EXAM_2_DAY && day != EXAM_3_DAY && day != exam4Day && day !=
            EXAM_5_DAY) {
            std::cout << "Не е денят за изпит. Взможните дни за изпит са 8-ия, 17-ия, 26-ия " << exam4Day <<
                    "-ия и 45-ия" << std::endl;
            goto backFromOption6;
        }


        //======LOST_GAME
        if (psychics < 0) {
            std::cout << "Психиката ти e по-малка от 0." << std::endl;
            printLostGame();
            break;
        }

        if (day == 45 && successfulExams < 5) {
            std::cout << "Мина 45-тия ден, а не си си взел изпитите." << std::endl;
            printLostGame();
            break;
        }

        if (money < 0) {
            std::cout << "Парите ти са по-малко от 0." << std::endl;
            printLostGame();
            break;
        }


        //WIN_GAME
        if (successfulExams == 5) {
            printWinGame();
            break;
        }


        day++;
    }
}
