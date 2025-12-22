#include <iostream>
#include <fstream>
#include <limits>
#include <random>

//========CONSTANTS=============
const int MAX_PARAMETER_VALUE = 100;
const int STUDENT_PARAMETERS_COUNT = 6;
const char *SAVE_FILE = "game.txt";
//=========RANDOM_GENERATOR==============
std::mt19937 randomGenerator(std::random_device{}());

int randomNumber(const int min, const int max) {
    std::uniform_int_distribution<int> range(min, max);
    return range(randomGenerator);
}

//========PARAMETERS==============
double money, energy, psychics, knowledge, successfulExams = 0, day = 1, examNumber = 1, penalty = (examNumber - 1) * 5,
        luck = randomNumber(1, 100), exam4Day = randomNumber(27, 45);
double success = (knowledge * 0.75) + (psychics * 0.1) + (energy * 0.1) + (luck * 0.2) - penalty;

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
    if (energy < 0) {
        day++;
        std::cout << "Припадна, защото енергията ти е по-малка от 0";
    }
}


//======CHANGE_STATS============
void goToLessons() {
    knowledge += 20;
    energy -= 20;
    psychics -= 10;
    int randomNum = randomNumber(1, 100);
    if (energy < 80 && energy >= 40 && randomNum > 75) {
        knowledge -= 10;
    } else if (energy < 40 && randomNum > 50) {
        knowledge -= 10;
    }
    parameterRestrictions();
}

void studyHome() {
    knowledge += 20;
    energy -= 15;
    psychics -= 20;
    int randomNum = randomNumber(1, 100);
    if (energy < 80 && energy >= 40 && randomNum > 75) {
        knowledge -= 10;
    } else if (energy < 40 && randomNum > 50) {
        knowledge -= 10;
    }
    parameterRestrictions();
}

void studyWithFriends() {
    knowledge += 5;
    energy -= 10;
    psychics += 10;
    int randomNum = randomNumber(1, 100);
    if (energy < 80 && energy >= 40 && randomNum > 75) {
        knowledge -= 2.5;
        psychics -= 5;
    } else if (energy < 40 && randomNum > 50) {
        knowledge -= 2.5;
        psychics -= 5;
    }
    parameterRestrictions();
}

void eat() {
    energy += 20;
    money -= 10;
    psychics += 5;
    int randomNum = randomNumber(1, 100);
    if (energy < 80 && energy >= 40 && randomNum > 75) {
        energy -= 10;
        psychics -= 2.5;
    } else if (energy < 40 && randomNum > 50) {
        energy -= 10;
        psychics -= 2.5;
    }
    parameterRestrictions();
}

void goOut() {
    psychics += 40;
    money -= 25;
    energy -= 15;
    int randomNum = randomNumber(1, 100);
    if (energy < 80 && energy >= 40 && randomNum > 75) {
        psychics -= 20;
    } else if (energy < 40 && randomNum > 50) {
        psychics -= 20;
    }
    parameterRestrictions();
}

void sleep() {
    energy += 50;
    psychics += 10;
    parameterRestrictions();
}

void work() {
    money += 40;
    energy -= 20;
    psychics -= 10;
    int randomNum = randomNumber(1, 100);
    if (energy < 80 && energy >= 40 && randomNum > 75) {
        money -= 20;
    } else if (energy < 40 && randomNum > 50) {
        money -= 20;
    }
    parameterRestrictions();
}

void goToExam() {
    energy -= 20;
    if (success >= 75) {
        successfulExams++;
        psychics += 20;
    } else {
        psychics -= 30;
    }
    examNumber++;
    int randomNum = randomNumber(1, 100);
    if (energy < 80 && energy >= 40 && randomNum > 75) {
        psychics -= 10;
    } else if (energy < 40 && randomNum > 50) {
        psychics -= 10;
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
    std::cout << "||==========================================||" << std::endl;
    std::cout << "||  Ден: " << day << " от 45                ||" << std::endl;
    std::cout << "||  Пари: " << money << " лв                ||" << std::endl;
    std::cout << "||  Енергия: " << energy << " 🔋            ||" << std::endl;
    std::cout << "||  Психика: " << psychics << " 🧠          ||" << std::endl;
    std::cout << "||  Знания: " << knowledge << " 📔          ||" << std::endl;
    std::cout << "||  Взети изпити: " << successfulExams << " 🎓    ||" << std::endl;
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
        case 1: goToLessons();
            break;
        case 2: eat();
            break;
        case 3: goOut();
            break;
        case 4: sleep();
            break;
        case 5: work();
            break;
        case 6: if (day == 8 || day == 17 || day == 26 || day == exam4Day || day == 45) {
                goToExam();
            }
            break;
        case 7:
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


void saveGame() {
    std::ofstream out(SAVE_FILE);
    if (!out) {
        std::cout << "Играта не успя да се запази";
        return;
    }
    double stats[] = {money, energy, psychics, knowledge, successfulExams, day};
    for (int i = 0; i < STUDENT_PARAMETERS_COUNT; i++) {
        out << stats[i] << " ";
    }
    out << std::endl;
    out.close();
}

bool loadGame() {
    std::ifstream in(SAVE_FILE);
    if (!in) {
        std::cout << "Файлът не успя да се отвори";
        return false;
    }
    double stats[] = {money, energy, psychics, knowledge, successfulExams, day};
    for (int i = 0; i < STUDENT_PARAMETERS_COUNT; i++) {
        in >> stats[i];
    }
    money = stats[0];
    energy = stats[1];
    psychics = stats[2];
    knowledge = stats[3];
    successfulExams = stats[4];
    day = stats[5];
    in.close();
    printStudentStatus();
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
    if (rand == 15) {
        money += 30;
    }
    parameterRestrictions();
}

void freeCoffe() {
    int rand = randomNumber(1, 30);
    if (rand == 15) {
        psychics += 10;
    }
    parameterRestrictions();
}

void getSick() {
    int rand = randomNumber(1, 30);
    if (rand == 15) {
        energy -= 20;
    }
    parameterRestrictions();
}

void noElectricity() {
    int rand = randomNumber(1, 30);
    if (rand == 15) {
        energy -= 20;
    }
    day++;
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
    } //=========LOOP_TO_THE_LAST_DAY==========
    while (day <= 45) {
        //============CHOOSE_WHAT_TO_DO_TODAY============
    backFromOption6:
        randomDayEvents();
        if (day == 8 || day == 17 || day == 26 || day == exam4Day || day == 45) {
            std::cout << "Днес е ден за изпит. Отиваш автоматично!";
            goToExam();
            day++;
        }
        printMenu();
        int menuOption;

        do {
            std::cout << "Избери опция 1 или 2 или 3 или 4 или 5 или 6 или 7:";
            std::cin >> menuOption;
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }
        } while (menuOption != 1 && menuOption != 2 && menuOption != 3 && menuOption != 4 && menuOption != 5 &&
                 menuOption != 6 && menuOption != 7);
        //======EXIT_FROM_THE_GAME=========
        if (menuOption == 7) {
            break;
        }
        menu(menuOption);
        printStudentStatus();
        saveGame();
        if (menuOption == 7 && day != 8 && day != 17 && day != 26 && day != exam4Day && day != 45) {
            std::cout << "Не е денят за изпит. Взможните дни за изпит са 8-ия, 17-ия, 26-ия " << exam4Day <<
                    "-ия и 45-ия";
            goto backFromOption6;
        }
        //======LOST_GAME
        if (money <= 0 || psychics <= 0) {
            printLostGame();
            break;
        }
        if (day == 45 && successfulExams < 5) {
            printLostGame();
            break;
        }
        if (money < 0) {
            std::cout << "Парите ти са по-малко от 0.";
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
